<?php
    /**
    * Fichero que recoge la implementación de la clase Cita
    * 
    * @package Negocio
    * @subpackage Visitas
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (29 - Diciembre - 2007)
    */
    
     /**
    * Inclusion del fichero DisplayManager para tener acceso a la logica de presentacion de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del fichero CitaDAO para tener acceso a la logica de almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/agenda/CitaDAO.inc";
    /**
    * Inclusion del fichero PacienteDAO para tener acceso a la logica de acceso a datos relativos a los pacientes
    */
    include_once PATH_BASE."src/gbdapp/pacientes/PacienteDAO.inc";
    /**
    * Inclusion del fichero OpcionesDAO para tener acceso a la logica de acceso a datos relativos a configuracion
    */
    include_once PATH_BASE."src/gbdapp/conf/OpcionesDAO.inc";
    /**
    * Inclusion del fichero Logger para sacar log
    */
    include_once PATH_BASE."src/gbdapp/log/Logger.inc";
    
    /**
    * Clase Cita. Implementa toda la lógica de negocio para los elementos cita
    * @package Negocio
    * @subpackage Visitas
    */
    class Cita extends DisplayManager
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
        * Almacenará la referencia al objeto Logger
        * @var resource
        */
        private $logger;
        
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @return void
        */
        function Cita ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/agenda/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 2);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
                        
            $this->datos = array();
            $this->dao = new CitaDAO();  
            $this->logger = new Logger($lang);
            return; 
        }
        /**
        * Funcion que muestra la agenda para el dia en curso
        * @param resource Objeto de tipo Params para tener acceso a los parámetros de la petición.
        * @param string Archivo que se ha solicitado
        * @return void   
        */
        function verAgenda ($params, $file)
        {
            $fecha = $params->getParam('dia');
            if(!isset($fecha))
            {
                $fecha = $this->fechas->getFecha(); 
            }
            $horas = array("8:00", "8:30", "9:00", "9:30", "10:00", "10:30", "11:00", "11:30", "12:00", "12:30", "13:00", "13:30", "14:00",
                "14:30", "15:00", "15:30", "16:00", "16:30", "17:00", "17:30", "18:00", "18:30", "19:00", "19:30", "20:00", "20:30",
                "21:00", "21:30", "22:00");
            
            $citas = array();
            $bloqueos = array();
            $iteraciones = 0;
            foreach($horas as $valor)
            {
                $iteraciones ++;
                $this->datos = $this->dao->verDia ($fecha, $valor);
                if(is_array($this->datos))
                {
                    foreach ($this->datos as $indice => $valor) {
                        if ($this->datos[$indice][bloqueado]){
                            if($iteraciones <= 16){
                                //Se asigna el id mayor que 0 y menor a partir del que se conocen el resto de 
                                //bloqueos. Esto se usa para luego poder desbloquear
                                $new = (int)$this->datos[$indice][id_cita];
                                $index = $this->datos[$indice][gabinete];
                                $currId = (int)$bloqueos[$index][AM];
                                $bloqueos[$index][AM] = $currId < $new && $currId > 0? $currId : $new;
                            } else {
                                $new = (int)$this->datos[$indice][id_cita];
                                $index = $this->datos[$indice][gabinete];
                                $currId = (int)$bloqueos[$index][PM];
                                $bloqueos[$index][PM] = $currId < $new && $currId > 0 ? $currId : $new;
                            }
                        }
                    }
                }
                array_push($citas, $this->datos);
            }
            $dias = $this->calcularDias ($fecha);
            $opts = new OpcionesDAO ();
            $temp = $opts->ver (0);
            if(is_array ($temp))
                $gabs = $temp[0][gabinetes] + 1;
            else 
                $gabs = 0;
            
            $this->smarty->assign ('citas', $citas);
            $this->smarty->assign ('horas', $horas);
            $this->smarty->assign ('gabinetes', $gabs);
            $this->smarty->assign ('dias', $dias);
            $this->smarty->assign ('bloqueos', $bloqueos);
            
            if($params->getParam('imp') == 1)
                $this->smarty->display ($this->path."imprimible.phtml");
            else
                $this->smarty->display ($this->path.$file.".phtml");
                
            return;
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
        * Funcion que muestra un formulario con los campos necesarios a rellenar para abrir una nueva cita
        * @param resource Objeto de tipo Params para tener acceso a los parámetros de la petición.
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function muestraFormulario ($params, $file)
        {
            $this->datos[fecha] = $params->getParam ('f');
            $this->datos[hora] = $params->getParam ('h');
            $this->datos[asiento] = $params->getParam ('a');
            $this->smarty->assign ('datos', $this->datos);
            $this->cargaPacientes ();
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que carga un listado de todos los pacientes dados de alta en la BD para asignarle la cita a alguno
        * @return void
        */
        function cargaPacientes ()
        {
            $datos = array();
            $dao = new PacienteDAO();
            $datos = $dao->listado(0);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach($datos as $linea)
                    $pacs[$linea[id_paciente]] = $linea[apellido]." ".$linea[apellido2].", ".$linea[nombre];
                $this->smarty->assign ('pacs', $pacs);      
            }
            return;    
        }
        
        /**
        * Funcion que guarda los datos de la visita en la BD
        * @param resource Objeto de tipo Params para tener acceso a los parámetros de la petición.
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function nueva ($params, $file)
        {
            $this->recibirFormulario ($params);
            $this->datos[id_usuario] = $_SESSION[id_usr];
            $fecha = $this->datos[fecha];
            $this->dao->start ();
            $ret = $this->bloquearAgenda ($this->datos);
            if($ret == true)
            {
                $resultado = $this->dao->nuevo ($this->datos);
                if($resultado > 0){
                    $this->logger->save (LOG_ALTA, "Visita para: ".$this->datos[paciente]);
                    $this->dao->commit ();
                }else
                    $this->dao->rollback ();
            }else{
                $this->dao->rollback();
                $resultado = -1;
            }
            $this->smarty->assign ('codigo', $resultado);
            $this->smarty->assign ('fecha', $fecha);
            $this->smarty->display ($this->path.$file.".phtml");   
        }
        /**
        * Funcion que bloquea los registros de la agenda pertenecientes al usuario para preparar la insercion en condiciones de concurrencia
        * y mantener la integridad de los datos
        * 
        * @param array Array con los datos de la nueva cita
        * @return bool
        */
        function bloquearAgenda ($info)
        {
            do{
                $datos = $this->dao->bloquear ($info[fecha], $info[gabinete]);
            }while ($datos == -1); 
            
            if(is_array($datos))
                return $this->comprobarDisponible ($datos[1], $info);
            else
                return true;   
        }
        /**
        * Funcion que comprueba que los recursos solicitados estan disponibles para ocuparlos
        * 
        * @param array Array con los datos recuperados de la BD
        * @param array Array con los datos de la nueva cita
        * @return bool 
        */
        function comprobarDisponible ($datos, $info)
        {
            $temp = explode(":", $info[hora]);
            $inicio = $temp[0] * 60 + $temp[1];
            $fin = $inicio + $info[duracion] * 30;
            
            if($fin > 1350)
                return false;
            
                
            foreach ($datos as $cita)
            {
                $temp = explode(":", $cita[hora]);
                $init = $temp[0] * 60 + $temp[1];
                $finit = $init + $cita[duracion] * 30;
                if(($finit <= $inicio)||($init >= $fin))
                    continue;
                else
                    return false; 
            }
            return true;      
        }
        /**
        * Funcion que recoje los datos del formulario enviados por el usuario
        * @param resource Objeto de tipo Params para tener acceso a los parámetros de la petición
        * @return void
        */
        function recibirFormulario ($params)
        {
            $this->datos[fecha] = $params->getParam ("txtFecha");   
            $this->datos[hora] = $params->getParam ("txtHora");
            $this->datos[duracion] = $params->getParam ("txtDuracion");
            $this->datos[gabinete] = $params->getParam ("txtAsiento");
            $this->datos[observaciones] = $params->getParam ("txtObservaciones");
            $this->datos[tipo] = $params->getParam ("txtTipo");
            $this->datos[id_paciente] = $params->getParam ("selPac");
            return;
        }
        /**
        * Funcion que borra una cita
        * @param resource Objeto de tipo Params para tener acceso a los parámetros de la petición.
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function borrar ($params, $file)
        {
            $id = $params->getParam ('id');
            $this->logger->save(LOG_BAJA, "Visita para: ".$this->getNombre($id));
            $this->datos = $this->dao->borrar ($id);
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        /**
        * Funcion que devuelve el nombre del paciente al que pertenece la cita
        * @param int Identificador de la cita
        * @return string Apellidos y nombre del paciente
        */
        function getNombre ($id)
        {
            $datos = $this->dao->ver($id)   ;
            return $datos[apellido]." ".$datos[apellido2].", ".$datos[nombre];
        }
        /**
        * Funcion que bloquea parte de un dia entero por tener el gabinete cerrado para evitar citas erroneas
        * @param resource Objeto de tipo Params para tener acceso a los parámetros de la petición.
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function bloquear($params, $file)
        {
            $this->dao->start ();
            $this->datos[id_usuario] = $_SESSION[id_usr];
            $bloqueado = true;
            
            $periodo = $params->getParam('p');
            if ($periodo == 1) {
                //Se bloquea la mañana
                $this->datos[fecha] = $params->getParam ('f');
                $this->datos[gabinete] = $params->getParam ("a");   
                $this->datos[hora] = "8:00";
                $this->datos[duracion] = "16";
                
            } else {
                //Se bloquea la tarde
                $this->datos[fecha] = $params->getParam ('f');
                $this->datos[gabinete] = $params->getParam ("a");   
                $this->datos[hora] = "16:00";
                $this->datos[duracion] = "13";
            }
            
            $fecha = $this->datos[fecha];
            $gab = $this->datos[gabinete]; 
            
            if($this->bloquearAgenda ($this->datos))
            {
                //Una vez comprobado que no hay citas dadas, se bloquean celdas una por una.
                if($this->dao->anulaPeriodo ($fecha, $periodo, $gab) <= 0){
                    $this->dao->rollback ();
                    $bloqueado = false;
                }
                if ($bloqueado)
                    $this->dao->commit();
            }else{
                $this->dao->rollback();
                $bloqueado = false;
            }
            
            $this->smarty->assign('bloqueado', $bloqueado);
            $this->verAgenda ($params, "agenda");  
        }
        /**
        * Funcion que desbloquea todo o parte de un dia de la agenda previamente bloqueado
        * @param resource Objeto de tipo Params para tener acceso a los parámetros de la petición.
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function desbloquear ($params, $file)
        {
            $id = $params->getParam ('id');
            $p = $params->getParam ('p');
            /**
             * p es la parte de la agenda
             * 1 para la mañana
             * 2 para la tarde
             */
            if($p == 1)
                $this->dao->quitaBloqueo ($id, 15);
            else
                $this->dao->quitaBloqueo ($id, 12);
            
            $this->verAgenda ($params, "agenda");           
        }
        /**
        * Funcion que borra una cita bloqueada
        * @param resource Objeto de tipo Params para tener acceso a los parámetros de la petición.
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function borraNoLog ($params, $file)
        {
            $id = $params->getParam ('id');
            $this->datos = $this->dao->borrar ($id);
            $this->verAgenda ($params, "agenda"); 
            return;   
        }
        function colorCita ($params, $peticion)
        {
        	$id = $params->getParam ('id');
        	$color = $params->getParam ('c');	
        	$this->dao->color ($id, "#".$color);
        	$this->verAgenda($params, "agenda");
        }
    }
?>