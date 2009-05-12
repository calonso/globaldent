<?php
/**
 * Archivo que encapsula el acceso a bases de datos cuando se trata de mysql
 */

  /**
  * Inclusion del archivo de configuracion
  */
  include_once PATH_BASE."conf/conf.inc";

class mysql {
	
	private static $connection;
	public $num_rows;
	
	function mysql(){
		if (self::$connection == null){
			self::$connection = mysqli_connect(DB_SERVIDOR, DB_USUARIO, DB_CLAVE, DB_BD);
			$err = mysqli_connect_error(self::$connection);
			if (strlen($err) > 0){
				echo "$err<br />";
			}
		}
	}
	
	function query($sentence){
		$result = mysqli_query(self::$connection, $sentence);
		$err = mysqli_error(self::$connection);
		if (strlen($err) > 0){
			echo "$err<br />";
		}
		if($result){
			$return_val = 0;
			if ( preg_match("/^(insert|replace)\\s+/i",$sentence) ) //Si es inserción o remplazo
			{
				$return_val = mysqli_insert_id(self::$connection); //Cojo el identificador de la inserción
				$return_val = $return_val != 0 ? $return_val : mysqli_affected_rows(self::$connection); //Para tablas sin auto_increment
			} else {
				$return_val = mysqli_affected_rows(self::$connection);
			}
			return $return_val;
		} else {
			return -1;
		}
	}
	
	function get_results($sentence){
		$result = mysqli_query(self::$connection, $sentence);
		$err = mysqli_error(self::$connection);
		if (strlen($err) > 0){
			echo "$err<br />";
		}
		if($result){
			$res = array();
			$data = mysqli_fetch_assoc($result);
			while ($data != null){
				array_push($res, $data);
				$data = mysqli_fetch_assoc($result);
			}
			$this->num_rows = mysqli_num_rows($result);
			$result = $res;
		} else {
			$result = 0;
		}
		return $result;
	}
}
?>