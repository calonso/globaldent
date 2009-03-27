<?php
    /**
    * Fichero que recoje la implementacion del dispatcher administrador.
    * 
    * @package Presentacion
    * @subpackage Acceso
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (4 - Febrero - 2008)
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
    * Inclusion del archivo tesis para la pagina de tesis
    */
    include_once PATH_BASE."src/publicaciones/Tesis.inc";
    /**
    * Inclusion del archivo libro para la pagina de libros
    */
    include_once PATH_BASE."src/publicaciones/Libro.inc";
    /**
    * Inclusion del archivo caso para la pagina de casos clínicos
    */
    include_once PATH_BASE."src/publicaciones/Caso.inc";
    /**
    * Inclusion del archivo artículo para la pagina de artículos y revistas
    */
    include_once PATH_BASE."src/publicaciones/Articulo.inc";
    
    /**
    * Clase Admin, implementa la lógica de transferencia de control para las peticiones que le conciernen.
    * 
    * @package Presentacion
    * @subpackage Acceso
    */
    class Admin extends Dispatcher
    {
        /**
        * Constructor de la clase, crea un objeto de la clase padre para obtener todas sus propiedades
        * @return void
        */
        function Admin()
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
                case "verpubli":
                    $objeto = new Publicaciones ($lang);
                    $objeto->verPubliUsr ($this->params, $peticion);
                    break;
                case "buscarpubli":
                    $objeto = new Publicaciones ($lang);
                    $objeto->buscarPubli ($this->params, $peticion);
                    break;
                case "foros":
                    $objeto = new Foros ($lang);
                    $objeto->muestraForos ($this->params, $peticion);
                    break;
                case "abrirforo":
                    $objeto = new Foros ($lang);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "nuevoforo":
                    $objeto = new Foros ($lang);
                    $objeto->nuevo ($this->params, $peticion);
                    break;
                case "listaforos":
                    $objeto = new Foros ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "verforo":
                    $objeto = new Foros ($lang);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "borraforo":
                    $objeto = new Foros ($lang);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "responder":
                    $objeto = new Foros ($lang);
                    $objeto->muestraForm ($this->params, $peticion);
                    break;
                case "nuevomensaje":
                    $objeto = new Foros ($lang);
                    $objeto->responder ($this->params, $peticion);
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
                case "listausuarios":
                    $objeto = new Usuario ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "login":
                    $objeto = new Usuario ($lang);
                    $objeto->muestraLogin ($this->params, $peticion);
                    break;
                case "acceso":
                    $objeto = new Usuario ($lang);
                    $objeto->login ($this->params, $peticion);
                    break;
                case "verfichaadmin":
                case "verficha":
                    $objeto = new Usuario ($lang);
                    $objeto->verFicha ($this->params, $peticion);
                    break;
                case "modificar":
                    $objeto = new Usuario ($lang);
                    $objeto->muestraModificar ($this->params, $peticion);
                    break;
                case "actualizar":
                    $objeto = new Usuario ($lang);
                    $objeto->modificar ($this->params, $peticion);
                    break;
                case "modificarpassadmin":
                case "modificarpass":
                    $objeto = new Usuario ($lang);
                    $objeto->muestraModificarPass ($this->params, $peticion);
                    break;
                case "actualizarpass":
                    $objeto = new Usuario ($lang);
                    $objeto->modificarPass ($this->params, $peticion);
                    break;
                case "listapagos":
                    $objeto = new Usuario ($lang);
                    $objeto->listaPagos ($this->params, $peticion);
                    break;
                case "logout":
                    $objeto = new Usuario ($lang);
                    $objeto->logout ($this->params, $peticion);
                    break;
                case "baja":
                    $objeto = new Usuario ($lang);
                    $objeto->baja ($this->params, $peticion);
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
                case "colgartesis":
                    $objeto = new Tesis($lang);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "nuevatesis":
                    $objeto = new Tesis ($lang);
                    $objeto->nuevaTesis ($this->params, $peticion);
                    break;
                case "vertesis":
                    $objeto = new Tesis ($lang);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "listatesis":
                    $objeto = new Tesis ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "modificartesis":
                    $objeto = new Tesis ($lang);
                    $objeto->muestraModificar ($this->params, $peticion);
                    break;
                case "actualizartesis":
                    $objeto = new Tesis ($lang);
                    $objeto->actualizar ($this->params, $peticion);
                    break;
                case "borrartesis":
                    $objeto = new Tesis ($lang);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "colgarlibro":
                    $objeto = new Libro ($lang);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "nuevolibro":
                    $objeto = new Libro ($lang);
                    $objeto->nuevo ($this->params, $peticion);
                    break;
                case "listalibros":
                    $objeto = new Libro ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "verlibro":
                    $objeto = new Libro ($lang);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "modificarlibro":
                    $objeto = new Libro ($lang);
                    $objeto->muestraModificar ($this->params, $peticion);
                    break;
                case "actualizarlibro":
                    $objeto = new Libro ($lang);
                    $objeto->actualizar ($this->params, $peticion);
                    break;
                case "borrarlibro":
                    $objeto = new Libro ($lang);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "colgarcaso":
                    $objeto = new Caso ($lang);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "nuevocaso":
                    $objeto = new Caso ($lang);
                    $objeto->nuevo ($this->params, $peticion);
                    break;
                case "listacasos":
                    $objeto = new Caso ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "vercaso":
                    $objeto = new Caso ($lang);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "modificarcaso":
                     $objeto = new Caso ($lang);
                    $objeto->muestraModificar ($this->params, $peticion);
                    break;
                case "actualizarcaso":
                    $objeto = new Caso ($lang);
                    $objeto->actualizar ($this->params, $peticion);
                    break;
                case "borrarcaso":
                    $objeto = new Caso ($lang);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "colgararticulo":
                    $objeto = new Articulo ($lang);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "nuevoarticulo":
                    $objeto = new Articulo ($lang);
                    $objeto->nuevo ($this->params, $peticion);
                    break;
                case "listaarticulos":
                    $objeto = new Articulo ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "verarticulo":
                    $objeto = new Articulo ($lang);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "modificararticulo":
                     $objeto = new Articulo ($lang);
                    $objeto->muestraModificar ($this->params, $peticion);
                    break;
                case "actualizararticulo":
                    $objeto = new Articulo ($lang);
                    $objeto->actualizar ($this->params, $peticion);
                    break;
                case "borrararticulo":
                    $objeto = new Articulo ($lang);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                default:
                    $objeto = new noAutorizado($lang);
                    $objeto->denegar ();
                    break;
            }    
        }
    }
?>