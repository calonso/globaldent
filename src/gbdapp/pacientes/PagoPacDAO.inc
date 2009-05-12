<?php
    /**
    * Fichero que recoje la implementacion de la clase PagoPacDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Pacientes
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (9 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase PagoPacDAO. Implementa toda la lógica de acceso a datos para el objeto Paciente
    * @package Acceso a Datos
    * @subpackage Pacientes
    */
    class PagoPacDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function PagoPacDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
            $valores = $datos[id_paciente].COMA.
            	$datos[id_usuario].COMA.
            	$datos[total_tarjeta].COMA.
            	$datos[total_efectivo].COMA.
            	COMILLA.$datos[fecha].COMILLA;
            
            $sentencia = "insert into pagopac (id_paciente, id_usuario, total_tarjeta, total_efectivo, fecha) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from pagopac where id_usuario = $idusr and id_pago = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;          
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from pagopac where id_usuario = $idusr and id_pago = $id";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            
            if(is_array($devuelto))
            {
                return $devuelto[1];
            }else
                return 0; 
        }
        function modificar ($datos)
        {
            $id = $datos[id_pago];
            $idusr = $_SESSION[id_usr];
            foreach ($datos as $indice => $valor)
            {
                $parejas .= "$indice = '$valor', "; 
            } 
            $parejas = substr ($parejas, 0, strlen($parejas) -2);
            $sentencia = "update pagopac set $parejas where id_pago = $id and id_usuario = $idusr";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            if($this->datos == 1)
                $this->datos = $id;
            return $this->datos;       
        }
        function listado ($id, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select fecha, total_tarjeta, total_efectivo from pagopac where id_usuario = $idusr and id_paciente = $id order by id_pago asc";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            
            if(is_array($devuelto))
            {
                return $devuelto[1];
            }else
                return 0;
            
        }
        function buscar ($datos)
        {
            $idusr = $_SESSION[id_usr];
            
            if(is_array($datos))
            {
                $idpac = $datos[id_paciente];
                $fecha = $datos[fecha];
                $sentencia1 = "select * from pagopac where id_usuario = '$idusr' and id_paciente = '$idpac' and fecha = '$fecha' order by id_paciente asc";
            }else
            {
                $fecha = $datos;  
                $sentencia1 = "select * from pagopac where id_usuario = '$idusr' and fecha = '$fecha' order by id_paciente asc";     
            }
                
            $devuelto = $this->DBManager->recoger_datos ($sentencia1);
            return $devuelto;      
        }
        function bloquear ($datos)
        {
        
        }  
    }
?>