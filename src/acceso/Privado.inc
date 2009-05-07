<?php
    /**
    * Archivo que recoje la implementacion de la clase Privado
    * 
    * @package Presentacion
    * @subpackage Acceso
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es
    * @version: 1.0 (28 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del fichero Dispatcher, padre de este, del que heredará su estructura
    */
    include_once PATH_BASE."src/acceso/Dispatcher.inc";
    
    /**
    * Clase Privado, implementa la lógica de transferencia de control para las peticiones que le conciernen.
    * 
    * @package Presentacion
    * @subpackage Acceso
    */
    class Privado extends Dispatcher
    {
        /**
        * Constructor de la clase, crea un objeto de la clase padre para obtener todas sus propiedades
        * @return void
        */
        function Privado()
        {
            parent::Dispatcher();
            return;
        }
        /**
        * Funcion que redefine el metodo de su clase padre
        */
        function dispatch()
        {
            $this->dispatchAdmin();
        }
    }
?>