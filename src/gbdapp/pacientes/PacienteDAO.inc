<?php
    /**
    * Fichero que recoje la implementacion de la clase PacienteDAO.
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
    * Clase PacienteDAO. Implementa toda la lógica de acceso a datos para el objeto Paciente
    * @package Acceso a Datos
    * @subpackage Pacientes
    */
    class PacienteDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function PacienteDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
        	$datos[nombre] = $this->crypter->cifrar($datos[nombre]);
        	$datos[apellido] = $this->crypter->cifrar($datos[apellido]);
        	$datos[apellido2] = $this->crypter->cifrar($datos[apellido2]);
        	$datos[direccion] = $this->crypter->cifrar($datos[direccion]);
        	$datos[cp] = $this->crypter->cifrar($datos[cp]);
        	$datos[telefono_fijo] = $this->crypter->cifrar($datos[telefono_fijo]);
        	$datos[telefono_trabajo] = $this->crypter->cifrar($datos[telefono_trabajo]);
        	$datos[telefono_movil] = $this->crypter->cifrar($datos[telefono_movil]);
        	$datos[dni] = $this->crypter->cifrar($datos[dni]);
        	$datos[email] = $this->crypter->cifrar($datos[email]);
        	$refer = $datos[id_paciente_referidor] == 0 ? 'NULL' : $datos[id_paciente_referidor];
        	$drrefer = $datos[id_dr_referidor] == 0 ? 'NULL' : $datos[id_dr_referidor];
        	
        	$valores = COMILLA.$datos[nombre].COMILLA.COMA.
        		COMILLA.$datos[apellido].COMILLA.COMA.
        		COMILLA.$datos[apellido2].COMILLA.COMA.
        		COMILLA.$datos[direccion].COMILLA.COMA.
        		COMILLA.$datos[ciudad].COMILLA.COMA.
        		$datos[id_provincia].COMA.
        		COMILLA.$datos[cp].COMILLA.COMA.
        		COMILLA.$datos[telefono_fijo].COMILLA.COMA.
        		COMILLA.$datos[telefono_trabajo].COMILLA.COMA.
        		COMILLA.$datos[telefono_movil].COMILLA.COMA.
        		COMILLA.$datos[profesion].COMILLA.COMA.
        		COMILLA.$datos[dni].COMILLA.COMA.
        		COMILLA.$datos[fecha_nacimiento].COMILLA.COMA.
        		COMILLA.$datos[email].COMILLA.COMA.
        		COMILLA.$datos[alertas_medicas].COMILLA.COMA.
        		COMILLA.$datos[observaciones].COMILLA.COMA.
        		COMILLA.$datos[extension].COMILLA.COMA.
        		$refer.COMA.
        		$drrefer.COMA.
        		COMILLA.$datos[fecha_alta].COMILLA.COMA.
        		$datos[id_usuario];
            
            $sentencia = "insert into paciente (nombre, apellido, apellido2, direccion, ciudad, id_provincia, cp, telefono_fijo, telefono_trabajo, 
            	telefono_movil, profesion, dni, fecha_nacimiento, email, alertas_medicas, observaciones, extension, id_paciente_referidor, 
            	id_dr_referidor, fecha_alta, id_usuario) values ($valores)";
            echo $sentencia;
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from paciente where id_usuario = $idusr and id_paciente = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from paciente as p
            	left outer join provincia as pr on (p.id_provincia = pr.id_provincia)
            	left outer join (select id_dr_externo, CONCAT(apellido, ' ', apellido2, ', ', nombre) as nombre_dr_referidor from dr_externo) as dr on (p.id_dr_referidor = dr.id_dr_externo)
              	left outer join (select id_paciente as id_refer, nombre as nom_ref, apellido as ap_ref, apellido2 as ap2_ref from paciente) as pac on (p.id_paciente_referidor = pac.id_refer)
            	where id_usuario = $idusr and id_paciente = $id";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                $this->datos = $devuelto[1][0];
                $this->datos[nombre] = $this->crypter->descifrar($this->datos[nombre]);
	        	$this->datos[apellido] = $this->crypter->descifrar($this->datos[apellido]);
	        	$this->datos[apellido2] = $this->crypter->descifrar($this->datos[apellido2]);
	        	$this->datos[direccion] = $this->crypter->descifrar($this->datos[direccion]);
	        	$this->datos[cp] = $this->crypter->descifrar($this->datos[cp]);
	        	$this->datos[telefono_fijo] = $this->crypter->descifrar($this->datos[telefono_fijo]);
	        	$this->datos[telefono_trabajo] = $this->crypter->descifrar($this->datos[telefono_trabajo]);
	        	$this->datos[telefono_movil] = $this->crypter->descifrar($this->datos[telefono_movil]);
	        	$this->datos[dni] = $this->crypter->descifrar($this->datos[dni]);
	        	$this->datos[email] = $this->crypter->descifrar($this->datos[email]);
	        	if($this->datos[id_paciente_referidor] != NULL){
	        		$nombre = $this->crypter->descifrar($this->datos[nom_ref]);
	        		$apellido = $this->crypter->descifrar($this->datos[ap_ref]);
	        		$apellido2 = $this->crypter->descifrar($this->datos[ap2_ref]); 
	        		$this->datos[nombre_pac_referidor] = $apellido." ".$apellido2.", ".$nombre;
	        	}
                return $this->datos;
            }else
                return 0;   
        }
        function modificar ($datos)
        {
            $id = $datos[id_paciente];
            $idusr = $_SESSION[id_usr];
            foreach ($datos as $indice => $valor)
            {
                if(!empty($valor)){
                	switch($indice){
                		case "nombre":
                		case "apellido":
                		case "apellido2":
                		case "direccion":
                		case "cp":
                		case "telefono_fijo":
                		case "telefono_trabajo":
                		case "telefono_movil":
                		case "dni":
                		case "email":
                			$valor = $this->crypter->cifrar($valor);
                			break;
                		default:
                			break;
                	}
                	$parejas .= "$indice = '$valor', ";
                }
            } 
            $parejas = substr ($parejas, 0, strlen($parejas) -2);
            $sentencia = "update paciente set $parejas where id_paciente = $id and id_usuario = $idusr";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            if($this->datos == 1)
                $this->datos = $id;
            return $this->datos;     
        }
        function listado ($idarg, $pagina = -1)
        {    
            $idusr = $_SESSION[id_usr];
             
            $sentencia1 = "select id_paciente, nombre, apellido, apellido2, id_paciente_referidor from paciente where id_usuario = '$idusr'";
            $devuelto = $this->DBManager->recoger_datos ($sentencia1);
            if(is_array($devuelto))
            {
                $mitabla = "busqueda".$_SESSION[id_usr];
                $sentencia1 = "CREATE TEMPORARY TABLE IF NOT EXISTS $mitabla (
                    id_paciente int(10) unsigned not null,
                    nombre varchar(40),
                    apellido varchar(40),
                    apellido2 varchar(40)
                    )";
                $this->DBManager->hacer_peticion ($sentencia1);
                
                $this->datos = $devuelto[1];

                foreach ($this->datos as $paciente)
                {
                    $id = $paciente[id_paciente];
                    $nombre = $this->crypter->descifrar ($paciente[nombre]);
                    $apellido = $this->crypter->descifrar ($paciente[apellido]);
                    $apellido2 = $this->crypter->descifrar ($paciente[apellido2]); 
                         
                    $valores .= "($id, '$nombre', '$apellido', '$apellido2'), ";
                }
                
                $valores = substr ($valores, 0, strlen($valores) -2);
                
                $sentencia1 = "insert into $mitabla values $valores";
                $this->DBManager->hacer_peticion ($sentencia1);
                
                $sentencia = "select id_paciente, nombre, apellido, apellido2 from $mitabla order by apellido asc, apellido2 asc, nombre asc";
                
                if($pagina != -1)
                {   
                    $inf = $pagina * MAX_FILAS;
                    $sup = MAX_FILAS;
                    $sentencia .= " limit $inf, $sup";
                }
                $devolver = $this->DBManager->recoger_datos($sentencia);
                $sentencia = "drop temporary table if exists $mitabla";
                $this->DBManager->hacer_peticion($sentencia);
                
                return $devolver;
            }else
                return 0;         
        }
        function listaReferidos($id){
        	$sentencia = "select id_paciente, nombre, apellido, apellido2 from paciente where id_paciente_referidor = $id";
        	$this->datos = $this->DBManager->recoger_datos($sentencia);
        	if (is_array($this->datos)){
        		$devolver = $this->datos[1];
        		foreach($devolver as $linea => $datos){
        			$devolver[$linea][nombre] = $this->crypter->descifrar($devolver[$linea][nombre]);
        			$devolver[$linea][apellido] = $this->crypter->descifrar($devolver[$linea][apellido]);
        			$devolver[$linea][apellido2] = $this->crypter->descifrar($devolver[$linea][apellido2]);
        		}
        	} 
        		return $devolver;
        		
        }
        function buscaParaLista ($letra, $pagina = 0)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_paciente, nombre, apellido, apellido2, extension from paciente where id_usuario = '$idusr'";
            $datos = $this->DBManager->recoger_datos ($sentencia);
            if (is_array ($datos))
            {
                $mitabla = "busqueda".$_SESSION[id_usr];
                $sentencia1 = "CREATE TEMPORARY TABLE IF NOT EXISTS $mitabla ( 
                    id_paciente int(10) unsigned NOT NULL,
                    nombre varchar(40), 
                    apellido varchar (40),
                    apellido2 varchar (40),
                    extension varchar (25)
                    )";
                $this->DBManager->hacer_peticion ($sentencia1);
                
                $this->datos = $datos[1];
                foreach ($this->datos as $paciente)
                {
                    $id = $paciente[id_paciente];
                    $nombre = $this->crypter->descifrar ($paciente[nombre]);
                    $apellido = $this->crypter->descifrar ($paciente[apellido]);
                    $apellido2 = $this->crypter->descifrar ($paciente[apellido2]);
                    $extension = $paciente[extension];
                    
                    $nueva = strtoupper($apellido[0]);
                    $valor = ord($nueva);
                    if ($valor >= 128) 
                    {
                        if( (($valor >= 192) && ($valor <= 197)) || (($valor >= 224) && ($valor <= 229))) 
                            $nueva = "A";
                        if( (($valor >= 200) && ($valor <= 203)) || (($valor >= 232) && ($valor <= 235))) 
                            $nueva = "E";
                        if( (($valor >= 204) && ($valor <= 207)) || (($valor >= 236) && ($valor <= 239))) 
                            $nueva = "I";
                        if( (($valor >= 210) && ($valor <= 214)) || (($valor >= 242) && ($valor <= 246))) 
                            $nueva = "O";
                        if( (($valor >= 217) && ($valor <= 220)) || (($valor >= 249) && ($valor <= 252))) 
                            $nueva = "U";
                    }
                    
                    if ($nueva == $letra) { 
                        //Solo meto en la tabla aquellos registros que coinciden con la letra,
                        //no me hacen falta mas
                        $valores .= "($id, '$nombre', '$apellido', '$apellido2', '$extension'), "; 
                    }
                }
                $valores = substr($valores, 0, strlen($valores) -2);
                $sentencia1 = "insert into $mitabla values $valores";
                $this->DBManager->hacer_peticion ($sentencia1); 
                
                $inf = $pagina * MAX_FILAS;
                $sup = MAX_FILAS + 1;
                $sentencia = "select * from $mitabla order by apellido asc, apellido2 asc, nombre asc limit $inf, $sup";
                $devolver = $this->DBManager->recoger_datos ($sentencia);
                
                $sentencia = "drop temporary table if exists $mitabla";
                $this->DBManager->hacer_peticion ($sentencia);
                
                return $devolver;
            } else
                return 0;        
        }
        function buscar ($datos)
        {
            $idusr = $_SESSION[id_usr];
            $pagina = 0;
            if(is_array($datos))
            {
                foreach ($datos as $indice => $valor)
                {
                    if((strcmp($valor, ''))&&($valor))
                    {
                        switch($indice)
                        {
                            case "nombre":
                            case "apellido":
                            case "apellido2":
                                $parejas .= "$indice LIKE '%$valor%' and ";
                                break;
                            case "id_provincia":
                            case "id_paciente_referidor":
                                $parejas .= "$indice = '$valor' and ";
                                $tabla .= "$indice int(10) unsigned default null,";
                                $campos .= "$indice, ";
                                break;
                            case "id_usuario":
                                /*
                                * Solo se usa para el filtrado de la query inicial, luego no es 
                                * necesario.
                                */
                                break;
                            case "id_dr_referidor":
                                if (is_int($valor)){
                                    $parejas .= "$indice = '$valor' and ";   
                                } else {
                                    $parejas .= "$indice $valor and ";
                                }
                                
                                $tabla .= "$indice int(10) unsigned default null,";
                                $campos .= "$indice, ";
                                break;
                            case "observaciones":
                            case "alertas_medicas":
                                $parejas .= "$indice LIKE '%$valor%' and ";
                                $tabla .= "$indice text,";
                                $campos .= "$indice, ";
                                break;
                            case "pag":
                                $pagina = $valor;
                                break;
                            case "grupoImgs":
                                $grupoImgs = $valor;
                                break;
                            default:
                                $parejas .= "$indice LIKE '%$valor%' and ";
                                $tabla .= "$indice varchar(250) default null,";
                                $campos .= "$indice, ";
                                break;
                        }
                    }
                }
                $campos = ", ".$campos;
                $parejas = substr ($parejas, 0, strlen($parejas) -5);
                $tabla = ",".$tabla;
                $tabla = substr ($tabla, 0, strlen($tabla)-1);
                $campos = substr ($campos, 0, strlen($campos) -2);
            }
            
            if (isset($grupoImgs)) {
                $sentencia1 = "select distinct p.id_paciente, p.nombre, p.apellido, p.apellido2, p.extension $campos from paciente as p 
                    INNER JOIN imagen as img on (p.id_paciente = img.id_paciente) 
                    where p.id_usuario = $idusr and id_grupo_imagen = $grupoImgs";
            } else {
                $sentencia1 = "select id_paciente, nombre, apellido, apellido2, extension $campos from paciente where id_usuario = '$idusr'";
            }
            
            $devuelto = $this->DBManager->recoger_datos ($sentencia1);
            if(is_array($devuelto))
            {
                $mitabla = "busqueda".$_SESSION[id_usr];
                $sentencia1 = "CREATE TEMPORARY TABLE IF NOT EXISTS $mitabla (
                    id_paciente int(11) unsigned,
                    nombre varchar(255),
                    apellido varchar(255),
                    apellido2 varchar(255),
                    extension varchar(4)
                    $tabla)";
                $this->DBManager->hacer_peticion ($sentencia1);
                $this->datos = $devuelto[1];
                
                $valores = "(";
                foreach ($this->datos as $elemento => $array)
                {
                    foreach ($array as $indice => $valor)
                    {
                    	switch($indice){
                    		case "nombre":
                    		case "apellido":
                    		case "apellido2":
                    		case "direccion":
                    		case "cp":
                    		case "dni":
                    		case "telefono_fijo":
                    		case "telefono_trabajo":
                    		case "telefono_movil":
                    		case "email":
                    			$valores .= "'".$this->crypter->descifrar($valor)."', ";
                    			break;
                    		default:
                    			$valores .= "'".$valor."', ";
              					break;
                    	}
                    } 
                    $valores = substr ($valores, 0, strlen($valores)-2);
                    $valores .= "), ("; 
                }
                $valores = substr ($valores, 0, strlen($valores)-3);
               
                $sentencia1 = "insert into $mitabla values $valores";
                $this->DBManager->hacer_peticion ($sentencia1); 

                $inf = $pagina * MAX_FILAS;
                $sup = MAX_FILAS + 1;
                
                if (strlen ($parejas) > 0){
                    $sentencia = "select id_paciente, nombre, apellido, apellido2, extension from $mitabla where $parejas order by apellido asc, apellido2 asc, nombre asc limit $inf, $sup";
                } else {
                    $sentencia = "select id_paciente, nombre, apellido, apellido2, extension from $mitabla order by apellido asc, apellido2 asc, nombre asc limit $inf, $sup";
                }
                $devolver = $this->DBManager->recoger_datos($sentencia);

                $sentencia = "drop temporary table if exists $mitabla";
                $this->DBManager->hacer_peticion($sentencia);
                 
                return $devolver;
            }else
                return 0;    
        }
        function iniciales ()
        {
            $idusr = $_SESSION[id_usr];
            $sentencia1 = "select apellido from paciente where id_usuario = '$idusr'";
            $devuelto = $this->DBManager->recoger_datos ($sentencia1);
            if(is_array($devuelto))
            {
                $mitabla = "busqueda".$_SESSION[id_usr];
                $sentencia1 = "CREATE TEMPORARY TABLE IF NOT EXISTS $mitabla 
                    ( apellido VARCHAR(40) NOT NULL )";
                $this->DBManager->hacer_peticion ($sentencia1);
                
                $this->datos = $devuelto[1];
                
                foreach ($this->datos as $array)
                {    
                    $valor .= "('".$this->crypter->descifrar ($array[apellido])."'), ";
                }
				$valor = substr($valor, 0, strlen($valor) -2);
                
                $sentencia1 = "insert into $mitabla values $valor";
                $this->DBManager->hacer_peticion ($sentencia1);  

                $sentencia = "select distinct apellido from $mitabla order by apellido asc";
                $devolver = $this->DBManager->recoger_datos($sentencia);

                $sentencia = "drop temporary table if exists $mitabla";
                $this->DBManager->hacer_peticion($sentencia);
                 
                return $devolver;
            }else
                return 0;   
        }
        function bloquear ($datos)
        {
          
        }  
    }
?>