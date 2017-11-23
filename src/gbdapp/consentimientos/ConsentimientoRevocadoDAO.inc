<?php
    /**
    * Fichero que recoje la implementacion de la clase ConsentimientoRevocadoDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Consentimientos
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (6 - Febrero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase ConsentimientoRevocadoDAO. Implementa toda la lógica de acceso a datos para el objeto Consentimiento Revocado
    * @package Acceso a Datos
    * @subpackage Consentimientos
    */
    class ConsentimientoRevocadoDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function ConsentimientoRevocadoDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
        	$datos[id_consentimiento] = $this->crypter->corregir($datos[id_consentimiento]);
        	$datos[fecha] = $this->crypter->corregir($datos[fecha]);
        	$datos[firma] = $this->crypter->corregir($datos[firma]);
        	
            $valores = $datos[id_consentimiento].COMA.
            	COMILLA.$datos[fecha].COMILLA.COMA.
            	COMILLA.$datos[firma].COMILLA.COMA.
            	$datos[id_usuario];
            
            $sentencia = "insert into consentimiento_revocado (id_consentimiento, fecha, firma, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($datos)
        {
                    
        }
        function ver ($datos)
        {
            $id = $datos[id_consentimiento];
            $idusr = $_SESSION[id_usr];
            $sentencia = "select c.id_paciente, r.id_consentimiento, c.fecha as fecha, r.fecha as fecha_r, texto_incluido from consentimiento_revocado as r
            	inner join consentimiento as c on (r.id_consentimiento = c.id_consentimiento)
            	inner join tipo_consentimiento as t on (c.id_tipo_consentimiento = t.id_tipo_consentimiento)
            	 where r.id_usuario = $idusr and r.id_consentimiento_revocado = $id";
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
            $sentencia = "select id_consentimiento, id_tipo_consentimiento, fecha, fecha_r from consentimiento_revocado where id_usuario = '$idusr' and id_paciente = '$id' order by id_consentimiento desc";
            
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