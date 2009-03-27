<?php
    /**
    * Fichero que recoje la implementación de la clase Home que se encarga del control de las paginas "home"
    * 
    * @package Negocio
    * @subpackage Home
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (10 - Diciembre - 2007)
    */
    
    /**
    * Inclusion de la clase DisplayManager
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    
    /**
    * Clase que se encarga del manejo de las paginas "home", hereda las variables necesarias para la presentación de DisplayManager
    * 
    * @package Negocio
    * @subpackage Home
    */
    class Home extends DisplayManager
    {
        /**
        * Constructor de la clase, carga el idioma y la ruta de los templates
        * @param string Lenguaje en que la pagina se ha solicitado
        * @return void
        */
        function Home ($lang)   
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."home/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);                
        }
        /**
        * Funcion que se encarga de mostrar la pagina principal
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraHome ($params, $file)
        {
            $this->smarty->assign ('on', 1);
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que se encarga de mostrar la pagina de servicios
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraServicios ($params, $file)
        {
            $this->smarty->assign ('on', 2);
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que se encarga de mostrar la pagina de gestion
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraGestion ($params, $file)
        {
            $this->smarty->assign ('on', 6);
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que se encarga de mostrar la pagina de clientes
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraClientes ($params, $file)
        {
            $this->smarty->assign ('on', 7);
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que se encarga de mostrar la pagina de informacion sobre el portal
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraAcerca ($params, $file)
        {
            $this->smarty->assign ('on', 8);
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que se encarga de mostrar la pagina de contacto
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraContacto ($params, $file)
        {
            $this->smarty->assign ('on', 9);
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que se encarga de mostrar la pagina de inicio de la aplicacion
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraHomeApp ($params, $file)
        {
            $this->smarty->assign ('on', 1);
            $this->smarty->display (TPL_PATH_BASE."gbdapp/acceso/index.phtml");
            return;    
        }
        
    }
?>