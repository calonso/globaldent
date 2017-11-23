<?php
	/**
	 * Fichero que recoje la implementacion de la clase fechas.
	 *
	 * @package Common
	 * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
	 * @version: 1.0 (17 - Diciembre - 2008)
	 */
	
	class Date {
		
		static function getDate(){
			$fecha = strftime ("%d-%m-%Y");
            $aux = explode ("-", $fecha);
            $aux[0]= (int)$aux[0];
            $aux[1] = (int)$aux[1];
            return $aux[0]."-".$aux[1]."-".$aux[2];
		}
		
		static function toSQL($date) {
			$ret = $date;
			if (preg_match("/\\d{1,2}-\\d{1,2}-\\d{4}/", $date)){
				$ret = preg_replace("/(\\d{1,2})-(\\d{1,2})-(\\d{4})/", "$3-$2-$1", $date);
			}
			return $ret;
		}
	}

?>