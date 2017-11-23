<?php
    /**
    * Archivo que recoje la implementacion de la clase Configuracion
    * 
    * @package Negocio
    * @subpackage Configuracion
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (15 - Enero - 2008) 
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la lógica de presentación de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo ServicioDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/conf/ServicioDAO.inc";
    /**
    * Inclusion del archivo OpcionesDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/conf/OpcionesDAO.inc";
    /**
    * Inclusion del archivo TipoImagenDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/imagenes/TipoImagenDAO.inc";
    /**
    * Inclusion del archivo ProvinciaDAO para tener acceso a la lógica de acceso a datos de provincias
    */
    include_once PATH_BASE."src/provincias/ProvinciaDAO.inc";
    /**
    * Inclusion del archivo TipoConsDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/conf/TipoConsDAO.inc";
    /**
    * Inclusion del archivo TipoRecetaDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/conf/TipoRecetaDAO.inc";
    /**
    * Inclusion del archivo OpcionesDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/conf/GrupoImgsDAO.inc";
    
    /**
    * Clase Configuracion. Implementa toda la lógica de negocio para configurar los elementos personalizables de la aplicacion
    * 
    * @package Negocio
    * @subpackage Configuracion
    */
    class Configuracion extends DisplayManager
    {
        /**
        *  Almacenará todos los datos que se manejen en cada petición y se usará como objeto de intercambio de datos con el DAO
        * @var array
        */
        private $datos;
        
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @return void
        */
        function Configuracion ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/conf/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 8);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            return;
        } 
        /**
        * Funcion que muestra la pagina principal de la configuracion
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
        * Funcion que muestra una lista con todos los servicios que se prestan en la clinica
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function listaServicios ($params, $file)
        {
            $dao = new ServicioDAO ();
            $this->datos = $dao->listado (1);
            $this->smarty->assign ('datos', $this->datos[1]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que muestra un formulario a partir del que se añadirá un nuevo elemento a la BD
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraFormulario ($params, $file)
        {
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que agrega un nuevo servicio a la BD
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function nuevo ($params, $file)
        {
            $dao = new ServicioDAO ();
            $this->datos[nombre] = $params->getParam ('txtNombre');   
            $this->datos[precio_unitario] = $params->getParam ('txtPrecio');
            $this->datos[descripcion] = $params->getParam ('txtDescripcion');
            $this->datos[id_usuario] = $_SESSION[id_usr];
            Utils::log_info("Starting new service register with name: ".$this->datos[nombre]);
            $this->datos = $dao->nuevo ($this->datos);
            Utils::log_info("New service registration finished with id: ".$this->datos);
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return; 
        }
        /**
        * Funcion que borra los datos correspondientes al servicio seleccionado de la BD
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function borrar ($params, $file)
        {
            $id = $params->getParam ('id');
            $dao = new ServicioDAO ();
            Utils::log_info("Deleting service with id: $id");
            $this->datos = $dao->borrar ($id);
            Utils::log_info("Deletion of service with id $id finished with code: ".$this->datos);
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que muestra una lista con todos los tipos de imagen registrados
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function listaTipoImgs ($params, $file)
        {
            $dao = new TipoImagenDAO ();
            $this->datos = $dao->listado (1);
            $this->smarty->assign ('datos', $this->datos[1]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que agrega un nuevo tipo de imagen a la BD
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function nuevoTipo ($params, $file)
        {
            $dao = new TipoImagenDAO ();
            $this->datos[nombre] = $params->getParam ('txtNombre');   
            $this->datos[descripcion] = $params->getParam ('txtDescripcion');
            $this->datos[id_usuario] = $_SESSION[id_usr];
            Utils::log_info("Starting new TipoImagen register with name: ".$this->datos[nombre]);
            $this->datos = $dao->nuevo ($this->datos);
            Utils::log_info("New TipoImagen registration finished with id: ".$this->datos);
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return; 
        }
        /**
        * Funcion que borra los datos correspondientes al tipo de imagen seleccionado de la BD
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function borrarTipo ($params, $file)
        {
            $id = $params->getParam ('id');
            $dao = new TipoImagenDAO ();
            Utils::log_info("Deleting TipoImagen with id: $id");
            $this->datos = $dao->borrar ($id);
            Utils::log_info("Deletion of TipoImagen with id $id finished with code: ".$this->datos);
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que muestra los datos almacenados referentes a la clínica en formato editable
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function verDatos ($params, $file)
        {
            $dao = new OpcionesDAO (); 
            $this->datos = $dao->ver (0);
            $this->cargaSelector ();
            $this->smarty->assign ('datos', $this->datos[0]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;      
        }
        /**
        * Funcion que recoje y carga un listado con todas las provincias disponibles
        * @return void
        */
        function cargaSelector ()
        {
            $aux = new ProvinciaDAO();
            $datos = $aux->listado(0);
            if(is_array($datos))
            {
                foreach($datos as $linea)
                    $prov[$linea[id_provincia]] = $linea[provincia];
                $this->smarty->assign ('provincias', $prov);      
            }
            return;  
        }
        /**
        * Funcion que actualiza los datos de la clínica a partir de los enviados por el usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function actualizarDatos ($params, $file)
        {
            $dao = new OpcionesDAO (); 
            $this->datos = $this->recibirFormulario ($params);
            $this->datos = $dao->modificar ($this->datos);
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        /**
        * Funcion que recoje y devuelve los datos enviados por el usuario a través del formulario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @return array
        */
        function recibirFormulario ($params)
        {
            $datos = array();
            
            $datos[nombre] = $params->getParam ('txtNombre');
            $datos[especialidad] = $params->getParam ('txtEspecialidad');
            $datos[nif] = $params->getParam ('txtNif');
            $datos[direccion] = $params->getParam ('txtDireccion');
            $datos[cp] = $params->getParam ('txtCP');
            $datos[ciudad] = $params->getParam ('txtCiudad');
            $datos[id_provincia] = $params->getParam ('selProv');
            $datos[telefono] = $params->getParam ('txtTelefono');
            $datos[gabinetes] = $params->getParam ('txtGabinetes');
            $datos[reg_sanidad] = $params->getParam ('txtRegSanidad');
            
            return $datos;   
        }
        /**
        * Funcion que muestra un listado con todos los tipos de consentimientos que hay registrados
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function listaTipoCons ($params, $file)
        {
            $dao = new TipoConsDAO ();
            $this->datos = $dao->listado (0);
            $this->smarty->assign ('datos', $this->datos[1]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;                
        }
        /**
        * Funcion que muestra un formulario para dar de alta aun nuevo tipo de consentimiento
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void 
        */                        
        function muestraFormCons ($params, $file)
        {
            $this->smarty->display ($this->path.$file.".phtml");
            return;             
        }
        /**
        * Funcion que recoje los datos enviados por el usuario y da de alta el nuevo consentimiento guardandolo en la BD
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function nuevoCons ($params, $file)
        {
            $dao = new TipoConsDAO ();
            $this->datos[nombre] = $params->getParam ('txtNombre');
            $this->datos[texto_incluido] = $params->getParam ('txtTexto');
            $this->datos[id_usuario] = $_SESSION[id_usr];
            Utils::log_info("Starting new TipoConsentimiento register with name: ".$this->datos[nombre]);
            $this->datos = $dao->nuevo ($this->datos);
            Utils::log_info("New TipoConsentimiento registration finished with id: ".$this->datos);
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que borra todos los datos del consentimiento seleccionado
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function borraCons ($params, $file)
        {
            $dao = new TipoConsDAO ();
            $id = $params->getParam ('id');
            Utils::log_info("Deleting TipoConsentimiento with id: $id");
            $this->datos = $dao->borrar ($id);
            Utils::log_info("Deletion of TipoConsentimiento with id $id finished with code: ".$this->datos);
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que recoje todos los datos del consentimiento seleccionado y los muestra en la pantalla en formato editable
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function verCons ($params, $file)
        {
            $dao = new TipoConsDAO ();
            $id = $params->getParam ('id');
            $this->datos = $dao->ver ($id);
            $this->smarty->assign ('datos', $this->datos[0]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que recoje los datos enviados por el usuario y actualiza los datos del consentimiento seleccionado
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function modificaCons ($params, $file)
        {
            $dao = new TipoConsDAO ();
            $this->datos[nombre] = $params->getParam ('txtNombre');
            $this->datos[texto_incluido] = $params->getParam ('txtTexto');
            Utils::log_info("Modifying TipoConsentimiento with id: ".$this->datos[id_tipo_consentimiento]. " and name: ".$this->datos[nombre]);
            $this->datos[id_tipo_consentimiento] = $params->getParam ('id');
            Utils::log_info("Modification of TipoConsentimiento with id: ".$this->datos[id_tipo_consentimiento]. " finished with code: ".$this->datos);
            $this->datos = $dao->modificar ($this->datos);
            $this->smarty->assign ('codigo', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;       
        }
        /**
        * Funcion que muestra un listado con todos los tipos de receta registrados
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function listaRecetas ($params, $file)
        {
            $dao = new TipoRecetaDAO();
            $this->datos = $dao->listado (0);
            if(is_array($this->datos))
                $this->smarty->assign ('datos', $this->datos[1]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que guarda los datos del tipo de receta en BD
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function nuevaReceta ($params, $file)
        {
            $dao = new TipoRecetaDAO ();
            $this->datos[id_usuario] = $_SESSION[id_usr];
            $this->datos[nombre] = $params->getParam('txtNombre');
            $this->datos[texto] = $params->getParam ('txtTexto');
            $this->datos[resumen] = $params->getParam ('txtResumen');
            Utils::log_info("Starting new Receta register with name: ".$this->datos[nombre]);
            $this->datos = $dao->nuevo ($this->datos);
            Utils::log_info("New Receta registration finished with id: ".$this->datos);
            $this->listaRecetas ($params, "tiporecetas");
            return;   
        }
        /**
        * Funcion que muestra los datos de la receta en formato editable
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function verReceta ($params, $file)
        {
            $id = $params->getParam ('id');
            $dao = new TipoRecetaDAO ();
            $this->datos = $dao->ver ($id);
            
            $this->smarty->assign ('datos', $this->datos[0]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que modifica los datos de la receta a partir de los introducidos por el usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function editaReceta ($params, $file)
        {
            $dao = new TipoRecetaDAO ();
            $id = $params->getParam ('id');
            
            $this->datos[id_tipo_receta] = $id;
            $this->datos[nombre] = $params->getParam('txtNombre');
            $this->datos[texto] = $params->getParam ('txtTexto');
            $this->datos[resumen] = $params->getParam ('txtResumen');
            Utils::log_info("Modifying Receta with id: ".$this->datos[id_tipo_receta]. " and name: ".$this->datos[nombre]);
            $this->datos = $dao->modificar ($this->datos);
            Utils::log_info("Modification of Receta with id: ".$this->datos[id_tipo_receta]. " finished with code: ".$this->datos);
            $this->listaRecetas ($params, "tiporecetas");
            return;          
        }
        /**
        * Funcion que borra todos los datos del tipo de receta seleccionado
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function borraReceta ($params, $file)
        {
            $id = $params->getParam ('id');
            $dao = new TipoRecetaDAO ();
            Utils::log_info("Deleting Receta with id: $id");
            $this->datos = $dao->borrar ($id);
            Utils::log_info("Deletion of Receta with id $id finished with code: ".$this->datos);
            $this->listaRecetas ($params, "tiporecetas");
            return;   
        }
        /**
        * Funcion que muestra una lista con todos los grupos de imagenes
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function listaGrupoImgs ($params, $file)
        {
            $dao = new GrupoImgsDAO();
            $this->datos = $dao->listado(0);
            if(is_array($this->datos))
                $this->smarty->assign ('datos', $this->datos[1]);
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        /**
        * Funcion que muestra un formulario para dar de alta un nuevo grupo de imagenes
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function nuevoGrupoImgs ($params, $file)
        {
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        /**
        * Funcion que da de alta un nuevo grupo de imagenes
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function altaGrupoImgs ($params, $file)
        {
            $dao = new GrupoImgsDAO();
            $this->datos[nombre] = $params->getParam('txtNombre');
            $this->datos[id_usuario] = $_SESSION[id_usr];
            Utils::log_info("Starting new GrupoImagenes register with name: ".$this->datos[nombre]);
            $this->datos = $dao->nuevo($this->datos);
            Utils::log_info("New GrupoImagenes registration finished with id: ".$this->datos);
            $this->listaGrupoImgs ($params, "grupoimgs");
            return;   
        }
        /**
        * Funcion que borra un grupo de imagenes
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function borraGrupoImgs ($params, $file)
        {
            $dao = new GrupoImgsDAO();
            $id = $params->getParam('id'); 
            Utils::log_info("Deleting GrupoImagenes with id: $id");  
            $this->datos = $dao->borrar($id);
            Utils::log_info("Deletion of GrupoImagenes with id $id finished with code: ".$this->datos);
            $this->listaGrupoImgs ($params, "grupoimgs");
            return;
        }
    }
?>