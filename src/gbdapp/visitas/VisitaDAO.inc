<?php
/**
 * Fichero que recoje la implementacion de la clase VisitaDAO.
 * 
 * @package Acceso a Datos
 * @subpackage Visitas
 * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
 * @version: 1.0 (14 - Enero - 2008)
 */

/**
 * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
 */
include_once PATH_BASE . "src/db/DAO.inc";

/**
 * Clase VisitaAO. Implementa toda la lógica de acceso a datos para el objeto Visita Médica
 * @package Acceso a Datos
 * @subpackage Visitas
 */
class VisitaDAO extends DAO {
	/**
	 * Constructor de la clase. Llama al constructor de la clase padre.
	 * @return void
	 */
	function VisitaDAO() {
		parent::DAO ();
		return;
	}
	function nuevo($datos) {
		$valores = COMILLA . $datos [fecha] . COMILLA . COMA . COMILLA . $datos [asiento] . COMILLA . COMA . COMILLA . $datos [motivo] . COMILLA . COMA . COMILLA . $datos [diagnostico] . COMILLA . COMA . COMILLA . $datos [observaciones] . COMILLA . COMA . $datos [precio] . COMA . $datos [id_paciente] . COMA . $datos [id_usuario];
		
		$sentencia = "insert into visita (fecha, asiento, motivo, diagnostico, observaciones, precio, id_paciente, id_usuario) values ($valores)";
		$this->datos = $this->DBManager->hacer_peticion ( $sentencia );
		return $this->datos;
	}
	function borrar($id) {
		$idusr = $_SESSION [id_usr];
		$sentencia = "delete from visita where id_usuario = $idusr and id_visita = $id";
		$this->datos = $this->DBManager->hacer_peticion ( $sentencia );
		return $this->datos;
	}
	function ver($datos) {
		$idusr = $_SESSION [id_usr];
		if (is_int ( $datos )) {
			$id = $datos;
			$sentencia = "select * from visita where id_usuario = $idusr and id_visita = $id";
		} else {
			$idp = $datos [id_paciente];
			$id = $datos [id_visita];
			$sentencia = "select * from visita where id_usuario = $idusr and id_visita = $id and id_paciente = $idp";
		}
		$devuelto = $this->DBManager->recoger_datos ( $sentencia );
		if (is_array ( $devuelto )) {
			return $devuelto [1];
		} else
			return 0;
	}
	function modificar($datos) {
		$id = $datos [id_visita];
		$idusr = $_SESSION [id_usr];
		$idp = $datos [id_paciente];
		foreach ( $datos as $indice => $valor ) {
			$parejas .= "$indice = '$valor', ";
		}
		$parejas = substr ( $parejas, 0, strlen ( $parejas ) - 2 );
		$sentencia = "update visita set $parejas where id_visita = $id and id_usuario = $idusr and id_paciente = $idp";
		$this->datos = $this->DBManager->hacer_peticion ( $sentencia );
		if ($this->datos == 1)
			$this->datos = $id;
		return $this->datos;
	}
	function listado($id, $pagina = -1) {
		$idusr = $_SESSION [id_usr];
		$sentencia = "select id_visita, fecha, observaciones from visita 
            	where id_usuario = $idusr and id_paciente = $id order by id_visita desc";
		
		if ($pagina != - 1) {
			$inf = $pagina * MAX_FILAS;
			$sup = MAX_FILAS + 1;
			$sentencia .= " limit $inf, $sup";
		}
		$devuelto = $this->DBManager->recoger_datos ( $sentencia );
		if (is_array ( $devuelto )) {
			$this->datos = $devuelto [1];
			if ($devuelto [0] == MAX_FILAS + 1) {
				$this->datos = array_slice ( $this->datos, 0, - 1, true );
			}
			return array ($devuelto [0], $this->datos );
		} else
			return 0;
	}
	function buscar($datos) {
	}
	function historial($idpac, $fecha, $orden) {
		$idusr = $_SESSION [id_usr];
		$sup = MAX_FILAS;
		
		if ($orden == "a") {
			$order = "asc";
			$comparator = "<=";
		} else {
			$order = "desc";
			$comparator = ">=";
		}
		if (! strncmp ( $fecha, "ultimo", 6 )) {
			/*
                * Si se solicitan los ultimos movimientos, la consulta se ordena de forma descendente 
                * y la fecha limite se obtiene del ultimo registro del array
                */
			$sent = "(select fecha from visita where id_paciente = $idpac)  UNION (select fecha from pagopac where id_paciente = $idpac) order by STR_TO_DATE(fecha, '%d-%m-%Y') desc limit 0, $sup";
		} else {
			/*
                * Si se solicitan movimientos anteriores.
                */
			$sent = "(select fecha from visita where id_paciente = $idpac and DATEDIFF(STR_TO_DATE('$fecha', '%d-%m-%Y'), STR_TO_DATE(fecha, '%d-%m-%Y')) $comparator 0)  
                    UNION (select fecha from pagopac where id_paciente = $idpac and DATEDIFF(STR_TO_DATE('$fecha', '%d-%m-%Y'), STR_TO_DATE(fecha, '%d-%m-%Y')) $comparator 0) 
                    order by STR_TO_DATE(fecha, '%d-%m-%Y') $order limit 0, $sup";
		}
		$temp = $this->DBManager->recoger_datos ( $sent );
		if (is_array ( $temp )) {
			$temp = $temp [1];
			if ($orden == "a") {
				$fechaInf = $this->toSQL ( $temp [0] [fecha] );
				$temp = array_reverse ( $temp );
				$fechaSup = $this->toSQL ( $temp [0] [fecha] );
			} else {
				$fechaSup = $this->toSQL ( $temp [0] [fecha] );
				$temp = array_reverse ( $temp );
				$fechaInf = $this->toSQL ( $temp [0] [fecha] );
			}
			
			$sentencia = "
                    (select id_visita, precio, fecha, 'tarj', 'ef', NULL as id_pago from visita where id_paciente = $idpac and STR_TO_DATE(fecha, '%d-%m-%Y') BETWEEN '$fechaInf' AND '$fechaSup' ) 
                    UNION 
                    (select NULL, '0', fecha, total_tarjeta, total_efectivo, id_pago from pagopac where id_paciente = $idpac and STR_TO_DATE(fecha, '%d-%m-%Y') BETWEEN '$fechaInf' AND '$fechaSup' ) 
                    order by STR_TO_DATE(fecha, '%d-%m-%Y') desc";
                    
			$devolver = $this->DBManager->recoger_datos ( $sentencia );
			
			/*
                * Se calcula el saldo del paciente hasta el dia en que se empiezan a mostrar resultados
                */
			$sentencia = "
                    (select SUM(precio) as precio, 'saldo' from visita where id_paciente = $idpac and DATEDIFF(STR_TO_DATE(fecha, '%d-%m-%Y'), '$fechaInf') < 0 ) 
                    UNION 
                    (select 'precio', SUM(total_tarjeta + total_efectivo) as saldo from pagopac where id_paciente = $idpac and DATEDIFF(STR_TO_DATE(fecha, '%d-%m-%Y'), '$fechaInf') < 0 )";
			
			$arraySaldo = $this->DBManager->recoger_datos ( $sentencia );
			
			if (is_array ( $arraySaldo )) {
				$arraySaldo = $arraySaldo [1];
				$saldo = ( int ) $arraySaldo [1] [saldo] - ( int ) $arraySaldo [0] [precio];
			} else {
				$saldo = 0;
			}
			
			return array ($devolver, $saldo );
		} else {
			return 0;
		}
	}
	function bloquear($datos) {
	
	}
	function deudores($id) {
		$sentencia = "select * from saldo_view where saldo < 0";
		$resultado = $this->DBManager->recoger_datos ( $sentencia );
		if(is_array($resultado)){
			$this->datos = $resultado[1];
			foreach($this->datos as $linea => $array){
				$this->datos[$linea][nombre] = $this->crypter->descifrar($this->datos[$linea][nombre]);
				$this->datos[$linea][apellido] = $this->crypter->descifrar($this->datos[$linea][apellido]);
				$this->datos[$linea][apellido2] = $this->crypter->descifrar($this->datos[$linea][apellido2]);	
			}
			return $this->datos;
		}
		return $resultado;
	}
	function verCaja($fecha) {
		$idusr = $_SESSION [id_usr];
		
		$sent = "select pagos.nombre, pagos.apellido, pagos.apellido2, vis.id_visita, vis.id_paciente, serv.nombre as servicio, cantidad, total, saldo, tarj, efect, precio from
			(select id_paciente, id_visita, precio from visita where fecha = '$fecha' and id_usuario = $idusr group by id_paciente) as vis
			left outer join
			(select id_servicio, id_visita, cantidad, total from linea_visita) as lin on (vis.id_visita = lin.id_visita)
			left outer join
			(select id_servicio, nombre from servicio) as serv on (lin.id_servicio = serv.id_servicio)
			left outer join
			(select * from saldo_view group by id_paciente) as pagos on (vis.id_paciente = pagos.id_paciente)
			left outer join
			(select id_paciente, sum(total_tarjeta) as tarj, sum(total_efectivo) as efect from pagopac where fecha = '$fecha' group by id_paciente) as pagos2 on (vis.id_paciente = pagos2.id_paciente)";
		
		$devolver = $this->DBManager->recoger_datos ( $sent );
		if(is_array($devolver)){
			$this->datos = $devolver[1];
			foreach($this->datos as $linea => $valor){
				
				$nombre = $this->crypter->descifrar($this->datos[$linea][nombre]);
				$apellido = $this->crypter->descifrar($this->datos[$linea][apellido]);
				$apellido2 = $this->crypter->descifrar($this->datos[$linea][apellido2]);
				$this->datos[$linea][paciente] = $apellido." ".$apellido2.", ".$nombre;
				$this->datos[$linea][servicio] = $this->datos[$linea][cantidad]."x".$this->crypter->descifrar($this->datos[$linea][servicio])." (".$this->datos[$linea][total]."€)<br />";
			}
			return array($devolver[0], $this->datos);
		}
		return $devolver;
	}
	function verPagosSueltos($excluir, $fecha) {
		$idusr = $_SESSION [id_usr];
		if (is_array ( $excluir )) {
			//Si hay pacientes excluidos, se descartan
			foreach ( $excluir as $id )
				$pacientes_excluidos .= "'$id', ";
			
			$pacientes_excluidos = substr ( $pacientes_excluidos, 0, strlen ( $pacientes_excluidos ) - 2 );
			
			$sentencia = "select pg.id_paciente, nombre, apellido, apellido2, tarj, efect, saldo from
				(select id_paciente, sum(total_tarjeta) as tarj, sum(total_efectivo) as efect from pagopac where fecha='$fecha' group by id_paciente) as pg
				inner join saldo_view as sal on (pg.id_paciente = sal.id_paciente) where pg.id_paciente not in ($pacientes_excluidos)";
		} else {
			//Si no, se consideran todos
			$sentencia = "select pg.id_paciente, nombre, apellido, apellido2, tarj, efect, saldo from
				(select id_paciente, sum(total_tarjeta) as tarj, sum(total_efectivo) as efect from pagopac where fecha='$fecha' group by id_paciente) as pg
				inner join saldo_view as sal on (pg.id_paciente = sal.id_paciente)";
		}
		$devolver = $this->DBManager->recoger_datos ( $sentencia );	
		if(is_array($devolver)){
			$this->datos = $devolver[1];
			foreach ($this->datos as $linea => $valor){
				$nombre = $this->crypter->descifrar($this->datos[$linea][nombre]);
				$apellido = $this->crypter->descifrar($this->datos[$linea][apellido]);
				$apellido2 = $this->crypter->descifrar($this->datos[$linea][apellido2]);
				$this->datos[$linea][paciente] = $apellido." ".$apellido2.", ".$nombre;
			}
			return $this->datos;
		}
		return $devolver;
	}
	/**
	 * Funcion que convierte una fecha espanhola a formato SQL
	 * @param String Fecha a convertir
	 * @return String Fecha convertida
	 */
	function toSQL($fecha) {
		$separator = "-";
		$temp = explode ( $separator, $fecha );
		
		$temp [0] = ( int ) $temp [0];
		$temp [1] = ( int ) $temp [1];
		$temp [2] = ( int ) $temp [2];
		
		return $temp [2] . $separator . $temp [1] . $separator . $temp [0];
	}
}
?>