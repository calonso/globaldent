<?php
    /**
    * Fichero que recoje la implementacion de la clase usuarioDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Usuarios
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (11 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase UsuarioDAO. Implementa toda la lógica de acceso a datos para el objeto Usuario
    * @package Acceso a Datos
    * @subpackage Usuarios
    */
    class UsuarioDAO extends DAO
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
        /**
        * Funcion que agrega un nuevo usuario en BD
        * @param array. Array donde se reciben los datos del nuevo usuario
        * @return int. Opciones:
        *   - -1 Si hubo error y no se pudo agregar el usuario
        *   - Cualquier otro entero que es el identificador que el usuario ha recibido en la BD.
        */
        function nuevo ($datos)
        {
            $pass = $this->crypter->cifrar($datos[password]);
            $valores = COMILLA.$datos[nombre].COMILLA.COMA.
            	COMILLA.$datos[apellido].COMILLA.COMA.
            	COMILLA.$datos[apellido2].COMILLA.COMA.
            	COMILLA.$datos[login].COMILLA.COMA.
            	COMILLA.$pass.COMILLA.COMA.
            	COMILLA.$datos[telefono].COMILLA.COMA.
            	COMILLA.$datos[email].COMILLA.COMA.
            	COMILLA.$datos[privilegios].COMILLA.COMA.
            	COMILLA.$datos[fin_suscripcion].COMILLA;
            
            $sentencia = "insert into usuario (nombre, apellido, apellido2, login, password, telefono, email, privilegios, fin_suscripcion) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;
        }
        function borrar ($datos)
        {
            $id = $datos[id_usuario];
            $sentencia = "delete from usuario where id_usuario = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;    
        }
        function ver ($id)
        {
            if(!isset($id))
                return 0;
            $sentencia = "select * from usuario where id_usuario = $id";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                $this->datos = $devuelto[1];
                foreach ($this->datos as $elemento => $array)
                {
                    $this->datos[$elemento][password] = $this->crypter->descifrar($this->datos[$elemento][password]);   
                }
                return $this->datos;
            }               
            return 0;
        }
        function modificar ($datos)
        {
            foreach ($datos as $indice => $valor)
            {
                if(!strncmp ($indice, "password", 8))
                {
                    $valor = $this->crypter->cifrar ($valor);
                }  
                $parejas .= "$indice = '$valor', ";
            } 
            $id = $datos[id_usuario];
            $parejas = substr($parejas, 0, strlen($parejas) -2);
            $sentencia = "update usuario set $parejas where id_usuario = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;  
        }
        function listado ($id, $pagina = -1)
        {
            $sentencia = "select id_usuario, nombre, apellido, apellido2, login, privilegios from usuario order by privilegios asc";
            $this->datos = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($this->datos))
            {
                $this->datos = $this->datos[1];
                foreach ($this->datos as $elemento => $array)
                {
                    $this->datos[$elemento][password] = $this->crypter->descifrar($this->datos[$elemento][password]);   
                }
                return $this->datos;
            }    
            return 0;
        }
        function buscar ($datos)
        {
            foreach ($datos as $indice => $valor)
            {
                $parejas .= "$indice = '$valor' and ";   
            }
            $parejas = substr($parejas, 0, strlen($parejas)-5);
            $sentencia = "select id_usuario, login, password, privilegios, fin_suscripcion from usuario where $parejas";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                $this->datos = $devuelto[1];
                foreach ($this->datos as $elemento => $array)
                {
                    $this->datos[$elemento][password] = $this->crypter->descifrar($this->datos[$elemento][password]);  
                }
                return array($devuelto[0], $this->datos);
            }               
            return 0;
        }
        
        function bloquear ($datos)
        {
        
        }  
    }
?>