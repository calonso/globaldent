<?php
    /**
    * Fichero que recoje la implementacion de la clase FacturaDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Facturas
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (22 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase FacturaDAO. Implementa toda la lógica de acceso a datos para el objeto Factura
    * @package Acceso a Datos
    * @subpackage Facturas
    */
    class FacturaDAO extends DAO
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
        	$datos[nombre_pagador] = $this->crypter->cifrar($datos[nombre_pagador]);
        	$datos[dni_pagador] = $this->crypter->cifrar($datos[dni_pagador]);
			$valores = COMILLA.$datos[numero].COMILLA.COMA.
				COMILLA.$datos[fecha].COMILLA.COMA.
				COMILLA.$datos[nombre_pagador].COMILLA.COMA.
				COMILLA.$datos[dni_pagador].COMILLA.COMA.
				$datos[total].COMA.
				$datos[id_paciente].COMA.
				$datos[id_usuario];
            
            $sentencia = "insert into factura (numero, fecha, nombre_pagador, dni_pagador, total, id_paciente, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($datos)
        {
            $id = $datos[id_factura];
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from factura where id_usuario = $idusr and id_factura = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($datos)
        {
            $id = $datos[id_factura];
            $idp = $datos[id_paciente];
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from factura where id_usuario = '$idusr' and id_factura = '$id' and id_paciente = '$idp'";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                $this->datos = $devuelto[1];
                foreach ($this->datos as $elemento => $array)
                {
                    $this->datos[$elemento][nombre_pagador] = $this->crypter->descifrar($this->datos[$elemento][nombre_pagador]);
                    $this->datos[$elemento][dni_pagador] = $this->crypter->descifrar($this->datos[$elemento][dni_pagador]);   
                }
                return $this->datos;
            }else
                return 0;       
        }
        function modificar ($datos)
        {
        	$id = $datos[id_factura];
            $idusr = $_SESSION[id_usr];
        	foreach ($datos as $indice => $valor)
            {
                if(!empty($valor)){
                	switch($indice){
                		case "nombre_pagador":
                		case "dni_pagador":
                			$valor = $this->crypter->cifrar($valor);
                			break;
                		default:
                			break;
                	}
                	$parejas .= "$indice = '$valor', ";
                }
            }
            $parejas = substr ($parejas, 0, strlen($parejas) -2);
            $sentencia = "update factura set $parejas where id_factura = $id and id_usuario = $idusr";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            if($this->datos == 1)
                $this->datos = $id;
            return $this->datos; 
        }
        function listado ($id, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_factura, numero, fecha, total from factura where id_usuario = $idusr and id_paciente = $id order by id_factura desc";
            
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
	        $idusr = $_SESSION[id_usr];
	
			$sentencia = "select IFNULL(MAX(numero),0) as numero, IFNULL(YEAR(STR_TO_DATE(fecha, '%d-%m-%Y')), YEAR(CURDATE())) as year from factura where id_usuario = $idusr and 
				YEAR(STR_TO_DATE(fecha, '%d-%m-%Y')) = YEAR(CURDATE()) for update";
			$this->datos = $this->DBManager->recoger_datos ($sentencia);
			return $this->datos;
        }  
        function yearList ()
        {
        	$idusr = $_SESSION[id_usr];
        	$sentencia = "select distinct YEAR(STR_TO_DATE(fecha, '%d-%m-%Y')) as year from factura where id_usuario = $idusr order by year desc";
        	$this->datos = $this->DBManager->recoger_datos ($sentencia);
        	if(is_array($this->datos)){
        		$this->datos = $this->datos[1];
        	}
			return $this->datos;
        }
        function fullListByYear ($year, $pagina = -1){
        	$idusr = $_SESSION[id_usr];
        	$sentencia = "select id_factura, numero, fecha, f.id_paciente, total, nombre, apellido, apellido2 from factura as f 
        		inner join (select id_paciente, nombre, apellido, apellido2 from paciente) as p on (f.id_paciente = p.id_paciente)
        		where id_usuario = $idusr and YEAR(STR_TO_DATE(fecha, '%d-%m-%Y')) = $year order by id_factura asc";
        	if($pagina != -1)
            {   
                $inf = $pagina * MAX_FILAS;
                $sup = MAX_FILAS;
                $sentencia .= " limit $inf, $sup";
            }
            $this->datos = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($this->datos)){
            	$this->datos = $this->datos[1];
            	foreach($this->datos as $indice => $valor){
            		$nombre = $this->crypter->descifrar($this->datos[$indice][nombre]);
            		$apellido = $this->crypter->descifrar($this->datos[$indice][apellido]);
            		$apellido2 = $this->crypter->descifrar($this->datos[$indice][apellido2]);
            		$this->datos[$indice][nombre] = $apellido." ".$apellido2.", ".$nombre;
            	}
            }
			return $this->datos;
        }
    }
?>