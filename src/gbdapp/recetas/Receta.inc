<?php
    /**
    * Fichero que recoje la implementación de la clase Receta
    * 
    * @package Negocio
    * @subpackage Visitas
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (29 - Enero - 2008)
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la lógica de presentación de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo RecetaDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/recetas/RecetaDAO.inc";
    /**
    * Inclusion del archivo VisitaDAO para tener acceso a la lógica de acceso a datos de cada visita
    */
    include_once PATH_BASE."src/gbdapp/visitas/VisitaDAO.inc";
    /**
    * Inclusion del archivo LineaVisitaDAO para tener acceso a la lógica de acceso a datos de cada linea de visita
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
    * Inclusion del archivo TipoRecetaDAO para tener acceso a los datos de las recetas
    */
    include_once PATH_BASE."src/gbdapp/conf/TipoRecetaDAO.inc";
    /**
    * Inclusion del archivo OpcionesDAO para tener acceso a los datos de la clinica
    */
    include_once PATH_BASE."src/gbdapp/conf/OpcionesDAO.inc";
    
    
    
    /**
    * Clase Receta. Implementa toda la lógica de manejo de datos y peticiones para el objeto Receta
    * @package Negocio
    * @subpackage Visitas
    */
    class Receta extends DisplayManager
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
        * Almacenará el identificador de la visita con que se está trabajando
        * @var int
        */
        private $vis;
        
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @param int Identificador del paciente sobre el que se esta trabajando
        * @param int Identificador de la visita para la que se va a hacer la receta
        * @return void
        */
        function Receta ($lang, $id, $vis)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/recetas/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 3);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            $this->dao = new RecetaDAO();
            $this->id = $id; 
            $this->vis = $vis;
            $this->carpeta = PATH_BASE."imagenes/".$_SESSION[id_usr]."/id$id";
            $this->cargaPaciente ($id);
            $this->cargaVisita ($vis); 
            $this->cargaOpciones ();
            return; 
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
        * Funcion que recoje y carga la informacion del paciente que se mostrará en la cabecera
        * @param int Id del usuario del que se quieren recojer los datos
        * @return void
        */
        function cargaPaciente ($id)
        {
            $aux = new PacienteDAO;
            $datos = $aux->ver ($id); 
            $this->smarty->assign ('paciente', $datos);
            return;      
        }
        /**
        * Funcion que recoje y carga la informacion de la visita que se mostrará en la cabecera
        * @param int Id de la visita de la que se quieren recojer los datos
        * @return void
        */
        function cargaVisita ($id)
        {
            $dao = new VisitaDAO ();
            $datos = $dao->ver ((int)$id);
            if(is_array($datos))
            {   
                $datos = $datos[0];             
                $datos[lineas] = $this->verLineas ($id);
                $this->smarty->assign ('visita', $datos);
            }
            return;   
        }
        
        /**
        * Funcion que recoje todos los servicios prestados en cada visita y devuelve una cadena con sus nombres
        * @param int Id de la visita
        * @return string
        */
        function verLineas ($id)
        {
            $aux = new LineaVisitaDAO ();
            $lineas = $aux->ver ($id);
            if(is_array($lineas))
            {
                foreach ($lineas as $indice => $valor)
                    $lineas[$indice][servicio] = $this->verTratamiento ("nombre", $lineas[$indice][id_servicio]);    
            }
            return $lineas;   
        }
        /**
        * Funcion que busca y carga los datos del tratamiento que se ha dado en la visita
        * @param string Caracteristica que queremos ver
        * @param int Id del tratamiento
        * @return array
        */
        function verTratamiento ($motivo, $id)
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
        * Funcion que muestra un formulario para introducir los datos de la receta
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void 
        */
        function muestraFormulario ($params, $file)
        {
            $tipo = $params->getParam ("tp");
            if ($tipo)
            {
                $this->cargatipo ($tipo);
                $this->smarty->assign('idtipo', $tipo);
            }
                
            $this->cargaSelector ();
            $this->smarty->display ($this->path.$file.".phtml"); 
            return;  
        }
        /**
        * Funcion que carga los datos almacenados para el tipo de presupuesto seleccionado
        * @param int Id del tipo seleccionado
        * @return void  
        */
        function cargaTipo ($id)
        {
            $dao = new TipoRecetaDAO ();
            $datos = $dao->ver ($id);
            $this->smarty->assign ('datos', $datos[0]);
            return;
        }
        /**
        * Funcion que carga el selector para el tipo de recetas
        * @return void
        */
        function cargaSelector ()
        {
            $dao = new TipoRecetaDAO ();
            $datos = $dao->listado (0);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach ($datos as $linea)
                {
                    $tiposrec[$linea[id_tipo_receta]] = $linea[nombre];   
                }
                $this->smarty->assign ('tiposrec', $tiposrec);    
            }
            
            return;
        }
        /**
        * Funcion que almacena todos los datos de la nueva receta
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function nueva ($params, $file)
        {
            $this->datos = $this->recibirFormulario ($params);
            Utils::log_info("Storig new receta for visita: ".$this->vis);
            $this->datos = $this->dao->nuevo ($this->datos);
            if ($this->datos > 0){
            	Utils::log_info("New receta stored successfully with id: ".$this->datos);
            } else {
            	Utils::log_error("An error ocurred creating new receta!!");
            }
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que recoje todos los datos enviados por el usuario a traves del formulario y prepara un array para su insercion en la BD
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @return void
        */
        function recibirFormulario ($params)
        {
            $datos = array();
            
            $datos[id_paciente] = $this->id;
            $datos[id_visita_medica] = $this->vis;
            $datos[id_usuario] = $_SESSION[id_usr];
            $datos[resumen] = $params->getParam ('txtResumen');
            $datos[texto] = $params->getParam ('txtTexto');
            $datos[observaciones] = $params->getParam ('txtObservaciones');
            $datos[id_tipo_receta] = $params->getParam ('selReceta');
            
            return $datos;   
        }
        /**
        * Funcion que muestra todos los detalles de la receta
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function ver ($params, $file)
        {
            $id = $params->getParam ('r');
            $imp = $params->getParam ('imp');
            $this->datos = $this->dao->ver ($id);
            
            $this->smarty->assign ('datos', $this->datos[0]);
            if($imp)
                $file = "imprimible";
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que borra todos los detalles de la receta de la BD
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function borrar ($params, $file)
        {
            $id = $params->getParam ('r');
            Utils::log_info("Deleting receta with id: $id");
            $this->datos = $this->dao->borrar ($id);
            if ($this->datos == 1){
            	Utils::log_info("Receta deleted successfully!");
            } else {
            	Utils::log_error("An error ocurred deleting the receta!!");
            }
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;       
        }
    }
?>