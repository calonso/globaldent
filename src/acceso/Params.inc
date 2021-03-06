<?php
/**
* Esta clase se encarga de gestionar los par�metros que se reciben. 
* Los par�metros se reciben de la forma: /variable.valor, esta clase permite 
* recojer los par�metros.
* Este sistema de formateo de par�metros permite una indexaci�n perfecta, de las p�ginas,
* en los buscadores tipo google.
*/
class Params {
		
	private $HTTP_GET_PARSED_VARS;
	private $HTTP_POST_VARS;
	
	/**
	* M�todo constructor de la clase. Simplemente recoje todos los par�metros
	* recibidos.
	*/
	function Params () {
		// Parseo de par�metros get
		if(!empty($_SERVER["PATH_INFO"])) {	

			$fchx_lang=$_SERVER["PATH_INFO"];
  			$fchx_tmp = preg_replace("/^\\//","",$fchx_lang);
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
		if (!empty($_POST)){
			$this->HTTP_POST_VARS = $_POST;
		}
	}
	
	/**
	* M�todo que permite recojer par�metros.
	* Recibe como par�metros de entrada: el nombre de la variable, par�metro, a recojer
	* y si el valor del par�metro contiene caracteres especiales que deben convertirse a caracteres html.
	* Devuelve el valor del par�metro solicitado. 
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
	    } else if ($this->HTTP_POST_VARS[$param]){
	    	return $this->HTTP_POST_VARS[$param];
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