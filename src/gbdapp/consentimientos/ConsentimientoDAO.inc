<?php
    /**
    * Fichero que recoje la implementacion de la clase ConsentimientoDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Consentimientos
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (23 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase ConsentimientoDAO. Implementa toda la lógica de acceso a datos para el objeto Consentimiento
    * @package Acceso a Datos
    * @subpackage Consentimientos
    */
    class ConsentimientoDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function ConsentimientoDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
            $valores = $datos[id_tipo_consentimiento].COMA.
            	$datos[id_paciente].COMA.
            	COMILLA.$datos[fecha].COMILLA.COMA.
            	COMILLA.$datos[firma].COMILLA.COMA.
            	$datos[id_usuario];
            
            $sentencia = "insert into consentimiento (id_tipo_consentimiento, id_paciente, fecha, firma, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($datos)
        {
            $idusr = $_SESSION[id_usr];
            $id = $datos [id_consentimiento];
            $sentencia = "delete from consentimiento where id_usuario = $idusr and id_consentimiento = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_consentimiento, id_paciente, fecha, firma, texto_incluido from consentimiento as c 
            	inner join tipo_consentimiento as t on (c.id_tipo_consentimiento = t.id_tipo_consentimiento)
            	where c.id_usuario = $idusr and id_consentimiento = $id";
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
            $sentencia = "select * from consentimientos_view where id_paciente = $id or isnull(id_paciente) and id_usuario = $idusr";
            
            if($pagina != -1)
            {   
                $inf = $pagina * MAX_FILAS;
                $sup = MAX_FILAS;
                $sentencia .= " limit $inf, $sup";
            }
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto)){
            	return $devuelto[1];
            } else {
            	return 0;
            }
        }
        function buscar ($datos)
        {
                
        } 
        function bloquear ($datos)
        {
        
        } 
    }
?>