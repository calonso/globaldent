<?php
    /**
    * Fichero que recoje la implementacion del dispatcher publico.
    * 
    * @package Presentacion
    * @subpackage Acceso
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (10 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del fichero Dispatcher, padre de este, del que heredará su estructura
    */
    include_once PATH_BASE."src/acceso/Dispatcher.inc";
    /**
    * Inclusion del archivo que controla las paginas de usuario
    */
    include_once PATH_BASE."src/usuarios/Usuario.inc";
    /**
    * Inclusion del archivo que controla las paginas "home"
    */
    include_once PATH_BASE."src/home/Home.inc";
    /**
    * Inclusion del archivo no Autorizado para las peticiones no autorizadas
    */
    include_once PATH_BASE."src/error/noAutorizado.inc";
    /**
    * Inclusion del archivo Publicaciones para la pagina de publicaciones
    */
    include_once PATH_BASE."src/publicaciones/Publicaciones.inc";
    /**
    * Inclusion del archivo foros para la pagina de foros
    */
    include_once PATH_BASE."src/publicaciones/Foros.inc";
    /**
    * Inclusion del archivo tesis para los listados de tesis
    */
    include_once PATH_BASE."src/publicaciones/Tesis.inc";
    /**
    * Inclusion del archivo libro para los listados de libros
    */
    include_once PATH_BASE."src/publicaciones/Libro.inc";
    /**
    * Inclusion del archivo caso para los listados de casos clínicos
    */
    include_once PATH_BASE."src/publicaciones/Caso.inc";
    /**
    * Inclusion del archivo artículo para los listados de artículos y revistas
    */
    include_once PATH_BASE."src/publicaciones/Articulo.inc";
    
    /**
    * Clase Publico, implementa la lógica de transferencia de control para las peticiones que le conciernen.
    * 
    * @package Presentacion
    * @subpackage Acceso
    */
    class Publico extends Dispatcher
    {
        /**
        * Constructor de la clase, crea un objeto de la clase padre para obtener todas sus propiedades
        * @return void
        */
        function Publico()
        {
            parent::Dispatcher();
            return;
        }
        /**
        * Funcion que redefine el metodo de su clase padre
        */
        function dispatch()
        {
            $peticion = $this->params->getParam("cod");
            $lang = $this->params->getParam("lang");
            
            if (($lang != "es_ES") && ($lang != "en_GB") && ($lang != "de_DE") && ($lang != "fr_FR") && ($lang != "it_IT") && ($lang != "pt_PT"))
            {
			    $lang = LANG_LOCALE_DEFAULT;
		    }
            
		     
            switch($peticion)
            {
                case "":
                    $peticion = "home";
                case "home":
                    $objeto = new Home($lang);
                    $objeto->muestraHome ($this->params, $peticion);
                    break;
                case "servicios":
                    $objeto = new Home($lang);
                    $objeto->muestraServicios ($this->params, $peticion);
                    break;
                case "publi":
                    $objeto = new Publicaciones ($lang);
                    $objeto->muestraPubli ($this->params, $peticion);
                    break;
                case "buscarpubli":
                    $objeto = new Publicaciones ($lang);
                    $objeto->buscarPubli ($this->params, $peticion);
                    break;
                case "listatesis":
                    $objeto = new Tesis ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "listalibros":
                    $objeto = new Libro ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "listacasos":
                    $objeto = new Caso ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "listaarticulos":
                    $objeto = new Articulo ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "foros":
                    $objeto = new Foros ($lang);
                    $objeto->muestraForos ($this->params, $peticion);
                    break;
                case "listaforos":
                    $objeto = new Foros ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "usuarios":
                    $objeto = new Usuario($lang);
                    $objeto->muestraUsuarios ($this->params, $peticion);
                    break;
                case "registro":
                    $objeto = new Usuario($lang);
                    $objeto->muestraRegistro ($this->params, $peticion);
                    break;
                case "altausuario":
                    $objeto = new Usuario ($lang);
                    $objeto->nuevoUsuario ($this->params, $peticion);
                    break;
                case "login":
                    $objeto = new Usuario ($lang);
                    $objeto->muestraLogin ($this->params, $peticion);
                    break;
                case "acceso":
                    $objeto = new Usuario ($lang);
                    $objeto->login ($this->params, $peticion);
                    break;
                case "gestion":
                    $objeto = new Home($lang);
                    $objeto->muestraGestion ($this->params, $peticion);
                    break;
                case "registroapp":
                    $objeto = new Usuario ($lang);
                    $objeto->muestraRegApp ($this->params, $peticion);
                    break;
                case "loginapp":
                    $objeto = new Usuario ($lang);
                    $objeto->muestraLoginApp ($this->params, $peticion);
                    break; 
                case "accesoapp":
                    $objeto = new Usuario ($lang);
                    $objeto->loginApp ($this->params, $peticion);
                    break; 
                case "altasuscriptor":
                    $objeto = new Usuario ($lang);
                    $objeto->nuevoSuscriptor ($this->params, $peticion);
                    break;
                case "clientes":
                    $objeto = new Home($lang);
                    $objeto->muestraClientes ($this->params, $peticion);
                    break;
                case "acerca":
                    $objeto = new Home($lang);
                    $objeto->muestraAcerca ($this->params, $peticion);
                    break;
                case "contacto":
                    $objeto = new Home($lang);
                    $objeto->muestraContacto ($this->params, $peticion);
                    break;
                default:
                    $objeto = new noAutorizado($lang);
                    $objeto->denegar ($this->params, $peticion);
                    break;
            }    
        }
    }
?>