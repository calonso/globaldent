<?php
    /**
    * Fichero que recoje la implementacion de la clase PresupuestoDAO.
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
    * Clase PresupuestoDAO. Implementa toda la lógica de acceso a datos para el objeto Presupuesto
    * @package Acceso a Datos
    * @subpackage Presupuestos
    */
    class PresupuestoDAO extends DAO
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
			$valores = $datos[id_paciente].COMA.
				COMILLA.$datos[numero].COMILLA.COMA.
				COMILLA.$datos[fecha].COMILLA.COMA.
				$datos[validez].COMA.
				$datos[duracion].COMA.
				$datos[total].COMA.
				COMILLA.$datos[objetivo].COMILLA.COMA.
				COMILLA.$datos[firma].COMILLA.COMA.
				$datos[id_usuario];
            
            $sentencia = "insert into presupuesto (id_paciente, numero, fecha, validez, duracion, total, objetivo, firma, id_usuario
            	) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($datos)
        {
            $id = $datos[id_presupuesto];
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from presupuesto where id_usuario = $idusr and id_presupuesto = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($datos)
        {
            $id = $datos[id_presupuesto];
            $idp = $datos[id_paciente];
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from presupuesto where id_usuario = '$idusr' and id_presupuesto = '$id' and id_paciente = '$idp'";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                return $devuelto[1];
            }else
                return 0;       
        }
        function modificar ($datos)
        {
            $id = $datos[id_presupuesto];
            $idusr = $_SESSION[id_usr];
            foreach ($datos as $indice => $valor)
            {
            	$parejas .= "$indice = '$valor', "; 
            } 
            $parejas = substr ($parejas, 0, strlen($parejas) -2);
            $sentencia = "update presupuesto set $parejas where id_presupuesto = $id and id_usuario = $idusr";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            if($this->datos == 1)
                $this->datos = $id;
            return $this->datos;        
        }
        function listado ($id, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_presupuesto, numero, fecha, total from presupuesto where id_usuario = $idusr and id_paciente = $id order by id_presupuesto desc";
            
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