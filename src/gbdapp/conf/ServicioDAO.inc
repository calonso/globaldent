<?php
    
    /**
    * Fichero que recoje la implementacion de la clase ServicioDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Configuracion
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (15 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase ServicioDAO. Implementa toda la lógica de acceso a datos para el objeto Servicio
    * @package Acceso a Datos
    * @subpackage Configuracion
    */
    class ServicioDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function ServicioDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
        	$datos[precio_unitario] = $this->crypter->corregir($datos[precio_unitario]);
            $nombre = $this->crypter->cifrar($datos[nombre]);
            
            $valores = COMILLA.$nombre.COMILLA.COMA.
            	$datos[precio_unitario].COMA.
            	$datos[id_usuario];
            
            $sentencia = "insert into servicio (nombre, precio_unitario, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from servicio where id_usuario = $idusr and id_servicio = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from servicio where id_usuario = '$idusr' and id_servicio = '$id'";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
            	$devuelto = $devuelto[1];
            	$devuelto[0][nombre] = $this->crypter->descifrar($devuelto[0][nombre]);
                return $devuelto;
            }else
                return 0;       
        }
        function modificar ($datos)
        {
                 
        }
        function listado ($id, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];
            
            $sentencia1 = "select * from servicio where id_usuario = '$idusr'";
            $devuelto = $this->DBManager->recoger_datos ($sentencia1);
            if(is_array($devuelto))
            {
                $mitabla = "busqueda".$_SESSION[id_usr];
                $sentencia1 = "CREATE TEMPORARY TABLE IF NOT EXISTS $mitabla LIKE servicio";
                $this->DBManager->hacer_peticion ($sentencia1);
                
                $this->datos = $devuelto[1];
                foreach ($this->datos as $elemento => $array)
                {
                    $valores .= "(".$array[id_servicio].COMA.
                    	COMILLA.$this->crypter->descifrar($array[nombre]).COMILLA.COMA.
                    	$array[precio_unitario].COMA.$array[id_usuario]."), ";
                    
                }   
                $valores = substr($valores, 0, strlen($valores) -2);
                $sentencia1 = "insert into $mitabla values $valores";
                $this->DBManager->hacer_peticion ($sentencia1);  
            
                $sentencia = "select id_servicio, nombre, precio_unitario from $mitabla where id_usuario = '$idusr' order by nombre asc";
                
                if($pagina != -1)
                {   
                    $inf = $pagina * MAX_FILAS;
                    $sup = MAX_FILAS;
                    $sentencia .= " limit $inf, $sup";
                }
                $devolver = $this->DBManager->recoger_datos ($sentencia);
                
                if(($devolver[0] == MAX_FILAS + 1) && ($pagina != -1)){
                    $devolver[1] = array_slice($devolver[1], 0, -1, true);   
                }
                $sentencia = "drop temporary table if exists $mitabla";
                $this->DBManager->hacer_peticion($sentencia);
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