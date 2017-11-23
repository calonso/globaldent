<?php
     /**
    * Fichero que recoje la implementación de la clase No Autorizado que se encarga de tratar las peticiones cuyo usuario no fue validado correctamente
    * 
    * @package Negocio
    * @subpackage Error
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (12 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del fichero DisplayManager para tener acceso a la lógica de presentacion de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del fichero Logger para sacar log de las actuaciones
    */
    include_once PATH_BASE."src/gbdapp/log/Logger.inc";
    
    /**
    * Clase No autorizado. Implementa la lógica a seguir para tratar peticiones cuyo usuario no ha sido correctamente validado
    */
    class noAutorizado extends DisplayManager
    {
        /**
        *  Guardará la referencia al objeto logger
        */
        private $logger;
        /**
        * Constructor de la clase, carga el idioma y la ruta de los templates
        * @param string Lenguaje en que la pagina se ha solicitado
        * @return void
        */
        function noAutorizado ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."noautorizado/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            $this->logger = new Logger($lang);
            return;
        } 
        /**
        * Funcion que se encarga de mostrar la pantalla correspondiente al error  
        * @return void
        */
        function denegar ($params, $peticion)
        {
            $this->logger->save(LOG_FORBIDDEN, $peticion);
            session_destroy();
            $this->smarty->assign ('autenticado', 0);
            $this->smarty->assign ('privilegios', 0);
            $this->smarty->display ($this->path."noautorizado.phtml");
            return;    
        }
    }
?>