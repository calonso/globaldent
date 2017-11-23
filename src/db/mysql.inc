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
			Utils::log_info("Creating connection to ".DB_USUARIO."@".DB_SERVIDOR."/".DB_BD);
			self::$connection = mysqli_connect(DB_SERVIDOR, DB_USUARIO, DB_CLAVE, DB_BD);
			$err = mysqli_connect_error(self::$connection);
			if (strlen($err) > 0){
				Utils::log_error("$err connecting to ".DB_USUARIO."@".DB_SERVIDOR."/".DB_BD);
				echo "$err<br />";
			}
		}
	}
	
	function query($sentence){
		Utils::log_info("Query: $sentence");
		$result = mysqli_query(self::$connection, $sentence);
		Utils::log_info("The query resulted: $result");
		$err = mysqli_error(self::$connection);
		if (strlen($err) > 0){
			Utils::log_error("$err performing query: $sentence");
			echo "$err<br />";
		}
		if($result){
			$return_val = 0;
			if ( preg_match("/^(insert|replace)\\s+/i",$sentence) ) //Si es inserción o remplazo
			{
				Utils::log_debug("$sentence is an insertion/replacement");
				$return_val = mysqli_insert_id(self::$connection); //Cojo el identificador de la inserción
				Utils::log_debug("$return_val received");
				$return_val = $return_val != 0 ? $return_val : mysqli_affected_rows(self::$connection); //Para tablas sin auto_increment
			} else {
				Utils::log_debug("$sentence is neither insertion nor replacement");
				$return_val = mysqli_affected_rows(self::$connection);
			}
			$this->log_warnings();
			Utils::log_info("Returning $return_val");
			return $return_val;
		} else {
			$this->log_warnings();
			Utils::log_warning("$sentence resulted in no resultset!! returning -1");
			return -1;
		}
	}
	
	function get_results($sentence){
		Utils::log_info("Query: $sentence");
		$result = mysqli_query(self::$connection, $sentence);
		$err = mysqli_error(self::$connection);
		if (strlen($err) > 0){
			Utils::log_error("$err performing query: $sentence");
			echo "$err<br />";
		}
		if($result){
			$res = array();
			Utils::log_debug("The query has results, fetching an array");
			$data = mysqli_fetch_assoc($result);
			while ($data != null){
				array_push($res, $data);
				$data = mysqli_fetch_assoc($result);
			}
			$this->num_rows = mysqli_num_rows($result);
			//Utils::log_debug($this->num_rows." fetched at this array: ".Utils::print_array($res));
			Utils::log_debug($this->num_rows." fetched");
			$result = $res;
			$this->log_warnings();
		} else {
			$this->log_warnings();
            Utils::log_warning("$sentence resulted in no resultset!! returning ");
			$result = 0;
		}
		return $result;
	}
	
	function log_warnings() {
		if (mysqli_warning_count(self::$connection)) {
		    if (($result = mysqli_query(self::$connection, "SHOW WARNINGS"))) {
		        $row = mysqli_fetch_row($result);
		        Utils::log_warning("MYSQL Warn: %s (%d): %s\n", $row[0], $row[1], $row[2]);
		    }
		}
	}
}
?>