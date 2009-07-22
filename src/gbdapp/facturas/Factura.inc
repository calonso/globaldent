<?php
    /**
    * Fichero que recoje la implementación de la clase Factura
    * 
    * @package Negocio
    * @subpackage Facturas
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (22 - Enero - 2008)
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la lógica de presentación de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo FacturaDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/facturas/FacturaDAO.inc";
    /**
    * Inclusion del archivo LineaFacturaDAO para tener acceso a los datos de cada línea de presupuesto
    */
    include_once PATH_BASE."src/gbdapp/facturas/LineaFacturaDAO.inc";
    /**
    * Inclusion del archivo PacienteDAO para tener acceso a los datos de los pacientes
    */
    include_once PATH_BASE."src/gbdapp/pacientes/PacienteDAO.inc";
    /**
    * Inclusion del archivo OpcionesDAO para tener acceso a los datos de la clínica
    */
    include_once PATH_BASE."src/gbdapp/conf/OpcionesDAO.inc";
    /**
    * Inclusion del archivo Logger
    */
    include_once PATH_BASE."src/gbdapp/log/Logger.inc";
    
    /**
    * Clase Factura. Implementa toda la lógica de manejo de datos y peticiones para el objeto Factura
    * @package Negocio
    * @subpackage Facturas
    */
    class Factura extends DisplayManager
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
        * Almacenará la referencia al objeto logger
        */
        private $logger;
        /**
        * Almacenará el nombre del paciente
        */
        private $nombre;
        
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @param int Identificador del paciente sobre el que se esta trabajando
        * @return void
        */
        function Factura ($lang, $id)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/facturas/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 3);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            $this->dao = new FacturaDAO();
            $this->id = $id; 
            $this->carpeta = PATH_BASE."imagenes/".$_SESSION[id_usr]."/id$id";
            $this->nombre = $this->cargaPaciente ($id);
            $this->nombre = "Factura de: ".$this->nombre;
            $this->cargaClinica (); 
            $this->logger = new Logger($lang);
            
            return; 
        }
        /**
        * Funcion que recoje y carga la informacion del paciente que se mostrará en la cabecera
        * @param int Id del usuario del que se quiere tomar la extension de la foto
        * @return void
        */
        function cargaPaciente ($id)
        {
            $aux = new PacienteDAO ();
            $datos = $aux->ver ($id); 
            $this->smarty->assign ('paciente', $datos);
            return $datos[apellido]." ".$datos[apellido2].", ".$datos[nombre];      
        }
        /**
        * Funcion que recoje y carga la información de la clínica que se mostrará en la cabecera
        * @return void
        */ 
        function cargaClinica ()
        {
            $aux = new OpcionesDAO ();
            $datos = $aux->ver (0);
            $this->smarty->assign ('clinica', $datos[0]);
            return;     
        }
        /**
        * Funcion que muestra un listado con todas las facturas del paciente
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function listado ($params, $file)
        {
            $this->datos = $this->dao->listado ($this->id);
            $this->smarty->assign ('datos', $this->datos[1]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que muestra un formulario para crear una nueva factura
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function muestraFormulario ($params, $file)
        {
            $this->cargaSelector();  
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        /**
        * Funcion que recoje y carga el listado de servicios para el selector
        * @return void
        */
        function cargaSelector()
        {
            $dao = new ServicioDAO ();
            $datos = $dao->listado(0);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach($datos as $linea)
                    $servicios[$linea[id_servicio]] = $linea[nombre]." --- ".$linea[precio_unitario]."€";
                $this->smarty->assign ('servicios', $servicios);      
            }  
            return; 
        }
        /**
        * Funcion que recoje los datos de la nueva linea y sigue con la creacion de la factura
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function nuevaLinea ($params, $file)
        {
            $this->datos[id_servicio] = $params->getParam ('selServicio');
            $this->datos[cantidad] = $params->getParam ('txtCuantos');
            $this->datos[unitario] = $params->getParam ('txtUnitario');
            $temp = $this->verServicio ($this->datos[id_servicio]);
            $this->datos[total] = $this->datos[unitario] * $this->datos[cantidad];
            $this->datos[servicio] = $temp[nombre];
            if(!isset($_SESSION['lf'.$this->id]))
                $_SESSION['lf'.$this->id] = array();
            array_push($_SESSION['lf'.$this->id], $this->datos);
            $this->smarty->assign ('datos', $_SESSION['lf'.$this->id]);
            
            $this->datos = $this->recibirFormulario ($params);
        	$id = $params->getParam ('fact');
            if($id)
            {
                $this->datos[id_factura] = $id;
            }
            $this->smarty->assign ('fact', $this->datos);
            
           	if($file == 'nuevalineamf')
                $this->muestraFormulario ($params, "modfact");
            else
                $this->muestraFormulario ($params, "nuevafact");  
            return;
        }
        /**
        * Funcion que busca y devuelve las propiedades del servicio solicitado
        * @param int Id del servicio
        * @return array
        */
        function verServicio ($id)
        {
            $datos = array();
            $aux = new ServicioDAO();
            $datos = $aux->ver ($id);
            $devolver = array ("nombre" => $datos[0][nombre], "precio" => $datos[0][precio_unitario]);
            return $devolver;    
        }
        /**
        * Funcion que quita la linea seleccionada de la factura que se esta creando
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function borraLinea ($params, $file)
        {
            $temp = array();
            $num = $params->getParam ('num');
            for ($i = 0; $i<count($_SESSION['lf'.$this->id]); $i++) 
            {
                if($i == $num)
                    continue;
                array_push ($temp, $_SESSION['lf'.$this->id][$i]);   
            }
            $_SESSION['lf'.$this->id] = $temp;
            $this->smarty->assign ('datos', $_SESSION['lf'.$this->id]);
            
            $this->datos = $this->recibirFormulario ($params);
            $id = $params->getParam ('fact');
            if($id)
            {
                $this->datos[id_factura] = $id;
            }
            $this->smarty->assign ('fact', $this->datos);
            
            if($file == 'borralineamf')
                $this->muestraFormulario ($params, "modfact");
            else
                $this->muestraFormulario ($params, "nuevafact");
            return;
        }
        /**
        * Funcion que guarda los datos de la factyra y de las lineas de la misma recibidas
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function nueva ($params, $file)
        {
            $ldao = new LineaFacturaDAO();
            $this->datos = $this->recibirFormulario ($params);
             
            Utils::log_info("Starting new factura register.");
            $this->dao->start();
            $numero = $this->dao->bloquear(null);
            $this->datos[numero] = $numero[1][0][numero] + 1;
            Utils::log_debug("Number ".$this->datos[numero]." assigned to the new factura.");
            $this->datos = $this->dao->nuevo ($this->datos);
            if($this->datos > 0)
            {   
            	Utils::log_debug("Factura register stored successfully with id: ".$this->datos);
            	Utils::log_info("Starting register of ".count($_SESSION['lf'.$this->id])."lines for factura id: ".$this->datos);
            	$linesArray = Utils::print_array($_SESSION['lf'.$this->id]);
            	Utils::log_debug("Storing lines: $linesArray");
                foreach ($_SESSION['lf'.$this->id] as $linea)
                {
                    $linea[id_factura] = $this->datos;
                    $linea[id_usuario] = $_SESSION[id_usr]; 
                    $aux = $ldao->nuevo ($linea); 
                    if($aux < 1)
                    {
                    	Utils::log_error("An error ocurred storing the line!! Rolling back");
                        $this->smarty->assign ('codigo', $aux);
                        $this->dao->rollback ();
                        $this->smarty->display ($this->path.$file.".phtml");
                        return;
                    } else {
                    	Utils::log_info("New stored line was given id: $aux");
                    }
                }
                $this->logger->save (LOG_ALTA, $this->nombre);
                Utils::log_info("Factura and lines stored successfully");
                $this->dao->commit ();
            } else {
            	Utils::log_error("An error ocurred storing the new factura. ".$this->datos." code retrieved");
            	$this->dao->rollback();
            }
            $_SESSION['lf'.$this->id] = null;    
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return; 
        }
        /**
        * Funcion que recoje y devuelve todos los datos enviados por el usuario a traves del formulario
        * @param resource Objeto de la clase params para acceder a los parámetros de la peticion
        * @return array
        */
        function recibirFormulario ($params)
        {
            $datos = array();
            $datos[nombre_pagador] = $params->getParam('txtNombre');
            $datos[dni_pagador] = $params->getParam('txtDNI');
            $datos[total] = $params->getParam('txtTotal');
            $fecha = strftime("%d-%m-%Y");
            $aux = explode ("-", $fecha);
            $aux[0] = (int)$aux[0];
            $aux[1] = (int)$aux[1];
            $datos[fecha] = $aux[0]."-".$aux[1]."-".$aux[2];
            $datos[id_paciente] = $this->id;
            $datos[id_usuario] = $_SESSION[id_usr];
            
            return $datos;  
        }
        /**
        * Funcion que muestra una ficha con todos los detalles de la factura
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function ver ($params, $file)
        {
            $ldao = new LineaFacturaDAO();
            $id = $params->getParam('fact');
            $this->datos = $this->dao->ver (array("id_factura" => $id, "id_paciente" => $this->id));
            if(is_array($this->datos))
            {   
                $lineas = $ldao->ver ($id);
                $year = explode("-", $this->datos[0][fecha]);
	            $year = str_split($year[2], 2);
	            $this->datos[0][numero] .= "/".$year[1]; 
	            $this->smarty->assign ('datos', $this->datos[0]);
	            $this->smarty->assign ('lineas', $lineas);
            }  
            
            $imprimible = $params->getParam('imp');
            if($imprimible == 1)
                $file="imprimible";
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que borra todos los datos de la factura seleccionada
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function borrar ($params, $file)
        {
            $id = $params->getParam ('fact');
            Utils::log_info("Deleting factura with id: $id");
            $this->dao->start ();
            $this->datos = $this->dao->borrar (array("id_paciente" => $this->id, "id_factura" => $id));
            if($this->datos > 0){
                $this->logger->save (LOG_BAJA, $this->nombre);
                Utils::log_info("Successful deletion of factura with id: $id");
                $this->dao->commit ();
            }else {
            	Utils::log_error("An error ocurred deleting the factura!! Rolling back...");
                $this->dao->rollback ();
            }
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
            /**
        * Funcion que muestra todos los datos de la factura en formato editable
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function muestraEditar ($params, $file)
        {
            $this->cargaSelector();
            $ldao = new LineaFacturaDAO();
            $id = $params->getParam('fact');
            $this->datos = $this->dao->ver (array("id_factura" => $id, "id_paciente" => $this->id));
            if(is_array($this->datos))
            {   
                $lineas = $ldao->ver ($id);
                if(is_array($lineas))
                {
                    foreach($lineas as $indice => $valor)
                    {
                        $lineas[$indice][unitario] = $lineas[$indice][total] / $lineas[$indice][cantidad];
                    }
                    $_SESSION['lf'.$this->id] = array();
                    $_SESSION['lf'.$this->id] = $lineas;   
                }
            }
                
            $this->smarty->assign ('fact', $this->datos[0]);
            $this->smarty->assign ('datos', $lineas);
            
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
    	/**
        * Funcion que actualiza los datos de la factura en funcion de los nuevos introducidos por el usuario
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function actualizar ($params, $file)
        {
            $id = $params->getParam ('fact');
        
            $this->datos = $this->recibirFormulario ($params);
            
            $this->datos[id_factura] = $id;
            Utils::log_info("Updating data of factura with id: $id");
            $this->dao->start ();
            
            $ldao = new LineaFacturaDAO();
            $lborradas = $ldao->borrar ($id);
            Utils::log_debug("$lborradas lines deleted of the factura");
            Utils::log_info("Starting register of ".count($_SESSION['lf'.$this->id])."lines for factura id: ".$this->datos);
            Utils::log_debug("Inserting this lines: ".Utils::print_array($_SESSION['lf'.$this->id]));
            
            
            foreach ($_SESSION['lf'.$this->id] as $linea)
            {
                $linea[id_factura] = $id;
                $linea[id_usuario] = $_SESSION[id_usr]; 
                $aux = $ldao->nuevo ($linea); 
                if($aux < 1)
                {
                	Utils::log_error("An error ocurred storing the line!! Rolling back");
                    $this->dao->rollback ();
                    $this->smarty->assign ('codigo', 0);
                    $this->smarty->display ($this->path.$file.".phtml");
                    $_SESSION['lf'.$this->id] = null;
                    return; 
                } else {
                	Utils::log_info("New stored line was given id: $aux");
                }
            }
            
            Utils::log_info("Updating now factura register data");
            $this->datos = $this->dao->modificar ($this->datos);
            if($this->datos >= 0){
                $this->logger->save(LOG_MODIFICACION, $this->nombre);
                Utils::log_info("Factura data was updated successfully!");
                $this->dao->commit ();
                $this->smarty->assign ('codigo', $id);
            }else {
            	Utils::log_error("An error ocurred updating data!! Rolling back...");
                $this->dao->rollback ();
                $this->smarty->assign ('codigo', 0);
            }
            
            $_SESSION['lf'.$this->id] = null;
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
    }
?>
