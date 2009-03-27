<?php
    /**
    * Fichero TipoForoDAO. Recoge la implementacion de la clase TipoForoDAO
    * 
    * @package Acceso a Datos
    * @subpackage Publicaciones
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (13 - Diciembre - 2007)
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
    class TipoForoDAO extends DAO
    {
        /**
        * Constructor de la clase. Crea un objeto de la clase padre e inicializa las variables
        * @return void   
        */
        function TipoForoDAO ()
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
            $sentencia = "select * from tipo_foro where id_tipo_foro = $id";
            $this->datos = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($this->datos))
                $this->datos = $this->datos[1];
            return $this->datos;
        }
        function modificar ($datos)
        {
        
        }
        function listado ($id, $pagina = -1)
        {
            $sentencia = "select * from tipo_foro";
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