<?php
    /**
    * Archivo que recoje la implementacion de la clase Pedido
    * 
    * @package Negocio
    * @subpackage Pedidos
    * @author Carlos Alonso P�rez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (23 - Enero - 2008) 
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la l�gica de presentaci�n de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo PedidoDAO para tener acceso a la l�gica de acceso y almacenamiento de datos
    */
    include_once PATH_BASE."src/gbdapp/pedidos/PedidoDAO.inc";
    
    /**
    * Clase Pedido. Implementa toda la l�gica de negocio para gestionar los pedidos de material
    * 
    * @package Negocio
    * @subpackage Pedidos
    */
    class Pedido extends DisplayManager
    {
        /**
        *  Almacenar� todos los datos que se manejen en cada petici�n y se usar� como objeto de intercambio de datos con el DAO
        * @var array
        */
        private $datos;
        /**
        *  Almacenar� la referencia a su objeto DAO
        * @var resource
        */
        private $dao;
        
        /**
        * Constuctor de la clase, prepara las variables necesarias para su funcionamiento
        * @param string Idioma en que se ha solicitado la pagina
        * @return void
        */
        function Pedido ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/pedidos/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 6);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->datos = array();
            $this->dao = new PedidoDAO();
            return;
        }
        /**
        * Funcion que muestra la p�gina principal de los pedidos
        * @param resource Objeto de la clase params para acceder a los par�metros de la petici�n
        * @param string Archivo que se ha solicitado
        * @return void
        */
        function index ($params, $file)
        {
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        
    }
?>