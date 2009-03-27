<?php
    /**
    * Fichero que recoje la implementacion de la clase abstracta Dispatcher, su método Dispatch será redefinido en sus clases hijas
    * 
    * @package Presentacion
    * @subpackage Acceso
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (10 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del archivo de configuracion.
    */
    include_once PATH_BASE."conf/conf.inc";
    /**
    * Inclusion de la clase Params encargada del manejo de los parametros de peticion
    */
    include_once PATH_BASE."src/acceso/Params.inc";
    
    /**
    * Clase abstracta Dispatcher, se encarga de transferir el control al objeto correspondiente
    * 
    * @package Presentacion
    * @subpackage Acceso
    * @abstract
    */
    abstract class Dispatcher
    {
        /**
        * Variable que guarda el objeto de la clase params, para recojer los parametros de las peticiones
        * @var resource 
        */
        protected $params;
        /**
        * Constructor de la clase Dispatcher
        * @return void
        */
        function Dispatcher()
        {
            $this->params = new Params();     
            return;  
        }
        /**
        * Funcion que transfiere el control de flujo al objeto correspondiente en funcion de la peticion recibida
        * Permite cargar cualquier pagina del site
        * 
        * @return void
        * @abstract
        */
        abstract function dispatch();   
    }
?>