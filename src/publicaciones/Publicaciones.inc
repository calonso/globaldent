<?php
    /**
    * Fichero que recoje la implementación de la clase Publicaciones que se encarga del control de las paginas de publicaciones
    * 
    * @package Negocio
    * @subpackage Publicaciones
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (13 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del archivo DisplayManager para tener acceso a la logica de presentacón de vistas
    */
    include_once PATH_BASE."src/vistas/DisplayManager.inc";
    /**
    * Inclusion del archivo TesisDAO para recoger las tesis
    */
    include_once PATH_BASE."src/publicaciones/TesisDAO.inc";
    /**
    * Inclusion del archivo LibroDAO para recoger los libros
    */
    include_once PATH_BASE."src/publicaciones/LibroDAO.inc";
    /**
    * Inclusion del archivo CasoDAO para recoger los casos
    */
    include_once PATH_BASE."src/publicaciones/CasoDAO.inc";
    /**
    * Inclusion del archivo ArticuloDAO para recoger los articulos
    */
    include_once PATH_BASE."src/publicaciones/ArticuloDAO.inc";
    /**
    * Inclusion del archivo UsuarioDAO para recoger el nombre del usuario
    */
    include_once PATH_BASE."src/usuarios/UsuarioDAO.inc";
    
    /**
    * Clase Publicaciones. Implementa la lógica de presentación de la página de publicaciones
    * @package Negocio
    * @subpackage Publicaciones
    */
    class Publicaciones extends DisplayManager
    {
        /**
        * Variable que almacenara los datos que se intercambian con el DAO
        * @var array
        */
        private $datos;
        /**
        * Constructor de la clase, crea un objeto de la clase padre e inicializa las variables
        * @param string Idioma en que se ha solicitado la página
        * @return void   
        */
        function Publicaciones ($lang)
        {
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."publicaciones/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            $this->smarty->assign ('on', 3);
            $this->datos = array();
            return;   
        }
        /**
        * Funcion que se encarga de mostrar la pagina de publicaciones
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function muestraPubli ($params, $file)
        {
            $this->muestraTesis();
            $this->muestraLibros();
            $this->muestraCasos();
            $this->muestraArticulos();
            
            $this->smarty->assign ('opciones', "publicaciones/opciones.phtml");
            $this->smarty->display ($this->path.$file.".phtml");
            return;    
        }
        /**
        * Funcion que carga los datos de las tesis que se mostraran
        * @param int Id del propietario de la tesis, por defecto ninguno para ver todas.
        * @return void
        */
        function muestraTesis ($id = 0)
        {
            $tesis = new TesisDAO();
            $this->datos = $tesis->listado ($id);
            if (is_array($this->datos))
            {
                $usuario = new UsuarioDAO();
                $this->smarty->assign ('num_tesis', $this->datos[0]);
                if($this->datos[0] > 5)
                    $this->datos = array_slice ($this->datos[1], 0, 5);
                else
                    $this->datos = $this->datos[1];
                    
                foreach ($this->datos as $indice => $valor)
                {
                    $temp = $usuario->ver ($this->datos[$indice][id_usuario]);
                    if(is_array($temp))
                    {    
                        $temp = $temp[0];
                        $this->datos[$indice][usuario] = $temp[apellido]." ".$temp[apellido2].", ".$temp[nombre];
                    }   
                }
                $this->smarty->assign ('tesis', $this->datos);   
            }else
                $this->smarty->assign ('num_tesis', 0);
            
            return;   
        }
        /**
        * Funcion que carga los datos de los libros que se mostraran
        * @param int Id del propietario del libro, por defecto ninguno para ver todos.
        * @return void
        */
        function muestraLibros ($id = 0)
        {
            $libro = new LibroDAO();
            $this->datos = $libro->listado ($id);
            if (is_array($this->datos))
            {
                $usuario = new UsuarioDAO();
                $this->smarty->assign ('num_libros', $this->datos[0]);
                if($this->datos[0] > 5)
                    $this->datos = array_slice ($this->datos[1], 0, 5);
                else
                    $this->datos = $this->datos[1];
                    
                foreach ($this->datos as $indice => $valor)
                {
                    $temp = $usuario->ver ($this->datos[$indice][id_usuario]);
                    if(is_array($temp))
                    {    
                        $temp = $temp[0];
                        $this->datos[$indice][usuario] = $temp[apellido]." ".$temp[apellido2].", ".$temp[nombre];
                    }   
                }
                $this->smarty->assign ('libros', $this->datos);   
            }else
                $this->smarty->assign ('num_libros', 0);
            
            return;   
        }
        /**
        * Funcion que carga los datos de los casos que se mostraran
        * @param int Id del propietario del caso, por defecto ninguno para ver todos.
        * @return void
        */
        function muestraCasos ($id = 0)
        {
            $caso = new CasoDAO();
            $this->datos = $caso->listado ($id);
            if (is_array($this->datos))
            {
                $usuario = new UsuarioDAO();
                $this->smarty->assign ('num_casos', $this->datos[0]);
                if($this->datos[0] > 5)
                    $this->datos = array_slice ($this->datos[1], 0, 5);
                else
                    $this->datos = $this->datos[1];
                    
                foreach ($this->datos as $indice => $valor)
                {
                    $temp = $usuario->ver ($this->datos[$indice][id_usuario]);
                    if(is_array($temp))
                    {    
                        $temp = $temp[0];
                        $this->datos[$indice][usuario] = $temp[apellido]." ".$temp[apellido2].", ".$temp[nombre];
                    }   
                }
                $this->smarty->assign ('casos', $this->datos);   
            }else
                $this->smarty->assign ('num_casos', 0);
            
            return;   
        }
        /**
        * Funcion que carga los datos de los articulos que se mostraran
        * @param int Id del propietario del articulo, por defecto ninguno para ver todos.
        * @return void
        */
        function muestraArticulos ($id = 0)
        {
            $articulo = new ArticuloDAO();
            $this->datos = $articulo->listado ($id);
            if (is_array($this->datos))
            {
                $usuario = new UsuarioDAO();
                $this->smarty->assign ('num_articulos', $this->datos[0]);
                if($this->datos[0] > 5)
                    $this->datos = array_slice ($this->datos[1], 0, 5);
                else
                    $this->datos = $this->datos[1];
                foreach ($this->datos as $indice => $valor)
                {
                    $temp = $usuario->ver ($this->datos[$indice][id_usuario]);
                    if(is_array($temp))
                    {    
                        $temp = $temp[0];
                        $this->datos[$indice][usuario] = $temp[apellido]." ".$temp[apellido2].", ".$temp[nombre];
                    }   
                }
                $this->smarty->assign ('articulos', $this->datos);   
            }else
                $this->smarty->assign ('num_articulos', 0);
            
            return;   
        }
        /**
        * Funcion que muestra todas las publicaciones pertenecientes a un usuario dado
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function verPubliUsr ($params, $file)
        {
            if ($_SESSION[privilegios] == 9)
            {
                $this->muestraTesis(0);
                $this->muestraLibros(0);
                $this->muestraCasos(0);
                $this->muestraArticulos(0);   
            }else{
                $this->muestraTesis($_SESSION[id_usr]);
                $this->muestraLibros($_SESSION[id_usr]);
                $this->muestraCasos($_SESSION[id_usr]);
                $this->muestraArticulos($_SESSION[id_usr]);
            }
            
            $this->smarty->assign ('opciones', "publicaciones/opcionesusr.phtml");
            $this->smarty->display ($this->path.$file.".phtml");
            return;         
        }
        /**
        * Funcion que busca en todas las publicaciones a partir de lo que el usuario introdujo
        * @param resource Objeto params para acceder a los parametros de la peticion
        * @param string Cadena que determina el template a mostrar
        * @return void
        */
        function buscarPubli ($params, $file)
        {
            $patron = $params->getParam ('txtBuscar');
            $array = array("titulo" => $patron);
            $this->buscarTesis($array);
            $this->buscarLibros ($array);
            $this->buscarCasos ($array);
            $this->buscarArticulos ($array);
            
            $this->smarty->assign ('opciones', "publicaciones/opciones.phtml");
            $this->smarty->display ($this->path.$file.".phtml");
            return;   
        }
        /**
        * Funcion que busca tesis a partir de los datos recibidos y carga los resultados para ser mostrados
        * @param array Datos a partir de los que se tiene que buscar
        * @return void
        */
        function buscarTesis ($datos)
        {
            $tesis = new TesisDAO();
            $this->datos = $tesis->buscar ($datos);
            if (is_array($this->datos))
            {
                $usuario = new UsuarioDAO();
                $this->smarty->assign ('num_tesis', $this->datos[0]);
                $this->datos = $this->datos[1];
                foreach ($this->datos as $indice => $valor)
                {
                    $temp = $usuario->ver ($this->datos[$indice][id_usuario]);
                    if(is_array($temp))
                    {    
                        $temp = $temp[0];
                        $this->datos[$indice][usuario] = $temp[apellido]." ".$temp[apellido2].", ".$temp[nombre];
                    }   
                }
                $this->smarty->assign ('tesis', $this->datos);   
            }else
                $this->smarty->assign ('num_tesis', 0);
            
            return;   
        }
        /**
        * Funcion que busca libros a partir de los datos recibidos y carga los resultados para ser mostrados
        * @param array Datos a partir de los que se tiene que buscar
        * @return void
        */
        function buscarLibros ($datos)
        {
            $libro = new LibroDAO();
            $this->datos = $libro->buscar ($datos);
            if (is_array($this->datos))
            {
                $usuario = new UsuarioDAO();
                $this->smarty->assign ('num_libros', $this->datos[0]);
                $this->datos = $this->datos[1];
                foreach ($this->datos as $indice => $valor)
                {
                    $temp = $usuario->ver ($this->datos[$indice][id_usuario]);
                    if(is_array($temp))
                    {    
                        $temp = $temp[0];
                        $this->datos[$indice][usuario] = $temp[apellido]." ".$temp[apellido2].", ".$temp[nombre];
                    }   
                }
                $this->smarty->assign ('libros', $this->datos);   
            }else
                $this->smarty->assign ('num_libros', 0);
            
            return;   
        }
        /**
        * Funcion que busca casos a partir de los datos recibidos y carga los resultados para ser mostrados
        * @param array Datos a partir de los que se tiene que buscar
        * @return void
        */
        function buscarCasos ($datos)
        {
            $caso = new CasoDAO();
            $this->datos = $caso->buscar ($datos);
            if (is_array($this->datos))
            {
                $usuario = new UsuarioDAO();
                $this->smarty->assign ('num_casos', $this->datos[0]);
                $this->datos = $this->datos[1];
                foreach ($this->datos as $indice => $valor)
                {
                    $temp = $usuario->ver ($this->datos[$indice][id_usuario]);
                    if(is_array($temp))
                    {    
                        $temp = $temp[0];
                        $this->datos[$indice][usuario] = $temp[apellido]." ".$temp[apellido2].", ".$temp[nombre];
                    }   
                }
                $this->smarty->assign ('casos', $this->datos);   
            }else
                $this->smarty->assign ('num_casos', 0);
            
            return;   
        }
        /**
        * Funcion que busca articulos y revistas a partir de los datos recibidos y carga los resultados para ser mostrados
        * @param array Datos a partir de los que se tiene que buscar
        * @return void
        */
        function buscarArticulos ($datos)
        {
            $articulo = new ArticuloDAO();
            $this->datos = $articulo->buscar ($datos);
            if (is_array($this->datos))
            {
                $usuario = new UsuarioDAO();
                $this->smarty->assign ('num_articulos', $this->datos[0]);
                $this->datos = $this->datos[1];
                foreach ($this->datos as $indice => $valor)
                {
                    $temp = $usuario->ver ($this->datos[$indice][id_usuario]);
                    if(is_array($temp))
                    {    
                        $temp = $temp[0];
                        $this->datos[$indice][usuario] = $temp[apellido]." ".$temp[apellido2].", ".$temp[nombre];
                    }   
                }
                $this->smarty->assign ('articulos', $this->datos);   
            }else
                $this->smarty->assign ('num_articulos', 0);
            
            return;   
        }
    }
?>