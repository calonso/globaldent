<?php 
    /**
     * Fichero que recoje la implementacion de la clase Utils, encargada de
     * facilitar tareas comunes.
     *
     * @package Common
     * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
     * @version: 1.0 (16 - Junio - 2009)
     */

    /**
    * Inclusion del archivo de configuracion.
    */
    include_once PATH_BASE."conf/conf.inc"; 
    
    define ("REMOTE_IP", "For: ".$_SERVER['REMOTE_ADDR'].":".$_SERVER['REMOTE_PORT']." ");
    
    class Utils {
    	
    	private static function getLogObject(){
    		$l = &Log::singleton(LOGGING_METHOD, LOGGING_TARGET, NULL, array(), LOGGING_FILTER);
    		return $l; 
    	}
    	/*
    	 * Funcion que se encarga de guardar un evento de error
    	 * @param String data
    	 */
    	public static function log_error($data) {
    		$log = Utils::getLogObject();
    		$log->log(REMOTE_IP.$data, PEAR_LOG_ERR);
    	}
    	/*
         * Funcion que se encarga de guardar un evento de aviso
         * @param String data
         */
    	public static function log_warning($data) {
    	    $log = Utils::getLogObject();
            $log->log(REMOTE_IP.$data, PEAR_LOG_WARNING);
    	}
    	/*
         * Funcion que se encarga de guardar un evento de informacion
         * @param String data
         */
    	public static function log_info($data) {
    		$log = Utils::getLogObject();
            $log->log(REMOTE_IP.$data, PEAR_LOG_INFO);
    	}
    	/*
         * Funcion que se encarga de guardar un evento de depuracion
         * @param String data
         */
    	public static function log_debug($data) {
    		$log = Utils::getLogObject();
            $log->log(REMOTE_IP.$data, PEAR_LOG_DEBUG);
    	}
    	
    	public static function print_array($data) {
    		if(is_array($data)){
    			return print_r ($data, true);
    		} else {
    			return "";
    		}
    	}
    	
    	public static function log_system_error($errno, $errdesc, $file, $line) {
    		$log = Utils::getLogObject();
    		if (strstr ($file, "smarty") === FALSE){
    		  $log->log("[SYSTEM_ERROR: $errno]".REMOTE_IP.$errdesc." at ".$file.":".$line."\n backtrace: \n".Utils::print_array(debug_backtrace()), PEAR_LOG_ERR);
//    		  $log->log("[SYSTEM_ERROR: $errno]".REMOTE_IP.$errdesc." at ".$file.":".$line, PEAR_LOG_ERROR);
    		}
    		return false;
    	}
    	
    	public static function log_system_exception (int $errno, String $errdesc) {
    		$log = Utils::getLogObject();
    		$log->log("[SYSTEM_EXCEPTION $errno]".REMOTE_IP.$errdesc, PEAR_LOG_ERR);
    		return false;
    	}
    }

?>