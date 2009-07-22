<?php
    /**
    * Archivo que recoge la implementación de la clase controller, que sera el punto de llegada de todas las peticiones.
    * 
    * @package Presentacion
    * @subpackage Acceso
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es
    * @version: 1.0 (10 - Diciembre - 2007)
    */
    /**
    * Inclusion del archivo de configuracion.
    */
    include_once PATH_BASE."conf/conf.inc";
    /**
    * Inclusion de la clase Publico, encargada de manejar las peticiones
    */
    include_once PATH_BASE."src/acceso/Publico.inc";
    /**
    * Inclusion de la clase Publico, encargada de manejar las peticiones de usuarios registrados
    */
    include_once PATH_BASE."src/acceso/Portal.inc";
    /**
    *  Inclusion de la clase Error, encargada de manejar las peticiones de usuario no validado
    */
    include_once PATH_BASE."src/acceso/Error.inc";
    /**
    *  Inclusion de la clase Privado, encargada de manejar las peticiones de usuario suscriptor
    */
    include_once PATH_BASE."src/acceso/Privado.inc";
    /**
    *  Inclusion de la clase Admin, encargada de manejar las peticiones de administrador
    */
    include_once PATH_BASE."src/acceso/Admin.inc";
    /**
    *  Inclusion de la clase SubAdmin, encargada de manejar las peticiones de sub administrador
    */
    include_once PATH_BASE."src/acceso/SubAdmin.inc";
    /**
    *  Inclusion de la clase Empleado, encargada de manejar las peticiones de administrador
    */
    include_once PATH_BASE."src/acceso/Empleado.inc";
    
    /**
    * Clase que implementa toda la lógica de control de acceso 
    * 
    * @package Presentacion
    * @subpackage Acceso
    */
    class Controller
    {
        /**
        * Variable que guardara la referencia al dispatcher que se le asigne a la peticion recibida
        * @var resource
        */
        private $dispatcher;
        /**
        * Constructor de la clase, inicializa o continua la sesion del usuario
        * Crea y llama al dispatcher apropiado
        * @return void
        */
        function Controller()
        {
            $privilegios = $this->validar();

            switch($privilegios)
            {
                 
                case 0: 
                    $this->dispatcher = new Publico();
                    break;
                case 1:
                    $this->dispatcher = new Portal();
                    break;
                case 4:
                    $this->dispatcher = new Privado();
                    break;
                case 5:
                    $this->dispatcher = new SubAdmin();
                    break;
                case 6:
                    $this->dispatcher = new Empleado();
                    break;
                case 9:
                    $this->dispatcher = new Admin();
                    break;
                case -1:
                default:
                    $this->dispatcher = new Error();
                    break;
            }
            
            $this->dispatcher->dispatch();
            
            return;
        }   
        /**
        * Funcion encargada de validar que la sesion pertenece al usuario
        * @return int Opciones:
        *   - 0 si usuario no registrado
        *   - 1 si usuario registrado
        *   - 4 si suscriptor
        *   - 9 si administrador
        *   - -1 si no validada
        */
        function validar()
        {
        	$ret = 0;
            session_start(); 
            if(isset($_SESSION[id]))
            {      
                if(!strncmp($_SESSION[ip], $_SERVER['REMOTE_ADDR'], strlen($_SESSION[ip])))
                {   
                    if (($_SESSION[privilegios] == 4)&&($_SESSION[start] == true))
                        $ret = $_SESSION[privilegios]; 
                    elseif ($_SESSION[privilegios] == 9)
                        $ret = 9;
                    elseif (($_SESSION[privilegios] == 5) && ($_SESSION[start]))
                        $ret = 5;
                    elseif (($_SESSION[privilegios] == 6) && ($_SESSION[start]))
                        $ret = 6;
                    else
                        $ret = 1;                
                }else
                    $ret = -1; 
            } 
            Utils::log_debug("$ret privileges value binded."); 
            return $ret;
        }
    }
?>