<?php
/**
 * Fichero que recoge la implementacion de la clase CitaDAO
 *
 * @package Acceso a Datos
 * @subpackage Visitas
 * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
 * @version: 1.0 (29 - Diciembre - 2007)
 */

/**
 * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
 */
include_once PATH_BASE."src/db/DAO.inc";

/**
 * Clase CitaDAO. Implementa toda la lógica de acceso a datos para el objeto Usuario
 * @package Acceso a Datos
 * @subpackage Usuarios
 */
class CitaDAO extends DAO
{
	/**
	 * Constructor de la clase. Llama al constructor de la clase padre.
	 * @return void
	 */
	function UsuarioDAO()
	{
		parent::DAO();
		return;
	}
	function nuevo ($datos)
	{
		$datos[fecha] = $this->crypter->corregir($datos[fecha]);
		$datos[hora] = $this->crypter->corregir($datos[hora]);
		$datos[duracion] = $this->crypter->corregir($datos[duracion]);
		$datos[gabinete] = $this->crypter->corregir($datos[gabinete]);
		$datos[id_paciente] = $this->crypter->corregir($datos[id_paciente]);
		$datos[observaciones] = $this->crypter->corregir($datos[observaciones]);
		$datos[tipo] = $this->crypter->corregir($datos[tipo]);
		
		$valores = COMILLA.$datos[fecha].COMILLA.COMA.
			COMILLA.$datos[hora].COMILLA.COMA.
			$datos[duracion].COMA.
			$datos[gabinete].COMA.
			$datos[id_paciente].COMA.
			COMILLA.$datos[observaciones].COMILLA.COMA.
			COMILLA.$datos[tipo].COMILLA.COMA.
			$_SESSION[id_usr];

		$sentencia = "insert into cita 
			(fecha, hora, duracion, gabinete, id_paciente, observaciones, tipo, id_usuario) 
			values ($valores)";
			
		$this->datos = $this->DBManager->hacer_peticion ($sentencia);
		return $this->datos;
	}
	function anulaPeriodo($fecha, $periodo, $gabinete){
		
		$AM = array("8:00", "8:30", "9:00", "9:30", "10:00", "10:30", "11:00", "11:30", "12:00", "12:30", "13:00", "13:30", "14:00",
                "14:30", "15:00", "15:30");
                
		$PM = array("16:00", "16:30", "17:00", "17:30", "18:00", "18:30", "19:00", "19:30", "20:00", "20:30",
                "21:00", "21:30", "22:00");
		
		$horas = $periodo == 1 ? $AM : $PM;
		$idusr = $_SESSION[id_usr];
		foreach($horas as $hora){
			$valores .= "('".$fecha.COMILLA.COMA.
				COMILLA.$hora.COMILLA.COMA.
				"1,".
				COMILLA.$gabinete.COMILLA.COMA.
				"1,".
				$idusr."), ";
		}
		$valores = substr($valores, 0, strlen($valores)-2);
		$sentencia = "insert into cita (fecha, hora, duracion, gabinete, bloqueado, id_usuario) values $valores";
		return $this->DBManager->hacer_peticion($sentencia);
	}
	function borrar ($id)
	{
		$idusr = $_SESSION[id_usr];
		$sentencia = "delete from cita where id_usuario = $idusr and id_cita = $id";
		$this->datos = $this->DBManager->hacer_peticion ($sentencia);
		return $this->datos;
	}

	function ver ($id)
	{
		$idusr = $_SESSION[id_usr];
		$sentencia = "select * from cita where id_usuario = $idusr and id_cita = $id";
		$this->datos = $this->DBManager->recoger_datos ($sentencia);
		if (is_array($this->datos)) {
			return $this->datos[1];
		}else
			return 0;
	}
	function modificar ($datos){}

	function color ($id, $color){
		$idusr = $_SESSION[id_usr];
		$sentencia = "update cita set color = '$color' where id_cita = $id and id_usuario = $idusr";
		$this->datos = $this->DBManager->hacer_peticion ($sentencia);
	}
	function listado ($id, $datos = -1){}

	function verDia($fecha, $hora){
		$idusr = $_SESSION[id_usr];
		$sentencia = "select id_cita, fecha, hora, duracion, gabinete, cit.id_paciente, observaciones, tipo, bloqueado, color, cit.id_usuario, nombre, apellido, apellido2, IFNULL(fsa, 0) as fsa from cita as cit
			left outer join (select id_paciente, nombre, apellido, apellido2 from paciente) as pac on (cit.id_paciente = pac.id_paciente)
			left outer join (select id_paciente, case when fsa LIKE '1,1%' then 1 else 0 end as fsa from
                (select id_paciente, cast(group_concat(fsa order by id_visita desc) as char) as fsa, id_usuario from visita where id_usuario = 1 group by id_paciente) as v where fsa = 1) as fsa on (pac.id_paciente = fsa.id_paciente)
			where fecha = '$fecha' and hora = '$hora' and id_usuario = $idusr order by gabinete asc";
		$this->datos = $this->DBManager->recoger_datos ($sentencia);
		if (is_array($this->datos))
		{
			$devolver = $this->datos[1]; 
			foreach ($devolver as $linea => $array){
				$nom = $this->crypter->descifrar($devolver[$linea][nombre]);
				$ape = $this->crypter->descifrar($devolver[$linea][apellido]);
				$ape2 = $this->crypter->descifrar($devolver[$linea][apellido2]);
				$devolver[$linea][paciente] = "$ape $ape2, $nom";
			}
			return $devolver;
		}else
			return 0;
	}
	function buscar ($datos){}

	function bloquear ($fecha, $gabinete)
	{
		$idusr = $_SESSION[id_usr];

		$sentencia = "select hora, duracion from cita
			where id_usuario = $idusr and fecha = '$fecha' and gabinete = '$gabinete' for update";
		$this->datos = $this->DBManager->recoger_datos ($sentencia);
		
		return $this->datos;
	}
	function quitaBloqueo ($id, $num)
	{
		$idusr = $_SESSION[id_usr];
		/**
		 * Se borran las citas a partir de la que tenga como identificador el id
		 * y hasta la que tenga identificador num
		 */
		$limit = $id + $num;
		$sentencia = "delete from cita where id_usuario = $idusr and id_cita BETWEEN $id and $limit and bloqueado = 1";
		$this->datos = $this->DBManager->hacer_peticion ($sentencia);
		return $this->datos;
	}
	/**
	 * Funcion que busca la proxima cita de un paciente
	 *
	 * @param int $id
	 * @return unknown
	 */
	function proximaCita ($id)
	{
		$idusr = $_SESSION[id_usr];
		$sentencia = "select fecha, hora, gabinete, tipo from proxima_cita where id_usuario = $idusr and id_paciente = $id";
		$this->datos = $this->DBManager->recoger_datos($sentencia);
		return $this->datos;
	}
}
?>