<?php
   /**
   * Archivo que implementa la clase que soporta la lógica de cifrados.
   * 
   * @package Acceso a Datos
   * @subpackage Base
   * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es
   * @version: 1.0 (5 - Diciembre - 2007)
   */
    
   
   /**
   * Clase única del archivo que soporta todos los métodos de cifrado y descifrado de cadenas
   * 
   * @package Acceso a Datos
   * @subpackage Base
   */
   class Crypter
   {
       /**
       * Almacenará el modulo, la llave y el vector empleados para cifrados y descifrados de cadenas.
       * @var array 
       */
        private $elementos;
        /**
        * Constructor de la clase, inicializa los módulos y prepara la llave.
        * @return void  
        */
        function Crypter()
        {
            $this->elementos[llave] = "AB1CD237690AF13B6721AD237A";
            $this->elementos[modulo] = mcrypt_module_open ('rijndael-256', '', 'cbc', ''); 
            $this->elementos[vector_inic] = "por874hyufijdue7w63ysxwet4320o90";
            $longitud_llave = mcrypt_enc_get_key_size ($this->elementos[modulo]);  
            $this->elementos[llave] = substr( md5($this->elementos[llave]), 0, $longitud_llave);
        }
        /**
        * Funcion que cifra los datos de la cadena que recibe como argumento
        * @param string Cadena en texto plano, recibida del usuario.
        * @return string Cadena cifrada, preparada para su uso en la BD
        */
        function cifrar ($cadena)
        {
            if (empty ($cadena))
                return $cadena;
         
            mcrypt_generic_init ($this->elementos[modulo], $this->elementos[llave], $this->elementos[vector_inic]);
            $resultado = mcrypt_generic ($this->elementos[modulo], $cadena);
            mcrypt_generic_deinit ($this->elementos[modulo]);
            $resultado = $this->corregir ($resultado);
        
            return $resultado;       
        }
        /**
        * Funcion que descifra los datos de la cadena que recibe como argumento
        * @param string Cadena cifrada, recibida de la BD.
        * @return string Cadena en texto plano, preparada para el usuario.
        */
        function descifrar ($cadena, $comillas = false)
        {
            if (empty ($cadena)){
                if($comillas)
                    return "'".$cadena."'";
                else
                    return $cadena;   
            }
             
                
            mcrypt_generic_init ($this->elementos[modulo], $this->elementos[llave], $this->elementos[vector_inic]);
            $resultado = mdecrypt_generic ($this->elementos[modulo], $cadena);
            mcrypt_generic_deinit ($this->elementos[modulo]);
            $resultado = trim ($resultado);
            $resultado = $this->corregir2 ($resultado);
            if ($comillas)
                $resultado = "'".preg_replace("/[\n\r]/","", $resultado)."'";
            return $resultado;      
        }
        
   		function descifrar2 ($cadena, $comillas = false)
        {
            if (empty ($cadena)){
                if($comillas)
                    return "'".$cadena."'";
                else
                    return 0;   
            }
             
                
            mcrypt_generic_init ($this->elementos[modulo], $this->elementos[llave], $this->elementos[vector_inic]);
            $resultado = mdecrypt_generic ($this->elementos[modulo], $cadena);
            mcrypt_generic_deinit ($this->elementos[modulo]);
            $resultado = trim ($resultado);
            $resultado = $this->corregir2 ($resultado);
            if ($comillas)
                $resultado = "'".$this->corregir($resultado)."'";
            else 
            	$resultado = preg_replace('/,/', '.', $resultado);
            return $resultado;      
        }
        /**
        * Funcion que corrige la cadena recien encriptada escapando los caracteres ",' y \
        * @param string Cadena cifrada a corregir
        * @return string Cadena preparada para su uso en base de datos.
        */
        function corregir ($cadena)
        {
            $cadena = preg_replace ('/\\\\/', '\\\\\\', $cadena);
            $cadena = preg_replace ('/;/', '\\;', $cadena);
            $cadena = preg_replace ('/\'/', '\\\'', $cadena);
            $cadena = preg_replace ('/\"/', '\\\"', $cadena);
            return $cadena;   
        }
        /**
        * Funcion que corrige la cadena recien descifrada
        * @param string Cadena en texto plano a corregir
        * @return string Cadena preparada para su uso en los templates.
        */
        function corregir2 ($cadena)
        {
            $cadena = preg_replace ('/\\\"/','"', $cadena);
            //$cadena = preg_replace("/[\n\r]/","", $cadena);
            return $cadena;   
        }
   }
?>