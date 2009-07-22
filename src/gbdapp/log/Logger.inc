<?php
/**
* Archivo que recoge la implementación de la clase Logger.
*/ 

/**
* Inclusion del archivo LoggerDAO para tener acceso al almacenamiento de datos de log
*/
include_once PATH_BASE."src/gbdapp/log/LoggerDAO.inc";

/**
* Inclusion del archivo PersonalDAO para tener acceso a los datos del personal
*/
include_once PATH_BASE."src/gbdapp/personal/PersonalDAO.inc";
/**
* Inclusion del archivo TipoLogDAO para tener acceso a los datos de las acciones
*/
include_once PATH_BASE."src/gbdapp/log/TipoLogDAO.inc";


/**
* Clase que se encarga de recoger log de todas las acciones realizadas por los usuarios
* de la aplicación GlobalDent
* 
* @package Negocio
* @subpackage Log
* @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
* @version: 1.0 (12 - Mayo - 2007)
*/
class Logger extends DisplayManager 
{
    
    private $dao;
    private $datos;
    
    /**
    * Constructor de la clase, inicializa las variables y recibe parámetro de lenguaje
    * @param String lenguaje en que se ha solicitado la página
    */
    function Logger($lang)
    {
        parent::DisplayManager();
        $this->path = TPL_PATH_BASE."gbdapp/log/";
        
        $lang_file = PATH_LANG.$lang."/site.lng";
        $this->smarty->assign ('lang_file', $lang_file);
        
        $this->smarty->assign('on', 9);
        
        $this->smarty->assign('privilegios', $_SESSION[privilegios]);
        
        $this->dao = new LoggerDAO();
    }
    
    /**
    * Funcion que almacena datos en el log
    * @param int Identificador dela acción realizada
    * @param String mensaje indicando la acción realizada
    */
    function save ($accion, $mensaje)
    {
        $this->datos[id_usuario] = isset($_SESSION[id_usr]) ? $_SESSION[id_usr] : 0;
        $this->datos[id_personal] = isset($_SESSION[id_pers]) ? $_SESSION[id_pers] : 0;
        $this->datos[nombre] = isset($_SESSION[nombre]) ? $_SESSION[nombre] : "nobody";
        $this->datos[id_tipo_log] = $accion;
        $this->datos[detalles] = $mensaje;
        $this->datos[fecha] = strftime ("%Y-%m-%d %H:%M:%S");
        $this->datos[ip] = $_SERVER['REMOTE_ADDR'];
        
        $this->dao->nuevo ($this->datos);
        return;
    }
    
    /**
    * Funcion que muestra la pagina principal para la consulta de log
    * @param resource Objeto de clase params para acceder a los parámetros de la petición
    * @param string Página que se ha solicitado
    */
    function index ($params, $file)
    {
        $this->cargaSelectores();
        $this->smarty->display ($this->path."index.phtml") ;
        return;
    }
    /**
    * Funcion que carga los selectores del menu de busqueda de log
    */
    function cargaSelectores()
    {
        $persdao = new PersonalDAO();
        
        $datos = $persdao->listado(0);
        if(is_array($datos))
        {
            $datos = $datos[1];
            foreach($datos as $linea)
                $pers[$linea[id_personal]] = $linea[apellido]." ".$linea[apellido2].", ".$linea[nombre];
            $this->smarty->assign ('pers', $pers);      
        }
        
        $tipos = new TipoLogDAO();
        $datos = $tipos->listado(0);
        if(is_array($datos))
        {
            foreach($datos as $linea)
                $logs[$linea[id_tipo_log]] = $linea[nombre];
            $this->smarty->assign ('logs', $logs);      
        }
        return;
    }
    /**
    * Funcion que muestra el log para los parámetros seleccionados
    * @param resource Objeto de la clase params para acceder a los parámetros de la petición
    * @param string Página que se ha solicitado
    * @return void
    */
    function ver ($params, $file)
    {
        $pag = $params->getParam('pag');
        if(isset($pag)){
            $this->datos = $_SESSION[busqueda];
            $this->datos[pag] = $pag;
            $this->smarty->assign('pag', $pag); 
        }else{
            $this->datos = $this->recibirFormulario ($params);
            $_SESSION[busqueda] = $this->datos;
            $this->datos[pag] = 0;
            $this->smarty->assign('pag', 0); 
        }
        
        $this->datos = $this->dao->buscar ($this->datos);
        
        $this->cargaSelectores();
        
        $this->smarty->assign ('numLineas', -1);
        
        if(is_array($this->datos))
        {
            $this->smarty->assign('numLineas', $this->datos[0]);
            $this->smarty->assign('inlogs', $this->datos[1]);
            $this->smarty->assign('numero', $this->datos[0]);
        }
        
        $this->smarty->display ($this->path.$file.".phtml");
        return;
    }
    /**
    * Funcion que carga los parámetros de la petición
    * @param resource Objeto de clase params para acceder a los parámetros
    * @return array cargado con los datos
    */
    function recibirFormulario ($params)
    {
        $pers = $params->getParam("selPers");
        if(is_array ($pers))
        {
            foreach ($pers as $id)
                $cadena .= "$id, ";
        }
        $cadena = substr($cadena, 0, strlen($cadena) - 2);
        
        $acts = $params->getParam("selTipos");
        if(is_array($acts))
        {
            foreach ($acts as $acc)
                $cadena2 .= "$acc, ";
        }
        $cadena2 = substr($cadena2, 0, strlen($cadena2) - 2);
        
        $datos[id_personal] = $cadena;
        $datos[id_tipo_log] = $cadena2;
        $datos[fecha_ini] = $params->getParam("fechaIni");
        $datos[fecha_fin] = $params->getParam("fechaFin");
        
        return $datos;
    }
    
}    
