<?php
	/**
	 * Fichero que recoje la implementacion de la clase fechas.
	 *
	 * @package Common
	 * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
	 * @version: 1.0 (17 - Diciembre - 2008)
	 */
	
	class fechas {
		
		private $fecha;
		
		function fechas() {
			$this->fecha = strftime ("%d-%m-%Y");
            $aux = explode ("-", $this->fecha);
            $aux[0]= (int)$aux[0];
            $aux[1] = (int)$aux[1];
            $this->fecha = $aux[0]."-".$aux[1]."-".$aux[2];
		}
		
		function getFecha(){
			return $this->fecha;
		}
	}

?>