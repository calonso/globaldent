<?php
    /**
    * Archivo que recoje la implementación de la clase Contabilidad
    * 
    * @package Negocio
    * @subpackage Contabilidad
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (16 - Enero - 2008)
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la lógica de presentación de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo VisitaDAO para tener acceso a los datos de las visitas
    */
    include_once PATH_BASE."src/gbdapp/visitas/VisitaDAO.inc";
    /**
    * Inclusion del archivo LineaVisitaDAO para tener acceso a los datos de las visitas
    */
    include_once PATH_BASE."src/gbdapp/visitas/LineaVisitaDAO.inc";
    /**
    * Inclusion del archivo PacienteDAO para tener acceso a los datos de los pacientes
    */
    include_once PATH_BASE."src/gbdapp/pacientes/PacienteDAO.inc";
    /**
    * Inclusion del archivo ServicioDAO para tener acceso a los datos de los servicios
    */
    include_once PATH_BASE."src/gbdapp/conf/ServicioDAO.inc";
    /**
    * Inclusion del archivo PagoPacDAO para tener acceso a los datos de los pagos de cada paciente
    */
    include_once PATH_BASE."src/gbdapp/pacientes/PagoPacDAO.inc";
    /**
    * Inclusion del archivo FacturaDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/facturas/FacturaDAO.inc";
    /**
    * Inclusion del archivo Logger
    */
    include_once PATH_BASE."src/gbdapp/log/Logger.inc";
    
    /**
    * Clase Contabilidad. Implementa toda la lógica de manejo de datos económicos
    * @package Negocio
    * @subpackage Contabilidad
    */
    class Contabilidad extends DisplayManager
    {
        /**
        * Variable que almacenará los datos y servirá de objeto de intercambio de datos con el dao
        * @var array
        */
        private $datos;
        /**
        * Almacenará la referencia a su objeto Logger
        */
        private $logger;
        
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @return void
        */
        function Contabilidad ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/conta/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 7);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            $this->logger = new Logger($lang);
            return; 
        } 
        /**
        * Funcion que muestra la pantalla principal para la contabilidad
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void  
        */
        function index ($params, $file)
        {
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que muestra la caja para el dia seleccionado
        * 
        * Busca todas las visitas del dia seleccionado, busca los pagos del dia seleccionado
        * Finalmente calcula los dias actual, siguiente y anterior para el funcionamiento de los enlaces
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function verCaja ($params, $file)
        {
            $dao = new VisitaDAO ();
            
            $fechahoy = strftime ("%d-%m-%Y");
            $aux = explode ("-", $fechahoy);
            $aux[0] = (int)$aux[0];
            $aux[1] = (int)$aux[1];
            $fechahoy = $aux[0]."-".$aux[1]."-".$aux[2];
            
            $fecha = $params->getParam ('f');
            //Recoje todas las visitas a dia de $fecha
            if((!$fecha) || ($fecha == $fechahoy))
            {
                $this->datos = $dao->verCaja ($fechahoy);
                $file = "vercaja";
                $fechacal = $fechahoy;
                $fecha = $fechahoy;
            }else{
                $this->datos = $dao->verCaja ($fecha);
                $file = "vercajaotro";
                $fechacal = $fecha;
            }
            
            if(is_array($this->datos))
            {
                //Si se recogieron datos se procesan.
                $this->datos = $this->datos[1];
                $resultados = array(); 
                $ids_pacientes = array();
                
                //Calculo los valores para el primer paciente
                $currId = $this->datos[0][id_paciente];
                $temp[paciente] = $this->datos[0][paciente];
                $temp[saldo] = $this->datos[0][saldo];
                $temp[id_paciente] = $currId;
                array_push($ids_pacientes, $temp[id_paciente]);
                $temp[pagos] = array("tarj" => (int)$this->datos[0][tarj], "efect" => (int)$this->datos[0][efect]);
                
                $tratamiento = "";
                $precioVisita = 0;
                foreach ($this->datos as $linea)
                {   
                    if($currId != $linea[id_paciente])
                    {   //Cambio de paciente
                        $temp[tratamiento] = $tratamiento;
                        $temp[precio] = $precioVisita;
                        array_push($resultados, $temp);
                        //Cargo los datos del proximo
                        $temp[paciente] = $linea[paciente];
                        $temp[id_paciente] = $linea[id_paciente];
                        $temp[saldo] = $linea[saldo];
                        array_push($ids_pacientes, $temp[id_paciente]);
                        $temp[pagos] = array("tarj" => (int)$linea[tarj], "efect" => (int)$linea[efect]);
                        //Reseteo las variables para empezar con el proximo
                        $currId = $linea[id_paciente];
                        $tratamiento = "";
                        $precioVisita = 0;
                    }       
                    $tratamiento .= $linea[servicio];
                    $precioVisita += $linea[total];   
                }
                $temp[tratamiento] = $tratamiento;
                $temp[precio] = $precioVisita;
                array_push($resultados, $temp);  
            }
            $this->smarty->assign ('visitas', $resultados);
            
            $this->datos = $dao->verPagosSueltos($ids_pacientes, $fecha);
            
            $this->smarty->assign ('pagos', $this->datos);
            
            $dias = $this->calcularDias ($fechacal);
            $this->smarty->assign ('dias', $dias);
            
            if($params->getParam('imp') == 1)
                $this->smarty->display ($this->path."imprimible.phtml");    
            else
                $this->smarty->display ($this->path.$file.".phtml");
            return;        
        }       
        /**
        * Funcion que recoje y carga los datos necesarios del paciente solicitado
        * @param int Id del paciente del que se quieren recojer los datos
        * @return array
        */
        function getPaciente ($id)
        {
            $datos = array();
            $devolver = array();
            $dao = new PacienteDAO ();
            
            $datos = $dao->ver ($id);
            if(is_array($datos))
            {
                $datos = $datos;
                $devolver[nombre] = $datos[apellido]." ".$datos[apellido2].", ".$datos[nombre];
                $devolver[id] = $datos[id_paciente];    
            }
            return $devolver;
        }
        /**
        * Funcion que recoje todas las lineas de cada visita y pide su nombre a getServicio
        * @param int Id de la visita que se quiere consultar
        * @return array
        */
        function verTratamiento ($id)
        {
            $aux = new LineaVisitaDAO ();
            $lineas = $aux->ver ($id);
            if(is_array($lineas))
            {
                foreach ($lineas as $indice => $valor)
                    $lineas[$indice][servicio] = $this->getServicio ("nombre", $lineas[$indice][id_servicio]);    
            }
            return $lineas;    
        }
        
        /**
        * Funcion que recoje y carga el nombre del servicio solicitado
        * @param int Id del servicio solicitado
        * @return string||void
        */
        function getServicio ($motivo, $id)
        {
            $aux = new ServicioDAO ();
            $datos = $aux->ver ($id);
            if(is_array($datos))
            {
                $cadena = $datos[0][nombre];
                $precio = $datos[0][precio_unitario];
            }
            switch ($motivo)
            {
                case "nombre":
                    return $cadena;
                    break;
                case "precio":
                    return $precio;
                    break;
                case "todo":
                    return array("nombre" => $cadena, "precio" => $precio);
                    break;   
            }   
        }
        /**
        * Funcion que calcula los dias siguiente y previo a uno dado y los devuelve
        * @param string Cadena con la fecha sobre la que se quiere operar
        * @return array
        */
        function calcularDias ($fecha)
        {
            $aux = explode ("-",$fecha);
            $dia = $aux[0];
            $mes = $aux[1];
            $annio = $aux[2];
            $dias[hoy] = $fecha;
            $dias[cal] = $aux[2]."/".$aux[1]."/".$aux[0];
            $diam = (int)$dia + 1;
            $diaa = (int)$dia -1;
            $mesm = $mesa = $mes;
            $anniom = $annioa = $annio;
            
            if($diam == 31) 
            {
                switch($mes)
                {
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        $diam = 1;
                        $mesm ++;
                        break;          
                }
            } 
            if($diam == 32)
            {
                $diam = 1;
                if($mes == 12)
                {
                    $mesm = 1;
                    $anniom ++;
                }else
                    $mesm ++;   
            }
            if(($diam == 29)&&($mes == 2))
            {
                $diam = 1;
                $mesm ++;       
            } 
            if($diaa == 0)
            {
                $mesa --;
                switch ($mesa)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                        $diaa = 31;
                        break;
                    case 2:
                        $diaa = 28;
                        break;
                    case 0:
                        $diaa = 31;
                        $mesa = 12;
                        $annioa --;
                        break;
                    default:
                        $diaa = 30;
                        break;
                }
            }
                $dias[mannana] = $diam."-".$mesm."-".$anniom;
                $dias[ayer] = $diaa."-".$mesa."-".$annioa;
                return $dias;                    
        }
        /**
        * Funcion que crea un nuevo pago
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function cobrar ($params, $file)
        {
            $dao = new PagoPacDAO ();
            $this->datos = $this->recibirFormulario ($params);
            
            $id = $this->datos[id_paciente];
            $tarj = $this->datos[total_tarjeta];
            $efect = $this->datos[total_efectivo];
            
            $this->datos = $dao->nuevo ($this->datos);
            if ($this->datos >= 1)
            {
                $aux = $this->getPaciente($id);
                $nombre = $aux[nombre]; 
                $this->logger->save(LOG_ALTA, "Pago de: $nombre por valor de: $tarj y $efect");          
            }else
                echo "<br /><br />Se ha producido un error, el pago no se ha guardado<br /><br />";
                
            $this->verCaja ($params, "vercaja");
                
            return;   
        }
        /**
        * Funcion que modifica los datos de un pago seleccionado
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function modificaPago ($params, $file)
        {
            $dao = new PagoPacDAO ();
            $this->datos = $this->recibirFormulario ($params);
            
            $id = $this->datos[id_paciente];
            $tarj = $this->datos[total_tarjeta];
            $efect = $this->datos[total_efectivo];
            
            $this->datos[id_pago] = $params->getParam('idp');
            unset($this->datos[fecha]);
            $this->datos = $dao->modificar ($this->datos);
            
            $aux = $this->getPaciente($id);
            $nombre = $aux[nombre];
            
        	$referer = $_SERVER[HTTP_REFERER];
            if (strpos($referer, "actualizapagopac") === false){
            	$this->logger->save(LOG_MODIFICACION, "Pago de: $nombre por valor de: $tarj y $efect");
            	$this->verCaja ($params, "vercaja");
            } else {
            	header('Location: '.REQ_BASE.'index.php/cod.historiaecon/id.'.$id);
            }
            return;
        }
        /**
        * Funcion que borra los datos de un pago seleccionado
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function borraPago ($params, $file)
        {
            $dao = new PagoPacDAO (); 
            $id = $params->getParam('idp'); 
            $idpac = $params->getParam('idpaciente');
            $dao->borrar ($id);
            
            $aux = $this->getPaciente($idpac);
            $nombre = $aux[nombre]; 
            
            $referer = $_SERVER[HTTP_REFERER];
            echo $referer;
            if (strpos($referer, "historiaecon") === false){
            	$this->logger->save(LOG_BAJA, "Pago de: $nombre");
            	$this->verCaja ($params, "vercaja");
            } else {
            	header('Location: '.REQ_BASE.'index.php/cod.historiaecon/id.'.$idpac);
            }
            return;  
        }
        /**
        * Funcion que recoje los datos del pago enviados por el usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @return array
        */ 
        function recibirFormulario ($params)
        {
            $datos = array();
            
            $datos[id_paciente] = $params->getParam ('idpaciente');
            $fecha = strftime ("%d-%m-%Y");
            $aux = explode ("-", $fecha);
            $aux[0] = (int)$aux[0];
            $aux[1] = (int)$aux[1];
            $datos[fecha] = $aux[0]."-".$aux[1]."-".$aux[2];
            $datos[total_tarjeta] = $params->getParam ('tarjeta');
            $datos[total_efectivo] = $params->getParam ('efectivo');
            $datos[id_usuario] = $_SESSION[id_usr];
            
            return $datos;
        }
        /**
        * Funcion que muestra un listado con todos los pacientes con saldo negativo
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function verPendientes ($params, $file)
        {
            $dao = new VisitaDAO();
            $this->datos = $dao->deudores(0);
            if (is_array ($this->datos))
            {
                $this->smarty->assign ('datos', $this->datos);
            }else
                $this->smarty->assign ('datos', 0);
            
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que muestra la pantalla de edición de un pago
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraEditar ($params, $file)
        {
            $dao = new PagoPacDAO();
            $idpac = $params->getParam('id');
            $fechahoy = strftime ("%d-%m-%Y");
            $aux = explode ("-", $fechahoy);
            $aux[0] = (int)$aux[0];
            $aux[1] = (int)$aux[1];
            $fechahoy = $aux[0]."-".$aux[1]."-".$aux[2];
            $this->datos = $dao->buscar(array("id_paciente" => $idpac, "fecha" => $fechahoy));
            
            if (is_array ($this->datos))
            {    
                $this->smarty->assign ('pagos', $this->datos[1]);
                $this->smarty->assign ('paciente', $this->getPaciente($idpac));
            }
            
            $this->smarty->display ($this->path.$file.".phtml");
        }
        
    	/**
        * Funcion que muestra la pantalla de edición de un pago
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraEditarPago ($params, $file)
        {
            $dao = new PagoPacDAO();
            $idpac = $params->getParam('id');
            $idpago = $params->getParam('idp');
            $this->datos = $dao->ver($idpago);
            
            if (is_array ($this->datos))
            {    
                $this->smarty->assign ('pago', $this->datos[0]);
                $this->smarty->assign ('paciente', $this->getPaciente($idpac));
            }
            
            $this->smarty->display ($this->path.$file.".phtml");
        }
		/**
        * Funcion que muestra un listado de facturas
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
		 */
        function listaFacturas ($params, $file)
        {
        	$dao = new FacturaDAO();
        	$years = $dao->yearList();
        	$year = $params->getParam('year');
        	if (is_array($years)){
	        	if (empty($year)){
	        		$year = $years[0][year];
	        	}
        		$tmp = array();
        		/*
        		 * tmp quedará un array de la forma {[2009]=>2009, [2008]=>2008}, etc para 
        		 * que sea más facil usarlo en el html select
        		 */
        		foreach($years as $indice => $valor){
        			$tmp[$years[$indice][year]] = $years[$indice][year];	
        		}
        		$years = $tmp;
	        	$this->datos = $dao->fullListByYear($year);
        	}
        	
        	$this->smarty->assign ('datos', $this->datos);
        	$this->smarty->assign ('years', $years);
        	$this->smarty->assign ('selected', $year);
        	$this->smarty->display ($this->path.$file.".phtml");
        }
    }
?>