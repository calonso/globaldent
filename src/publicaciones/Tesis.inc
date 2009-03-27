<?php
    /**
    * Fichero que recoje la implementación de la clase Tesis que se encarga del control de las tesis doctorales
    * 
    * @package Negocio
    * @subpackage Publicaciones
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (13 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la logica de presentacón de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo TesisDAO para tener acceso a la lógica de acceso a datos
    */
    include_once PATH_BASE."src/publicaciones/TesisDAO.inc";
    /**
    * Inclusion del archivo UsuarioDAO para tener acceso a los datos de los usuarios
    */
    include_once PATH_BASE."src/usuarios/UsuarioDAO.inc";
    
    /**
    * Clase Tesis. Implementa toda la lógica de manejo de las tesis
    * @package Negocio
    * @subpackage Publicaciones
    */
    class Tesis extends DisplayManager
    {
        /**
        * Variable de almacenamiento e intercambio de datos con su objeto DAO
        * @var array
        */
        private $datos;
        /**
        * Variable que guarda la referencia al objeto DAO que le ayudara a acceder a la BD
        * @var resource
        */
        private $dao;
        /**
        * Constructor de la clase. Crea un objeto de la clase padre e inicializa las variables   
        * @param string. Idioma en que se ha solicitado la pagina
        * @return void
        */
        function Tesis ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."publicaciones/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            $this->smarty->assign ('on', 3);
            $this->datos = array();
            $this->dao = new TesisDAO();
            return;   
        }
        /**
        * Funcion que muestra un formulario donde el usuario metera los datos de su nueva tesis.
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function muestraFormulario ($params, $file)
        {
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que guarda los datos de la nueva tesis enviada en la BD.
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function nuevaTesis ($params, $file)
        {
            $this->recibirFormulario ($params); 
            $this->datos[fecha] = strftime("%d-%m-%Y");
            $this->datos[id_usuario] = $_SESSION[id_usr];
            
            if(is_uploaded_file($_FILES[fileTesis][tmp_name]))
            {
                switch($_FILES[fileTesis][type])
                {
                    case "application/pdf":
                        $extension = ".pdf";
                        break;
                        /*
                    case "application/msword":
                        $extension = ".doc";
                        break;
                    case "text/plain":
                        $extension = ".txt";
                        break;
                    case "application/vnd.ms-excel":
                        $extension = ".xls";
                        break;
                    case "application/vnd.ms-powerpoint":
                        $extension = ".ppt";
                        break;  */
                    default:
                        $this->smarty->assign ('codigo', -3);
                        $this->smarty->display ($this->path."nueva.phtml");
                        return;
                        break;    
                }
                $nuevoid = $this->dao->nuevo ($this->datos);
                $this->smarty->assign ('codigo', $nuevoid);
                if($nuevoid > 0)
                    move_uploaded_file($_FILES[fileTesis][tmp_name], PATH_BASE."publi/tesis/".$nuevoid.$extension);
                          
            }else
                $this->smarty->assign('codigo', -2);
                
            $this->smarty->display ($this->path."nueva.phtml");
            return;
              
        }
        /**
        * Funcion que recoge y carga todos los valores recibidos en el formulario enviado por el usuario
        * @params resource Objeto de la clase params para tener acceso a los parametros de la peticion
        * @return void
        */
        function recibirFormulario ($params)
        {
            $this->datos[titulo] = $params->getParam('txtTitulo');
            $this->datos[autor] = $params->getParam ('txtAutor');
            $this->datos[directores] = $params->getParam ('txtDir');
            return;   
        }
        /**
        * Funcion que muestra una lista con todas las tesis alojadas en el portal
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function listado ($params, $file)
        {
            $pagina = $params->getParam ('pg');
            if(isset($pagina))
            {
                $this->datos = $this->dao->listado (0, $pagina);
            }else
                $this->datos = $this->dao->listado (0);
            if(is_array ($this->datos))
            {
                $usuario = new UsuarioDAO ();
                $recibidas = $this->datos[0];
                $this->datos = $this->datos[1];
                if(isset($pagina))
                {
                    $total = $params->getParam ('total');
                    $inicio = ($pagina * MAX_FILAS);
                    $final = $inicio + $recibidas;
                    $numero = array("inicio" => $inicio, "final" => $final, "total" => $total, "pagina" => $pagina);   
                }else{
                    $total = $recibidas;
                    $inicio = 0;
                    if($recibidas > MAX_FILAS)
                    {
                        $final = MAX_FILAS;
                        $this->datos = array_slice ($this->datos, 0, MAX_FILAS, TRUE);
                    }else
                        $final = $recibidas;
                    $numero = array("inicio" => $inicio, "final" => $final, "total" => $total, "pagina" => $pagina);      
                }
                foreach ($this->datos as $indice => $valor)
                {
                    $temp = $usuario->ver ($this->datos[$indice][id_usuario]);
                    if(is_array($temp))
                    {    
                        $temp = $temp[0];
                        $this->datos[$indice][usuario] = $temp[apellido]." ".$temp[apellido2].", ".$temp[nombre];
                    }      
                }
                $this->smarty->assign ('tesis', $this->datos);
            }else
                $numero = array("inicio" => 0, "final" => 0, "total" => 0, "pagina" => 0);
                
            $this->smarty->assign ('numero', $numero);    
            $this->smarty->display ($this->path.$file.".phtml");   
        }
        /**
        * Funcion que muestra el contenido completo de la tesis
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function ver ($params, $file)
        {
            $id = $params->getParam ('id');
            $this->datos = $this->dao->ver ($id);
            if(is_array ($this->datos))
            {
                $usuario = new UsuarioDAO(); 
                $this->datos = $this->datos[0];
                $temp = $usuario->ver ($this->datos[id_usuario]);
                $this->datos[usuario] = $temp[0][apellido]." ".$temp[0][apellido2].", ".$temp[0][nombre];
                $this->smarty->assign ('codigo', 1);
                $this->smarty->assign ('tesis', $this->datos);
            }else
                $this->smarty->assign ('codigo', 0);
                
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que muestra los datos de la tesis en formato editable para ser modificados
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function muestraModificar ($params, $file)
        {
            $id = $params->getParam ('id');
            $this->datos = $this->dao->ver ($id);
            if (is_array ($this->datos))
            {
                $this->datos = $this->datos[0];
                if($_SESSION[id_usr] == $this->datos[id_usuario])
                {
                    $this->smarty->assign ('codigo', 1);
                    $this->smarty->assign ('tesis', $this->datos);
                }else
                    $this->smarty->assign ('codigo', -1);    
            }else
                $this->smarty->assign ('codigo', 0);
              
            $this->smarty->display ($this->path.$file.".phtml");   
        }
        /**
        * Funcion que actualiza los datos de la tesis a partir de los nuevos recibidos
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function actualizar ($params, $file)
        {
            $this->recibirFormulario ($params);
            $this->datos[id_tesis] = $params->getParam('id');
            $resultado = $this->dao->modificar ($this->datos);
            $this->smarty->assign ('codigo', $resultado);
            $this->smarty->display ($this->path."actualizar.phtml");   
        }
        /**
        * Funcion que borra los datos de la tesis
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function borrar ($params, $file)
        {
            $id = $params->getParam ('id');
            $this->datos = $this->dao->borrar ($id);
            $this->smarty->assign ('codigo', $this->datos);
            if($this->datos == 1)
                unlink (PATH_BASE."publi/tesis/$id.pdf");
            $this->smarty->display ($this->path."borrar.phtml");
            return;    
        }
    }
    
?>