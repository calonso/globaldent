<?php
    /**
    * Archivo que recoje la implementacion de la clase Foros.
    * 
    * @package Negocio
    * @subpackage Publicaciones
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (13 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la lógica de presentación de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo ForosDAO para tener acceso a la lógica de acceso a datos
    */
    include_once PATH_BASE."src/publicaciones/ForosDAO.inc";
    /**
    * Inclusion del archivo TipoForoDAO para tener acceso a la lógica de acceso a datos
    */
    include_once PATH_BASE."src/publicaciones/TipoForoDAO.inc";
    /**
    * Inclusion del archivo MensajeDAO para tener acceso a la lógica de acceso a datos
    */
    include_once PATH_BASE."src/publicaciones/MensajeDAO.inc";
    /**
    * Inclusion del archivo UsuarioDAO para tener acceso a la lógica de acceso a datos
    */
    include_once PATH_BASE."src/usuarios/UsuarioDAO.inc";
    
    /**
    * Clase Foros. Implementa toda la lógica de negocio de los objetos Foro
    */
    class Foros extends DisplayManager
    {
        /**
        * Variable que almacenara los datos que se intercambian con el DAO
        * @var array
        */
        private $datos;
        /**
        * Variable que guarda la referencia al objeto DAO correspondiente
        * @var resource
        */
        private $dao;
        /**
        * Variable que guarda la referencia al objeto DAO correspondiente a los mensajes
        * @var resource
        */
        private $mensdao;
        /**
        * Constructor de la clase, crea un objeto de la clase padre e inicializa las variables
        * @param string Idioma en que se ha solicitado la página
        * @return void   
        */
        function Foros ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."foros/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            $this->smarty->assign ('on', 4);
            $this->datos = array();
            $this->dao = new ForosDAO();
            $this->mensdao = new MensajeDAO();
            return;   
        }
        /**
        * Funcion que muestra la pagina principal de los foros
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraForos ($params, $file)
        {
            $objeto = new TipoForoDAO ();
            $usuario = new UsuarioDAO ();
            $this->datos = $objeto->listado (1);
            $nombres = array();
            $numeros = array();
            $foros = array();
            foreach ($this->datos as $array)
            {
                array_push($nombres, $array[nombre]);
                $datos = $this->dao->listado ($array[id_tipo_foro]);
                if(is_array($datos))
                {   
                    if($datos[0] > 5)
                        $datos[1] = array_slice ($datos[1], 0, 5, true);
                    foreach ($datos[1] as $indice => $elemento)
                    {
                        $mensajes = $this->mensdao->listado ($elemento[id_foro]);
                        if(is_array($mensajes))
                        {
                            $datos[1][$indice][numero] = $mensajes[0];
                            $datos[1][$indice][fecha] = $mensajes[1][0][fecha];
                            $datos[1][$indice][hora] = $mensajes[1][0][hora];
                            $temp = $usuario->ver ($mensajes[1][0][id_usuario]);
                            if(is_array($temp))
                                $datos[1][$indice][usuario] = $temp[0][apellido]." ".$temp[0][apellido2].", ".$temp[0][nombre];
                            else
                                $datos[1][$indice][usuario] = "Usuario dado de baja";
                        }else
                            $datos[1][$indice][numero] = 0;   
                    }
                    array_push($numeros, $datos[0]);
                    array_push($foros, $datos[1]);
                }else{
                    array_push($foros, 0);
                    array_push($numeros, 0);
                }
            }
            $this->smarty->assign('foros', $foros);
            $this->smarty->assign('numeros', $numeros);
            $this->smarty->assign('nombres', $nombres);
            
            if($_SESSION[privilegios] == 9)
                $file = "forosadmin";
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que muestra un formulario para abrir un nuevo foro.
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraFormulario ($params, $file)
        {
            $objeto = new TipoForoDAO();
            $this->datos = $objeto->listado (1);
            foreach ($this->datos as $linea)
                $tipos[$linea[id_tipo_foro]] = $linea[nombre];    
            $this->smarty->assign ('tipos', $tipos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que guarda los datos del nuevo foro enviados por el usuario en la BD
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function nuevo ($params, $file)
        {
            $this->recibirFormularioForo ($params);
            $nuevoid = $this->dao->nuevo ($this->datos);
            if($nuevoid >= 1)
            {
                $this->datos = array();
                $this->recibirFormulario ($params);
                $this->datos[id_usuario] = $_SESSION[id_usr];
                $this->datos[fecha] = strftime("%d-%m-%Y");
                $this->datos[hora] = strftime("%H:%M");
                $this->datos[id_foro] = $nuevoid;
                $this->datos[id_padre] = 0;
                $nuevoid2 = $this->mensdao->nuevo ($this->datos);
                $this->smarty->assign ('codigo', $nuevoid2);   
            }else
                $this->smarty->assign ('codigo', -1);
            
            $this->smarty->display ($this->path.$file.".phtml");
        } 
        /**
        * Funcion que recoje los datos que el usuario envió a través del formulario relativos al nuevo foro. 
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @return void
        */
        function recibirFormularioForo ($params)
        {
            $this->datos[nombre] = $params->getParam('txtNombre');
            $this->datos[id_tipo_foro] = $params->getParam ('selTipo');
            return;   
        }
        /**
        * Funcion que recoje los datos que el usuario envió a través del formulario relativos al nuevo mensaje. 
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @return void
        */
        function recibirFormulario ($params)
        {
            $this->datos[titulo] = $params->getParam('txtTitulo');
            $this->datos[texto] = $params->getParam ('txtTexto');
            return;   
        }
        /**
        * Función que muestra un listado con todos los foros abiertos del tipo escogido por el usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function listado ($params, $file)
        {
            $id = $params->getParam ('id');
            $objeto = new TipoForoDAO ();
            $temp = $objeto->ver ($id);
            $this->smarty->assign ('tipo', $temp[0]);
            $mens = array();
            $foros = array ();
            
            $pagina = $params->getParam ('pg');
            if(isset($pagina))
            {
                $this->datos = $this->dao->listado ($id, $pagina);
            }else
                $this->datos = $this->dao->listado ($id);
                
            if(is_array($this->datos))
            {   
                $usuario = new UsuarioDAO ();
                $recibidos = $this->datos[0];
                if(isset($pagina))
                {
                    $total = $params->getParam ('total');
                    $inicio = ($pagina * MAX_FILAS);
                    $final = $inicio + $recibidos;
                    $numero = array("inicio" => $inicio, "final" => $final, "total" => $total, "pagina" => $pagina);   
                }else{
                    $total = $recibidos;
                    $inicio = 0;
                    if($recibidos > MAX_FILAS)
                    {
                        $final = MAX_FILAS;
                        $this->datos[1] = array_slice ($this->datos[1], 0, MAX_FILAS, TRUE);
                    }else
                        $final = $recibidos;
                    $numero = array("inicio" => $inicio, "final" => $final, "total" => $total, "pagina" => $pagina);      
                }
                foreach ($this->datos[1] as $indice => $elemento)
                {
                    $mensajes = $this->mensdao->listado ($elemento[id_foro]);
                    if(is_array($mensajes))
                    {
                        $this->datos[1][$indice][numero] = $mensajes[0];
                        $this->datos[1][$indice][fecha] = $mensajes[1][0][fecha];
                        $this->datos[1][$indice][hora] = $mensajes[1][0][hora];
                        $temp = $usuario->ver ($mensajes[1][0][id_usuario]);
                        if(is_array($temp))
                            $this->datos[1][$indice][usuario] = $temp[0][apellido]." ".$temp[0][apellido2].", ".$temp[0][nombre];
                        else
                            $this->datos[1][$indice][usuario] = "Usuario dado de baja";
                            
                    }else
                        $this->datos[1][$indice][numero] = 0;   
                    
                }
                $this->smarty->assign ('foros', $this->datos[1]);
            }else
                $numero = array("inicio" => 0, "final" => 0, "total" => 0, "pagina" => 0);
             
            $this->smarty->assign ('numero', $numero);
            
            if($_SESSION[privilegios] == 9)
                $file = "listaforosadmin";   
            $this->smarty->display ($this->path.$file.".phtml"); 
        }
        /**
        * Funcion que muestra todos los mensajes pertenecientes a un foro
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function ver ($params, $file)
        {
            $usuario = new UsuarioDAO ();
            $final = array ();
            $id = $params->getParam ('id');
            $array = array("id_foro" => $id, "id_padre" => 0);
            $this->datos = $this->mensdao->ver ($array);
            if(is_array($this->datos))
            {   
                $profundidad = 0;
                $this->datos = $this->datos[1];
                foreach ($this->datos as $padre)
                {   
                    $aux = $usuario->ver ($padre[id_usuario]);
                    $padre[usuario] = $aux[0][apellido]." ".$aux[0][apellido2].", ".$aux[0][nombre];
                    $padre[profundidad] = $profundidad;
                    array_push($final, $padre);
                    $hijos = $this->verHijos ($id, $padre[id_mensaje], $profundidad);
                    if(is_array($hijos))
                    {   
                        foreach ($hijos as $unidad)
                        {    
                            if(is_array($unidad))
                                array_push($final, $unidad);
                        }        
                    }else  
                        array_push($final, 0);    
                } 
                $this->smarty->assign ('codigo', 1);  
            }else
                $this->smarty->assign ('codigo', 0);
                
            $this->smarty->assign ('datos', $final);
            $this->smarty->display ($this->path.$file.".phtml");
               
        }
        /**
        * Funcion que obtiene de forma recursiva un array con los hijos directos de un mensaje determinado
        * @param int Identificador del foro al que pertenecen los mensajes que se quieren buscar
        * @param int Identificador del mensaje al que responden los mensajes que se quieren buscar
        * @param int Representa a la profundidad en que se anidará el mensaje
        * @return array 
        */
        function verHijos ($idforo, $idmens, $profundidad)
        {
            $usuario = new UsuarioDAO();
            $array = array("id_foro" => $idforo, "id_padre" => $idmens);
            $temp = $this->mensdao->ver ($array);
            if(is_array($temp))
            {   $profundidad ++;
                $datos = array();
                $temp = $temp[1];
                foreach($temp as $padre)
                {   
                    $aux = $usuario->ver ($padre[id_usuario]);
                    $padre[usuario] = $aux[0][apellido]." ".$aux[0][apellido2].", ".$aux[0][nombre];
                    $padre[profundidad] = $profundidad;
                    array_push($datos, $padre);
                    $hijos = $this->verHijos ($idforo, $padre[id_mensaje], $profundidad);
                    if(is_array($hijos))
                    {   
                        foreach ($hijos as $unidad)
                        {
                            if(is_array($unidad))
                                array_push($datos, $unidad);
                        }       
                    }else
                        array_push($datos, 0);
                } 
                return $datos;      
            }else
                return $datos;                    
        }
        /**
        * Funcion que muestra el formulario para crear un nuevo mensaje
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraForm ($params, $file)
        {
            $id = $params->getParam('id');
            $this->smarty->assign ('id', $id);
            $this->datos = $this->mensdao->ver (array("id_mensaje" => $id));
            $this->smarty->assign ('cadena', "RE:".$this->datos[1][0][titulo]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que crea un nuevo mensaje en respuesta al seleccionado por el usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function responder ($params, $file)
        {
            $id = $params->getParam('id');
            $this->recibirFormulario ($params);
            $temp = $this->mensdao->ver (array("id_mensaje" => $id));
            if(is_array($temp))
            {
                $temp = $temp[1];
                $foro = $temp[0][id_foro];  
            }else{
                $this->smarty->assign ('codigo', 0);
                $this->smarty->display ($this->path."nuevoforo.phtml");
                return;   
            }
            $this->datos[id_usuario] = $_SESSION[id_usr];
            $this->datos[fecha] = strftime("%d-%m-%Y");
            $this->datos[hora] = strftime("%H:%M");
            $this->datos[id_foro] = $foro;
            $this->datos[id_padre] = $id;
            
            $nuevoid = $this->mensdao->nuevo ($this->datos);
            $this->smarty->assign ('codigo', $nuevoid);
            $this->smarty->display ($this->path."nuevoforo.phtml");
            return;   
        }
        /**
        * Funcion que borra un foro
        * 
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function borrar ($params, $file)
        {
            $id = $params->getParam ('id');
            
            $this->datos = $this->dao->borrar ($id);
            $this->muestraForos ($params, "foros");
            return;   
        }
    }
?>