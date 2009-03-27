<?php
    /**
    * Fichero que recoje la implementacion de la clase LineaPresDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Presupuestos
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (16 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase LineaPresDAO. Implementa toda la lógica de acceso a datos para el objeto Línea de presupuesto
    * @package Acceso a Datos
    * @subpackage Presupuestos
    */
    class LineaPresDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function LineaPresDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
			$valores = $datos[id_presupuesto].COMA.
				$datos[id_servicio].COMA.
				$datos[cantidad].COMA.
				$datos[total].COMA.
				$datos[id_usuario];
            
            $sentencia = "insert into linea_presupuesto (id_presupuesto, id_servicio, cantidad, total, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from linea_presupuesto where id_presupuesto = $id and id_usuario = $idusr";           
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from linea_presupuesto as lin
            	left outer join servicio as serv on (lin.id_servicio = serv.id_servicio) where lin.id_usuario = $idusr and id_presupuesto = $id";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
            	$res = $devuelto[1];
            	foreach($res as $linea => $val){
            		$res[$linea][servicio] = $this->crypter->descifrar($res[$linea][nombre]);
            	}
                return $res;
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