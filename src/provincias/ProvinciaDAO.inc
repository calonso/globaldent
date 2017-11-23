<?php
    /**
    * Fichero ProvinciaDAO. Recoge la implementacion de la clase ProvinciaDAO
    * 
    * @package Acceso a Datos
    * @subpackage Provincias
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (9 - Enero - 1008)
    */
    
    /**
    * Inclusion del archivo DAO del que se heredaran propiedades y estructura
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase TipoForoDAO. Implementa toda la lógica de acceso a los datos de tipos de foro
    * @package Acceso a Datos
    * @subpackage Publicaciones
    */
    class ProvinciaDAO extends DAO
    {
        /**
        * Constructor de la clase. Crea un objeto de la clase padre e inicializa las variables
        * @return void   
        */
        function ProvinciaDAO ()
        {
            parent::DAO();
            return;   
        }
        function nuevo ($datos)
        {
            
        }
        function borrar ($datos)
        {
        
        }
        function ver ($id)
        {
            $sentencia = "select provincia from provincia where id_provincia = '$id'";
            $this->datos = $this->DBManager->recoger_datos ($sentencia);
            return $this->datos[1][0][provincia];   
        }
        function modificar ($datos)
        {
        
        }
        function listado ($id, $pagina = -1)
        {
            $sentencia = "select * from provincia";
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