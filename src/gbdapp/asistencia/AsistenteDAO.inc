<?php
    
    /**
    * Fichero que recoje la implementacion de la clase AsistenteDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Visitas
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (15 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase AsistenteDAO. Implementa la lógica de acceso a datos correspondiente a los empleados que participan en una visita médica.
    * @package Acceso a Datos
    * @subpackage Visitas
    */
    class AsistenteDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function AsistenteDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
            foreach ($datos as $indice => $valor)
            {   
                $campos .= "$indice"." ,";
                $valores .= "'$valor'"." ,";
            }
            
            $campos = substr($campos, 0, strlen($campos)-2);
            $valores = substr ($valores, 0, strlen($valores)-2);
            
            $sentencia = "insert into asistente ($campos) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $sentencia = "delete from asistente where id_visita_medica = '$id'";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;           
        }
        function ver ($id)
        {
            $sentencia = "select id_personal from asistente where id_visita_medica = '$id'";
            $this->datos = $this->DBManager->recoger_datos ($sentencia);
            if (is_array ($this->datos))
            {
                $devolver = array();
                foreach ($this->datos[1] as $linea)
                    array_push ($devolver, $linea[id_personal]);    
                return $devolver;
            }else
                return 0;      
        }
        function modificar ($datos)
        {
                 
        }
        function listado ($id, $pagina = -1)
        {
            $sentencia = "select id_visita_medica from asistente where id_personal = '$id' order by id_visita_medica desc";
            
            $this->datos = $this->DBManager->recoger_datos ($sentencia);
            if (is_array ($this->datos))
            {
                $devolver = array();
                foreach ($this->datos[1] as $linea)
                    array_push ($devolver, $linea[id_visita_medica]);    
                return $devolver;
            }else
                return 0;   
        }
        function buscar ($datos)
        {
                
        }
        function bloquear ($datos)
        {
        
        }  
    }
?>