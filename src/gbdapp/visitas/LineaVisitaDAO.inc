<?php
    /**
    * Fichero que recoje la implementacion de la clase LineaVisitaDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Visitas
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (22 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase LineaVisitaDAO. Implementa toda la lógica de acceso a datos para el objeto Línea de visita
    * @package Acceso a Datos
    * @subpackage Visitas
    */
    class LineaVisitaDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function LineaVisitaDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
        	$datos[cantidad] = $this->crypter->corregir($datos[cantidad]);
        	$datos[total] = $this->crypter->corregir($datos[total]);
        	
            $valores = $datos[id_visita].COMA.
				$datos[id_servicio].COMA.
				$datos[cantidad].COMA.
				$datos[total].COMA.
				$datos[id_usuario];
            
            $sentencia = "insert into linea_visita (id_visita, id_servicio, cantidad, total, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from linea_visita where id_usuario = $idusr and id_visita = $id";
            $this->datos = $this->DBManager->hacer_peticion($sentencia);
            return $this->datos;            
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select l.id_servicio, nombre as servicio, cantidad, total from linea_visita as l
                left outer join 
                servicio as s on (l.id_servicio = s.id_servicio)
                where l.id_usuario = '$idusr' and id_visita = '$id'";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                $this->datos = $devuelto[1];
                foreach ($this->datos as $elemento => $array)
                {
                	$this->datos[$elemento][servicio] = $this->crypter->descifrar($this->datos[$elemento][servicio]); 
                }
                return $this->datos;
            }else
                return 0;       
        }
        function modificar ($datos)
        {
                 
        }
        function listado ($id, $pagina = -1)
        {
                
        }
        function buscar ($datos)
        {
                
        } 
        function bloquear ($datos)
        {
        
        } 
    }
?>