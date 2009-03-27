<?php
/**
 * Fichero que recoje la implementacion de la clase Copier.
 *
 * @package Acceso a Datos
 * @subpackage Admin
 * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
 * @version: 1.0 (23 - Mayo - 2008)
 */

/**
 * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
 */
include_once PATH_BASE."src/db/DAO.inc";

/**
 *  Clase que se encarga de recoger todos los datos asociados a un usuario para la tabla
 *  que se especifica. Empleada para realizar las copias de seguridad de los datos.
 */
class Copier extends DAO
{

	function Copier()
	{
		parent::DAO();
		return;
	}
	function nuevo ($datos)
	{
		echo "nuevo";
		/*$sent = substr($datos, 12, 8);
		 if($sent == "paciente")
		 echo $datos."<br />";*/
		//echo $datos;
		$datos = preg_replace('/,[\s*](?=,)/', ', NULL', $datos, -1);
		$datos = preg_replace('/,[\s*]\)/', ', NULL)', $datos, -1);
		/* $sent = substr($datos, 12, 8);
		 if($sent == "paciente")
		 echo $datos."<br />"; */

		$sent = substr($datos, 12, 12);
		//echo "a".$sent."a<br />";
		/*if($sent == "linea_visita")
		 echo $sentencia."<br />"; */
		$retorn = $this->DBManager->hacer_peticion($datos);
		return $retorn;
	}
	function borrar ($id)
	{
		$sentencia = "delete from usuario where id_usuario = $id";
		$this->datos = $this->DBManager->hacer_peticion($sentencia);
		return $this->datos;
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

	}
	function bloquear ($datos)
	{

	}
	/**
	 * Funcion que devuelve el numero de registros de la tabla
	 * @param String nombre de la tabla que queremos consultar
	 * @return Int numero de registros que hay en la tabla.
	 */
	function consultar ($tabla)
	{
		$idusr = $_SESSION[id_usr];
		$sentencia = "select COUNT(*) as total from $tabla where id_usuario = '$idusr'";
		return $this->DBManager->recoger_datos($sentencia);
	}
	function copiar ($tabla, $inf)
	{
		$idusr = $_SESSION[id_usr];
		$sup = $inf + 100;
		switch ($tabla)
		{
			case "asistente":
				$orden = "id_visita_medica asc, id_personal asc";
				break;
			case "colaborador":
				$orden = "id_visita_medica asc, id_dr_colaborador asc";
				break;
			case "consentimiento_revocado":
				$orden = "id_consentimiento asc";
				break;
			case "linea_factura":
			case "linea_presupuesto":
			case "linea_visita":
				$orden = "id_linea asc";
				break;
			case "opciones":
				$orden = "id_opts asc";
				break;
			case "pagopac":
				$orden = "id_pago asc";
				break;
			default:
				$orden = "id_$tabla asc";
				break;
		}
		$sentencia = "select * from $tabla where id_usuario = $idusr order by $orden limit $inf, $sup";
		$devuelto = $this->DBManager->recoger_datos ($sentencia);
		if(is_array($devuelto))
		{
			$this->datos = $devuelto[1];
			$this->datos = $this->descifrar($this->datos, $tabla);

			return array ($devuelto[0], $this->datos);
		}else
			return $devuelto;
	}
	function script($script)
	{
		$sentencias = file_get_contents($script);
		$partes = split("insert", $sentencias);
		try{
			$this->start();
			echo "voy";
			$this->borrar($_SESSION[id_usr]);
			foreach ($partes as $sql){
				if(!empty($sql)){
					if($this->nuevo (rtrim("insert ".$sql)) < 0){
						echo "rollback!!!!";
						$this->rollback();
						return -1;
					}
				}
			}
		} catch (Exception $e) {
			echo "Excepcion: ".print_r($e);
			$this->rollback();
		}
		$this->commit();
	}
	
	function migrate ($tabla, $fich){
		$idusr = $_SESSION[id_usr];
		$sentencia = "select * from $tabla where id_usuario = $idusr";
		$this->datos = $this->DBManager->recoger_datos($sentencia);

		if(is_array($this->datos)){
			$datos = $this->datos[1];
			switch($tabla){
				case "usuario":
					foreach ($datos as $elemento){
						$temp = array();
						$temp[id_usuario] = $elemento[id_usuario];
						$temp[nombre] = $this->crypter->descifrar2 ($elemento[nombre], true);
						$temp[apellido] = $this->crypter->descifrar2 ($elemento[apellido], true);
						$temp[apellido2] = $this->crypter->descifrar2 ($elemento[apellido2], true);
						$temp[login] = $this->crypter->descifrar2 ($elemento[login], true);
						$temp[telefono] = $this->crypter->descifrar2 ($elemento[telefono], true);
						$temp[email] = $this->crypter->descifrar2 ($elemento[email], true);
						$temp[privilegios] = $this->crypter->descifrar2 ($elemento[privilegios], true);
						$temp[fin_suscripcion] = $this->crypter->descifrar2 ($elemento[fin_suscripcion], true);

						$sentencia = "update $tabla set".
							" nombre = ".$temp[nombre].
							", apellido = ".$temp[apellido].
							", apellido2 = ".$temp[apellido2].
							", login = ".$temp[login].
							", telefono = ".$temp[telefono].
							", email = ".$temp[email].
							", privilegios = ".$temp[privilegios].
							", fin_suscripcion = ".$temp[fin_suscripcion].
							" where id_usuario = ".$temp[id_usuario].";\n";
						fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
					}
					break;
				case "paciente":
					foreach ($datos as $elemento){
						$temp = array();
						$temp[id_paciente] = $elemento[id_paciente];
						$temp[fecha_alta] = $this->crypter->descifrar2 ($elemento[fecha_alta], true);
						$temp[fecha_nacimiento] = $this->crypter->descifrar2 ($elemento[fecha_nacimiento], true);
						$temp[extension] = $this->crypter->descifrar2 ($elemento[extension], true);
						$temp[alertas_medicas] = $this->crypter->descifrar2 ($elemento[alertas_medicas], true);
						$temp[observaciones] = $this->crypter->descifrar2 ($elemento[observaciones], true);
						$temp[profesion] = $this->crypter->descifrar2 ($elemento[profesion], true);
						$temp[ciudad] = $this->crypter->descifrar2 ($elemento[ciudad], true);
						$sentencia = "update $tabla set".
							" fecha_alta = ".$temp[fecha_alta].
							", fecha_nacimiento = ".$temp[fecha_nacimiento].
							", extension = ".$temp[extension].
							", alertas_medicas = ".$temp[alertas_medicas].
							", observaciones = ".$temp[observaciones].
							", profesion = ".$temp[profesion].
							", ciudad = ".$temp[ciudad].
							" where id_paciente = ".$temp[id_paciente].";\n";
						fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
					}
					break;
				case "personal":
					foreach($datos as $elemento)
					{
						$temp = array();
						$temp[id_personal] = $elemento[id_personal];
						$temp[nombre] = $this->crypter->descifrar2 ($elemento[nombre], true);
						$temp[apellido] = $this->crypter->descifrar2 ($elemento[apellido], true);
						$temp[apellido2] = $this->crypter->descifrar2 ($elemento[apellido2], true);
						$temp[dni] = $this->crypter->descifrar2 ($elemento[dni], true);
						$temp[direccion] = $this->crypter->descifrar2 ($elemento[direccion], true);
						$temp[cp] = $this->crypter->descifrar2 ($elemento[cp], true);
						$temp[ciudad] = $this->crypter->descifrar2 ($elemento[ciudad], true);
						$temp[telefono] = $this->crypter->descifrar2 ($elemento[telefono], true);
						$temp[movil] = $this->crypter->descifrar2 ($elemento[movil], true);
						$temp[email] = $this->crypter->descifrar2 ($elemento[email], true);
						$temp[num_colegiado] = $this->crypter->descifrar2 ($elemento[num_colegiado], true);
						$temp[especialidad] = $this->crypter->descifrar2 ($elemento[especialidad], true);
						$temp[fecha_alta] = $this->crypter->descifrar2 ($elemento[fecha_alta], true);
						$temp[curriculum] = $this->crypter->descifrar2 ($elemento[curriculum], true);
						$temp[extension] = $this->crypter->descifrar2 ($elemento[extension], true);
						$temp[login] = $this->crypter->descifrar2 ($elemento[login], true);

						$sentencia = "update $tabla set".
							" nombre = ".$temp[nombre].
							", apellido = ".$temp[apellido2].
							", apellido2 = ".$temp[apellido].
							", dni = ".$temp[dni].
							", direccion = ".$temp[direccion].
							", cp = ".$temp[cp].
							", ciudad = ".$temp[ciudad].
							", telefono = ".$temp[telefono].
							", movil = ".$temp[movil].
							", email = ".$temp[email].
							", num_colegiado = ".$temp[num_colegiado].
							", especialidad = ".$temp[especialidad].
							", fecha_alta = ".$temp[fecha_alta].
							", curriculum = ".$temp[curriculum].
							", extension = ".$temp[extension].
							", login = ".$temp[login].
							" where id_personal = ".$temp[id_personal].";\n";
						fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
					}
					break;
				case "dr_externo":
					foreach($datos as $elemento)
					{
						$temp = array();
						$temp[id_dr_externo] = $elemento[id_dr_externo];
						$temp[nombre] = $this->crypter->descifrar2 ($elemento[nombre], true);
						$temp[apellido] = $this->crypter->descifrar2 ($elemento[apellido], true);
						$temp[apellido2] = $this->crypter->descifrar2 ($elemento[apellido2], true);
						$temp[dni] = $this->crypter->descifrar2 ($elemento[dni], true);
						$temp[direccion] = $this->crypter->descifrar2 ($elemento[direccion], true);
						$temp[cp] = $this->crypter->descifrar2 ($elemento[cp], true);
						$temp[ciudad] = $this->crypter->descifrar2 ($elemento[ciudad], true);
						$temp[telefono_clinica] = $this->crypter->descifrar2 ($elemento[telefono_clinica], true);
						$temp[telefono_movil] = $this->crypter->descifrar2 ($elemento[telefono_movil], true);
						$temp[telefono_casa] = $this->crypter->descifrar2 ($elemento[telefono_casa], true);
						$temp[fax] = $this->crypter->descifrar2 ($elemento[fax], true);
						$temp[email] = $this->crypter->descifrar2 ($elemento[email], true);
						$temp[especialidad] = $this->crypter->descifrar2 ($elemento[especialidad], true);
						$temp[fecha_nacimiento] = $this->crypter->descifrar2 ($elemento[fecha_nacimiento], true);

						$sentencia = "update $tabla set".
							" nombre = ".$temp[nombre].
							", apellido = ".$temp[apellido].
							", apellido2 = ".$temp[apellido2].
							", dni = ".$temp[dni].
							", direccion = ".$temp[direccion].
							", cp = ".$temp[cp].
							", ciudad = ".$temp[ciudad].
							", telefono_clinica = ".$temp[telefono_clinica].
							", telefono_movil = ".$temp[telefono_movil].
							", telefono_casa = ".$temp[telefono_casa].
							", fax = ".$temp[fax].
							", email = ".$temp[email].
							", especialidad = ".$temp[especialidad].
							", fecha_nacimiento = ".$temp[fecha_nacimiento].
							" where id_dr_externo = ".$temp[id_dr_externo].";\n";
						fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
					}
					break;
				case "opciones":
					foreach($datos as $elemento)
					{
						$temp = array();
						$temp[id_opts] = $elemento[id_opts];
						$temp[nombre] = $this->crypter->descifrar2 ($elemento[nombre], true);
						$temp[especialidad] = $this->crypter->descifrar2 ($elemento[especialidad], true);
						$temp[nif] = $this->crypter->descifrar2 ($elemento[nif], true);
						$temp[direccion] = $this->crypter->descifrar2 ($elemento[direccion], true);
						$temp[telefono] = $this->crypter->descifrar2 ($elemento[telefono], true);
						$temp[cp] = $this->crypter->descifrar2 ($elemento[cp], true);
						$temp[ciudad] = $this->crypter->descifrar2 ($elemento[ciudad], true);
						$temp[gabinetes] = $this->crypter->descifrar2 ($elemento[gabinetes], false);
						$temp[reg_sanidad] = $this->crypter->descifrar2 ($elemento[reg_sanidad], true);
						$temp[extension] = $this->crypter->descifrar2 ($elemento[extension], true);
						$temp[extensionf] = $this->crypter->descifrar2 ($elemento[extensionf], true);

						$sentencia = "update $tabla set".
							" nombre = ".$temp[nombre].
							", especialidad = ".$temp[especialidad].
							", nif = ".$temp[nif].
							", direccion = ".$temp[direccion].
							", telefono = ".$temp[telefono].
							", cp = ".$temp[cp].
							", ciudad = ".$temp[ciudad].
							", gabinetes = ".$temp[gabinetes].
							", reg_sanidad = ".$temp[reg_sanidad].
							", extension = ".$temp[extension].
							", extensionf = ".$temp[extensionf].
							" where id_opts = ".$temp[id_opts].";\n";
						fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
					}
					break;
				case "servicio":
					foreach($datos as $elemento)
					{
						$temp = array();
						$temp[id_servicio] = $elemento[id_servicio];
						$temp[precio_unitario] = $this->crypter->descifrar2 ($elemento[precio_unitario], false);
						$sentencia = "update $tabla set".
							" precio_unitario = ".$temp[precio_unitario].
							" where id_servicio = ".$temp[id_servicio].";\n";
						fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
					}
					break;
				case "tipo_imagen":
					foreach($datos as $elemento)
					{
						$temp = array();
						$temp[id_tipo_imagen] = $elemento[id_tipo_imagen];
						$temp[nombre] = $this->crypter->descifrar2 ($elemento[nombre], true);
						$temp[descripcion] = $this->crypter->descifrar2 ($elemento[descripcion], true);
						$sentencia = "update $tabla set".
							" nombre = ".$temp[nombre].
							", descripcion = ".$temp[descripcion].
							" where id_tipo_imagen = ".$temp[id_tipo_imagen].";\n";
						fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
					}
				break;
				case "tipo_consentimiento":
					foreach($datos as $elemento)
					{
						$temp = array();
						$temp[id_tipo_consentimiento] = $elemento[id_tipo_consentimiento];
						$temp[nombre] = $this->crypter->descifrar2 ($elemento[nombre], true);
						$temp[texto_incluido] = $this->crypter->descifrar2 ($elemento[texto_incluido], true);
						$temp[descripcion] = $this->crypter->descifrar2 ($elemento[descripcion], true);
						$sentencia = "update $tabla set".
							" nombre = ".$temp[nombre].
							", texto_incluido = ".$temp[texto_incluido].
							", descripcion = ".$temp[descripcion].
							" where id_tipo_consentimiento = ".$temp[id_tipo_consentimiento].";\n";
						fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
					}
				break;
				case "tipo_receta":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_tipo_receta] = $elemento[id_tipo_receta];
					$temp[nombre] = $this->crypter->descifrar2 ($elemento[nombre], true);
					$temp[texto] = $this->crypter->descifrar2 ($elemento[texto], true);
					$temp[resumen] = $this->crypter->descifrar2 ($elemento[resumen], true);
					$sentencia = "update $tabla set".
						" nombre = ".$temp[nombre].
						", texto = ".$temp[texto].
						", resumen = ".$temp[resumen].
						" where id_tipo_receta = ".$temp[id_tipo_receta].";\n";
					fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
				}
				break;
			case "log":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_log] = $elemento[id_log];
					$temp[nombre] = $this->crypter->descifrar2 ($elemento[nombre], true);
					$temp[detalles] = $this->crypter->descifrar2 ($elemento[detalles], true);
					$sentencia = "update $tabla set".
						" nombre = ".$temp[nombre].
						", detalles = ".$temp[detalles].
						" where id_log = ".$temp[id_log].";\n";
					fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
				}
				break;
			case "pagopac":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_pago] = $elemento[id_pago];
					$temp[fecha] = $this->crypter->descifrar2 ($elemento[fecha], true);
					$temp[total_efectivo] = $this->crypter->descifrar2 ($elemento[total_efectivo], false);
					$temp[total_tarjeta] = $this->crypter->descifrar2 ($elemento[total_tarjeta], false);
					$sentencia = "update $tabla set".
						" fecha = ".$temp[fecha].
						", total_efectivo = ".$temp[total_efectivo].
						", total_tarjeta = ".$temp[total_tarjeta].
						" where id_pago = ".$temp[id_pago].";\n";
					fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
				}
				break;
			case "cita":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_cita] = $elemento[id_cita];
					$temp[fecha] = $this->crypter->descifrar2 ($elemento[fecha], true);
					$temp[hora] = $this->crypter->descifrar2 ($elemento[hora], true);
					$temp[gabinete] = $this->crypter->descifrar2 ($elemento[gabinete], false);
					$temp[duracion] = $this->crypter->descifrar2 ($elemento[duracion], false);
					$temp[observaciones] = $this->crypter->descifrar2 ($elemento[observaciones], true);
					$temp[tipo] = $this->crypter->descifrar2 ($elemento[tipo], true);
					$sentencia = "update $tabla set".
						" fecha = ".$temp[fecha].
						", hora = ".$temp[hora].
						", duracion = ".$temp[duracion].
						", observaciones = ".$temp[observaciones].
						", tipo = ".$temp[tipo].
						", gabinete = ".$temp[gabinete].
						" where id_cita = ".$temp[id_cita].";\n";
					fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
				}
				break;
			case "visita":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_visita] = $elemento[id_visita];
					$temp[fecha] = $this->crypter->descifrar2 ($elemento[fecha], true);
					$temp[asiento] = $this->crypter->descifrar2 ($elemento[asiento], true);
					$temp[motivo] = $this->crypter->descifrar2 ($elemento[motivo], true);
					$temp[diagnostico] = $this->crypter->descifrar2 ($elemento[diagnostico], true);
					$temp[precio] = $this->crypter->descifrar2 ($elemento[precio], false);
					$temp[observaciones] = $this->crypter->descifrar2 ($elemento[observaciones], true);
					$sentencia = "update $tabla set".
						" fecha = ".$temp[fecha].
						", asiento = ".$temp[asiento].
						", motivo = ".$temp[motivo].
						", diagnostico = ".$temp[diagnostico].
						", precio = ".$temp[precio].
						", observaciones = ".$temp[observaciones].
						" where id_visita = ".$temp[id_visita].";\n";
					fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
				}
				break;
			case "factura":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_factura] = $elemento[id_factura];
					$temp[fecha] = $this->crypter->descifrar2 ($elemento[fecha], true);
					$temp[numero] = $this->crypter->descifrar2 ($elemento[numero], true);
					$temp[total] = $this->crypter->descifrar2 ($elemento[total], false);
					$sentencia = "update $tabla set".
						" fecha = ".$temp[fecha].
						", numero = ".$temp[numero].
						", total = ".$temp[total].
						" where id_factura = ".$temp[id_factura].";\n";
					fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
				}
				break;
			case "presupuesto":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_presupuesto] = $elemento[id_presupuesto];
					$temp[fecha] = $this->crypter->descifrar2 ($elemento[fecha], true);
					$temp[numero] = $this->crypter->descifrar2 ($elemento[numero], true);
					$temp[validez] = $this->crypter->descifrar2 ($elemento[validez], true);
					$temp[duracion] = $this->crypter->descifrar2 ($elemento[duracion], true);
					$temp[total] = $this->crypter->descifrar2 ($elemento[total], false);
					$temp[objetivo] = $this->crypter->descifrar2 ($elemento[objetivo], true);
					$temp[extension] = $this->crypter->descifrar2 ($elemento[extension], true);
					$sentencia = "update $tabla set".
						" fecha = ".$temp[fecha].
						", numero = ".$temp[numero].
						", total = ".$temp[total].
						", validez = ".$temp[validez].
						", duracion = ".$temp[duracion].
						", objetivo = ".$temp[objetivo].
						", extension = ".$temp[extension].
						" where id_presupuesto = ".$temp[id_presupuesto].";\n";
					fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
				}
				break;
			case "consentimiento":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_consentimiento] = $elemento[id_consentimiento];
					$temp[fecha] = $this->crypter->descifrar2 ($elemento[fecha], true);
					$temp[extension] = $this->crypter->descifrar2 ($elemento[extension], true);
					$sentencia = "update $tabla where".
						" fecha = ".$temp[fecha].
						", extension = ".$temp[extension].
						" where id_consentimiento = ".$temp[id_consentimiento].";\n";
					fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
				}
				break;
			case "consentimiento_revocado":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_consentimiento] = $elemento[id_consentimiento];
					$temp[fecha] = $this->crypter->descifrar2 ($elemento[fecha], true);
					$temp[fechar] = $this->crypter->descifrar2 ($elemento[fechar], true);
					$temp[extension] = $this->crypter->descifrar2 ($elemento[extension], true);
					$temp[extensionr] = $this->crypter->descifrar2 ($elemento[extensionr], true);
					$sentencia = "update $tabla where".
						" fecha = ".$temp[fecha].
						", extension = ".$temp[extension].
						", fechar = ".$temp[fechar].
						", extensionr = ".$temp[extensionr].
						" where id_consentimiento = ".$temp[id_consentimiento].";\n";
					fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
				}
				break;
			case "receta":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_receta] = $elemento[id_receta];
					$temp[observaciones] = $this->crypter->descifrar2 ($elemento[observaciones], true);
					$temp[texto] = $this->crypter->descifrar2 ($elemento[texto], true);
					$temp[resumen] = $this->crypter->descifrar2 ($elemento[resumen], true);
					$sentencia = "update $tabla set".
						" observaciones = ".$temp[observaciones].
						", texto = ".$temp[texto].
						", resumen = ".$temp[resumen].
						" where id_receta = ".$temp[id_receta].";\n";
					fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
				}
				break;
			case "linea_factura":
			case "linea_presupuesto":
			case "linea_visita":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_linea] = $elemento[id_linea];
					$temp[cantidad] = $this->crypter->descifrar2 ($elemento[cantidad], false);
					$temp[total] = $this->crypter->descifrar2 ($elemento[total], false);
					$sentencia = "update $tabla set".
						" cantidad = ".$temp[cantidad].
						", total = ".$temp[total].
						" where id_linea = ".$temp[id_linea].";\n";
					fprintf($fich, "%s", $this->cp1252_to_utf8($sentencia));
				}
				break;
			}
		}
	}
	function cp1252_to_utf8($str) {
//	    $cp1252_map = array ("\xc2\x80" => "\xe2\x82\xac",
//	    "\xc2\x82" => "\xe2\x80\x9a",
//	    "\xc2\x83" => "\xc6\x92",    
//	    "\xc2\x84" => "\xe2\x80\x9e",
//	    "\xc2\x85" => "\xe2\x80\xa6",
//	    "\xc2\x86" => "\xe2\x80\xa0",
//	    "\xc2\x87" => "\xe2\x80\xa1",
//	    "\xc2\x88" => "\xcb\x86",
//	    "\xc2\x89" => "\xe2\x80\xb0",
//	    "\xc2\x8a" => "\xc5\xa0",
//	    "\xc2\x8b" => "\xe2\x80\xb9",
//	    "\xc2\x8c" => "\xc5\x92",
//	    "\xc2\x8e" => "\xc5\xbd",
//	    "\xc2\x91" => "\xe2\x80\x98",
//	    "\xc2\x92" => "\xe2\x80\x99",
//	    "\xc2\x93" => "\xe2\x80\x9c",
//	    "\xc2\x94" => "\xe2\x80\x9d",
//	    "\xc2\x95" => "\xe2\x80\xa2",
//	    "\xc2\x96" => "\xe2\x80\x93",
//	    "\xc2\x97" => "\xe2\x80\x94",
//	
//	    "\xc2\x98" => "\xcb\x9c",
//	    "\xc2\x99" => "\xe2\x84\xa2",
//	    "\xc2\x9a" => "\xc5\xa1",
//	    "\xc2\x9b" => "\xe2\x80\xba",
//	    "\xc2\x9c" => "\xc5\x93",
//	    "\xc2\x9e" => "\xc5\xbe",
//	    "\xc2\x9f" => "\xc5\xb8");
//	    
//    	return strtr ( utf8_encode ( $str ), $cp1252_map );	
		return $str;
	}
	function descifrar($datos, $tabla)
	{
		$final = array();
		//echo "descifrando $tabla<br />";
		switch($tabla)
		{
			case "usuario":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[nombre] = $this->crypter->descifrar ($elemento[nombre], true);
					$temp[apellido] = $this->crypter->descifrar ($elemento[apellido], true);
					$temp[apellido2] = $this->crypter->descifrar ($elemento[apellido2], true);
					$temp[login] = $this->crypter->descifrar ($elemento[login], true);
					$temp[password] = "'".$this->crypter->corregir ($elemento[password])."'";
					$temp[telefono] = $this->crypter->descifrar ($elemento[telefono], true);
					$temp[email] = $this->crypter->descifrar ($elemento[email], true);
					$temp[privilegios] = $this->crypter->descifrar ($elemento[privilegios], true);
					$temp[fin_suscripcion] = $this->crypter->descifrar ($elemento[fin_suscripcion], true);
					array_push ($final, $temp);
				}
				break;
			case "personal":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_personal] = $elemento[id_personal];
					$temp[nombre] = $this->crypter->descifrar ($elemento[nombre], true);
					$temp[apellido] = $this->crypter->descifrar ($elemento[apellido], true);
					$temp[apellido2] = $this->crypter->descifrar ($elemento[apellido2], true);
					$temp[dni] = $this->crypter->descifrar ($elemento[dni], true);
					$temp[direccion] = $this->crypter->descifrar ($elemento[direccion], true);
					$temp[cp] = $this->crypter->descifrar ($elemento[cp], true);
					$temp[ciudad] = $this->crypter->descifrar ($elemento[ciudad], true);
					$temp[id_provincia] = $elemento[id_provincia];
					$temp[telefono] = $this->crypter->descifrar ($elemento[telefono], true);
					$temp[movil] = $this->crypter->descifrar ($elemento[movil], true);
					$temp[email] = $this->crypter->descifrar ($elemento[email], true);
					$temp[num_colegiado] = $this->crypter->descifrar ($elemento[num_colegiado], true);
					$temp[especialidad] = $this->crypter->descifrar ($elemento[especialidad], true);
					$temp[fecha_alta] = $this->crypter->descifrar ($elemento[fecha_alta], true);
					$temp[curriculum] = $this->crypter->descifrar ($elemento[curriculum], true);
					$temp[extension] = $this->crypter->descifrar ($elemento[extension], true);
					$temp[login] = $this->crypter->descifrar ($elemento[login], true);
					$temp[password] = "'".$this->crypter->corregir ($elemento[password])."'";
					$temp[privilegios] = "'".$this->crypter->corregir ($elemento[privilegios])."'";
					$temp[id_usuario] = $elemento[id_usuario];
					array_push ($final, $temp);
				}
				break;
			case "dr_externo":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_dr_externo] = $elemento[id_dr_externo];
					$temp[nombre] = $this->crypter->descifrar ($elemento[nombre], true);
					$temp[apellido] = $this->crypter->descifrar ($elemento[apellido], true);
					$temp[apellido2] = $this->crypter->descifrar ($elemento[apellido2], true);
					$temp[dni] = $this->crypter->descifrar ($elemento[dni], true);
					$temp[direccion] = $this->crypter->descifrar ($elemento[direccion], true);
					$temp[cp] = $this->crypter->descifrar ($elemento[cp], true);
					$temp[ciudad] = $this->crypter->descifrar ($elemento[ciudad], true);
					$temp[id_provincia] = $elemento[id_provincia];
					$temp[telefono_clinica] = $this->crypter->descifrar ($elemento[telefono_clinica], true);
					$temp[telefono_movil] = $this->crypter->descifrar ($elemento[telefono_movil], true);
					$temp[telefono_casa] = $this->crypter->descifrar ($elemento[telefono_casa], true);
					$temp[fax] = $this->crypter->descifrar ($elemento[fax], true);
					$temp[email] = $this->crypter->descifrar ($elemento[email], true);
					$temp[especialidad] = $this->crypter->descifrar ($elemento[especialidad], true);
					$temp[fecha_nacimiento] = $this->crypter->descifrar ($elemento[fecha_nacimiento], true);
					$temp[id_usuario] = $elemento[id_usuario];
					array_push ($final, $temp);
				}
				break;
			case "opciones":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_opts] = $elemento[id_opts];
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[nombre] = $this->crypter->descifrar ($elemento[nombre], true);
					$temp[especialidad] = $this->crypter->descifrar ($elemento[especialidad], true);
					$temp[nif] = $this->crypter->descifrar ($elemento[nif], true);
					$temp[direccion] = $this->crypter->descifrar ($elemento[direccion], true);
					$temp[telefono] = $this->crypter->descifrar ($elemento[telefono], true);
					$temp[cp] = $this->crypter->descifrar ($elemento[cp], true);
					$temp[ciudad] = $this->crypter->descifrar ($elemento[ciudad], true);
					$temp[id_provincia] = $elemento[id_provincia];
					$temp[gabinetes] = $this->crypter->descifrar ($elemento[gabinetes], false);
					$temp[reg_sanidad] = $this->crypter->descifrar ($elemento[reg_sanidad], true);
					$temp[extension] = $this->crypter->descifrar ($elemento[extension], true);
					$temp[extensionf] = $this->crypter->descifrar ($elemento[extensionf], true);
					array_push ($final, $temp);
				}
				break;
			case "servicio":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_servicio] = $elemento[id_servicio];
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[nombre] = "'".$this->crypter->corregir ($elemento[nombre])."'";
					$temp[precio_unitario] = $this->crypter->descifrar ($elemento[precio_unitario], false);
					array_push ($final, $temp);
				}
				break;
			case "tipo_imagen":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_tipo_imagen] = $elemento[id_tipo_imagenrvicio];
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[nombre] = $this->crypter->descifrar ($elemento[nombre], true);
					$temp[descripcion] = $this->crypter->descifrar ($elemento[descripcion], true);
					array_push ($final, $temp);
				}
				break;
			case "tipo_consentimiento":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_tipo_consentimiento] = $elemento[id_tipo_consentimiento];
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[nombre] = $this->crypter->descifrar ($elemento[nombre], true);
					$temp[texto_incluido] = $this->crypter->descifrar ($elemento[texto_incluido], true);
					$temp[descripcion] = $this->crypter->descifrar ($elemento[descripcion], true);
					array_push ($final, $temp);
				}
				break;
			case "tipo_receta":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_tipo_receta] = $elemento[id_tipo_receta];
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[nombre] = $this->crypter->descifrar ($elemento[nombre], true);
					$temp[texto] = $this->crypter->descifrar ($elemento[texto], true);
					$temp[resumen] = $this->crypter->descifrar ($elemento[resumen], true);
					array_push ($final, $temp);
				}
				break;
			case "pedido":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_pedido] = $elemento[id_pedido];
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[numero] = $this->crypter->descifrar ($elemento[numero], true);
					$temp[fecha_pedido] = $this->crypter->descifrar ($elemento[fecha_pedido], true);
					$temp[fecha_recibido] = $this->crypter->descifrar ($elemento[fecha_recibido], true);
					$temp[proveedor] = $this->crypter->descifrar ($elemento[proveedor], true);
					$temp[observaciones] = $this->crypter->descifrar ($elemento[observaciones], true);
					array_push ($final, $temp);
				}
				break;
			case "log":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_log] = $elemento[id_log];
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_personal] = $elemento[id_personal];
					$temp[id_tipo_log] = $elemento[id_tipo_log];
					$temp[fecha] = "'".$elemento[fecha]."'";
					$temp[nombre] = $this->crypter->descifrar ($elemento[nombre], true);
					$temp[detalles] = $this->crypter->descifrar ($elemento[detalles], true);
					array_push ($final, $temp);
				}
				break;
			case "paciente":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_paciente] = $elemento[id_paciente];
					$temp[nombre] = "'".$this->crypter->corregir ($elemento[nombre])."'";
					$temp[apellido] = "'".$this->crypter->corregir ($elemento[apellido])."'";
					$temp[apellido2] = "'".$this->crypter->corregir ($elemento[apellido2])."'";
					$temp[dni] = "'".$this->crypter->corregir ($elemento[dni])."'";
					$temp[direccion] = "'".$this->crypter->corregir ($elemento[direccion])."'";
					$temp[cp] = "'".$this->crypter->corregir ($elemento[cp])."'";
					$temp[ciudad] = "'".$this->crypter->corregir ($elemento[ciudad])."'";
					$temp[id_provincia] = $elemento[id_provincia];
					$temp[telefono_fijo] = "'".$this->crypter->corregir ($elemento[telefono_fijo])."'";
					$temp[telefono_movil] = "'".$this->crypter->corregir ($elemento[telefono_movil])."'";
					$temp[telefono_trabajo] = "'".$this->crypter->corregir ($elemento[telefono_trabajo])."'";
					$temp[profesion] = "'".$this->crypter->corregir ($elemento[profesion])."'";
					$temp[fecha_nacimiento] = "'".$this->crypter->corregir ($elemento[fecha_nacimiento])."'";
					$temp[email] = "'".$this->crypter->corregir ($elemento[email])."'";
					$temp[alertas_medicas] = "'".$this->crypter->corregir ($elemento[alertas_medicas])."'";
					$temp[alto_riesgo] = "'".$this->crypter->corregir ($elemento[alto_riesgo])."'";
					$temp[fecha_alta] = $this->crypter->descifrar ($elemento[fecha_alta], true);
					$temp[observaciones] = "'".$this->crypter->corregir ($elemento[observaciones])."'";
					$temp[extension] = $this->crypter->descifrar ($elemento[extension], true);
					$temp[id_paciente_referidor] = $elemento[id_paciente_referidor];
					$temp[id_dr_referidor] = $elemento[id_dr_referidor];
					$temp[id_usuario] = $elemento[id_usuario];
					array_push ($final, $temp);
				}
				break;
			case "pagopac":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_pago] = $elemento[id_pago];
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_paciente] = $elemento[id_paciente];
					$temp[fecha] = $this->crypter->descifrar ($elemento[fecha], true);
					$temp[total_efectivo] = $this->crypter->descifrar ($elemento[total_efectivo], false);
					$temp[total_tarjeta] = $this->crypter->descifrar ($elemento[total_tarjeta], false);
					array_push ($final, $temp);
				}
				break;
			case "cita":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_cita] = $elemento[id_cita];
					$temp[fecha] = $this->crypter->descifrar ($elemento[fecha], true);
					$temp[hora] = $this->crypter->descifrar ($elemento[hora], true);
					$temp[duracion] = $this->crypter->descifrar ($elemento[duracion], false);
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_paciente] = $elemento[id_paciente];
					$temp[bloqueado] = $elemento[bloqueado];
					$temp[color] = "'".$elemento[color]."'";
					$temp[observaciones] = $this->crypter->descifrar ($elemento[observaciones], true);
					$temp[tipo] = $this->crypter->descifrar ($elemento[tipo], true);
					array_push ($final, $temp);
				}
				break;
			case "visita":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_visita] = $elemento[id_visita];
					$temp[fecha] = $this->crypter->descifrar ($elemento[fecha], true);
					$temp[asiento] = $this->crypter->descifrar ($elemento[asiento], false);
					$temp[motivo] = $this->crypter->descifrar ($elemento[motivo], true);
					$temp[diagnostico] = $this->crypter->descifrar ($elemento[diagnostico], true);
					$temp[precio] = $this->crypter->descifrar ($elemento[precio], false);
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_paciente] = $elemento[id_paciente];
					$temp[observaciones] = $this->crypter->descifrar ($elemento[observaciones], true);
					array_push ($final, $temp);
				}
				break;
			case "factura":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_factura] = $elemento[id_factura];
					$temp[fecha] = $this->crypter->descifrar ($elemento[fecha], true);
					$temp[numero] = $this->crypter->descifrar ($elemento[numero], true);
					$temp[nombre_pagador] = "'".$this->crypter->corregir ($elemento[nombre_pagador])."'";
					$temp[dni_pagador] = "'".$this->crypter->corregir ($elemento[dni_pagador])."'";
					$temp[total] = $this->crypter->descifrar ($elemento[total], false);
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_paciente] = $elemento[id_paciente];
					array_push ($final, $temp);
				}
				break;
			case "presupuesto":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_presupuesto] = $elemento[id_presupuesto];
					$temp[fecha] = $this->crypter->descifrar ($elemento[fecha], true);
					$temp[numero] = $this->crypter->descifrar ($elemento[numero], true);
					$temp[validez] = $this->crypter->descifrar ($elemento[validez], true);
					$temp[duracion] = $this->crypter->descifrar ($elemento[duracion], true);
					$temp[total] = $this->crypter->descifrar ($elemento[total], false);
					$temp[objetivo] = $this->crypter->descifrar ($elemento[objetivo], true);
					$temp[extension] = $this->crypter->descifrar ($elemento[extension], true);
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_paciente] = $elemento[id_paciente];
					array_push ($final, $temp);
				}
				break;
			case "consentimiento":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_consentimiento] = $elemento[id_consentimiento];
					$temp[id_tipo_consentimiento] = $elemento[id_tipo_consentimiento];
					$temp[fecha] = $this->crypter->descifrar ($elemento[fecha], true);
					$temp[extension] = $this->crypter->descifrar ($elemento[extension], true);
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_paciente] = $elemento[id_paciente];
					array_push ($final, $temp);
				}
				break;
			case "consentimiento_revocado":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_consentimiento] = $elemento[id_consentimiento];
					$temp[id_tipo_consentimiento] = $elemento[id_tipo_consentimiento];
					$temp[fecha] = $this->crypter->descifrar ($elemento[fecha], true);
					$temp[fechar] = $this->crypter->descifrar ($elemento[fechar], true);
					$temp[extension] = $this->crypter->descifrar ($elemento[extension], true);
					$temp[extensionr] = $this->crypter->descifrar ($elemento[extensionr], true);
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_paciente] = $elemento[id_paciente];
					array_push ($final, $temp);
				}
				break;
			case "colaborador":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_visita_medica] = $elemento[id_visita_medica];
					$temp[id_dr_colaborador] = $elemento[id_dr_colaborador];
					$temp[id_usuario] = $elemento[id_usuario];
					array_push ($final, $temp);
				}
				break;
			case "asistente":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_visita_medica] = $elemento[id_visita_medica];
					$temp[id_personal] = $elemento[id_personal];
					$temp[id_usuario] = $elemento[id_usuario];
					array_push ($final, $temp);
				}
				break;
			case "receta":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_receta] = $elemento[id_receta];
					$temp[id_visita_medica] = $elemento[id_visita_medica];
					$temp[observaciones] = $this->crypter->descifrar ($elemento[observaciones], true);
					$temp[texto] = $this->crypter->descifrar ($elemento[texto], true);
					$temp[resumen] = $this->crypter->descifrar ($elemento[resumen], true);
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_paciente] = $elemento[id_paciente];
					$temp[id_tipo_receta] = $elemento[id_tipo_receta];
					array_push ($final, $temp);
				}
				break;
			case "linea_factura":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_linea] = $elemento[id_linea];
					$temp[id_factura] = $elemento[id_factura];
					$temp[cantidad] = $this->crypter->descifrar ($elemento[cantidad], false);
					$temp[total] = $this->crypter->descifrar ($elemento[total], false);
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_servicio] = $elemento[id_servicio];
					array_push ($final, $temp);
				}
				break;
			case "linea_presupuesto":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_linea] = $elemento[id_linea];
					$temp[id_presupuesto] = $elemento[id_presupuesto];
					$temp[cantidad] = $this->crypter->descifrar ($elemento[cantidad], false);
					$temp[total] = $this->crypter->descifrar ($elemento[total], false);
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_servicio] = $elemento[id_servicio];
					array_push ($final, $temp);
				}
				break;
			case "linea_visita":
				foreach($datos as $elemento)
				{
					$temp = array();
					$temp[id_linea] = $elemento[id_linea];
					$temp[id_visita] = $elemento[id_visita];
					$temp[cantidad] = $this->crypter->descifrar ($elemento[cantidad], false);
					$temp[total] = $this->crypter->descifrar ($elemento[total], false);
					$temp[id_usuario] = $elemento[id_usuario];
					$temp[id_servicio] = $elemento[id_servicio];
					array_push ($final, $temp);
				}
				break;

			default:
				break;

		}
		return $final;
	}
}
?>