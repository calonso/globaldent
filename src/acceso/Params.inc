<?php
/**
* Esta clase se encarga de gestionar los parámetros que se reciben. 
* Los parámetros se reciben de la forma: /variable.valor, esta clase permite 
* recojer los parámetros.
* Este sistema de formateo de parámetros permite una indexación perfecta, de las páginas,
* en los buscadores tipo google.
*/
class Params {
		
	var $HTTP_GET_PARSED_VARS;
	
	/**
	* Método constructor de la clase. Simplemente recoje todos los parámetros
	* recibidos.
	*/
	function Params () {
		
		// Parseo de parámetros get
		if(!empty($_SERVER["PATH_INFO"])) {	

			$fchx_lang=$_SERVER["PATH_INFO"];
  			$fchx_tmp = ereg_replace("^/","",$fchx_lang);
			$fchx_tok = strtok($fchx_tmp,"/");
			while($fchx_tok) {
    		// list($k,$v) = explode(".",$fchx_tok);
				$fchx_pos = strpos ($fchx_tok, ".");
				if ($fchx_pos === false) {
					$k = $fchx_tok;
					$v = "";
				} else {
					$k = substr($fchx_tok,0,$fchx_pos);
					$v = urldecode(substr($fchx_tok,$fchx_pos+1));
				}
			$this->HTTP_GET_PARSED_VARS[$k] = $v;
			$fchx_tok = strtok("/");
			}
		}
	}
	
	/**
	* Método que permite recojer parámetros.
	* Recibe como parámetros de entrada: el nombre de la variable, parámetro, a recojer
	* y si el valor del parámetro contiene caracteres especiales que deben convertirse a caracteres html.
	* Devuelve el valor del parámetro solicitado. 
	*
	* @param string, boolean
	* @return string
	*/
	function getParam($param, $htmlencode=false) {

	  if ($htmlencode) {
	    if ($this->HTTP_GET_PARSED_VARS[$param]) {
	      return htmlspecialchars(stripslashes($this->HTTP_GET_PARSED_VARS[$param]));
	    } else {
	      return htmlspecialchars(stripslashes($_REQUEST[$param]));
	    }
	  } else { 
	    if ($this->HTTP_GET_PARSED_VARS[$param]) {
	      return stripslashes($this->HTTP_GET_PARSED_VARS[$param]);		
	    } else {
	      return $_REQUEST[$param];
	  	}
	  }
	  
	  					
    }
	
	
	function getParams() {
		return $this->HTTP_GET_PARSED_VARS;
	}
	
	
}

?>