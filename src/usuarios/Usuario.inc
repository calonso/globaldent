<?php
    /**
    * Fichero que recoje la implementacion de la clase usuario.
    * 
    * @package Negocio
    * @subpackage Usuarios
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (11 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del fichero DisplayManager para tener acceso a la logica de presentacion de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del fichero UsuarioDAO para tener acceso a la logica de almacenamiento de datos
    */
    include_once PATH_BASE."src/usuarios/UsuarioDAO.inc";
    /**
    * Inclusion del fichero PagoDAO para tener acceso a la logica de almacenamiento de datos
    */
    include_once PATH_BASE."src/usuarios/PagoDAO.inc";
    /**
    * Inclusion del fichero PersonalDAO para tener acceso a las cuentas de personal
    */
    include_once PATH_BASE."src/gbdapp/personal/PersonalDAO.inc";
    /**
    * Inclusion del fichero Logger para hacer log
    */
    include_once PATH_BASE."src/gbdapp/log/Logger.inc";
    
    /**
    * Clase Usuario. Implementa toda la logica de manejo de datos de usuario por parte de los usuarios
    * @package Negocio
    * @subpackage Usuarios
    */
    class Usuario extends DisplayManager
    {
        /**
        *  Almacenará todos los datos que se manejen en cada petición y se usará como objeto de intercambio de datos con el DAO
        * @var array
        */
        private $datos;
        /**
        *  Almacenará la referencia a su objeto DAO
        * @var resource
        */
        private $dao;
        /**
        * Almacena la referencia a su objeto Logger
        */ 
        private $logger;
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @return void
        */
        function Usuario ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."usuarios/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 5);
            
            if(($_SESSION[privilegios] >= 4) && ($_SESSION[privilegios] < 9))
                $this->smarty->assign('privilegios', $_SESSION[privilegios]);
                
            $this->logger = new Logger($lang);
            
            $this->datos = array();
            $this->dao = new UsuarioDAO();  
            return; 
        }
        /**
        * Funcion que se encarga de mostrar la pagina de usuarios
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraUsuarios ($params, $file)
        {
            if(isset($_SESSION[id]))
            {
                $this->smarty->assign ('autenticado', 1);
                if($_SESSION[privilegios] == 9)
                    $this->smarty->display ($this->path."accesoadmin.phtml");
                else
                    $this->smarty->display ($this->path."acceso.phtml");
            }else
                $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que muestra el formulario de registro para un nuevo usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function muestraRegistro ($params, $file)
        {
            if(isset($_SESSION[id]))
            {
                $this->smarty->assign ('autenticado', 1);
                $this->smarty->display ($this->path."acceso.phtml");
            }else
                $this->smarty->display ($this->path.$file.".phtml");
            return; 
        }
        /**
        * Funcion que almacena los datos de un nuevo registro en BD
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return int
        */
        function nuevoUsuario ($params, $file)
        {
            $this->recibirFormulario ($params);
            $resultado = $this->dao->buscar (array("login" => $this->datos[login]));
            if(is_array($resultado))
            {
                $this->smarty->assign ('codigo', -2);
                $this->smarty->display ($this->path.$file.".phtml");
                return;
            }    
            $this->datos[privilegios] = 1;
            $resultado = $this->dao->nuevo ($this->datos);
            $this->smarty->assign ('codigo', $resultado);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que recoge todos los datos que envia el usuario a traves de un formulario
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @return void
        */
        function recibirFormulario ($params, $objetivo = "alta")
        {
            switch ($objetivo)
            {
                case "alta": 
                    $this->datos[nombre] = $params->getParam('txtNombre'); 
                    $this->datos[apellido] = $params->getParam('txtApe'); 
                    $this->datos[apellido2] = $params->getParam('txtApe2');
                    $this->datos[login] = $params->getParam('txtLogin');
                    $this->datos[password] = $params->getParam('txtPass'); 
                    $this->datos[email] = $params->getParam('txtEmail');
                    $this->datos[telefono] = $params->getParam('txtTelefono');
                    break;
                case "actualizar":
                    $this->datos[nombre] = $params->getParam('txtNombre'); 
                    $this->datos[apellido] = $params->getParam('txtApe'); 
                    $this->datos[apellido2] = $params->getParam('txtApe2'); 
                    $this->datos[email] = $params->getParam('txtEmail');
                    $this->datos[telefono] = $params->getParam('txtTelefono');
                    break;
                case "cambiapass":
                    $this->datos[passact] = $params->getParam('txtPassAct');
                    $this->datos[password] = $params->getParam('txtPass');
                    break;
                case "pago":
                    $this->datos[numero_tarjeta] = $params->getParam('txtTarjeta');
                    $this->datos[caducidad] = $params->getParam('txtCaducidad');
                    $this->datos[importe] = $params->getParam('txtImporte');
                    break;
            }
            return;
        }
        /**
        * Funcion que muestra el formulario de login para los usuarios registrados que quieren acceder a su cuenta en el portal
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function muestraLogin ($params, $file)
        {
            if(isset($_SESSION[id]))
            {
                $this->smarty->assign ('autenticado', 1);
                $this->smarty->display ($this->path."acceso.phtml");
            }else
                $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que implementa la logica de login para los usuarios registrados que quieren acceder a su cuenta en el portal
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return bool
        */
        function login ($params, $file)
        {
            $this->datos[login] = $params->getParam('txtLogin');
            $recogido = $this->dao->buscar ($this->datos);
            $this->datos[password] = $params->getParam ('txtPass');
            $this->smarty->assign ('autenticado', 0);
            if (is_array($recogido))
            {  
                if (!strcmp ($recogido[1][0][password], $this->datos[password]))
                {
                    $this->smarty->assign ('autenticado', 1);    
                    $this->abrirSesion ($recogido[1][0]);
                    if($_SESSION[privilegios] == 9)
                        $file = "accesoadmin";
                }
            }
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que implementa la logica de abrir una sesion para un usuario que acaba de acceder a su cuenta en el portal
        * @param array Array con los datos del usuario necesarios para abrir la sesion
        * @return void
        */
        function abrirSesion ($datos)
        {
            session_start();
            session_cache_limiter("nocache");
            $_SESSION[id] = session_id();
            $_SESSION[id_ssl] = $_SERVER[SSL_SESSION_ID];
            $_SESSION[id_usr] = $datos[id_usuario];
            $_SESSION[privilegios] = $datos[privilegios];   
            $_SESSION[ip] = $_SERVER[REMOTE_ADDR];
            $_SESSION[id_pers] = $datos[id_personal];
            $_SESSION[nombre] = $datos[apellido]." ".$datos[apellido2].", ".$datos[nombre];
            if(($_SESSION[privilegios] >= 4) && ($_SESSION[privilegios] < 9)) 
                $this->logger->save(LOG_LOGIN, "Desde: ".$_SESSION[ip]);
            return;   
        }
        /**
        * Funcion que muestra la ficha con todos los datos personales del usuario registrado.
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void 
        */
        function verFicha ($params, $file)
        {
            $this->datos[id_usuario] = $_SESSION[id_usr];
            if($_SESSION[privilegios] == 9)
                $this->datos[id_usuario] = $params->getParam ('id');
            $this->datos = $this->dao->ver ($this->datos[id_usuario]);
            if(is_array($this->datos))
            {
                $this->smarty->assign('codigo', 1);
                $this->smarty->assign('datos', $this->datos[0]);
            }else
                $this->smarty->assign('codigo', 0);
                
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que muestra todos los datos personales del usuario en un formato editable para su actualizacion
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function muestraModificar ($params, $file)
        {
            $this->datos = $_SESSION[id_usr];
            $this->datos = $this->dao->ver ($this->datos);
            if(is_array($this->datos))
            {
                $this->smarty->assign('codigo', 1);
                $this->smarty->assign('datos', $this->datos[0]);
            }else
                $this->smarty->assign('codigo', 0);
                
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que recoje los datos enviados por el usuario y actualiza los existentes en la base de datos.
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function modificar ($params, $file)
        {
            $this->recibirFormulario ($params, "actualizar");
            $this->datos[id_usuario] = $_SESSION[id_usr];
            $resultado = $this->dao->modificar ($this->datos);
            
            $this->smarty->assign('codigo', $resultado);
            $this->smarty->display ($this->path.$file.".phtml");
            return;      
        }
        /**
        * Funcion que muestra un formulario que facilita al usuario un cambio de contraseña
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function muestraModificarPass($params, $file)
        {
            if($_SESSION[privilegios] == 9)
            {
                $id = $params->getParam ('id');
                $this->smarty->assign ('id', $id);   
            }
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que cambia la password del usuario
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function modificarPass ($params, $file)
        {
            
            if($_SESSION[privilegios] == 9)
            {
                $id = $params->getParam ('id');
                $this->recibirFormulario ($params, "cambiapass");
                $resultado = $this->dao->modificar (array("id_usuario" => $id, "password" => $this->datos[password]));
            }else{
                $this->datos = $this->dao->buscar (array("id_usuario" => $_SESSION[id_usr]));
                $resultado = 0;
                if (is_array($this->datos))
                {
                    $vieja = $this->datos[1][0][password];
                    $this->recibirFormulario ($params, "cambiapass");
                    if (!strncmp ($vieja, $this->datos[passact], strlen($vieja)))
                        $resultado = $this->dao->modificar (array("id_usuario" => $_SESSION[id_usr], "password" => $this->datos[password]));
                }
            }
            $this->smarty->assign ('codigo', $resultado);
            $this->smarty->display ($this->path."actualizar.phtml");
            return;   
        }
        /**
        * Funcion que cierra la sesion del usuario
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function logout ($params, $file)
        {
            if(($_SESSION[privilegios] >= 4) && ($_SESSION[privilegios] < 9)) 
                $this->logger->save(LOG_LOGOUT, "Satisfactoriamente");
            session_destroy();
            $this->smarty->assign ('autenticado', 0);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que da de baja un usuario y borra todos sus datos de la BD
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function baja ($params, $file)
        {
            if ($_SESSION[privilegios] == 9)
                $resultado = $this->dao->borrar(array("id_usuario" => $params->getParam ('id')));
            else{
            $resultado = $this->dao->borrar(array("id_usuario" => $_SESSION[id_usr]));
            if($resultado == 1)
                session_destroy();
            }
            $this->smarty->assign ('codigo', $resultado);   
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que muestra el formulario para contratar la aplicacion
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function muestraRegApp ($params, $file)
        {
            if(isset($_SESSION[id]))
                $this->smarty->assign ('registrado', 1);
            else
                $this->smarty->assign ('registrado', 0);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que añade un nuevo suscriptor a la BD
        * 
        * Esta funcion tiene un comportamiento diferente dependiendo de la situacion en que esté el usuario.
        * Si no es usuario registrado, primero registra sus datos, luego los correspondientes al pago y finalmente extiende los privilegios.
        * Si es usuario registrado pero no tiene sesion abierta, se pide su login y contraseña. Se guardan los datos del pago y se extienden los privilegios.
        * Si es usuario registrado y tiene sesion abierta, se guardan los datos del pago y se extienden sus privilegios.
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function nuevoSuscriptor ($params, $file)
        {
            $fechafin = $this->fechaFin($params);
            $pago = new PagoDAO ();
            $registrado = $params->getParam ('Reg');
            if($registrado == "false")
            {
                $this->recibirFormulario ($params);
                $this->datos[privilegios] = 1;
                $resultado = $this->dao->buscar (array("login" => $this->datos[login]));
                if(is_array($resultado))
                {
                    //Login repetido
                    $this->smarty->assign ('codigo', -2);
                    $this->smarty->display ($this->path."altausuario.phtml");
                    return;
                }
                $nuevoid = $this->dao->nuevo ($this->datos);
                if($nuevoid <= 0)
                {
                    //Error insertando
                    $this->smarty->assign ('codigo', $nuevoid);
                    $this->smarty->display ($this->path."altausuario.phtml");
                    return;
                } 
                $this->dao->start(); 
                $this->datos[id_usuario] = $nuevoid;
                $this->datos[privilegios] = 4;
                $this->datos[fin_suscripcion] = $fechafin;
                $datos_usuario = $this->datos;
                $this->datos = array();   
                $this->recibirFormulario ($params, "pago");
                $this->datos[fecha] = strftime ("%d-%m-%Y");
                $this->datos[id_usuario] = $nuevoid;
                $resultado = $pago->nuevo ($this->datos);
                $this->smarty->assign ('codigo', $resultado);
                if($resultado > 0)
                {    
                    //OK
                    if($this->primerUsuario($datos_usuario))
                    {
                        if($this->dao->modificar ($datos_usuario) > 0){
                            mkdir(PATH_BASE."/imagenes/".$nuevoid);  
                            //mkdir(PAH_BASE."/imagenes/".$nuevoid."/pers"); 
                            $this->dao->commit();
                        }else
                           $this->dao->rollback(); 
                    }else
                        $this->dao->rollback();  
                }   
            }else{
                //Usuario registrado
                if(isset($_SESSION[id]))
                {
                    //Usuario conectado
                    $this->recibirFormulario ($params, "pago");
                    $this->datos[fecha] = strftime ("%d-%m-%Y");
                    $this->datos[id_usuario] = $_SESSION[id_usr];
                    $this->dao->start();
                    $resultado = $pago->nuevo ($this->datos);
                    $this->smarty->assign ('codigo', $resultado);
                    if($resultado > 0)
                    {
                        
                        $this->datos = $this->dao->ver ($_SESSION[id_usr]);
                        if($this->primerUsuario($this->datos))
                        {
                            if($this->dao->modificar (array("id_usuario" => $_SESSION[id_usr], "privilegios" => 4, "fin_suscripcion" => $fechafin)) > 0)
                            {
                                mkdir(PATH_BASE."/imagenes/".$_SESSION[id_usr]);    
                                $this->dao->commit();
                            }else
                                $this->dao->rollback();     
                        }else
                            $this->dao->rollback();      
                    }else
                        $this->dao->rollback();
                           
                }else{
                    //Usuario no conectado
                    $this->datos[login] = $params->getParam('txtLogin');
                    $recogido = $this->dao->buscar ($this->datos);
                    $this->datos[password] = $params->getParam ('txtPass');
                    if (is_array($recogido))
                    {  
                        if (!strcmp ($recogido[1][0][password], $this->datos[password]))
                        {
                            //Login - Pass encontrados
                            $this->datos = array();
                            $this->recibirFormulario ($params, "pago");
                            $this->datos[fecha] = strftime ("%d-%m-%Y");
                            $this->datos[id_usuario] = $recogido[1][0][id_usuario];
                            $this->dao->start();
                            $resultado = $pago->nuevo ($this->datos);
                            $this->smarty->assign ('codigo', $resultado);
                            if($resultado > 0)
                            {
                                $this->datos = $this->dao->ver ($_SESSION[id_usr]);
                                if($this->primerUsuario($this->datos))
                                {
                                    if($this->dao->modificar (array("id_usuario" => $recogido[1][0][id_usuario], "privilegios" => 4, "fin_suscripcion" => $fechafin)) > 0)
                                    {
                                        mkdir(PATH_BASE."/imagenes/".$recogido[1][0][id_usuario]);
                                        $this->dao->commit();
                                    }else
                                        $this->dao->rollback(); 
                                }else
                                    $this->dao->rollback();   
                            }else
                                $this->dao->rollback();
                        }else
                            //Pass no coincide
                            $this->smarty->assign ('codigo', -3);
                    }else
                        //Login no encontrado
                        $this->smarty->assign ('codigo', -3);
                }        
            }
            
            $this->smarty->display ($this->path."altausuario.phtml");
            return;   
        }
        
        /**
        * Funcion que inserta el primer usuario como empleado en la tabla personal para dar acceso a la cuenta a partir de 
        * este momento a traves de la tabla personal
        * 
        * @param array con los datos del nuevo registro a insertar
        */
        function primerUsuario ($datos)
        {
            
            $persdao = new PersonalDAO();
            $data[nombre] = "#"; 
            $data[apellido] = "#"; 
            $data[apellido2] = "#";
            $data[login] = $datos[login];
            $data[password] = $datos[password];
            $data[id_usuario] = $datos[id_usuario];
            $data[privilegios] = 4;
            
            $ret = $persdao->nuevo($data);
            
            return $ret > 0 ? true : false;
        }
        /**
        * Funcion que calcula la fecha de fin de suscripcion de un usuario
        * 
        * A partir del tiempo de contratacion introducido por el usuario, se devuelve la fecha que sera fin de su suscripcion
        * @param resource Objeto de tipo params para recoger el valor del tiempo 
        * @return string Cadena que marca la fecha de fin de suscripcion de un usuario
        */
        function fechaFin ($params)
        {
            $tiempo = $params->getParam ('txtTiempo');
            $annios = $tiempo / 12;
            $annios1 = $annios;
            $annios = round ($annios);
            if($annios > $annios1)
                $annios --;
            $annios = idate("Y") + $annios;
            $meses = $tiempo % 12;
            $meses = idate("m") + $meses;
            if($meses > 12)
            {
                $annios ++;
                $meses = $meses-12;   
            }
            $dias = idate("d");
            $cadena = $dias."-".$meses."-".$annios;
            return $cadena;
        }
        /**
        * Funcion que muestra el formulario de login para acceder a la aplicacion
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function muestraLoginApp ($params, $file)
        {
            if(isset($_SESSION[id]) && $_SESSION[privilegios] == 4)
            {
                $_SESSION[start] = true;
                $this->smarty->assign ('on', 1);
                $this->smarty->assign ('autenticado', 1);
                $this->smarty->display (TPL_PATH_BASE."gbdapp/acceso/index.phtml");
                return;
            }       
            $this->smarty->display(TPL_PATH_BASE."gbdapp/acceso/login.phtml");
            return;
        }
        /**
        * Funcion que da acceso a la aplicacion al usuario en funcion de los datos introducidos como login y password
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function loginApp ($params, $file)
        {
        	$this->smarty->assign ('autenticado', 0);
            $persdao = new PersonalDAO();
            
            $login = $params->getParam('txtLogin');
            $recogido = $persdao->acceder ($login);
            $password = $params->getParam ('txtPass');
            
            if (is_array($recogido))
            {  
                if (!strcmp ($recogido[password], $password))
                {   
                    $this->abrirSesion ($recogido);
                    $_SESSION[start] = true;
                }else{
                  $this->smarty->display ($this->path."accesoapp.phtml");
                  return;
                }  
            }else{
               $this->smarty->display ($this->path."accesoapp.phtml");
               return;
            }
            
            $this->smarty->assign ('on', 1);    
            $this->smarty->assign ('privilegios', $_SESSION[privilegios]);
            $this->smarty->display (TPL_PATH_BASE."gbdapp/acceso/index.phtml");
            return;   
          
        }
        /**
        * Funcion que muestra al usuario el estado de su suscripcion y sus datos personales.
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function verSuscripcion ($params, $file)
        {
            $this->smarty->assign ('on', 1);
            $pago = new PagoDAO();
            $this->datos = $this->dao->ver ($_SESSION[id_usr]);
            if(is_array ($this->datos))
                $this->smarty->assign ('usuario', $this->datos[0]);
            else{
                $this->smarty->assign ('resultados', 0);
                $this->smarty->display ($this->path.$file.".phtml");
                return;   
            }
            $this->datos = array();
            $this->datos = $pago->listado ($_SESSION[id_usr]);
            if(is_array ($this->datos))
            {
                $this->smarty->assign ('resultados', $this->datos[0]);
                $this->smarty->assign ('pagos', $this->datos[1]);   
            }else
                $this->smarty->assign ('resultados', 0);
            
            $this->smarty->display ($this->path.$file.".phtml");   
        }
        /**
        * Funcion que muestra un listado de todos los usuarios al administrador
        * 
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function listado ($params, $file)
        {
            $this->datos = $this->dao->listado (0);
            $this->smarty->assign ('datos', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;       
        }
        /**
        * Funcion que muestra un listado con todos los pagos de los suscriptores
        * 
        * @param resource Objeto de la clase params para acceder a los parametros de la peticion
        * @param string Archivo que se ha solicitado para ser mostrado
        * @return void
        */
        function listaPagos ($params, $file)
        {
            $dao = new PagoDAO ();
            $this->datos = $dao->listado (0);
            if(is_array ($this->datos))
            {
                $this->datos = $this->datos[1];
                foreach ($this->datos as $indice => $valor)
                {
                    $this->datos[$indice][usuario] = $this->getUsr ($this->datos[$indice][id_usuario]);          
                }
                $this->smarty->assign ('datos', $this->datos);
            }   
            
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        /**
        * Funcion que busca y devuelve el nombre del usuario
        * 
        * @param int Id del usuario
        * @return string
        */
        function getUsr ($id)
        {
            $datos = $this->dao->ver ($id);
            if(is_array ($datos))
            {
                $cadena = $datos[0][apellido]." ".$datos[0][apellido2].", ".$datos[0][nombre];
                return $cadena;
            }   
            return;
        }
    }
?>