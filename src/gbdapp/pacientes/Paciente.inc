<?php
    /**
    * Fichero que recoje la implementacion de la clase paciente.
    * 
    * @package Negocio
    * @subpackage Pacientes
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (9 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DisplayManager para tener acceso a la logica de presentacion de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del fichero PacienteDAO para tener acceso a la logica de almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/pacientes/PacienteDAO.inc";
    /**
    * Inclusion del fichero DresDAO para tener acceso a la lógica de acceso a datos para doctores
    */
    include_once PATH_BASE."src/gbdapp/dres/DresDAO.inc";
    /**
    * Inclusion del fichero ProvinciaDAO para tener acceso a la lógica de acceso a datos para provincias
    */
    include_once PATH_BASE."src/provincias/ProvinciaDAO.inc";
    /**
    * Inclusion del fichero DresDAO para tener acceso a la lógica de acceso a datos para doctores
    */
    include_once PATH_BASE."src/gbdapp/log/Logger.inc";
    /**
    * Inclusion del fichero GrupoImgsDAO para tener acceso a la lógica de acceso a datos para doctores
    */
    include_once PATH_BASE."src/gbdapp/conf/GrupoImgsDAO.inc";
    
    
    /**
    * Clase Paciente. Implementa toda la logica de manejo de datos de pacientes por parte de los usuarios
    * @package Negocio
    * @subpackage Pacientes
    */
    class Paciente extends DisplayManager
    {
        /**
        *  Almacenará todos los datos que se manejen en cada petición y se usará como objeto de intercambio de datos con el DAO
        * @var array
        */
        private $datos;
        /**
        *  Almacenará la referencia a su objeto DAO
        * @var resource
        */
        private $dao;
        /**
        * Almacenará la ruta a la carpeta de las imágenes
        * @var string
        */
        private $carpeta;
        /**
        * Almacenará la referencia al objeto Logger
        */
        private $logger;
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @return void
        */
        function Paciente ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/pacientes/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 3);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            $this->dao = new PacienteDAO(); 
            $this->carpeta = PATH_BASE."imagenes/".$_SESSION[id_usr]."/";
            
            $this->logger = new Logger($lang); 
            return; 
        }
        /**
        * Funcion que muestra la página principal de los pacientes
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function index ($params, $file)
        {
            $this->smarty->display ($this->path.$file.".phtml"); 
            return;  
        }
        /**
        * Funcion que muestra el formulario a rellenar por el usuario para dar de alta un nuevo paciente
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraFormulario ($params, $file)
        {
            $this->cargaSelectores ();
                
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que carga los datos correspondientes a las listas de seleccion de provincia, paciente y doctores ajenos
        * @return void
        */
        function cargaSelectores ()
        {
            $datos = array();
            $aux = new DresDAO();
            $datos = $aux->listado(0);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach($datos as $linea)
                    $dres[$linea[id_dr_externo]] = $linea[apellido]." ".$linea[apellido2].", ".$linea[nombre];
                $this->smarty->assign ('dres', $dres);      
            }
                
            $aux = new ProvinciaDAO();
            $datos = $aux->listado(0);
            if(is_array($datos))
            {
                foreach($datos as $linea)
                    $prov[$linea[id_provincia]] = $linea[provincia];
                $this->smarty->assign ('provincias', $prov);      
            }
            
            $aux = new GrupoImgsDAO();
            $datos = $aux->listado(0);
            if(is_array($datos))
            {
                foreach($datos[1] as $linea)
                    $grupos[$linea[id_grupo_imagenes]] = $linea[nombre];
                $this->smarty->assign ('grupoImagenes', $grupos);      
            }
            
            $datos = $this->dao->listado(0);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach($datos as $linea)
                    $pacs[$linea[id_paciente]] = $linea[apellido]." ".$linea[apellido2].", ".$linea[nombre];
                $this->smarty->assign ('pacs', $pacs);      
            }
            return;    
        }
        
        /**
        * Funcion que agrega un nuevo paciente a la base de datos a partir de los datos introducidos por el usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function nuevo ($params, $file)
        {
            $this->datos = $this->recibirFormulario ($params);
            $fecha = strftime ("%d-%m-%Y");
            $aux = explode("-", $fecha);
            $aux[0] = (int)$aux[0];
            $aux[1] = (int)$aux[1];
            $fecha = $aux[0]."-".$aux[1]."-".$aux[2];
            $this->datos[fecha_alta] = $fecha;
            $this->datos[id_usuario] = $_SESSION[id_usr];
            
            if(is_uploaded_file($_FILES[fileFoto][tmp_name])) 
            {
                $extension = $_FILES[fileFoto][type];
                $aux = explode ("/",$extension);
                $this->datos[extension] = $aux[1];
            } 
            
            $ret = $this->dao->nuevo ($this->datos);
            $this->smarty->assign ('codigo', $ret);
            if($ret > 0)
            {
                mkdir ($this->carpeta."id".$ret);
                if(is_uploaded_file($_FILES[fileFoto][tmp_name])) 
                {
                    move_uploaded_file ($_FILES[fileFoto][tmp_name], $this->carpeta."id".$ret."/fotopers");
                }  
                
                $nombre = $this->datos[apellido]." ".$this->datos[apellido2].", ".$this->datos[nombre];
                $this->logger->save (LOG_ALTA, $nombre);
            }
            $this->smarty->display ($this->path.$file.".phtml");       
        }
        /**
        * Funcion que recoje y devuelve todos los datos enviados por el usuario a través del formulario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @return array
        */
        function recibirFormulario ($params)
        {
            $datos = array();
            $datos[nombre] = $params->getParam('txtNombre');
            $datos[apellido] = $params->getParam('txtApe');
            $datos[apellido2] = $params->getParam('txtApe2');
            $datos[dni] = $params->getParam('txtDNI');
            $datos[fecha_nacimiento] = $params->getParam('txtFechanac');
            $datos[profesion] = $params->getParam('txtProf'); 
            $datos[direccion] = $params->getParam('txtDir'); 
            $datos[cp] = $params->getParam('txtCP');
            $datos[ciudad] = $params->getParam('txtCiudad');
            $datos[id_provincia] = $params->getParam('selProv');    
            $datos[telefono_fijo] = $params->getParam('txtTelfijo');
            $datos[telefono_movil] = $params->getParam('txtMovil');
            $datos[telefono_trabajo] = $params->getParam('txtTeltrab');
            $datos[email] = $params->getParam('txtEmail');
            $datos[id_dr_referidor] = $params->getParam('selDr');
            $datos[id_paciente_referidor] = $params->getParam('selPac');
            $datos[observaciones] = $params->getParam('txtObservaciones');
            $datos[alertas_medicas] = $params->getParam('txtAlertas');
            $datos[alto_riesgo] = $params->getParam ("txtAlto"); 
            
            return $datos;  
        }
        /**
        * Funcion que muestra todos los datos almacenados de un doctor
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function ver ($params, $file)
        {
            $idPac = $params->getParam ('id');
            $this->datos = $this->dao->ver ($idPac);
            if(is_array($this->datos))
            {   
                $aux = $this->dao->listaReferidos ($this->datos[id_paciente]);
                if(is_array($aux))
                {
                    $referidos = array();
                    foreach ($aux as $linea)
                    {
                        $nombre = $linea[apellido]." ".$linea[apellido2].", ".$linea[nombre];
                        $id = $linea[id_paciente];
                        $temp = array("nombre" => $nombre, "id" => $id);
                        array_push ($referidos, $temp);
                    }
                    $this->datos[referidos] = $referidos;
                }
                
                $cita = new CitaDAO();
                $aux = $cita->proximaCita($idPac);
                $this->datos[cita] = $aux[1];	
                $this->datos[num_citas] = $aux[0];
                $this->smarty->assign ('datos', $this->datos);
            }
                
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que muestra la ficha del paciente en formato editable para actualizar los datos
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraModificar ($params, $file)
        {
            $id = $params->getParam ('id');
            $this->datos = $this->dao->ver ($id);
            if(is_array($this->datos))
            {
                $this->cargaSelectores();
                $this->smarty->assign ('datos', $this->datos);
            }
                
            $this->smarty->display ($this->path.$file.".phtml");
            return;       
        }
        /**
        * Funcion que actualiza los datos del paciente a partir de los introducidos por el usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function actualizar ($params, $file)
        {
            $this->datos = $this->recibirFormulario ($params);
            $this->datos[id_usuario] = $_SESSION[id_usr];
            $this->datos[id_paciente] = $params->getParam ('id');
            
            if(is_uploaded_file($_FILES[fileFoto][tmp_name])) 
            {
                @unlink ($this->carpeta."id".$this->datos[id_paciente]."/fotopers");
                $extension = $_FILES[fileFoto][type];
                $aux = explode ("/",$extension);
                $this->datos[extension] = $aux[1];
                move_uploaded_file ($_FILES[fileFoto][tmp_name], $this->carpeta."id".$this->datos[id_paciente]."/fotopers"); 
            }
            
            $ret = $this->dao->modificar ($this->datos);
            
            $nombre = $this->datos[apellido]." ".$this->datos[apellido2].", ".$this->datos[nombre];
            $this->logger->save(LOG_MODIFICACION, $nombre);
            
            $this->smarty->assign ('codigo', $this->datos[id_paciente]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que borra todos los datos del paciente seleccionado de la base de datos
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function borrar ($params, $file)
        {
            $id = $params->getParam ('id');
            $nombre = $this->getPaciente($id);
            
            $this->datos = $this->dao->borrar ($id);
            if($this->datos == -1){
                $this->logger->save(LOG_BAJA, $nombre);
                $this->borraDir ($this->carpeta."id".$id);
            }
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que devuelve el nombre del paciente
        * @param int Id del paciente
        * @return String Apellidos y nombre del paciente
        */
        function getPaciente ($id)
        {
            $datos = $this->dao->ver ($id);
            $datos = $datos[0];
            return $datos[apellido]." ".$datos[apellido2].", ".$datos[nombre];    
        }
        /**
        * Funcion que borra el directorio completo donde se alojaban todos los documentos e imagenes del paciente
        * @param string Ruta de la carpeta del paciente
        * @return void
        */
        function borraDir ($carpeta)
        {   
            if( is_dir( $carpeta ) ){
                foreach( scandir( $carpeta ) as $item ){
                    if( !strcmp( $item, '.' ) || !strcmp( $item, '..' ) )
                        continue;
                    $this->borraDir( $carpeta . "/" . $item );
                }
                rmdir( $carpeta );
            } else {
                unlink( $carpeta );
            }   
        }
        /**
        * Funcion que muestra un listado ordenado por la inicial de cada apellido de todos los pacientes almacenados
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function listado ($params, $file)
        {
            $let = $params->getParam ('let');
            $pag = $params->getParam ('pag');
            $letras = $this->getLetras ();
            
            $letter = isset($let) ? $let : $letras[1][0];
            $page = isset ($pag) ? $pag : 0; 
                
            $this->datos = $this->dao->buscaParaLista ($letter, $pag);            
            if(is_array($this->datos))
            {
                $this->smarty->assign ('pag', $page);
                $this->smarty->assign ('codigo', 1);
                $this->smarty->assign ('datos', $this->datos[1]);
                $this->smarty->assign ('numero', $this->datos[0]);
            }else
                $this->smarty->assign ('codigo', 0);
            
            $this->smarty->assign ('letras', $letras[1]);
            $this->smarty->assign ('todas', $letras[0]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        /**
        * Funcion que determina las letras iniciales que pertenecen a algun apellido de entres los doctores almacenados
        * @return array Array compuesto por dos arrays, uno con todas las letras y otro con aquellas encontradas.
        */
        function getLetras ()
        {
            $array_todas = array("A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z");
            $array_letras = array();
            
            $resultados = $this->dao->iniciales ();
            if (is_array($resultados[1])) 
            {
                foreach ($resultados[1] as $linea)
                {     
                        $nueva = strtoupper($linea[apellido][0]);
                        $valor = ord($nueva);
                        if ($valor >= 128) 
                        {
                            if( (($valor >= 192) && ($valor <= 197)) || (($valor >= 224) && ($valor <= 229))) 
                                $nueva = "A";
                            if( (($valor >= 200) && ($valor <= 203)) || (($valor >= 232) && ($valor <= 235))) 
                                $nueva = "E";
                            if( (($valor >= 204) && ($valor <= 207)) || (($valor >= 236) && ($valor <= 239))) 
                                $nueva = "I";
                            if( (($valor >= 210) && ($valor <= 214)) || (($valor >= 242) && ($valor <= 246))) 
                                $nueva = "O";
                            if( (($valor >= 217) && ($valor <= 220)) || (($valor >= 249) && ($valor <= 252))) 
                                $nueva = "U";
                        }
                        if (array_search($nueva, $array_letras) === false)
                            array_push($array_letras, $nueva);
                                                  
                }
                return array($array_todas, $array_letras);   
            }else
                return 0;   
        }
        /**
        * Funcion que muestra un formulario prepardo para introducir datos a partir de los que buscar pacientes
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraBuscar ($params, $file)
        {
            $this->cargaSelectores ();
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que busca pacientes a partir de los datos introducidos por el usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function buscar ($params, $file)
        {
            if(array_key_exists("pag", $params->getParams())){
                $pag = (int)$params->getParam('pag');
                $this->datos = $_SESSION[busqueda];
                $this->datos[pag] = $pag;
                $this->smarty->assign('pag', $pag); 
            }else{
                $this->datos = $this->recibirFormulario ($params); 
                $referido = $params->getParam('referido');
                //Si se activó la casilla, se buscarán pacientes donde el campo
                //sea not null
                $referido = $referido === "on" ? "IS NOT NULL" : "";
                //Si se seleccionó dr_referidor, se usa este valor, sino, el genérico obtenido antes.
                $this->datos[id_dr_referidor] = (int)$this->datos[id_dr_referidor] > 0
                    ? (int)$this->datos[id_dr_referidor] 
                        : $referido;
                //Si se seleccionó algun grupo de imagen, se almacena.
                if($params->getParam('selGrupo') != 0) {
                    $this->datos[grupoImgs] = $params->getParam('selGrupo');
                }
                        
                $this->datos [id_usuario] = $_SESSION[id_usr];
                $this->datos [fecha_alta] = $params->getParam('txtFechaAlta');
                $_SESSION[busqueda] = $this->datos; 
                $this->datos[pag] = 0;
                $this->smarty->assign('pag', 0); 
            }
            
            $this->datos = $this->dao->buscar ($this->datos);
            if(is_array($this->datos))
            {
                $this->smarty->assign ('codigo', $this->datos[0]);
                $this->smarty->assign ('datos', $this->datos[1]);
                $this->smarty->assign ('numero', $this->datos[0]);
            }else
                $this->smarty->assign ('codigo', $this->datos);
             
            $this->smarty->display ($this->path.$file.".phtml");
            return;  
        }
    }
?>