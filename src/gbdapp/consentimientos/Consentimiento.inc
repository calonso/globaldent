<?php
    /**
    * Archivo que recoje la implementacion de la clase Consentimiento
    * 
    * @package Negocio
    * @subpackage Consentimientos
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (23 - Enero - 2008) 
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la lógica de presentación de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo ConsentimientoDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/consentimientos/ConsentimientoDAO.inc";
    /**
    * Inclusion del archivo ConsentimientoRevocadoDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/consentimientos/ConsentimientoRevocadoDAO.inc";
    /**
    * Inclusion del archivo TipoConsDAO para tener acceso a la lógica de acceso a datos de tipos de consentimiento
    */
    include_once PATH_BASE."src/gbdapp/conf/TipoConsDAO.inc";
    /**
    * Inclusion del archivo PacienteDAO para tener acceso a los datos de los pacientes
    */
    include_once PATH_BASE."src/gbdapp/pacientes/PacienteDAO.inc";
    
    define ('FIRMADOS', 0);
    define ('REVOCADOS', 1);
    define ('SINFIRMA', 2);
    
    /**
    * Clase Consentimiento. Implementa toda la lógica de negocio para gestionar el firmado de consentimientos por parte del paciente
    * 
    * @package Negocio
    * @subpackage Consentimientos
    */
    class Consentimiento extends DisplayManager
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
        * Almacenará el identificador del paciente con que se está trabajando
        * @var int
        */
        private $id;
        /**
         * Almacenará la ruta a la carpeta donde se guardan las firmas del paciente
         * @var string
         */
        private $carpeta;
        
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @return void
        */
        function Consentimiento ($lang, $id)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/consentimientos/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 3);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            $this->dao = new ConsentimientoDAO();
            $this->id = $id; 
            $this->cargaPaciente ($id);
            $this->carpeta = PATH_BASE."imagenes/".$_SESSION[id_usr]."/id$id/";
            return;
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
            return;      
        } 
        /**
         * Funcion que muestra el consentimiento con los datos del paciente para que lo lea y firme
         * @param resource Objeto de la clase params para acceder a los parámetros de la petición
         * @param string Archivo que se ha solicitado
         */
        function muestraFormulario (Params $params, $file){
        	$id_cons = $params->getParam("cons");
        	$tipoDAO = new TipoConsDAO();
        	$this->datos = $tipoDAO->ver($id_cons);
        	$this->smarty->assign('datos', $this->datos[0]);
        	$this->smarty->display ($this->path.$file.".phtml");
        }
        /**
         * Funcion que muestra el consentimiento con los datos del paciente para que lo lea y firme su revocación
         * @param resource Objeto de la clase params para acceder a los parámetros de la petición
         * @param string Archivo que se ha solicitado
         */
        function muestraFormularioR (Params $params, $file){
        	$id_cons = $params->getParam("cons");
        	$this->datos = $this->dao->ver($id_cons);
        	$this->smarty->assign('datos', $this->datos[0]);
        	$this->smarty->display ($this->path.$file.".phtml");
        }
        /**
        * Funcion que muestra un listado con todos los consentimientos que el paciente tiene firmados y los que le quedan
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function listado ($params, $file)
        {     
            $this->datos = $this->dao->listado ($this->id);
            $firmados = array();
            $revocados = array();
            $sinfirma = array();
            if(is_array($this->datos))
            {
                foreach ($this->datos as $consent)
                {
                	switch($consent['cod']){
                		case FIRMADOS:
                			array_push($firmados, $consent);
                			break;
                		case REVOCADOS:
                			array_push($revocados, $consent);
                			break;
                		case SINFIRMA:
                			array_push($sinfirma, $consent);
                			break;
                	}
                }
            }
            if (count($firmados) > 0){
            	$this->smarty->assign ('firmados', $firmados);
            }
            if (count($sinfirma) > 0){
            	$this->smarty->assign ('resto', $sinfirma);
            }
            if (count($revocados) > 0){
            	$this->smarty->assign ('revocados', $revocados);
            }
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que añade un nuevo consentimiento firmado a la base de datos
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
         function nuevo ($params, $file)
         {
            $id = $params->getParam ('cons');
            
            $fecha = strftime ("%d-%m-%Y");
            $aux = explode ("-", $fecha);
            $aux[0] = (int)$aux[0];
            $aux[1] = (int)$aux[1];
            $fecha = $aux[0]."-".$aux[1]."-".$aux[2];
            
            $this->datos[id_paciente] = $this->id;
            $this->datos[id_tipo_consentimiento] = $id;
            $this->datos[id_usuario] = $_SESSION[id_usr];
            $this->datos[fecha] = $fecha;
			$this->datos[firma] = $params->getParam('txtSignData');
			$image = base64_decode($params->getParam('txtSignImage'));
            
            $this->datos = $this->dao->nuevo ($this->datos);
            if($this->datos > 0){
            	$imageFile = fopen($this->carpeta."fcons".$this->datos, 'x');
                fwrite($imageFile, $image);
                fclose($imageFile);
            }
            
            $this->listado ($params, "cons");
            return; 
         }
         /**
         * Funcion que revoca el consentimiento seleccionado de la BD
         * @param resource Objeto de la clase params para acceder a los parámetros de la petición
         * @param string Archivo que se ha solicitado
         * @return void
         */
         function revocar ($params, $file)
         {
            $id = $params->getParam ('cons');
            
            $fecha = strftime ("%d-%m-%Y");
            $aux = explode ("-", $fecha);
            $aux[0] = (int)$aux[0];
            $aux[1] = (int)$aux[1];
            $fecha = $aux[0]."-".$aux[1]."-".$aux[2];
            
            $this->datos[id_consentimiento] = $id;
            $this->datos[id_usuario] = $_SESSION[id_usr];
            $this->datos[fecha] = $fecha;
			$this->datos[firma] = $params->getParam('txtSignData');
			$image = base64_decode($params->getParam('txtSignImage'));
            
			$dao = new ConsentimientoRevocadoDAO();
            $this->datos = $dao->nuevo ($this->datos);
            if($this->datos > 0){
            	$imageFile = fopen($this->carpeta."fconsr".$id, 'x');
                fwrite($imageFile, $image);
                fclose($imageFile);
            }
            
            $this->listado ($params, "cons");
            return;    
         }
        /**
        * Funcion que muestra todos los datos del consentimiento
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function ver ($params, $file)
        {
            $id = $params->getParam ('cons');
            $this->datos = $this->dao->ver ($id);
            $this->smarty->assign ('datos', $this->datos[0]);
            $this->smarty->display ($this->path."imprimible.phtml");
            return;   
        }
        /**
        * Funcion que muestra todos los datos del consentimiento revocado
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function verRevocado ($params, $file)
        {
            $dao = new ConsentimientoRevocadoDAO ();
            $id = $params->getParam ('cons');
            $this->datos = $dao->ver ($id);
  
            $this->smarty->assign ('datos', $this->datos[0]);
            $this->smarty->display ($this->path."imprimibleR.phtml");
            return;   
        }
    }
?>