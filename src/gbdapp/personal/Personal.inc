<?php
    /**
    * Fichero que recoje la implementacion de la clase personal.
    * 
    * @package Negocio
    * @subpackage Personal
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (10 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DisplayManager para tener acceso a la logica de presentacion de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del fichero PersonalDAO para tener acceso a la logica de almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/personal/PersonalDAO.inc";
    /**
    * Inclusion del fichero ProvinciaDAO para tener acceso a la lógica de acceso a datos para provincias
    */
    include_once PATH_BASE."src/provincias/ProvinciaDAO.inc";
    /**
    * Inclusion del fichero AsistenteDAO para tener acceso a la lógica de acceso a datos para su actividad
    */
    include_once PATH_BASE."src/gbdapp/asistencia/AsistenteDAO.inc";
    /**
    * Inclusion del fichero VisitaDAO para tener acceso a la lógica de acceso a datos para visitas medicas
    */
    include_once PATH_BASE."src/gbdapp/visitas/VisitaDAO.inc";
    /**
    * Inclusion del fichero LineaVisitaDAO para tener acceso a la lógica de acceso a datos para lineas de visita medica
    */
    include_once PATH_BASE."src/gbdapp/visitas/LineaVisitaDAO.inc";
    
    /**
    * Clase Personal. Implementa toda la logica de manejo de datos de personal por parte de los usuarios
    * @package Negocio
    * @subpackage Personal
    */
    class Personal extends DisplayManager
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
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @return void
        */
        function Personal ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/personal/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 5);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            $this->smarty->assign('puedoModificar', 0);
            
            $this->datos = array();
            $this->dao = new PersonalDAO();  
            $this->carpeta = PATH_BASE."imagenes/".$_SESSION[id_usr]."/";
            return; 
        }
        /**
        * Funcion que muestra la página principal de los empleados
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function index ($params, $file)
        {
            $id = $params->getParam('id');
            $this->smarty->assign('id', $id);
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
            $aux = new ProvinciaDAO();
            $datos = $aux->listado(0);
            if(is_array($datos))
            {
                foreach($datos as $linea)
                    $prov[$linea[id_provincia]] = $linea[provincia];
                $this->smarty->assign ('provincias', $prov);      
            }
            
            return;    
        }
        
        /**
        * Funcion que agrega un nuevo empleado a la base de datos a partir de los datos introducidos por el usuario
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
            
            Utils::log_info ( "Starting new personal register: " . $this->datos [apellido] . " " . $this->datos [apellido2] . ", " . $this->datos [nombre] );
            if(is_uploaded_file($_FILES[fileFoto][tmp_name])) 
            {    
            	Utils::log_info ( "Uploaded personal photo at: " . $_FILES [fileFoto] [tmp_name] );
                $extension = $_FILES[fileFoto][type];
                Utils::log_debug ( "Photo file type is: " . $extension );
                $aux = explode ("/",$extension);
	            if (! strncmp ( $aux [0], "image", 5 )) {
	                Utils::log_debug ( "Photo extension is: " . $aux [1] );
	            } else {
	                Utils::log_error ( "Uploaded file was not a phto!!" );
	                $this->smarty->display ( $this->path . $file . ".phtml" );
	                return;
	            }
                $this->datos[extension] = $extension;
            } 
            
            $this->datos = $this->dao->nuevo ($this->datos);
            
            $this->smarty->assign ('codigo', $this->datos);
            if($this->datos > 0)
            {
            	Utils::log_info ( "Personal stored successfully with id: ".$this->datos );
                mkdir ($this->carpeta."pers".$this->datos);
                Utils::log_debug ( "New directory created at: " . $this->carpeta."pers".$this->datos );
                if(is_uploaded_file($_FILES[fileFoto][tmp_name])) 
                {    
                	Utils::log_debug ( "Moving personal's photo to " . $this->carpeta."pers".$this->datos."/fotopers" );
                    move_uploaded_file ($_FILES[fileFoto][tmp_name], $this->carpeta."pers".$this->datos."/fotopers");
                }  
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
            $datos[direccion] = $params->getParam('txtDir'); 
            $datos[cp] = $params->getParam('txtCP');
            $datos[ciudad] = $params->getParam('txtCiudad');
            $datos[id_provincia] = $params->getParam('selProv');    
            $datos[telefono] = $params->getParam('txtTelfijo');
            $datos[movil] = $params->getParam('txtMovil');
            $datos[email] = $params->getParam('txtEmail');
            $datos[num_colegiado] = $params->getParam('txtNumcol');
            $datos[especialidad] = $params->getParam('txtEspecialidad');
            $datos[curriculum] = $params->getParam ('txtCV');
            $datos[login] = $params->getParam('txtLogin');
            $datos[password] = $params->getParam('txtPass');
            $privi = $params->getParam('RPrivilegios');
            
            if(isset($privi)){
                switch($privi)
                {
                    case "Empleado":
                        $datos[privilegios] = EMPLEADO;
                        break;
                    case "SubAdmin":
                        $datos[privilegios] = SUBADMIN;
                        break;
                    case "Admin" :
                        $datos[privilegios] = CLINICADMIN;
                        break;
                    default: 
                        $datos[privilegios] = EMPLEADO;
                        echo "Privilegios mal recibidos: $privi";
                }
            }
            
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
            $id = $params->getParam ('id');
            
            if ($_SESSION[privilegios] == CLINICADMIN || $_SESSION[id_pers] == $id)
                $this->smarty->assign ('puedoModificar', 1);
                
            $this->datos = $this->dao->ver ($id);
            if(is_array($this->datos))
            {
                $this->datos = $this->datos[0];
                $prov = new ProvinciaDAO();
                $nombre = $prov->ver ($this->datos[id_provincia]);
                $this->datos[provincia] = $nombre;
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
                $this->smarty->assign ('datos', $this->datos[0]);
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
            $this->datos[id_personal] = $params->getParam ('id');
            Utils::log_info ( "Starting personal " . $this->datos [id_personal] . " modification." );
            $this->dao->start();
            $ret = $this->dao->modificar ($this->datos);
            if ($ret == 1){
            	Utils::log_info ( "Personal data modification successfull" );
	            if(is_uploaded_file($_FILES[fileFoto][tmp_name])) 
	            {
	            	Utils::log_info ( "Uploaded new file to " . $_FILES [fileFoto] [tmp_name] );
	                $extension = $_FILES[fileFoto][type];
	                Utils::log_debug ( "New file type is: " . $extension );
	                $aux = explode ("/",$extension);
		            if (! strncmp ( $aux [0], "image", 5 )) {
	                    $this->datos [extension] = $aux [1];
	                    Utils::log_debug ( "New image extension is " . $aux [1] );
	                    unlink ($this->carpeta."pers".$this->datos[id_personal]."/fotopers");
                        move_uploaded_file ($_FILES[fileFoto][tmp_name], $this->carpeta."pers".$this->datos[id_personal]."/fotopers");
	                    Utils::log_info ( "Substituted photo at: " . $this->carpeta."pers".$this->datos[id_personal]."/fotopers" );
	                    $this->dao->commit();
	                } else {
	                    Utils::log_error ( "Uploaded file was not an image!!! Rolling back..." );
	                    $this->dao->rollback();
	                    $this->smarty->display ( $this->path . $file . ".phtml" );
	                    return;
	                }
	            } else {
			$this->dao->commit();
		    }
	            $this->smarty->assign ( 'codigo', $this->datos [id_personal] );
            } else {
            	Utils::log_error ( "An error ocurred updating data!! Rolling back..." );
                $this->dao->rollback();
            }
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
            $this->datos = $this->dao->borrar ($id);
            Utils::log_info("Deleting personal $id");
            if($this->datos == 1){
            	Utils::log_info("Personal deleted successfully, deleting associated files at: ".$this->carpeta."pers".$id);
                $this->borraDir ($this->carpeta."pers".$id);
            } else {
                Utils::log_error("An error ocurred deleting the paciente!!");
            }
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
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
                Utils::log_debug("Deleted folder: ".$carpeta);
            } else {
                unlink( $carpeta );
                Utils::log_debug("Deleted file: ".$carpeta);
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
            $letras = $this->getLetras ();
            if(isset($let))      
                $busqueda = array("id_usuario" => $_SESSION[id_usr], "letra" => $let);
            else
                $busqueda = array("id_usuario" => $_SESSION[id_usr], "letra" => $letras[1][0]);
                
            $this->datos = $this->dao->buscar ($busqueda);            
            if(is_array($this->datos))
            {
                $this->smarty->assign ('datos', $this->datos[1]);   
            }

            $this->smarty->assign ('letras', $letras[1]);
            $this->smarty->assign ('todas', $letras[0]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        /**
        * Funcion que determina las letras iniciales que pertenecen a algun apellido de entre los empleados almacenados
        * @return array Array compuesto por dos arrays, uno con todas las letras y otro con aquellas encontradas.
        */
        function getLetras ()
        {
            $array_todas = array("A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z");
            $array_letras = array();
            $resultados = $this->dao->buscar (1);
            if (is_array($resultados[1])) 
            {
                foreach ($resultados[1] as $linea)
                {  
                    foreach ($linea as $apellido)
                    {   
                        $encontrado = false;
                        $nueva = strtoupper($apellido[0]);
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
                        foreach ($array_letras as $letra)
                        {
                            if (!strcmp ($nueva, $letra))
                            {   
                                $encontrado = true;
                                break;
                            }
                        }
                        if(!$encontrado)
                            array_push($array_letras, $nueva); 
                    }  
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
            $this->datos = $this->recibirFormulario ($params);
            $this->datos [id_usuario] = $_SESSION[id_usr];
            $this->datos = $this->dao->buscar ($this->datos);
            if(is_array($this->datos))
            {
                $this->smarty->assign ('datos', $this->datos[1]);
            }
             
            $this->smarty->display ($this->path.$file.".phtml");
            return;  
        }
        /**
        * Funcion que muestra la actividad que el empleado ha tenido ordenada por meses
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function actividad ($params, $file)
        {
            $id = $params->getParam ('id');
            $aux = new AsistenteDAO ();
            $vis = new VisitaDAO ();

            $this->datos = $aux->listado ($id);
            if(is_array($this->datos))
            {
                foreach ($this->datos as $indice => $valor)
                {   
                    $temp = $vis->ver ((int)$valor);
                    $temp = $temp[0];
                    $fecha = explode ("-", $temp[fecha]);
                    $temp[mes] = $fecha[1]."-".$fecha[2];
                    $temp[tratamiento] = $this->verLineas ((int)$valor);
                    $this->datos[$indice] = $temp;
                }
            } 
            
            $this->smarty->assign ('id', $id); 
            $this->smarty->assign ('visitas', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return; 
        }
        /**
        * Funcion que recoje todas las lineas de visita asociadas a una visita médica en concreto
        * 
        * @param int Id de la visita
        * @return array 
        */
        function verLineas ($id)
        {
            $dao = new LineaVisitaDAO ();
            $serv = new ServicioDAO ();
            $datos = $dao->ver ($id);
            if(is_array($datos))
            {
                foreach ($datos as $indice => $valor)
                {
                    $temp = $serv->ver ($datos[$indice][id_servicio]);
                    $datos[$indice][servicio] = $temp[0][nombre];             
                }
                return $datos;
            }   
        }
        /**
        * Funcion que actualiza la contraseña del empleado
        * 
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function actualizaPass ($params, $file)
        {
            $id = $params->getParam('id');
            $this->datos = $this->dao->ver($id);
            if(is_array($this->datos))
            {
                $pass = $params->getParam('txtPass');
                $control = $params->getParam('txtAnt');
                $this->datos = $this->datos[0];
                if($this->datos[password] == $control || $_SESSION[privilegios] == CLINICADMIN){
                    
                    if($_SESSION[privilegios] == CLINICADMIN){
                        //Solo si es administrador podrá modificar los privilegios
                        $privi = $params->getParam('RPrivilegios');

                        switch($privi)
                        {
                            case "Empleado":
                                $privi = EMPLEADO;
                                break;
                            case "SubAdmin":
                                $privi = SUBADMIN;
                                break;
                            case "Admin" :
                                $privi = CLINICADMIN;
                                break;
                            default:
                                $privi = EMPLEADO;
                                echo "Privilegios mal recibidos: .$privi";    
                        }
                        $this->datos = $this->dao->modificar(array("id_personal" => $id, "password" => $pass, "privilegios" => $privi));       
                    }else {
                        $this->datos = $this->dao->modificar(array("id_personal" => $id, "password" => $pass));
                    }
                    $this->smarty->assign('codigo', $this->datos);
                }else
                    $this->smarty->assign('codigo', -2);
            } else {
                $this->smarty->assign ('codigo', -1); 
            } 
            
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
    }
?>