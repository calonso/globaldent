<?php
    /**
    * Fichero que recoje la implementacion de la clase PersonalDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Personal
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (10 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase PersonalDAO. Implementa toda la lógica de acceso a datos para el objeto Paciente
    * @package Acceso a Datos
    * @subpackage Personal
    */
    class PersonalDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function PersonalDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
        	$pass = $this->crypter->cifrar($datos[password]);
        	$privi = $this->crypter->cifrar($datos[privilegios]);
        	$datos[nombre] = $this->crypter->corregir($datos[nombre]);
        	$datos[apellido] = $this->crypter->corregir($datos[apellido]);
        	$datos[apellido2] = $this->crypter->corregir($datos[apellido2]);
        	$datos[dni] = $this->crypter->corregir($datos[dni]);
        	$datos[direccion] = $this->crypter->corregir($datos[direccion]);
        	$datos[cp] = $this->crypter->corregir($datos[cp]);
        	$datos[ciudad] = $this->crypter->corregir($datos[ciudad]);
        	$datos[telefono] = $this->crypter->corregir($datos[telefono]);
        	$datos[movil] = $this->crypter->corregir($datos[movil]);
        	$datos[email] = $this->crypter->corregir($datos[email]);
        	$datos[num_colegiado] = $this->crypter->corregir($datos[num_colegiado]);
        	$datos[especialidad] = $this->crypter->corregir($datos[especialidad]);
        	$datos[fecha_alta] = $this->crypter->corregir($datos[fecha_alta]);
        	$datos[curriculum] = $this->crypter->corregir($datos[curriculum]);
        	$datos[extension] = $this->crypter->corregir($datos[extension]);
        	$datos[login] = $this->crypter->corregir($datos[login]);
        	
        	$valores = COMILLA.$datos[nombre].COMILLA.COMA.
        		COMILLA.$datos[apellido].COMILLA.COMA.
        		COMILLA.$datos[apellido2].COMILLA.COMA.
        		COMILLA.$datos[dni].COMILLA.COMA.
        		COMILLA.$datos[direccion].COMILLA.COMA.
        		COMILLA.$datos[cp].COMILLA.COMA.
        		COMILLA.$datos[ciudad].COMILLA.COMA.
        		$datos[id_provincia].COMA.
        		COMILLA.$datos[telefono].COMILLA.COMA.
        		COMILLA.$datos[movil].COMILLA.COMA.
        		COMILLA.$datos[email].COMILLA.COMA.
        		COMILLA.$datos[num_colegiado].COMILLA.COMA.
        		COMILLA.$datos[especialidad].COMILLA.COMA.
        		COMILLA.$datos[fecha_alta].COMILLA.COMA.
        		COMILLA.$datos[curriculum].COMILLA.COMA.
        		COMILLA.$datos[extension].COMILLA.COMA.
        		COMILLA.$datos[login].COMILLA.COMA.
        		COMILLA.$pass.COMILLA.COMA.
        		COMILLA.$privi.COMILLA.COMA.
        		$datos[id_usuario];
            
            $sentencia = "insert into personal (nombre, apellido, apellido2, dni, direccion, cp, ciudad, id_provincia, telefono, movil, email, 
            	num_colegiado, especialidad, fecha_alta, curriculum, extension, login, password, privilegios, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from personal where id_usuario = $idusr and id_personal = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from personal where id_usuario = $idusr and id_personal = $id";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                $this->datos = $devuelto[1];
                $this->datos[0][password] = $this->crypter->descifrar($this->datos[0][password]);
                $this->datos[0][privilegios] = $this->crypter->descifrar($this->datos[0][privilegios]);
                return $this->datos;
            }else
                return 0;   
        }
        function modificar ($datos)
        {
            $id = $datos[id_personal];
            $idusr = $_SESSION[id_usr];
            foreach ($datos as $indice => $valor)
            {
            	switch($indice){
            		case "password":
            		case "privilegios":
            			$valor = $this->crypter->cifrar($valor);
            			break;
            		case "id_provincia":
            			if($valor == 0){
            				$valor = "NULL";
            			}
            			break;
            		default:
            			$valor = $this->crypter->corregir($valor);
            			break;
            	}
            	$parejas .= "$indice = '$valor', ";
            } 
            $parejas = substr ($parejas, 0, strlen($parejas) -2);
            $sentencia = "update personal set $parejas where id_personal = '$id' and id_usuario = '$idusr'";

            return $this->DBManager->hacer_peticion ($sentencia);     
        }
        function listado ($id, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_personal, nombre, apellido, apellido2, extension from personal where id_usuario = '$idusr' order by apellido desc";
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
            if(is_array($datos))
            {
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
            }
            
           if(is_array($datos))
               $sentencia = "select id_personal, nombre, apellido, apellido2, extension from personal where $parejas and nombre != '#' and apellido != '#' and apellido2 != '#' order by apellido asc";
           else
               $sentencia = "select distinct apellido from personal where apellido != '#' order by apellido asc";
           $devolver = $this->DBManager->recoger_datos($sentencia);
           return $devolver;  
        }
        function acceder ($login) 
        {
            $sentencia = "select id_personal, nombre, apellido, apellido2, login, password, id_usuario, privilegios from personal where login = '$login'";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                $registro = $devuelto[1][0];
                $registro[password] = $this->crypter->descifrar($registro[password]);
                $registro[privilegios] = $this->crypter->descifrar($registro[privilegios]);    
                	
                return $registro;
            }               
            return 0;  
        }
        function bloquear ($datos)
        {
        
        }  
    }
?>