<?php
    /**
    * Fichero que recoje la implementación de la clase DisplayManager. Encargada de las labores de presentación de vistas
    * 
    * @package Presentacion
    * @subpackage Vistas
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (10 - Diciembre - 2007)
    */
    
    /**
    * Inclusion de la biblioteca Smarty
    */
    include_once PATH_BASE."smarty/Smarty.class.php";
    /**
    * Inclusion de la clase fechas
    */
    include_once PATH_BASE."src/common/fechas.inc";
    
    class DisplayManager
    {
        /**
        * Guarda la referencia al objeto smarty
        * @var resource
        */
        protected $smarty;
        /**
        * Guarda el idioma en que se le pide la pagina
        * @var string
        */
        protected $lang;
        /**
        * Guarda el identificador de idioma en que se pide la pagina
        * @var int
        */
        protected $id_lang;
        
        protected $fechas;
    
        /**
        * Constructor de la clase, de ella heredarán todas sus hijas los valores necesarios para la presentación de vistas
        * @return void       
        */
        function DisplayManager()
        {
            $this->smarty = new Smarty();
            
            $this->smarty->template_dir = PATH_BASE."templates/templates/";
            $this->smarty->compile_dir = PATH_BASE."templates/templates_c/";
            $this->smarty->config_dir = PATH_BASE."templates/configs/";
            $this->smarty->cache_dir = PATH_BASE."templates/cache/";
            
            $this->smarty->left_delimiter = '{';
            $this->smarty->right_delimiter = '}';
            
            $this->smarty->caching = SMARTY_CACHING;
            
            $this->lang = $_SESSION['lang'];
            $this->id_lang = $_SESSION['id_lang'];
            $this->smarty->assign ('id_lang', $this->id_lang);
            $this->smarty->assign ('lang', $this->lang);
            $this->smarty->assign ('req_base', REQ_BASE);
            $this->smarty->assign ('tpl_path_base', TPL_PATH_BASE);
            $this->smarty->assign ('img_path_base', IMG_PATH_BASE);
            $this->smarty->assign ('max_lineas', MAX_FILAS);
            
            setlocale(LC_TIME, 'esp');
            $fecha = strftime ("%A, %d %B %Y");
            $this->smarty->assign ('fecha', $fecha);
            if(isset($_SESSION[id]))
                $this->smarty->assign ('autenticado', 1);
            else
                $this->smarty->assign ('autenticado', 0);   

            $this->fechas = new fechas();
        }
    }
?>