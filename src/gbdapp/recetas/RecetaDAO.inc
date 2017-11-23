<?php
    /**
    * Fichero que recoje la implementacion de la clase RecetaDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Visitas
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (29 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase RecetaDAO. Implementa toda la lógica de acceso a datos para el objeto Receta
    * @package Acceso a Datos
    * @subpackage Visitas
    */
    class RecetaDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function RecetaDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
        	$datos[observaciones] = $this->crypter->corregir($datos[observaciones]);
        	$datos[resumen] = $this->crypter->corregir($datos[resumen]);
        	$datos[texto] = $this->crypter->corregir($datos[texto]);
        	
            $valores = COMILLA.$datos[observaciones].COMILLA.COMA.
            	$datos[id_visita_medica].COMA.
            	$datos[id_paciente].COMA.
            	$datos[id_usuario].COMA.
            	COMILLA.$datos[resumen].COMILLA.COMA.
            	COMILLA.$datos[texto].COMILLA.COMA.
            	$datos[id_tipo_receta];
            
            $sentencia = "insert into receta (observaciones, id_visita_medica, id_paciente, id_usuario, resumen, texto, id_tipo_receta) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from receta where id_usuario = $idusr and id_receta = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;             
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from receta where id_usuario = '$idusr' and id_receta = '$id'";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                return $devuelto[1];
            }else
                return 0;          
        }
        function modificar ($datos)
        {
                  
        }
        function listado ($id, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];                                                                        
            $sentencia = "select id_receta, observaciones, id_tipo_receta from receta where id_usuario = $idusr and id_visita_medica = $id";
            
            if($pagina != -1)
            {   
                $inf = $pagina * MAX_FILAS;
                $sup = MAX_FILAS;
                $sentencia .= " limit $inf, $sup";
            }
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            return $devuelto;   
        }
        function buscar ($datos)
        {
                 
        } 
        function bloquear ($datos)
        {
        
        }
    }
?>