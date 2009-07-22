<?php
    /**
    * Fichero que recoje la implementacion de la clase DresDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Doctores
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (9 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase DresDAO. Implementa toda la lógica de acceso a datos para el objeto Dres
    * @package Acceso a Datos
    * @subpackage Doctores
    */
    class DresDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function DresDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
        	$datos[nombre] = $this->crypter->corregir($datos[nombre]);
        	$datos[apellido] = $this->crypter->corregir($datos[apellido]);
        	$datos[apellido2] = $this->crypter->corregir($datos[apellido2]);
        	$datos[dni] = $this->crypter->corregir($datos[dni]);
        	$datos[direccion] = $this->crypter->corregir($datos[direccion]);
        	$datos[cp] = $this->crypter->corregir($datos[cp]);
        	$datos[ciudad] = $this->crypter->corregir($datos[ciudad]);
        	$datos[id_provincia] = $this->crypter->corregir($datos[id_provincia]);
        	$datos[telefono_clinica] = $this->crypter->corregir($datos[telefono_clinica]);
        	$datos[telefono_movil] = $this->crypter->corregir($datos[telefono_movil]);
        	$datos[telefono_casa] = $this->crypter->corregir($datos[telefono_casa]);
        	$datos[fax] = $this->crypter->corregir($datos[fax]);
        	$datos[email] = $this->crypter->corregir($datos[email]);
        	$datos[fecha_nacimiento] = $this->crypter->corregir($datos[fecha_nacimiento]);
        	$datos[especialidad] = $this->crypter->corregir($datos[especialidad]);
        	
            $valores = COMILLA.$datos[nombre].COMILLA.COMA.
            	COMILLA.$datos[apellido].COMILLA.COMA.
            	COMILLA.$datos[apellido2].COMILLA.COMA.
            	COMILLA.$datos[dni].COMILLA.COMA.
            	COMILLA.$datos[direccion].COMILLA.COMA.
            	COMILLA.$datos[cp].COMILLA.COMA.
            	COMILLA.$datos[ciudad].COMILLA.COMA.
            	$datos[id_provincia].COMILLA.COMA.
            	COMILLA.$datos[telefono_clinica].COMILLA.COMA.
            	COMILLA.$datos[telefono_movil].COMILLA.COMA.
            	COMILLA.$datos[telefono_casa].COMILLA.COMA.
            	COMILLA.$datos[fax].COMILLA.COMA.
            	COMILLA.$datos[email].COMILLA.COMA.
            	COMILLA.$datos[fecha_nacimiento].COMILLA.COMA.
            	COMILLA.$datos[especialidad].COMILLA.COMA.
            	$datos[id_usuario];
            
            $sentencia = "insert into dr_externo (nombre, apellido, apellido2, dni, direccion, cp, 
            	ciudad, id_provincia, telefono_clinica, telefono_movil, telefono_casa, fax, email, 
            	fecha_nacimiento, especialidad, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from dr_externo where id_usuario = $idusr and id_dr_externo = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;           
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from dr_externo as dr
            	left outer join provincia as pr on (dr.id_provincia = pr.id_provincia)
            	where id_usuario = $idusr and id_dr_externo = $id";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            return $devuelto;   
        }
        function modificar ($datos)
        {
            $id = $datos[id_dr_externo];
            $idusr = $_SESSION[id_usr];
            foreach ($datos as $indice => $valor)
            {
            	$valor = $this->crypter->corregir($valor);
                $parejas .= "$indice = '$valor', ";
            } 
            $parejas = substr ($parejas, 0, strlen($parejas) -2);
            $sentencia = "update dr_externo set $parejas where id_dr_externo = $id and id_usuario = $idusr";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            if($this->datos == 1)
                $this->datos = $id;
            return $this->datos;   
        }
        function listado ($datos, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_dr_externo, nombre, apellido, apellido2 from dr_externo where id_usuario = $idusr";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            return $devuelto;  
        }
        function buscar ($datos)
        {
            if(is_array($datos))
            {
            	$datos[id_usuario] = $_SESSION[id_usr];
                foreach ($datos as $indice => $valor)
                {
                    if((strcmp($valor, ''))&&($valor))
                    {
                        switch($indice)
                        {
                            case "id_provincia":
                            case "id_usuario":
                                $parejas .= "$indice = '$valor' and ";
                                break;
                            case "letra":
                                $parejas .= "apellido LIKE '$valor%' and ";
                                break;
                            default:
                                $parejas .= "$indice LIKE '%$valor%' and ";
                                break;
                        }   
                    }
                }
                $parejas = substr ($parejas, 0, strlen($parejas) -5);
                $sentencia = "select id_dr_externo, nombre, apellido, apellido2 from dr_externo where $parejas order by apellido asc";
            }else
            	$sentencia = "select distinct apellido from dr_externo order by apellido asc";
                
            $devolver = $this->DBManager->recoger_datos($sentencia);
            return $devolver;
        }
        function bloquear ($datos)
        {
        
        }  
    }
?>