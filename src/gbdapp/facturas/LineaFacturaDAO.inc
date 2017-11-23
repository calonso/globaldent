<?php
    /**
    * Fichero que recoje la implementacion de la clase LineaFacturaDAO.
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
    * Clase LineaFacturaDAO. Implementa toda la lógica de acceso a datos para el objeto Línea de factura
    * @package Acceso a Datos
    * @subpackage Presupuestos
    */
    class LineaFacturaDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function LineaFacturaDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
        	$datos[cantidad] = $this->crypter->corregir($datos[cantidad]);
        	$datos[total] = $this->crypter->corregir($datos[total]);
        	$datos[texto] = $this->crypter->corregir($datos[texto]);
       
			$valores = $datos[id_factura].COMA.
				$datos[id_servicio].COMA.
				$datos[cantidad].COMA.
				$datos[total].COMA.
				$datos[id_usuario].COMA.
				COMILLA.$datos[texto].COMILLA;
				            
            $sentencia = "insert into linea_factura (id_factura, id_servicio, cantidad, total, id_usuario, texto) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from linea_factura where id_factura = $id and id_usuario = $idusr";           
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos; 
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from linea_factura as lin
            	left outer join servicio as serv on (lin.id_servicio = serv.id_servicio) where lin.id_usuario = $idusr and id_factura = $id";
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