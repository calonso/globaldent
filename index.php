<?php
    /**
    * Archivo index que sera ejecutado para todas las peticiones. 
    * Llama al controller
    * 
    * @package Presentacion
    * @subpackage Index
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (10 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del fichero de configuracion
    */
    include_once "conf/conf.inc";
    /**
    * Inclusion del fichero controller para poder usarla
    */
    include_once PATH_BASE."src/acceso/Controller.inc";
    
    new Controller();
?>