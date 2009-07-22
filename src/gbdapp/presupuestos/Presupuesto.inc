<?php
    /**
    * Fichero que recoje la implementación de la clase Presupuesto
    * 
    * @package Negocio
    * @subpackage Presupuestos
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (16 - Enero - 2008)
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la lógica de presentación de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo PresupuestoDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/presupuestos/PresupuestoDAO.inc";
    /**
    * Inclusion del archivo LineaPresDAO para tener acceso a los datos de cada línea de presupuesto
    */
    include_once PATH_BASE."src/gbdapp/presupuestos/LineaPresDAO.inc";
    /**
    * Inclusion del archivo PacienteDAO para tener acceso a los datos de los pacientes
    */
    include_once PATH_BASE."src/gbdapp/pacientes/PacienteDAO.inc";
    /**
    * Inclusion del archivo OpcionesDAO para tener acceso a los datos de la clinica
    */
    include_once PATH_BASE."src/gbdapp/conf/OpcionesDAO.inc";
    /**
    * Inclusion del archivo Logger para sacar log
    */
    include_once PATH_BASE."src/gbdapp/log/Logger.inc";
    
    /**
    * Clase Presupuesto. Implementa toda la lógica de manejo de datos y peticiones para el objeto Presupuesto
    * @package Negocio
    * @subpackage Presupuestos
    */
    class Presupuesto extends DisplayManager
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
        * Almacenará la dirección de la carpeta donde estan las imagenes del paciente
        * @var string
        */ 
        private $carpeta;
        /**
        * Almacenará el identificador del paciente con que se está trabajando
        * @var int
        */
        private $id;
        /**
        * Almacenará la referencia a su objeto logger
        * @var resource
        */
        private $logger;
        /**
        * Almacenará el nombre del paciente
        * @var string
        */
        private $nombre;
        
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @param int Identificador del paciente sobre el que se esta trabajando
        * @return void
        */
        function Presupuesto ($lang, $id)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/presupuestos/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 3);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            $this->dao = new PresupuestoDAO();
            $this->id = $id; 
            $this->carpeta = PATH_BASE."imagenes/".$_SESSION[id_usr]."/id$id/";
            $this->nombre = $this->cargaPaciente ($id); 
            $this->nombre = "Presupuesto de: ".$this->nombre;
            $this->logger = new Logger($lang);
            $this->cargaOpciones ();
            return; 
        }
        /**
        * Funcion que recoje y carga la informacion del paciente que se mostrará en la cabecera
        * @param int Id del usuario del que se quiere tomar la extension de la foto
        * @return void
        */
        function cargaPaciente ($id)
        {
            $aux = new PacienteDAO;
            $datos = $aux->ver ($id); 
            $this->smarty->assign ('paciente', $datos);
            return $datos[apellido]." ".$datos[apellido2].", ".$datos[nombre];      
        }
        /**
        * Funcion que muestra un listado con todos los presupuestos del paciente
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function listado ($params, $file)
        {
            $this->datos = $this->dao->listado ($this->id);
            $this->smarty->assign ('datos', $this->datos[1]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que muestra un formulario para crear un nuevo presupuesto
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function muestraFormulario ($params, $file)
        {
            $this->cargaSelector();  
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        /**
        * Funcion que recoje y carga el listado de servicios para el selector
        * @return void
        */
        function cargaSelector()
        {
            $dao = new ServicioDAO ();
            $datos = $dao->listado(0);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach($datos as $linea)
                    $servicios[$linea[id_servicio]] = $linea[nombre]." --- ".$linea[precio_unitario]."€";
                $this->smarty->assign ('servicios', $servicios);      
            }  
            return; 
        }
        /**
        * Funcion que recoje los datos de la nueva linea y sigue con la creacion del presupuesto
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function nuevaLinea ($params, $file)
        {
            $this->datos[id_servicio] = $params->getParam ('selServicio');
            $this->datos[cantidad] = $params->getParam ('txtCuantos');
            $this->datos[unitario] = $params->getParam ('txtUnitario');
            $temp = $this->verServicio ($this->datos[id_servicio]);
            $this->datos[total] = $this->datos[unitario] * $this->datos[cantidad];
            $this->datos[servicio] = $temp[nombre];
            /*
            * Si el array de sesion para este presupuesto no existe lo creamos
            */
            if(!isset($_SESSION['lp'.$this->id]))
                $_SESSION['lp'.$this->id] = array();
                
            array_push($_SESSION['lp'.$this->id], $this->datos);
            
            $this->smarty->assign ('datos', $_SESSION['lp'.$this->id]);
            
            $this->datos = $this->recibirFormulario ($params);
            $id = $params->getParam ('pres');
            if($id)
            {
                $this->datos[id_presupuesto] = $id;
            }
            $this->smarty->assign ('presup', $this->datos);
            
            if($file == 'nuevalineamp')
                $this->muestraFormulario ($params, "modpres");
            else
                $this->muestraFormulario ($params, "nuevopres");
                  
            return;
        }
        /**
        * Funcion que busca y devuelve las propiedades del servicio solicitado
        * @param int Id del servicio
        * @return array
        */
        function verServicio ($id)
        {
            $datos = array();
            $aux = new ServicioDAO();
            $datos = $aux->ver ($id);
            $devolver = array ("nombre" => $datos[0][nombre], "precio" => $datos[0][precio_unitario]);
            return $devolver;    
        }
        /**
        * Funcion que quita la linea seleccionada del presupuesto que se esta creando
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function borraLinea ($params, $file)
        {
            $temp = array();
            $num = $params->getParam ('num');
            for ($i = 0; $i<count($_SESSION['lp'.$this->id]); $i++) 
            {
                if($i == $num)
                    continue;
                array_push ($temp, $_SESSION['lp'.$this->id][$i]);   
            }
            $_SESSION['lp'.$this->id] = $temp;
            $this->smarty->assign ('datos', $_SESSION['lp'.$this->id]);
            
            $this->datos = $this->recibirFormulario ($params);
            $id = $params->getParam ('pres');
            if($id)
            {
                $this->datos[id_presupuesto] = $id;
            }
            $this->smarty->assign ('presup', $this->datos);
            
            if($file == 'borralineamp')
                $this->muestraFormulario ($params, "modpres");
            else
                $this->muestraFormulario ($params, "nuevopres");
        
            return;
        }
        /**
        * Funcion que guarda el los datos del presupuesto y de las lineas del mismo recibidas
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function nuevo ($params, $file)
        {
            $ldao = new LineaPresDAO();
            $this->datos = $this->recibirFormulario ($params);
            $image = base64_decode($this->datos['image']);
             
            Utils::log_info("Starting new presupuesto register.");
            $this->dao->start();
            $numero = $this->dao->bloquear($this->id);
            $this->datos[numero] = $numero[1][0][numero] + 1;
            Utils::log_debug("Number ".$this->datos[numero]." assigned to the new presupuesto.");
            $this->datos = $this->dao->nuevo ($this->datos);
            if($this->datos > 0)
            { 
            	Utils::log_debug("Presupuesto register stored successfully with id: ".$this->datos);
                Utils::log_info("Starting register of ".count($_SESSION['lp'.$this->id])."lines for presupuesto id: ".$this->datos);
                $linesArray = Utils::print_array($_SESSION['lp'.$this->id]);
                Utils::log_debug("Storing lines: $linesArray");
                foreach ($_SESSION['lp'.$this->id] as $linea)
                {
                    $linea[id_presupuesto] = $this->datos;
                    $linea[id_usuario] = $_SESSION[id_usr]; 
                    $aux = $ldao->nuevo ($linea); 
                    if($aux < 1)
                    {
                    	Utils::log_error("An error ocurred storing the line!! Rolling back");
                        $this->dao->rollback ();
                        $this->smarty->assign ('codigo', 0);
                        $this->smarty->display ($this->path.$file.".phtml");
                        return; 
                    } else {
                        Utils::log_info("New stored line was given id: $aux");
                    }
                }
                $this->logger->save(LOG_ALTA, $this->nombre);
                Utils::log_info("Writing signature to: ".$this->carpeta."fpres".$this->datos);
                $imageFile = fopen($this->carpeta."fpres".$this->datos, 'x');
                fwrite($imageFile, $image);
                fclose($imageFile);
                Utils::log_info("Presupuesto and lines stored successfully");
                $this->dao->commit ();
            } else {
            	Utils::log_error("An error ocurred storing the new presupuesto. ".$this->datos." code retrieved");
            	$this->dao->rollback();
            }
            
            $_SESSION['lp'.$this->id] = null; 
                
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return; 
        }
        /**
        * Funcion que recoje y devuelve todos los datos enviados por el usuario a traves del formulario
        * @param resource Objeto de la clase params para acceder a los parámetros de la peticion
        * @return array
        */
        function recibirFormulario ($params)
        {
            $datos = array();
            $datos[validez] = $params->getParam('txtValidez');
            $datos[duracion] = $params->getParam('txtDuracion');
            $datos[total] = $params->getParam('txtTotal');
            $datos[firma] = $params->getParam('txtSignData');
            $datos[image] = $params->getParam('txtSignImage');
            $fecha = strftime("%d-%m-%Y");
            $aux = explode ("-", $fecha);
            $aux[0] = (int)$aux[0];
            $aux[1] = (int)$aux[1];
            $datos[fecha] = $aux[0]."-".$aux[1]."-".$aux[2];
            $datos[id_paciente] = $this->id;
            $datos[id_usuario] = $_SESSION[id_usr];
            
            return $datos;  
        }
        /**
        * Funcion que recoje y carga la informacion de la clinica que se mostrará en la cabecera
        */
        function cargaOpciones(){
            $aux = new OpcionesDAO();
            $datos = $aux->ver(0);
            $this->smarty->assign('clinica', $datos[0]);
            return;   
        }
        /**
        * Funcion que muestra una ficha con todos los detalles del presupuesto
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function ver ($params, $file)
        {
            $ldao = new LineaPresDAO();
            $id = $params->getParam('pres');
            $this->datos = $this->dao->ver (array("id_presupuesto" => $id, "id_paciente" => $this->id));
            if(is_array($this->datos))
            {   
                $lineas = $ldao->ver ($id);
                $year = explode("-", $this->datos[0][fecha]);
	            $year = str_split($year[2], 2);
	            $this->datos[0][numero] .= "/".$year[1];   
	            $this->smarty->assign ('datos', $this->datos[0]);
	            $this->smarty->assign ('lineas', $lineas);
            }
            
            $imprimible = $params->getParam('imp');
            if($imprimible == 1)
                $file="imprimible";
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que borra todos los datos del presupuesto seleccionado
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function borrar ($params, $file)
        {
            $id = $params->getParam ('pres');
            Utils::log_info("Deleting presupuesto with id: $id");
            $this->dao->start ();
            $this->datos = $this->dao->borrar (array("id_paciente" => $this->id, "id_presupuesto" => $id));
            if($this->datos > 0)
            {
            	Utils::log_debug("Deleting signature file: ".$this->carpeta."fpres$id");
                @unlink($this->carpeta."fpres$id");
                $this->logger->save(LOG_BAJA, $this->nombre);
                Utils::log_info("Successful deletion of presupuesto with id: $id");
                $this->dao->commit ();   
            }else {
            	Utils::log_error("An error ocurred deleting the presupuesto!! Rolling back...");
                $this->dao->rollback ();
            }
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que muestra todos los datos del presupuesto en formato editable
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function muestraEditar ($params, $file)
        {
            $this->cargaSelector();
            $ldao = new LineaPresDAO();
            $id = $params->getParam('pres');
            $this->datos = $this->dao->ver (array("id_presupuesto" => $id, "id_paciente" => $this->id));
            if(is_array($this->datos))
            {   
                $lineas = $ldao->ver ($id);
                if(is_array($lineas))
                {
                    foreach($lineas as $indice => $valor)
                    {
                        $lineas[$indice][unitario] = $lineas[$indice][total] / $lineas[$indice][cantidad];
                    }
                    $_SESSION['lp'.$this->id] = array();
                    $_SESSION['lp'.$this->id] = $lineas;   
                }
            }
                
            $this->smarty->assign ('presup', $this->datos[0]);
            $this->smarty->assign ('datos', $lineas);
            
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        /**
        * Funcion que actualiza los datos del presupuesto en funcion de los nuevos introducidos por el usuario
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function actualizar ($params, $file)
        {
            $id = $params->getParam ('pres');
        
            $this->datos = $this->recibirFormulario ($params);
            $image = base64_decode($this->datos['image']);
            unset($this->datos['image']);
      
            
            $this->datos[id_presupuesto] = $id;
            Utils::log_info("Updating data of presupuesto with id: $id");
            $this->dao->start ();
            
            $ldao = new LineaPresDAO();
            $lborradas = $ldao->borrar ($id);
            Utils::log_debug("$lborradas lines deleted of the presupuesto");
            Utils::log_info("Starting register of ".count($_SESSION['lp'.$this->id])."lines for presupuesto id: ".$this->datos);
            Utils::log_debug("Inserting this lines: ".Utils::print_array($_SESSION['lp'.$this->id]));
            
            foreach ($_SESSION['lp'.$this->id] as $linea)
            {
                $linea[id_presupuesto] = $id;
                $linea[id_usuario] = $_SESSION[id_usr]; 
                $aux = $ldao->nuevo ($linea); 
                if($aux < 1)
                {
                	Utils::log_error("An error ocurred storing the line!! Rolling back");
                    $this->dao->rollback ();
                    $this->smarty->assign ('codigo', 0);
                    $this->smarty->display ($this->path.$file.".phtml");
                    return; 
                } else {
                	Utils::log_info("New stored line was given id: $aux");
                }
            }
            
            Utils::log_info("Updating now presupuesto register data");
            $this->datos = $this->dao->modificar ($this->datos);
            if($this->datos >= 0){
            	Utils::log_info("Factura data was updated successfully!");
            	Utils::log_debug("Deleting old signature at: ".$this->carpeta."fpres$id");
            	@unlink($this->carpeta."fpres$id");
            	Utils::log_debug("Writing new signature to: ".$this->carpeta."fpres$id");
            	$imageFile = fopen($this->carpeta."fpres$id", 'x');
                fwrite($imageFile, $image);
                fclose($imageFile);
                $this->logger->save(LOG_MODIFICACION, $this->nombre);
                $this->dao->commit ();
                $this->smarty->assign ('codigo', $id);
            }else {
            	Utils::log_error("An error ocurred updating data!! Rolling back...");
                $this->dao->rollback ();
                $this->smarty->assign ('codigo', 0);
            }
            
            $_SESSION['lp'.$this->id] = null;
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
    }
?>
