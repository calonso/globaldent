<?php
    /**
    * Fichero que recoje la implementación de la clase Imagen
    * 
    * @package Negocio
    * @subpackage Imagenes
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (16 - Enero - 2008)
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la lógica de presentación de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo ImagenDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/imagenes/ImagenDAO.inc";
    /**
    * Inclusion del archivo PacienteDAO para tener acceso a los datos de los pacientes
    */
    include_once PATH_BASE."src/gbdapp/pacientes/PacienteDAO.inc";
    /**
    * Inclusion del archivo TipoImagenDAO para tener acceso a los datos de los tipos de imagenes
    */
    include_once PATH_BASE."src/gbdapp/imagenes/TipoImagenDAO.inc";
    /**
    * Inclusion del archivo Logger para sacar log
    */
    include_once PATH_BASE."src/gbdapp/log/Logger.inc";
    /**
    * Inclusion del archivo GrupoImagenDAO para tener acceso a los datos de los tipos de imagenes
    */
    include_once PATH_BASE."src/gbdapp/conf/GrupoImgsDAO.inc";
    
    /**
    * Clase Imagen. Implementa toda la lógica de manejo de datos y peticiones para el objeto Imagen
    * @package Negocio
    * @subpackage Imagenes
    */
    class Imagen extends DisplayManager
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
        * Almacenará la referencia al objeto logger
        */
        private $logger;
        /**
        * Almacenará el nombre del paciente
        */
        private $nombre;
        
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @param int Identificador del paciente sobre el que se esta trabajando
        * @return void
        */
        function Imagen ($lang, $id)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/imagenes/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 3);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            $this->dao = new ImagenDAO();
            $this->id = $id; 
            $this->carpeta = PATH_BASE."imagenes/".$_SESSION[id_usr]."/id$id";
            $this->nombre = $this->cargaPaciente ($id); 
            $this->nombre = "Imagen de: ".$this->nombre;
            $this->logger = new Logger($lang);
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
        * Funcion que muestra un listado con todas las imágenes que se han tomado del paciente
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void   
        */
        function listado ($params, $file)
        {
            $this->datos = $this->dao->listado ($this->id);
            if(is_array ($this->datos))
            {
                $this->datos = $this->datos [1];
                foreach ($this->datos as $indice => $valor)
                {
                    $this->datos[$indice][tipoimg] = $this->getNombreTipo ($this->datos[$indice][id_tipo]);          
                }
            }
            $this->smarty->assign ('datos', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que busca el nombre del tipo de la imagen a partir del identificador de tipo recibido
        * @param int Identificador del tipo de imagen
        * @return string
        */
        function getNombreTipo ($id)
        {
            $datos = array();
            $aux = new TipoImagenDAO ();
            $datos = $aux->ver ($id);
            return $datos[0][nombre];
        }
        /**
        * Funcion que muestra un formulario para rellenar los datos correspondientes a la nueva imagen que se quiere añadir.
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraFormulario ($params, $file)
        {
            $this->cargaSelector();
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que prepara y carga los datos de los tipos de imagen para ser mostrados en un <select>
        * @return void
        */
        function cargaSelector ()
        {
            $datos = array();
            $aux = new TipoImagenDAO ();   
            $datos = $aux->listado (0);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach ($datos as $linea)
                    $tipos[$linea[id_tipo_imagen]] = $linea[nombre];
                $this->smarty->assign ('tipos', $tipos);  
            }
            
            $aux = new GrupoImgsDAO ();   
            $datos = $aux->listado (0);
            if(is_array($datos))
            {
                $datos = $datos[1];
                foreach ($datos as $linea)
                    $grupos[$linea[id_grupo_imagenes]] = $linea[nombre];
                $this->smarty->assign ('grupos', $grupos);  
            }
            return;
        }
        /**
        * Funcion que guarda los datos de la imagen enviados por el usuario
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function nueva ($params, $file)
        {
        	$image = $_FILES[fileFoto][tmp_name];
            if(is_uploaded_file($image))
            {
            	Utils::log_info("Uploaded new image $image");
                $fileType = $_FILES[fileFoto][type];
                Utils::log_debug("Image filetype is: $fileType");
                $aux = explode ("/", $fileType);
                if (!strncmp ($aux[0], "image", 5))
                { 
                    $this->datos = $this->recibirFormulario ($params);
                    Utils::log_debug("Image extension is: ".$aux[1]);
                    $this->datos[extension] = $aux[1];
                    Utils::log_info("Starting new image register");
                    $this->datos = $this->dao->nuevo ($this->datos);
                    if($this->datos > 0)
                    {  
                    	Utils::log_info("New image data stored successfully, now moving the image to: ".$this->carpeta."/im".$this->datos);
                        move_uploaded_file ($_FILES[fileFoto][tmp_name], $this->carpeta."/im".$this->datos);
                        $this->logger->save(LOG_ALTA, $this->nombre);
                        $this->smarty->assign ('codigo', $this->datos);
                    } else {
                    	Utils::log_error("An error ocurred storing the image data!!"); 
                    }
                }else {
                	Utils::log_error("The uploaded image is not an image!");
                    $this->smarty->assign ('codigo', -3);
                }          
            }else {
            	Utils::log_error("No image was uploaded at $image");
                $this->smarty->assign ('codigo', -2);
            }
            
            $this->smarty->display ($this->path.$file.".phtml");   
        }
        /**
        * Funcion que recoje los datos enviados por el usuario a través del formulario
        * 
        * Esta funcion además carga el valor de la fecha actual realizando la conversión al formato usado en la BD
        * También carga el valor del identificador del paciente y del usuario, para así rellenar todos los datos necesarios
        * @param resource Objeto params para acceder a los parámetros de la petición
        * @return array
        */
        function recibirFormulario ($params)
        {
            $datos = array();
            $datos[id_tipo] = $params->getParam('selTipo');
            $datos[comentarios] = $params->getParam ('txtComentarios');
            
            $fecha = strftime ("%d-%m-%Y");
            $aux = explode ("-", $fecha);
            $aux[0] = (int)$aux[0];
            $aux[1] = (int)$aux[1];
            $datos[fecha] = $aux[0]."-".$aux[1]."-".$aux[2];
            
            $datos[id_paciente] = $this->id;
            $datos[id_usuario] = $_SESSION[id_usr];
            $datos[id_grupo_imagen] = $params->getParam('selGrupo');
             
            return $datos;   
        }
        /**
        * Funcion que muestra todos los detalles de la imagen seleccionada
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function ver ($params, $file)
        {
            $id = $params->getParam ('img');
            $this->datos = array("id_paciente" => $this->id, "id_imagen" => $id);
            $this->datos = $this->dao->ver ($this->datos);
            if(is_array($this->datos))
            {
                $this->smarty->assign ('datos', $this->datos[0]);
            }else
            $this->smarty->assign ('datos', $this->datos);
            $this->smarty->display ($this->path.$file.".phtml");   
        }
        /**
        * Funcion que borra todos los datos de la imagen seleccionada y elimina el archivo de la carpeta correspondiente
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function borrar ($params, $file)
        {
            $id = $params->getParam ('img');
            $this->datos = array("id_paciente" => $this->id, "id_imagen" => $id);
            Utils::log_info("Retrieving image $id data for deletion");
            $imgInfo = $this->dao->ver($this->datos);
            if (is_array($imgInfo)){
            	$extension = $this->datos[0][extension];
            	Utils::log_debug("Image info retrieved successfully, the image extension is: $extension");
                Utils::log_info("Deleting the image $id");
	            $this->datos = $this->dao->borrar ($this->datos); 
	            if($this->datos == 1)
	            {
	                $this->smarty->assign ('codigo', $this->datos);
	                $this->logger->save(LOG_BAJA, $this->nombre);
	                Utils::log_info("Image deleted successfully, deleting now the file: ".$this->carpeta."/im".$id.".".$extension);  
	                unlink ($this->carpeta."/im".$id.".".$extension);  
	            } else {
	            	Utils::log_error("An error ocurred deleting the image!!");	
	            }
            } else {
            	Utils::log_error("An error ocurred!! Image with id $id data couldn't be retrieved!!");
            }
            $this->smarty->display ($this->path.$file.".phtml");
        }
    }
?>