<?php
  /**
    * Archivo que recoge la implementación de la clase error, que sera el dispatcher empleado para usuarios no validados.
    * 
    * @package Presentacion
    * @subpackage Acceso
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es
    * @version: 1.0 (12 - Diciembre - 2007)
    */
    
    /**
    * Inclusion de la clase dispatcher de la que se heredarán estructura y variables
    */
    include_once PATH_BASE."src/acceso/Dispatcher.inc";
    /**
    * Inclusion de la clase No Autorizado, que sera la que maneje las peticiones
    */
     include_once PATH_BASE."src/error/noAutorizado.inc";
    /**
    * Clase que implementa la lógica de redireccionamiento de peticiones con validacion erronea
    */
    class Error extends Dispatcher
    {
        /**
        * Constructor de la clase, crea un objeto de la clase padre para obtener sus propiedades
        * @return void
        */
        function Error()
        {
            parent::Dispatcher();
            return;
        } 
        function dispatch()
        {
            $lang = $this->params->getParam("lang");
            
            if (($lang != "es_ES") && ($lang != "en_GB") && ($lang != "de_DE") && ($lang != "fr_FR") && ($lang != "it_IT") && ($lang != "pt_PT"))
            {
			    $lang = LANG_LOCALE_DEFAULT;
		    } 
            
            $objeto = new noAutorizado ($lang);
            $objeto->denegar ();
            return;
        }  
    }
?>