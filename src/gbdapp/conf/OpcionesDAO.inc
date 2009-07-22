<?php
    
    /**
    * Fichero que recoje la implementacion de la clase OpcionesDAO.
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
    * Clase OpcionesDAO. Implementa toda la lógica de acceso a datos para las opciones configurables
    * @package Acceso a Datos
    * @subpackage Configuracion
    */
    class OpcionesDAO extends DAO
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
        	$datos[nombre] = $this->crypter->corregir($datos[nombre]);
        	$datos[especialidad] = $this->crypter->corregir($datos[especialidad]);
        	$datos[nif] = $this->crypter->corregir($datos[nif]);
        	$datos[direccion] = $this->crypter->corregir($datos[direccion]);
        	$datos[telefono] = $this->crypter->corregir($datos[telefono]);
        	$datos[cp] = $this->crypter->corregir($datos[cp]);
        	$datos[ciudad] = $this->crypter->corregir($datos[ciudad]);
        	$datos[id_provincia] = $this->crypter->corregir($datos[id_provincia]);
        	$datos[gabinetes] = $this->crypter->corregir($datos[gabinetes]);
        	$datos[reg_sanidad] = $this->crypter->corregir($datos[reg_sanidad]);
        	$datos[extension] = $this->crypter->corregir($datos[extension]);
        	$datos[extensionf] = $this->crypter->corregir($datos[extensionf]);
        	
            $valores = $datos[id_usuario].COMA.
            	COMILLA.$datos[nombre].COMILLA.COMA.
            	COMILLA.$datos[especialidad].COMILLA.COMA.
            	COMILLA.$datos[nif].COMILLA.COMA.
            	COMILLA.$datos[direccion].COMILLA.COMA.
            	COMILLA.$datos[telefono].COMILLA.COMA.
            	COMILLA.$datos[cp].COMILLA.COMA.
            	COMILLA.$datos[ciudad].COMILLA.COMA.
            	$datos[id_provincia].COMA.
            	$datos[gabinetes].COMA.
            	COMILLA.$datos[reg_sanidad].COMILLA.COMA.
            	COMILLA.$datos[extension].COMILLA.COMA.
            	COMILLA.$datos[extensionf].COMILLA;
            
            $sentencia = "insert into opciones (id_usuario, nombre, especialidad, nif, direccion, telefono, 
            	cp, ciudad, id_provincia, gabinetes, reg_sanidad, extension, extensionf) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from opciones where id_usuario = $idusr";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from opciones where id_usuario = $idusr";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                return $devuelto[1];
            }else
                return 0;       
        }
        function modificar ($datos)
        {
            $idusr = $_SESSION[id_usr];
            foreach ($datos as $indice => $valor)
            {
            	if (!empty($valor)){
            		$valor = $this->crypter->corregir($valor);
	          		$parejas .= "$indice = $valor, ";
            	}
            } 
            $parejas = substr ($parejas, 0, strlen($parejas) -2);
            $sentencia = "update opciones set $parejas where id_usuario = $idusr";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;
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