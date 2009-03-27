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
    class LoggerDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function LoggerDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
            $valores = $datos[id_usuario].COMA.
            	$datos[id_personal].COMA.
            	COMILLA.$datos[nombre].COMILLA.COMA.
            	COMILLA.$datos[detalles].COMILLA.COMA.
            	COMILLA.$datos[fecha].COMILLA.COMA.
            	$datos[id_tipo_log];
            
            $sentencia = "insert into log (id_usuario, id_personal, nombre, detalles, fecha, id_tipo_log) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
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
            
        }
        function buscar ($datos)
        {
            $parejas = "l.id_usuario = ".$_SESSION[id_usr]." and ";
            foreach ($datos as $indice => $valor)
            {
                if(strlen($valor) > 0)
                {
                    switch($indice)
                    {
                        case "id_personal":
                        case "id_tipo_log":
                            $parejas .= "l.$indice in ($valor) and ";
                            break;   
                        case "fecha_ini":
                            $parejas .= "DATEDIFF(fecha, STR_TO_DATE('$valor', '%d-%m-%Y')) >= 0 and ";
                            break;
                        case "fecha_fin":
                            $parejas .= "DATEDIFF(STR_TO_DATE('$valor', '%d-%m-%Y'), fecha) >= 0 and ";
                            break;
                        case "pag":
                            $pagina = $valor;
                            break;
                    }
                }
            }  
            $parejas = substr ($parejas, 0, strlen($parejas) -5);     
            $sentencia = 
            "select l.*, a.nombre as accion, p.nombre as nom, apellido, apellido2 
            from log as l 
            inner join personal as p on (l.id_personal = p.id_personal) 
            inner join tipo_log as a on (l.id_tipo_log = a.id_tipo_log)
            where $parejas order by fecha asc";
            
            if (isset($pagina)){
                $inf = $pagina * MAX_FILAS;
                $sup = MAX_FILAS + 1;
                $sentencia .= " limit $inf, $sup";    
            }
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            return $devuelto;
        }
        function bloquear ($datos)
        {
          
        }  
    }
?>