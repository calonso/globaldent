<?php
    /**
    * Fichero que recoje la implementacion de la clase doctor ajeno.
    * 
    * @package Negocio
    * @subpackage Doctores
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
    include_once PATH_BASE."src/gbdapp/dres/DresDAO.inc";
    /**
    * Inclusion del fichero ProvinciaDAO para tener acceso a la lógica de acceso a datos para las provincias
    */
    include_once PATH_BASE."src/provincias/ProvinciaDAO.inc";
    /**
    * Inclusion del fichero Logger para sacar log
    */
    include_once PATH_BASE."src/gbdapp/log/Logger.inc";
    
    
    /**
    * Clase Dres. Implementa toda la logica de manejo de datos de doctores ajenos por parte de los usuarios
    * @package Negocio
    * @subpackage Doctores
    */
    class Dres extends DisplayManager
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
        * Almacenará la referencia a su objeto Logger
        */
        private $logger;
        
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @return void
        */
        function Dres ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/dres/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 4);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            $this->dao = new DresDAO();
            $this->logger = new Logger($lang);  
            return; 
        }
        /**
        * Funcion que muestra la página principal de los doctores ajenos
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
        * Funcion que muestra el formulario a rellenar por el usuario para dar de alta un nuevo doctor ajeno
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraFormulario ($params, $file)
        {
            $aux = new ProvinciaDAO();
            $this->datos = $aux->listado(0);
            foreach ($this->datos as $linea)
                $provincias[$linea[id_provincia]] = $linea[provincia];
            $this->smarty->assign ('provincias', $provincias);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Función que añade un nuevo doctor externo a la base de datos
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function nuevo ($params, $file)
        {
            $this->datos = $this->recibirFormulario ($params);
            $this->datos[id_usuario] = $_SESSION[id_usr];
            Utils::log_info("Starting new doctor register with name: ".$this->datos[apellido]." ".$this->datos[apellido2].", ".$this->datos[nombre]);
            $ret = $this->dao->nuevo ($this->datos);
            if($ret > 0){
            	Utils::log_info("New doctor stored successfully with id: $ret");
                $this->logger->save (LOG_ALTA, "Dr. Refer: ".$this->datos[apellido]." ".$this->datos[apellido2].", ".$this->datos[nombre]);
            } else {
            	Utils::log_error("An error ocurred storing new doctor!! code returned: $ret");
            }
            $this->smarty->assign ('codigo', $ret);
            $this->smarty->display ($this->path.$file.".phtml");
            return;  
        }
        /**
        * Funcion que recoje y carga los datos recibidos del cliente a través del envío del formulario
        * @param resource Objeto params para acceder a los parámetros de la petición
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
            $datos[direccion] = $params->getParam('txtDir'); 
            $datos[cp] = $params->getParam('txtCP');
            $datos[ciudad] = $params->getParam('txtCiudad');
            $datos[id_provincia] = $params->getParam('selProv');    
            $datos[telefono_clinica] = $params->getParam('txtTelcli');
            $datos[telefono_movil] = $params->getParam('txtMovil');
            $datos[telefono_casa] = $params->getParam('txtTelcasa');
            $datos[fax] = $params->getParam('txtFax');
            $datos[email] = $params->getParam('txtEmail');
            $datos[especialidad] = $params->getParam('txtEspecialidad');
            
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
            $this->datos = $this->dao->ver ($id);
            if(is_array($this->datos))
            {
                $this->datos = $this->datos[1][0];
                $this->smarty->assign ('codigo', 1);
                $this->smarty->assign ('datos', $this->datos);
            }else
                $this->smarty->assign ('codigo', 0);
                
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que muestra un formulario prepardo para introducir datos a partir de los que buscar doctores
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraBuscar ($params, $file)
        {
            $aux = new ProvinciaDAO();
            $this->datos = $aux->listado(0);
            foreach ($this->datos as $linea)
                $provincias[$linea[id_provincia]] = $linea[provincia];
            $this->smarty->assign ('provincias', $provincias);
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que busca doctores a partir de los datos introducidos por el usuario
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
                $this->smarty->assign ('codigo', $this->datos[0]);
                $this->smarty->assign ('datos', $this->datos[1]);
            }else
                $this->smarty->assign ('codigo', $this->datos);
             
            $this->smarty->display ($this->path.$file.".phtml");
            return;  
        }
        /**
        * Funcion que muestra la ficha del doctor en formato editable para actualizar los datos
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
                $this->datos = $this->datos[1][0];
                $prov = new ProvinciaDAO();
                $aux = $prov->listado (0);
                foreach ($aux as $linea)
                    $provincias[$linea[id_provincia]] = $linea[provincia];
                           
                $this->smarty->assign ('codigo', 1);
                $this->smarty->assign ('provincias', $provincias);
                $this->smarty->assign ('datos', $this->datos);
            }else
                $this->smarty->assign ('codigo', 0);
                
            $this->smarty->display ($this->path.$file.".phtml");
            return;       
        }
        /**
        * Funcion que actualiza los datos del doctor a partir de los introducidos por el usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function actualizar ($params, $file)
        {
            $this->datos = $this->recibirFormulario ($params);
            $this->datos[id_usuario] = $_SESSION[id_usr];
            $this->datos[id_dr_externo] = $params->getParam ('id');
            Utils::log_info("Starting modification of doctor id: ".$this->datos[id_dr_externo]." : ".$this->datos[apellido]." ".$this->datos[apellido2].", ".$this->datos[nombre]);
            $ret = $this->dao->modificar ($this->datos);
            if ($ret > 0){
            	Utils::log_info("Successfully modification of doctor ".$this->datos[apellido]." ".$this->datos[apellido2].", ".$this->datos[nombre]);
                $this->logger->save (LOG_MODIFICACION, "Dr. Refer: ".$this->datos[apellido]." ".$this->datos[apellido2].", ".$this->datos[nombre]);
            } else {
            	Utils::log_error("An error ocurred modifying the doctor: ".$this->datos[apellido]." ".$this->datos[apellido2].", ".$this->datos[nombre]);
            }
            $this->smarty->assign ('codigo', $ret);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que borra todos los datos del doctor seleccionado de la base de datos
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function borrar ($params, $file)
        {
            $id = $params->getParam ('id');
            $nombre = $this->getNombre($id);
            Utils::log_info("Deleting doctor with id: $id: $nombre");
            $this->datos = $this->dao->borrar ($id);
            if ($this->datos != 1){
            	Utils::log_error("An error ocurred deleting the doctor!!");
            } else {
            	Utils::log_info("Successful deletion of doctor id: $id: $nombre");
                $this->logger->save (LOG_BAJA, "Dr. Refer: $nombre");
            } 
            
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
         /**
         * Funcion que retorna el nombre del doctor referidor
         * @param int Identificador del doctor
         * @return String Nombre y apellidos del doctor.
         */
        function getNombre ($id)
        {
            $datos = $this->dao->ver ($id);
            return $datos[apellido].", ".$datos[apellido2].", ".$datos[nombre];
        }
        /**
        * Funcion que muestra un listado ordenado por la inicial de cada apellido de todos los doctores almacenados
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
                $busqueda = array("id_usuario" => $_SESSION[id_usr], "letra" => $letras[0][0]);
                
            $this->datos = $this->dao->buscar ($busqueda);            
            if(is_array($this->datos))
            {
                $this->smarty->assign ('codigo', 1);
                $this->smarty->assign ('datos', $this->datos[1]);   
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
    }
?>