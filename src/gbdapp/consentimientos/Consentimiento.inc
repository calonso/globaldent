<?php
    /**
    * Archivo que recoje la implementacion de la clase Consentimiento
    * 
    * @package Negocio
    * @subpackage Consentimientos
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (23 - Enero - 2008) 
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la lógica de presentación de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo ConsentimientoDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/consentimientos/ConsentimientoDAO.inc";
    /**
    * Inclusion del archivo ConsentimientoRevocadoDAO para tener acceso a la lógica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/consentimientos/ConsentimientoRevocadoDAO.inc";
    /**
    * Inclusion del archivo TipoConsDAO para tener acceso a la lógica de acceso a datos de tipos de consentimiento
    */
    include_once PATH_BASE."src/gbdapp/conf/TipoConsDAO.inc";
    /**
    * Inclusion del archivo PacienteDAO para tener acceso a los datos de los pacientes
    */
    include_once PATH_BASE."src/gbdapp/pacientes/PacienteDAO.inc";
    
    /**
    * Clase Consentimiento. Implementa toda la lógica de negocio para gestionar el firmado de consentimientos por parte del paciente
    * 
    * @package Negocio
    * @subpackage Consentimientos
    */
    class Consentimiento extends DisplayManager
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
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @return void
        */
        function Consentimiento ($lang, $id)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/consentimientos/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 3);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            $this->dao = new ConsentimientoDAO();
            $this->id = $id; 
            $this->carpeta = PATH_BASE."imagenes/".$_SESSION[id_usr]."/id$id";
            $this->cargaPaciente ($id);
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
            return;      
        } 
        /**
        * Funcion que muestra un listado con todos los consentimientos que el paciente tiene firmados y los que le quedan
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function listado ($params, $file)
        {
            
            $this->datos = $this->dao->listado ($this->id);
            if(is_array($this->datos))
            {
                $temp = array();
                $this->datos = $this->datos[1];
                foreach ($this->datos as $indice => $valor)
                {
                    $this->datos[$indice][nombre] = $this->verTipoCons ("nombre", $this->datos[$indice][id_tipo_consentimiento]);
                    array_push ($temp, $this->datos[$indice][id_tipo_consentimiento]);      
                }
            }
            $this->smarty->assign ('firmados', $this->datos);
            $aux = new TipoConsDAO ();
            if(is_array($temp))
            {
                $this->datos = $aux->buscar ($temp);
                $this->smarty->assign ('resto', $this->datos);
            }else
            {    
                $this->datos = $aux->listado (0);
                $this->smarty->assign ('resto', $this->datos[1]);
            }
            $aux = new ConsentimientoRevocadoDAO ();
            $this->datos = $aux->listado ($this->id);
            if(is_array($this->datos))
            {
                $temp = array();
                $this->datos = $this->datos[1];
                foreach ($this->datos as $indice => $valor)
                {
                    $this->datos[$indice][nombre] = $this->verTipoCons ("nombre", $this->datos[$indice][id_tipo_consentimiento]);
                    array_push ($temp, $this->datos[$indice][id_tipo_consentimiento]);      
                }
            }
            $this->smarty->assign ('revocados', $this->datos);
            
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que recoje el nombre y el texto del tipo de consentimiento seleccionado
        * @param int Id del tipo de consentimiento que se quiere consultar
        * @return string
        */
        function verTipoCons ($motivo, $id)
        {
            $dao = new TipoConsDAO ();
            $datos = $dao->ver ($id);
            switch ($motivo)
            {
                case "nombre":
                    return $datos[0][nombre];
                    break;
                case "texto":
                    return $datos[0][texto_incluido];
                    break;   
            }
               
        }
        /**
        * Funcion que añade un nuevo consentimiento firmado a la base de datos
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
         function nuevo ($params, $file)
         {
            $id = $params->getParam ('cons');
            
            $fecha = strftime ("%d-%m-%Y");
            $aux = explode ("-", $fecha);
            $aux[0] = (int)$aux[0];
            $aux[1] = (int)$aux[1];
            $fecha = $aux[0]."-".$aux[1]."-".$aux[2];
            
            $this->datos[id_paciente] = $this->id;
            $this->datos[id_tipo_consentimiento] = $id;
            $this->datos[id_usuario] = $_SESSION[id_usr];
            $this->datos[fecha] = $fecha;
            
            if(is_uploaded_file($_FILES[fileFirma][tmp_name]))
            {
                $ext = $_FILES[fileFirma][type];
                $aux = explode ("/", $ext);
                $this->datos[extension] = $aux[1];  
            }
            
            $this->datos = $this->dao->nuevo ($this->datos);
            if($this->datos > 0)
            {
                if(is_uploaded_file($_FILES[fileFirma][tmp_name]))
                {
                    move_uploaded_file ($_FILES[fileFirma][tmp_name], $this->carpeta."/fcons".$this->datos);   
                }
            } 
            
            $this->listado ($params, "cons");
            return; 
         }
         /**
         * Funcion que revoca el consentimiento seleccionado de la BD
         * @param resource Objeto de la clase params para acceder a los parámetros de la petición
         * @param string Archivo que se ha solicitado
         * @return void
         */
         function revocar ($params, $file)
         {
            $id = $params->getParam ('cons');
            $this->dao->start();
            $this->datos = $this->nuevoRevocado ($id);
            if($this->datos > 0)
            {
                $ret = $this->dao->borrar (array("id_paciente" => $this->id, "id_consentimiento" => $id));
                if($ret > 0)
                {
                    @rename ($this->carpeta."/fcons$id", $this->carpeta."/fconsr".$this->datos);   
                    $this->dao->commit ();
                }else
                    $this->dao->rollback ();
            }else
                $this->dao->rollback ();
            
            $this->listado ($params, "cons");
            return;   
         }
         /**
         * Funcion que crea el nuevo presupuesto revocado
         * @param int Id del viejo presupuesto para consultar sus datos
         * @return int
         */
         function nuevoRevocado ($id)
         {
            $datos = $this->dao->ver (array("id_paciente" => $this->id, "id_consentimiento" => $id));
            if(is_array($datos))
            {
                $aux[fecha] = $datos[0][fecha];
                $aux[id_tipo_consentimiento] = $datos[0][id_tipo_consentimiento];
                $fecha = strftime ("%d-%m-%Y");
                $temp = explode("-", $fecha);
                $temp[0] = (int)$temp[0];
                $temp[1] = (int)$temp[1];
                $fecha = $temp[0]."-".$temp[1]."-".$temp[2];
                $aux[fecha_r] = $fecha;
                $aux[id_paciente] = $this->id;
                $aux[id_usuario] = $_SESSION[id_usr];
                $aux[extension] = $datos[0][extension];
                
                if(is_uploaded_file($_FILES[fileFirma][tmp_name]))
                {
                    $ext = $_FILES[fileFirma][type];
                    $ext = explode ("/", $ext);
                    $aux[extensionr] = $ext[1];   
                }
                
                $rdao = new ConsentimientoRevocadoDAO();
                $datos = $rdao->nuevo ($aux);
                
                if(is_uploaded_file($_FILES[fileFirma][tmp_name]))
                {
                    move_uploaded_file ($_FILES[fileFirma][tmp_name], $this->carpeta."/fconsr".$datos."b");       
                }
            }else
                $datos = -1;    
            
            return $datos;
         }
        /**
        * Funcion que muestra todos los datos del consentimiento
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function ver ($params, $file)
        {
            $id = $params->getParam ('cons');
            $this->datos = $this->dao->ver (array("id_consentimiento" => $id, "id_paciente" => $this->id));
            $this->datos[0][texto_incluido] = $this->verTipoCons ("texto", $this->datos[0][id_tipo_consentimiento]);
            $this->smarty->assign ('datos', $this->datos[0]);
            $this->smarty->display ($this->path."imprimible.phtml");
            return;   
        }
        /**
        * Funcion que muestra todos los datos del consentimiento revocado
        * @param resource Objeto de la clase params para acceder a los parámetros de la petición
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function verRevocado ($params, $file)
        {
            $dao = new ConsentimientoRevocadoDAO ();
            $id = $params->getParam ('cons');
            $this->datos = $dao->ver (array("id_consentimiento" => $id, "id_paciente" => $this->id));
            $this->datos[0][texto_incluido] = $this->verTipoCons ("texto", $this->datos[0][id_tipo_consentimiento]);
  
            $this->smarty->assign ('datos', $this->datos[0]);
            $this->smarty->display ($this->path."imprimibleR.phtml");
            return;   
        }
    }
?>