<?php
    /**
    * Fichero que recoje la implementacion de la clase LoggerDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Log
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (12 - Mayo - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase LoggerDAO. Implementa toda la lógica de acceso a datos para el objeto Logger
    * @package Acceso a Datos
    * @subpackage Log
    */
    class TipoLogDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function TipoLogDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
               
        }
        function borrar ($id)
        {
                    
        }
        function ver ($id)
        {
              
        }
        function modificar ($datos)
        {
                 
        }
        function listado ($id, $pagina = -1)
        {    
            $sentencia = "select * from tipo_log";
            $this->datos = $this->DBManager->recoger_datos ($sentencia);
            return $this->datos[1];  
        }
        function buscar ($datos)
        {
               
        }
        function bloquear ($datos)
        {
          
        }  
    }
?>