<?php
    /**
    * Fichero que recoje la implementación de la clase Visita
    * 
    * @package Negocio
    * @subpackage Visitas
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (11 - Enero - 2008)
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la lógica de presentación de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo VisitaDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/visitas/VisitaDAO.inc";
    /**
    * Inclusion del archivo LineaVisitaDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/visitas/LineaVisitaDAO.inc";
    /**
    * Inclusion del archivo PacienteDAO para tener acceso a los datos de los pacientes
    */
    include_once PATH_BASE."src/gbdapp/pacientes/PacienteDAO.inc";
    /**
    * Inclusion del archivo ServicioDAO para tener acceso a los datos de los servicios
    */
    include_once PATH_BASE."src/gbdapp/conf/ServicioDAO.inc";
    /**
    * Inclusion del archivo PersonalDAO para tener acceso a los datos de los empleados
    */
    include_once PATH_BASE."src/gbdapp/personal/PersonalDAO.inc";
    /**
    * Inclusion del archivo DresoDAO para tener acceso a los datos de los doctores ajenos
    */
    include_once PATH_BASE."src/gbdapp/dres/DresDAO.inc";
    /**
    * Inclusion del archivo AsistenteDAO para tener acceso a los datos de los empleados que asisten una visita
    */
    include_once PATH_BASE."src/gbdapp/asistencia/AsistenteDAO.inc";
    /**
    * Inclusion del archivo ColaboradorDAO para tener acceso a los datos de los doctores ajenos que asisten una visita
    */
    include_once PATH_BASE."src/gbdapp/asistencia/ColaboradorDAO.inc";
    /**
    * Inclusion del archivo PagoPacDAO para tener acceso a los datos de los pagos de los pacientes
    */
    include_once PATH_BASE."src/gbdapp/pacientes/PagoPacDAO.inc";
    /**
    * Inclusion del archivo TipoRecetaDAO para tener acceso a los datos de las recetas
    */
    include_once PATH_BASE."src/gbdapp/conf/TipoRecetaDAO.inc";
    /**
    * Inclusion del archivo RecetaDAO para tener acceso a los datos de las recetas
    */
    include_once PATH_BASE."src/gbdapp/recetas/RecetaDAO.inc";
    /**
    * Inclusion del archivo Logger
    */
    include_once PATH_BASE."src/gbdapp/log/Logger.inc";
    
    
    /**
    * Clase Visita. Implementa toda la lógica de manejo de datos y peticiones para el objeto Visita médica
    * @package Negocio
    * @subpackage Visitas
    */
    class Visita extends DisplayManager
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
        * Almacenará la dirección de la carpeta donde estan las imagenes del paciente
        * @var string
        */ 
        private $carpeta;
        /**
        * Almacenará el identificador del paciente con que se está trabajando
        * @var int
        */
        private $id;
        /**
        * Almacenará la referencia a su objeto Logger
        */
        private $logger;
        
        /**
        * Almacena el nombre del paciente
        */
        private $nombre;
        
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @param int Identificador del paciente sobre el que se esta trabajando
        * @return void
        */
        function Visita ($lang, $id)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/visitas/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 3);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            $this->dao = new VisitaDAO();
            $this->id = $id; 
            $this->carpeta = PATH_BASE."imagenes/".$_SESSION[id_usr]."/id$id";
            $this->logger = new Logger($lang);
            $this->nombre = $this->cargaPaciente ($id); 
            return; 
        } 
        /**
        * Funcion que muestra un listado con todas las visitas que pertenecen a un paciente de forma ordenada
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void  
        */
        function listado ($params, $file)
        {  
            $pag = $params->getParam('pag');

            if(!isset($pag))
                $pag = 0;
            
            $this->datos = $this->dao->listado ($this->id, $pag);
            if(is_array($this->datos))
            {
                $numero = $this->datos[0];
                $this->datos = $this->datos[1];
                foreach ($this->datos as $indice => $valor)
                {
                	if (!$this->datos[$indice][fsa] == 1){
                        $this->datos[$indice][tratamiento] = $this->verLineas ($this->datos[$indice][id_visita]);
                        $this->datos[$indice][recetas] = $this->verRecetas ($this->datos[$indice][id_visita]);
                	} 
                }
            }    
            $this->smarty->assign ('datos', $this->datos);
            $this->smarty->assign ('pag', $pag);
            $this->smarty->assign ('numero', $numero);

            $this->smarty->display ($this->path.$file.".phtml");
            return; 
        }
        /**
        * Funcion que recoje todas las recetas prestadas en una visita y devuelve un array con sus nombres
        * @param int Id de la visita
        * @return string
        */
        function verRecetas ($id)
        {
            $dao = new RecetaDAO ();
            $tipodao = new TipoRecetaDAO ();
            $datos = $dao->listado ($id);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach ($datos as $indice => $valor)
                {
                    $temp = $tipodao->ver ($datos[$indice][id_tipo_receta]);
                    $datos[$indice][nombre] = $temp[0][nombre];   
                }
            } 
            return $datos;  
        }
        /**
        * Funcion que recoje todos los servicios prestados en cada visita y devuelve un array con sus nombres
        * @param int Id de la visita
        * @return array
        */
        function verLineas ($id)
        {
            $aux = new LineaVisitaDAO ();
            $lineas = $aux->ver ($id);
            if(is_array($lineas))
            {
                foreach ($lineas as $indice => $valor)
                {
                    if(!$lineas[$indice][total])
                        $lineas[$indice][total] = 0;    
                    $lineas[$indice][unitario] = $lineas[$indice][total] / $lineas[$indice][cantidad];
                }
            }
            return $lineas;   
        }
        /**
        * Funcion que recoje y carga la informacion del paciente que se mostrará en la cabecera
        * @param int Id del usuario del que se quiere tomar la extension de la foto
        * @return void
        */
        function cargaPaciente ($id)
        {
            $aux = new PacienteDAO;
            $datos = $aux->ver ($id);
            $this->smarty->assign ('paciente', $datos);
            return $datos[apellido]." ".$datos[apellido2].", ".$datos[nombre];      
        }
        /**
        * Funcion que muestra un formulario para rellenar con los datos de la nueva visita
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
        * Funcion que añade una linea al tratamiento de la visita y sigue con la su creacion
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function nuevaLinea ($params, $file)
        {
            $this->datos[id_servicio] = $params->getParam ('selServicio');
            $this->datos[cantidad] = $params->getParam ('txtCuantos');
            $this->datos[unitario] = $params->getParam ('txtUnitario');
            $temp = $this->verTratamiento ("todo", $this->datos[id_servicio]);
            $this->datos[total] = $this->datos[unitario] * $this->datos[cantidad];
            $this->datos[servicio] = $temp[nombre];
            if(!isset($_SESSION['lv'.$this->id]))
                $_SESSION['lv'.$this->id] = array();
            array_push($_SESSION['lv'.$this->id], $this->datos);
            $this->smarty->assign ('lineas', $_SESSION['lv'.$this->id]);
            
            $aux = $this->recibirFormulario ($params);
            $aux[pers] = $params->getParam ('selPers');
            $aux[col] = $params->getParam ('selDres');
            $id = $params->getParam('vis');
            if($id)
                $aux[id_visita] = $id;
            $this->smarty->assign ('datos', $aux);
            
            if($file == 'nuevalineamv')
                $this->muestraFormulario ($params, "modvisita");
            else
                $this->muestraFormulario ($params, "abrirvisita");  
                
            return;    
        }
        /**
        * Funcion que quita la linea seleccionada de la visita que se esta creando
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function borraLinea ($params, $file)
        {
            $temp = array();
            $num = $params->getParam ('num');
            for ($i = 0; $i<count($_SESSION['lv'.$this->id]); $i++) 
            {
                if($i == $num)
                    continue;
                array_push ($temp, $_SESSION['lv'.$this->id][$i]);   
            }
            $_SESSION['lv'.$this->id] = $temp;
            $this->smarty->assign ('lineas', $_SESSION['lv'.$this->id]);
            
            $aux = $this->recibirFormulario ($params);
            $aux[pers] = $params->getParam ('selPers');
            $aux[col] = $params->getParam ('selDres');
            $id = $params->getParam('vis');
            if($id)
                $aux[id_visita] = $id;
            $this->smarty->assign ('datos', $aux);
            
            if($file == 'borralineamv')
                $this->muestraFormulario ($params, "modvisita");
            else
                $this->muestraFormulario ($params, "abrirvisita");

            return;
        }
        /**
        * Funcion que carga los selectores para empleados, doctores ajenos y tratamientos
        * @return void
        */
        function cargaSelectores ()
        {
            $datos = array();
            
            $dao = new DresDAO ();
            $datos = $dao->listado(0);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach($datos as $linea)
                    $dres[$linea[id_dr_externo]] = $linea[apellido]." ".$linea[apellido2].", ".$linea[nombre];
                $this->smarty->assign ('dres', $dres);      
            }
            
            $dao = new ServicioDAO ();
            $datos = $dao->listado(0);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach($datos as $linea)
                    $servicios[$linea[id_servicio]] = $linea[nombre]." --- ".$linea[precio_unitario]."€ ";
                $this->smarty->assign ('servicios', $servicios);      
            }
            
            $dao = new PersonalDAO ();
            $datos = $dao->listado(0);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach($datos as $linea)
                    $pers[$linea[id_personal]] = $linea[apellido]." ".$linea[apellido2].", ".$linea[nombre];
                $this->smarty->assign ('pers', $pers);      
            }
            return;
                  
        }
        /**
         * Funcion que añade una nueva visita a la base de datos como falta sin aviso.
         *
         * @param resource Objeto params para acceder a los parametros de la peticion
         * @param string Cadena que determina el template a mostrar
         * @return void
         */
        function fsa ($params, $file) {
            $this->datos[id_paciente] = $this->id;
            $this->datos[asiento] = $params->getParam ('txtAsiento');
            $this->datos[fsa] = 1;
            $this->datos[fecha] = Date::getDate();
            $this->datos[id_usuario] = $_SESSION[id_usr];
            
            Utils::log_info("Starting new visita register for paciente".$this->id);
            $this->datos = $this->dao->fsa ($this->datos);
            $this->smarty->assign ('codigo', $this->datos);
            if($this->datos < 1) {
                Utils::log_error("An error ocurred!!Rolling back...");
            }
            $file = "nuevavisita";
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        
        /**
        * Funcion que añade una nueva visita a la base de datos a partir de los datos recibidos
        * 
        * Esta funcion guarda los registros correspondientes a la asistencia y colaboracion de la visita
        * así como los servicios prestados.
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function nueva ($params, $file)
        {
            $this->datos = $this->recibirFormulario($params);
            $this->datos[id_paciente] = $this->id;
            $this->datos[id_usuario] = $_SESSION[id_usr];
            $this->datos[fecha] = Date::getDate();
            
            Utils::log_info("Starting new visita register for paciente".$this->id);
            $this->dao->start ();
            $this->datos = $this->dao->nuevo ($this->datos);
            $this->smarty->assign ('codigo', $this->datos);
            if($this->datos < 1)
            {
            	Utils::log_error("An error ocurred!!Rolling back...");
            	$this->dao->rollback();
            } else {
            	Utils::log_info("Storing now the lines of the visita");
	            $ret = $this->guardaServicios ($params, $this->datos);
	            if ($ret)
	            {
	            	Utils::log_info("Visita's lines stored successfully");
	            	Utils::log_info("Storing now visita's assistance");
	                $ret1 = $this->guardaAsistencia ($params, $this->datos);
	                if($ret1)
	                {
	                	Utils::log_info("Visita's assistance stored successfully");
	                	Utils::log_info("Storing now visita's collaborations");
	                    $ret2 = $this->guardaColaboracion ($params, $this->datos);
	                    if ($ret2){
	                    	Utils::log_info("Visita's collaboration stored successfully");
	                        $this->logger->save(LOG_ALTA, "Visita de: ".$this->nombre);
	                        $this->dao->commit ();
	                        Utils::log_info("Visita stored successfully");
	                    } else {
	                    	Utils::log_error("An error ocurred storing visita's collaboration!!Rolling back...");
	                        $this->smarty->assign ('codigo', -1);
	                        $this->dao->rollback ();  
	                    }
	                } else {
	                	Utils::log_error("An error ocurred storing visita's assistance!!Rolling back...");
	                    $this->smarty->assign ('codigo', -1);
	                    $this->dao->rollback (); 
	                }
	            } else {
	            	Utils::log_error("An error ocurred storing visita's service lines!!Rolling back...");
	                $this->smarty->assign ('codigo', -1);
	                $this->dao->rollback (); 
	            }
            }
            
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        /**
        * Funcion que recoje todos los datos enviados por el usuario a traves del formulario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @return array
        */
        function recibirFormulario ($params)
        {
            $datos = array();
            $datos[asiento] = $params->getParam ('txtAsiento');
            $datos[motivo] = $params->getParam ('txtMotivo');
            $datos[diagnostico] = $params->getParam ('txtDiag');
            $datos[observaciones] = $params->getParam ('txtObservaciones');       
            $datos[precio] = $params->getParam ('txtPrecio');
            
            return $datos;   
        }
        /**
        * Funcion que guarda los servicios que se prestaron en la visita
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param int Identificador que ha recibido la nueva visita
        * @return bool
        */
        function guardaServicios ($params, $id)
        {
            $ldao = new LineaVisitaDAO ();
            Utils::log_debug("Starting register of ".count($_SESSION['lv'.$this->id])." service lines for visita: $id");
            Utils::log_debug("Storing this lines: ".Utils::print_array($_SESSION['lv'.$this->id]));
            foreach ($_SESSION['lv'.$this->id] as $linea)
            {
                $linea[id_visita] = $id;
                $linea[id_usuario] = $_SESSION[id_usr];
              
                $aux = $ldao->nuevo ($linea); 
                if($aux < 1) {
                	Utils::log_error("An error ocurred storing the line!!Returning error");
                    return false;
                } else {
                	Utils::log_debug("Service line stored successfully with id: $aux");
                }
            }
            $_SESSION['lv'.$this->id] = null;
            return true;  
        }
        
        /**
        * Funcion que guarda la asistencia de la visita
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param int Identificador que ha recibido la nueva visita
        * @return bool
        */
        function guardaAsistencia ($params, $id)
        {
            $aux = new AsistenteDAO ();
            $datos = $params->getParam ('selPers');
            Utils::log_debug("Starting register of ".count($datos)." assistance items for visita: $id");
            Utils::log_debug("Storing this lines: ".Utils::print_array($datos));
            if (isset($datos))
            {
                foreach ($datos as $empleado)
                {
                    $temp = array ("id_visita_medica" => $id, "id_personal" => $empleado, "id_usuario" => $_SESSION[id_usr]);
                    $ret = $aux->nuevo ($temp);
                    if ($ret < 1) {
                    	Utils::log_error("An error ocurred storing the assistance item!!Returning error");
                        return false;
                    } else {
                    	Utils::log_debug("Assistance item stored successfully with id: $ret");    
                    }
                }   
                return true;
            } else {
            	Utils::log_warning("No assistance was defined for visita: $id");
                return true;
            }   
        }
        /**
        * Funcion que guarda la colaboracion de la visita
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param int Identificador que ha recibido la nueva visita
        * @return bool
        */
        function guardaColaboracion ($params, $id)
        {
            $aux = new ColaboradorDAO ();
            $datos = $params->getParam ('selDres');
            Utils::log_debug("Starting register of ".count($datos)." collaboration items for visita: $id");
            Utils::log_debug("Storing this lines: ".Utils::print_array($datos));
            $idusr = $_SESSION[id_usr];
            if (isset($datos))
            {
                foreach ($datos as $doctor)
                {
                    $temp = array ("id_visita_medica" => $id, "id_dr_colaborador" => $doctor, "id_usuario" => $idusr);
                    $ret = $aux->nuevo ($temp);
                    if ($ret < 1) {
                    	Utils::log_error("An error ocurred storing the collaboration item!!Returning error");
                        return false;
                    } else {
                    	Utils::log_debug("Collaboration item stored successfully with id: $aux");       
                    }
                }   
                return true;
            } else {
            	Utils::log_debug("No collaboration was set for visita: $id");
                return true;
            }   
        }
        /**
        * Funcion que muestra todos los detalles de la visita medica
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function ver ($params, $file)
        {
            $id = $params->getParam ('vis');
            $this->datos = array("id_paciente" => $this->id, "id_visita" => $id);
            $this->datos = $this->dao->ver ($this->datos);
            if (is_array ($this->datos))
            {
                $this->datos[0][asistentes] = $this->verAsistencia ($id);
                $this->datos[0][colaboradores] = $this->verColaboracion ($id);
                $this->smarty->assign ('datos', $this->datos[0]); 
                $this->datos = $this->verLineas ($id);
                $this->smarty->assign ('lineas', $this->datos);
            }
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que busca y carga los datos de los empleados que asistieron la visita
        * @param int Identificador de la visita que queremos consultar
        * @return array
        */
        function verAsistencia ($id)
        {
            $aux = new AsistenteDAO ();
            $datos = $aux->ver ($id);
            if(is_array($datos))
            {
                $aux = new PersonalDAO();
                foreach ($datos as $indice => $valor)
                {
                    $temp = $aux->ver ($valor);
                    $temp = $temp[0];
                    $cadena = $temp[apellido]." ".$temp[apellido2].", ".$temp[nombre];
                    $datos[$indice] = array("id_personal" => $valor, "nombre" => $cadena);
                }
            }   
            return $datos;   
        }
        /**
        * Funcion que busca y carga los datos de los doctores ajenos que colaboraron en la visita
        * @param int Identificador de la visita que queremos consultar
        * @return array
        */
        function verColaboracion ($id)
        {
            $aux = new ColaboradorDAO ();
            $datos = $aux->ver ($id);
            if(is_array($datos))
            {
                $aux = new DresDAO();
                foreach ($datos as $indice => $valor)
                {
                    $temp = $aux->ver ($valor);
                    $temp = $temp[1][0];
                    $cadena = $temp[apellido]." ".$temp[apellido2].", ".$temp[nombre];
                    $datos[$indice] = array("id_dr" => $valor, "nombre" => $cadena);
                }
            } 
            return $datos;   
        }
        /**
        * Funcion que busca y carga los datos del tratamiento que se ha dado en la visita
        * @param string Caracteristica que queremos ver
        * @param int Id del tratamiento
        * @return array
        */
        function verTratamiento ($motivo, $id)
        {
            $aux = new ServicioDAO ();
            $datos = $aux->ver ($id);
            if(is_array($datos))
            {
                $cadena = $datos[0][nombre];
                $precio = $datos[0][precio_unitario];
            }
            switch ($motivo)
            {
                case "nombre":
                    return $cadena;
                    break;
                case "precio":
                    return $precio;
                    break;
                case "todo":
                    return array("nombre" => $cadena, "precio" => $precio);
                    break;   
            }   
        }
        /**
        * Funcion que muestra los datos de la visita en formato editable para modificarlos
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraEditar ($params, $file)
        {
            $this->cargaSelectores ();
            $id = $params->getParam ('vis');
            $this->datos = array("id_paciente" => $this->id, "id_visita" => $id);
            $this->datos = $this->dao->ver ($this->datos);
            $this->datos[0][pers] = $this->cargaAsistencia ($id);
            $this->datos[0][col] = $this->cargaColaboracion ($id);
            $this->smarty->assign ('datos', $this->datos[0]); 
            $this->datos = $this->verLineas ($id);
            if(is_array($this->datos)){
                $_SESSION['lv'.$this->id] = array();
                $_SESSION['lv'.$this->id] = $this->datos;
            }
            $this->smarty->assign ('lineas', $this->datos);

            $this->smarty->display ($this->path.$file.".phtml");
            return;      
        }
        /**
        * Funcion que carga los datos de la asistencia para modificacion de la visita
        * @param int Id de la visita
        * @return array
        */
        function cargaAsistencia ($id) 
        {
            $ret = array();
            $dao = new AsistenteDAO ();
            $datos = $dao->ver ($id);
            if(is_array($datos))   
            {
                foreach ($datos as $indice => $valor)
                    array_push ($ret, $valor);       
            }
            return $ret;
        }
        /**
        * Funcion que carga los datos de la colaboracion para modificacion de la visita
        * @param int Id de la visita
        * @return array
        */
        function cargaColaboracion ($id) 
        {
            $ret = array();
            $dao = new ColaboradorDAO ();
            $datos = $dao->ver ($id);
            if(is_array($datos))   
            {
                foreach ($datos as $indice => $valor)
                    array_push ($ret, $valor);       
            }
            return $ret;
        }
        /**
        * Funcion que actualiza los datos de la visita seleccionada a partir de los nuevos introducidos por el usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function actualizar ($params, $file)
        {
            $id = $params->getParam ('vis');    
            $this->datos = $this->recibirFormulario ($params);
            $this->datos[id_visita] = $id;
            $this->datos[id_paciente] = $this->id;
            
            Utils::log_info("Starting visita $id modification");
            $this->dao->start (); 
           
            $ret = $this->actualizaDatos ($params, $id);
            if ($ret)
            {
            	Utils::log_info("Visita components modified successfully");
            	Utils::log_info("Modifying now visita's data");
                $this->datos = $this->dao->modificar ($this->datos);
                if($this->datos >= 0){
                    $this->logger->save(LOG_MODIFICACION, "Visita de: ".$this->nombre);
                    $this->dao->commit ();
                    Utils::log_info("Visita data modified successfully");
                    $this->smarty->assign ('codigo', $id);
                }else {
                	Utils::log_error("An error ocurred updating visita's data!!Rolling back...");
                    $this->dao->rollback ();
                    $this->smarty->assign ('codigo', $this->datos);
                }
            } else {
            	Utils::log_error("An error ocurred updating visita's components!!Rolling back...");
                $this->dao->rollback ();
            }
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que se encarga de actualizar todos los datos referentes a lineas de visita, asistencia y colaboracion de la visita recién modificada
        * 
        * Primero borra todos los datos de la visita referentes a Asistencia, colaboración y líneas de visita, 
        * posteriormente, mediante el uso de las funciones de clase implementadas para ello, los vuelve a guadar.
        * @param resource Objeto params para acceder a los parámetros de la petición
        * @param int Id de la visita
        * @return bool
        */
        function actualizaDatos ($params, $id)
        {
            $dao = new AsistenteDAO ();
            Utils::log_info("Deleting previous assistance");
            $ret = $dao->borrar ($id);
            Utils::log_debug("Deleted $ret assistance lines");
            if ($ret >= 0)
            {
            	Utils::log_debug("Inserting new assistance lines");
                $ret1 = $this->guardaAsistencia ($params, $id);
                if (!$ret1){
                    return false;
                }
            }
            
            $dao = new ColaboradorDAO ();
            Utils::log_info("Deleting previous assistance");
            $ret = $dao->borrar ($id);
            Utils::log_debug("Deleted $ret collaboration lines");
            if ($ret >= 0)
            { 
            	Utils::log_debug("Inserting new collaboration lines");
                $ret1 = $this->guardaColaboracion ($params, $id);
                if (!$ret1) {
                    return false;
                }
            }
            
            $dao = new LineaVisitaDAO ();
            Utils::log_info("Deleting previous service's lines");
            $ret = $dao->borrar ($id);
            Utils::log_debug("Deleted $ret service's' lines");
            if ($ret >= 0)
            { 
            	Utils::log_debug("Inserting new service's lines");
                $ret1 = $this->guardaServicios ($params, $id);
                if (!$ret1){
                    return false;
                }
            }
            return true;     
        }
        /**
        * Funcion que borra los datos de la visita
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function borrar ($params, $file)
        {
            $id = $params->getParam ('vis');
            Utils::log_info("Starting visita $id deletion");
            $this->dao->start ();
            $this->datos = $this->dao->borrar ($id);
            if ($this->datos < 1) {
            	Utils::log_error("An error ocurred deleting the visita!!Rolling back...");
                $this->dao->rollback ();
            } else {
                $this->logger->save(LOG_BAJA, "Visita de: ".$this->nombre);
                $this->dao->commit ();
                Utils::log_info("Visita $id deleted successfully");
            }
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");   
        }
        /**
        * Funcion que muestra un listado de visitas y pagos formando un historial económico
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function listadoEcon ($params, $file)
        {
            $numero = 0;
            //Si viene fecha se usa, sino, se pone ultimo indicando que se quieren ver los ultimos movimientos.
            $paramFecha = $params->getParam ('fecha');
            if (isset($paramFecha)) {
                $fecha = $paramFecha;
                $orden = $params->getParam('order');
            } else {
                /*
                * La primera consulta (el parametro fecha no existe) se realiza sobre los ultimos movimientos
                * en sentido descendente.
                */
                $fecha = "ultimo";
                $orden = "d";
            }
            
            $this->datos = $this->dao->historial ($this->id, $fecha, $orden);
            if(is_array($this->datos[0]))
            {
                $saldo = $this->datos[1];

                $this->datos = $this->datos[0];
                $numero = $this->datos[0];
                $this->datos = array_reverse($this->datos[1]);

                $fechas[primera] = $this->datos[0][fecha];
                foreach ($this->datos as $indice => $valor)
                {
                    if($this->datos[$indice][id_visita])
                        $this->datos[$indice][tratamiento] = $this->verLineas ($this->datos[$indice][id_visita]);
                }
                $fechas[ultima] = $this->datos[$indice][fecha];

            }
            $fechas[curr] = $fecha;
            $this->smarty->assign ('saldoAnt', $saldo);
            $this->smarty->assign ('order', $orden);
            $this->smarty->assign ('fechas', $fechas);
            $this->smarty->assign ('numero', $numero);    
            $this->smarty->assign ('datos', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;  
        }
    }
?>
