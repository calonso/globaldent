<?php
    /**
    * Fichero que recoje la implementacion de la clase abstracta Dispatcher, su método Dispatch será redefinido en sus clases hijas
    * 
    * @package Presentacion
    * @subpackage Acceso
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (10 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del archivo de configuracion.
    */
    include_once PATH_BASE."conf/conf.inc";
    /**
    * Inclusion de la clase Params encargada del manejo de los parametros de peticion
    */
    include_once PATH_BASE."src/acceso/Params.inc";
    /**
    * Inclusion del archivo no Autorizado para las peticiones no autorizadas
    */
    include_once PATH_BASE."src/error/noAutorizado.inc";
    /**
    * Inclusion del archivo Home para las peticiones home
    */
    include_once PATH_BASE."src/home/Home.inc";
    /**
    * Inclusion del archivo Cita para las peticiones de la agenda
    */
    include_once PATH_BASE."src/gbdapp/agenda/Cita.inc";
    /**
    * Inclusion del archivo Paciente para las peticiones de los pacientes
    */
    include_once PATH_BASE."src/gbdapp/pacientes/Paciente.inc";
    /**
    * Inclusion del archivo Dres para las peticiones de los doctores ajenos a la clínica
    */
    include_once PATH_BASE."src/gbdapp/dres/Dres.inc";
    /**
    * Inclusion del archivo Personal para las peticiones de los empleados de la clínica
    */
    include_once PATH_BASE."src/gbdapp/personal/Personal.inc";
    /**
    * Inclusion del archivo Visitas para las peticiones de las visitas médicas de los pacientes
    */
    include_once PATH_BASE."src/gbdapp/visitas/Visita.inc";
    /**
    * Inclusion del archivo Configuracion para las peticiones de configuracion de elementos personalizables
    */
    include_once PATH_BASE."src/gbdapp/conf/Configuracion.inc";
    /**
    * Inclusion del archivo Imagen para las peticiones de imágenes
    */
    include_once PATH_BASE."src/gbdapp/imagenes/Imagen.inc";
    /**
    * Inclusion del archivo Contabilidad para las peticiones de contabilidad
    */
    include_once PATH_BASE."src/gbdapp/conta/Contabilidad.inc";
    /**
    * Inclusion del archivo Presupuesto para las peticiones de presupuestos
    */
    include_once PATH_BASE."src/gbdapp/presupuestos/Presupuesto.inc";
    /**
    * Inclusion del archivo Factura para las peticiones de facturas
    */
    include_once PATH_BASE."src/gbdapp/facturas/Factura.inc";
    /**
    * Inclusion del archivo Consentimiento para las peticiones de consentimientos
    */
    include_once PATH_BASE."src/gbdapp/consentimientos/Consentimiento.inc";
    /**
    * Inclusion del archivo Pedido para las peticiones de pedidos de material
    */
    include_once PATH_BASE."src/gbdapp/pedidos/Pedido.inc";
    /**
    * Inclusion del archivo Receta para las peticiones de recetas
    */
    include_once PATH_BASE."src/gbdapp/recetas/Receta.inc";
    /**
    * Inclusion del archivo Admin para las peticiones de administracion
    */
    include_once PATH_BASE."src/gbdapp/admin/ClinicAdmin.inc";
    
    /**
    * Clase abstracta Dispatcher, se encarga de transferir el control al objeto correspondiente
    * 
    * @package Presentacion
    * @subpackage Acceso
    * @abstract
    */
    abstract class Dispatcher
    {
        /**
        * Variable que guarda el objeto de la clase params, para recojer los parametros de las peticiones
        * @var resource 
        */
        protected $params;
        /**
        * Constructor de la clase Dispatcher
        * @return void
        */
        function Dispatcher()
        {
            $this->params = new Params();     
            return;  
        }
        /**
        * Funcion que transfiere el control de flujo al objeto correspondiente en funcion de la peticion recibida
        * Permite cargar cualquier pagina del site
        * 
        * @return void
        * @abstract
        */
        abstract function dispatch(); 

    	function dispatchEmpleado()
        {
            $peticion = $this->params->getParam("cod");
            $lang = $this->params->getParam("lang");
            
            if (($lang != "es_ES") && ($lang != "en_GB") && ($lang != "de_DE") && ($lang != "fr_FR") && ($lang != "it_IT") && ($lang != "pt_PT"))
            {
			    $lang = LANG_LOCALE_DEFAULT;
		    }
		    
		    Utils::log_info("Starting dispatch as empleado for $peticion request.");
             
            switch($peticion)
            {
                case "home":
                case "accesoapp":
                    $objeto = new Home ($lang);
                    $objeto->muestraHomeApp ($this->params, $peticion);
                    break; 
                case "agenda":
                    $objeto = new Cita ($lang);
                    $objeto->verAgenda ($this->params, $peticion);
                    break;
                case "abrircita":
                    $objeto = new Cita ($lang);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "nuevacita":
                    $objeto = new Cita ($lang);
                    $objeto->nueva ($this->params, $peticion);
                    break;
                case "borrarcita":
                    $objeto = new Cita ($lang);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "buscarcita":
                    $objeto = new Cita ($lang);
                    $objeto->buscar ($this->params, $peticion);
                    break;
                case "bloqagenda":
                    $objeto = new Cita ($lang);
                    $objeto->bloquear ($this->params, $peticion);
                    break;
                case "desbloqagenda":
                    $objeto = new Cita ($lang);
                    $objeto->desbloquear ($this->params, $peticion);
                    break;
                case "borranolog":
                    $objeto = new Cita ($lang);
                    $objeto->borraNoLog ($this->params, $peticion);
                    break;
                case "colorcita":
                	$objeto = new Cita ($lang);
                	$objeto->colorCita ($this->params, $peticion);
                	break;
                case "pacientes":
                    $objeto = new Paciente ($lang);
                    $objeto->index ($this->params, $peticion);
                    break;
                case "nuevopaciente":
                    $objeto = new Paciente ($lang);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "altapaciente":
                    $objeto = new Paciente ($lang);
                    $objeto->nuevo ($this->params, $peticion);
                    break;
                case "verpac":
                    $objeto = new Paciente ($lang);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "modpac":
                    $objeto = new Paciente ($lang);
                    $objeto->muestraModificar ($this->params, $peticion);
                    break;
                case "actualizapaciente":
                    $objeto = new Paciente ($lang);
                    $objeto->actualizar ($this->params, $peticion);
                    break;
                case "borrapac":
                    $objeto = new Paciente ($lang);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "listapacientes":
                    $objeto = new Paciente ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "buscapacientes":
                    $objeto = new Paciente ($lang);
                    $objeto->muestraBuscar ($this->params, $peticion);
                    break;
                case "busquedapacientes":
                    $objeto = new Paciente ($lang);
                    $objeto->buscar ($this->params, $peticion);
                    break;
                case "dres":
                    $objeto = new Dres ($lang);
                    $objeto->index ($this->params, $peticion);
                    break;
                case "nuevodr":
                    $objeto = new Dres ($lang);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "altadr":
                    $objeto = new Dres ($lang);
                    $objeto->nuevo ($this->params, $peticion);
                    break;
                case "verdr":
                    $objeto = new Dres ($lang);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "buscadr":
                    $objeto = new Dres ($lang);
                    $objeto->muestraBuscar ($this->params, $peticion);
                    break;
                case "busquedadr":
                    $objeto = new Dres ($lang);
                    $objeto->buscar ($this->params, $peticion);
                    break;
                case "moddr":
                    $objeto = new Dres ($lang);
                    $objeto->muestraModificar ($this->params, $peticion);
                    break;
                case "actualizadr":
                    $objeto = new Dres ($lang);
                    $objeto->actualizar ($this->params, $peticion);
                    break;
                case "borrardr":
                    $objeto = new Dres ($lang);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "listadr":
                    $objeto = new Dres ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "personal":
                    $objeto = new Personal ($lang);
                    $objeto->index ($this->params, $peticion);
                    break;
                case "verpers":
                    $objeto = new Personal ($lang);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "modemp":
                    if($_SESSION[id_pers] == $this->params->getParam('id'))
                    {
                        $objeto = new Personal ($lang);
                        $objeto->muestraModificar ($this->params, $peticion);
                    }else {
                       $objeto = new noAutorizado ($lang);
                       $objeto->denegar ($this->params, $peticion); 
                    }
                    break;
                case "actualizaempleado":
                    if($_SESSION[id_pers] == $this->params->getParam('id'))
                    {
                        $objeto = new Personal ($lang);
                        $objeto->actualizar ($this->params, $peticion);
                    }else {
                       $objeto = new noAutorizado ($lang);
                       $objeto->denegar ($this->params, $peticion); 
                    }
                    break;
                case "verModPassEmp":
                     if($_SESSION[id_pers] == $this->params->getParam('id'))
                    {
                        $objeto = new Personal ($lang);
                        $objeto->index ($this->params, $peticion);
                    }else {
                       $objeto = new noAutorizado ($lang);
                       $objeto->denegar ($this->params, $peticion); 
                    }
                    break;
                case "actualizaPassEmp":
                     if($_SESSION[id_pers] == $this->params->getParam('id'))
                    {
                        $objeto = new Personal ($lang);
                        $objeto->actualizaPass ($this->params, $peticion);
                    }else {
                       $objeto = new noAutorizado ($lang);
                       $objeto->denegar ($this->params, $peticion); 
                    }
                    break;
                case "buscaempleados":
                    $objeto = new Personal ($lang);
                    $objeto->muestraBuscar ($this->params, $peticion);
                    break;
                case "busquedaempleados":
                    $objeto = new Personal ($lang);
                    $objeto->buscar ($this->params, $peticion);
                    break;
                case "listaempleados":
                    $objeto = new Personal ($lang);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "actividademp":
                    $objeto = new Personal ($lang);
                    $objeto->actividad ($this->params, $peticion);
                    break;
                case "historia":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }    
                    $objeto = new Visita ($lang, $id);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "historiaecon":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }    
                    $objeto = new Visita ($lang, $id);
                    $objeto->listadoEcon ($this->params, $peticion);
                    break;
                case "abrirvisita":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Visita ($lang, $id);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "nuevavisita":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Visita ($lang, $id);
                    $objeto->nueva ($this->params, $peticion);
                    break;
                case "nuevalineamv":
                case "nuevalineav":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Visita ($lang, $id);
                    $objeto->nuevaLinea ($this->params, $peticion);
                    break;
                case "borralineamv":
                case "borralineav":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Visita ($lang, $id);
                    $objeto->borraLinea ($this->params, $peticion);
                    break;
                case "fsa":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Visita ($lang, $id);
                    $objeto->fsa ($this->params, $peticion);
                    break;
                case "vervisita":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Visita ($lang, $id);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "modvisita":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Visita ($lang, $id);
                    $objeto->muestraEditar ($this->params, $peticion);
                    break;
                case "actualizavisita":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Visita ($lang, $id);
                    $objeto->actualizar ($this->params, $peticion);
                    break;
                case "borravisita":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Visita ($lang, $id);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "imagenes":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Imagen ($lang, $id);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "nuevaimagen":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Imagen ($lang, $id);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "altaimagen":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Imagen ($lang, $id);
                    $objeto->nueva ($this->params, $peticion);
                    break;
                case "verimagen":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Imagen ($lang, $id);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "borraimagen":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Imagen ($lang, $id);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "presupuestos":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Presupuesto ($lang, $id);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "nuevopres":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Presupuesto ($lang, $id);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "nuevalineamp":
                case "nuevalineap":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Presupuesto ($lang, $id);
                    $objeto->nuevaLinea ($this->params, $peticion);
                    break;
                case "borralineamp":
                case "borralineap":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Presupuesto ($lang, $id);
                    $objeto->borraLinea ($this->params, $peticion);
                    break;
                case "guardapres":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Presupuesto ($lang, $id);
                    $objeto->nuevo ($this->params, $peticion);
                    break;
                case "verpres":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Presupuesto ($lang, $id);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "borrapres":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Presupuesto ($lang, $id);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "modpres":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Presupuesto ($lang, $id);
                    $objeto->muestraEditar ($this->params, $peticion);
                    break;
                case "actualizapres":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Presupuesto ($lang, $id);
                    $objeto->actualizar ($this->params, $peticion);
                    break;
                case "facturas":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Factura ($lang, $id);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "nuevafact":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Factura ($lang, $id);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "nuevalineaf":
                case "nuevalineamf":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Factura ($lang, $id);
                    $objeto->nuevaLinea ($this->params, $peticion);
                    break;
                case "borralineaf":
                case "borralineamf":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Factura ($lang, $id);
                    $objeto->borraLinea ($this->params, $peticion);
                    break;
                case "guardafact":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Factura ($lang, $id);
                    $objeto->nueva ($this->params, $peticion);
                    break;
                case "verfact":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Factura ($lang, $id);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "borrafact":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Factura ($lang, $id);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "modfact":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Factura ($lang, $id);
                    $objeto->muestraEditar ($this->params, $peticion);
                    break;
                case "actualizafact":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Factura ($lang, $id);
                    $objeto->actualizar ($this->params, $peticion);
                    break;
                case "cons":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Consentimiento ($lang, $id);
                    $objeto->listado ($this->params, $peticion);
                    break;
                case "nuevocons":
                	$objeto = new Consentimiento($lang, $this->params->getParam('id'));
                	$objeto->muestraFormulario ($this->params, $peticion);
                	break;
                case "nuevoconsr":
                	$objeto = new Consentimiento($lang, $this->params->getParam('id'));
                	$objeto->muestraFormularioR ($this->params, $peticion);
                	break;
                case "firmacons":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Consentimiento ($lang, $id);
                    $objeto->nuevo ($this->params, $peticion);
                    break; 
                case "revocar":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Consentimiento ($lang, $id);
                    $objeto->revocar ($this->params, $peticion);
                    break; 
                case "vercons":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Consentimiento ($lang, $id);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "verconsr":
                    $id = $this->params->getParam('id');
                    if(!isset($id))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Consentimiento ($lang, $id);
                    $objeto->verRevocado ($this->params, $peticion);
                    break;
                case "nuevareceta":
                    $id = $this->params->getParam('id');
                    $vis = $this->params->getParam ('vis');
                    if((!isset($id))||(!isset($vis)))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Receta ($lang, $id, $vis);
                    $objeto->nueva ($this->params, $peticion);
                    break; 
                case "receta":
                    $id = $this->params->getParam('id');
                    $vis = $this->params->getParam ('vis');
                    if((!isset($id))||(!isset($vis)))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Receta ($lang, $id, $vis);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break; 
                case "verreceta":
                    $id = $this->params->getParam('id');
                    $vis = $this->params->getParam ('vis');
                    if((!isset($id))||(!isset($vis)))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Receta ($lang, $id, $vis);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "borrareceta":
                    $id = $this->params->getParam('id');
                    $vis = $this->params->getParam ('vis');
                    if((!isset($id))||(!isset($vis)))
                    {
                        $objeto = new noAutorizado ($lang);
                        $objeto->denegar ($this->params, $peticion);
                        break;
                    }
                    $objeto = new Receta ($lang, $id, $vis);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "pedidos":
                    $objeto = new Pedido ($lang);
                    $objeto->index ($this->params, $peticion);
                    break;  
                case "conta":
                    $objeto = new Contabilidad ($lang);
                    $objeto->index ($this->params, $peticion);
                    break;
                case "vercaja":
                    $objeto = new Contabilidad ($lang);
                    $objeto->verCaja ($this->params, $peticion);
                    break;
                case "pagavisita":
                    $objeto = new Contabilidad ($lang);
                    $objeto->cobrar ($this->params, $peticion);
                    break;
                case "editapagopac":
                    $objeto = new Contabilidad ($lang);
                    $objeto->muestraEditar ($this->params, $peticion);
                    break;
                case "modpagopac":
                    $objeto = new Contabilidad ($lang);
                    $objeto->modificaPago ($this->params, $peticion);
                    break;
                case "borrapagopac":
                    $objeto = new Contabilidad ($lang);
                    $objeto->borraPago ($this->params, $peticion);
                    break;
                case "verpendientes":
                    $objeto = new Contabilidad ($lang);
                    $objeto->verPendientes ($this->params, $peticion);
                    break;
                case "logout":
                    $objeto = new Usuario ($lang);
                    $objeto->logout ($this->params, $peticion);
                    break;
                default:
                	Utils::log_info("Dispatch for $peticion request wasn't performed denying permissions.");
                    $objeto = new noAutorizado ($lang);
                    $objeto->denegar ($this->params, $peticion);
                    break;    
            }
        }
    
    	function dispatchSubAdmin(){
    		$peticion = $this->params->getParam("cod");
            $lang = $this->params->getParam("lang");
            
            if (($lang != "es_ES") && ($lang != "en_GB") && ($lang != "de_DE") && ($lang != "fr_FR") && ($lang != "it_IT") && ($lang != "pt_PT"))
            {
			    $lang = LANG_LOCALE_DEFAULT;
		    }
		    
		    Utils::log_info("Starting dispatch as subAdmin for $peticion request.");
             
            switch($peticion)
            {
                case "suscripcion":
                    $objeto = new Usuario ($lang);
                    $objeto->verSuscripcion ($this->params, $peticion);
                    break;
                case "conf":
                    $objeto = new Configuracion ($lang);
                    $objeto->index ($this->params, $peticion);
                    break;
                case "servicios":
                    $objeto = new Configuracion ($lang);
                    $objeto->listaServicios ($this->params, $peticion);
                    break;
                case "nuevotipoimg":
                case "nuevoservicio":
                case "nuevotiporec":
                    $objeto = new Configuracion ($lang);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "altaservicio":
                    $objeto = new Configuracion ($lang);
                    $objeto->nuevo ($this->params, $peticion);
                    break;
                case "borraservicio":
                    $objeto = new Configuracion ($lang);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "tipoimgs":
                    $objeto = new Configuracion ($lang);
                    $objeto->listaTipoImgs ($this->params, $peticion);
                    break;
                case "altatipoimg":
                    $objeto = new Configuracion ($lang);
                    $objeto->nuevoTipo ($this->params, $peticion);
                    break;
                case "borratipo":
                    $objeto = new Configuracion ($lang);
                    $objeto->borrarTipo ($this->params, $peticion);
                    break;
                case "datosclinica":
                    $objeto = new Configuracion ($lang);
                    $objeto->verDatos ($this->params, $peticion);
                    break;
                case "actualizadatosclinica":
                    $objeto = new Configuracion ($lang);
                    $objeto->actualizarDatos ($this->params, $peticion);
                    break;
                case "tipocons":
                    $objeto = new Configuracion ($lang);
                    $objeto->listaTipoCons ($this->params, $peticion);
                    break;
                case "nuevotipocons":
                    $objeto = new Configuracion ($lang);
                    $objeto->muestraFormCons ($this->params, $peticion);
                    break;
                case "altatipocons":
                    $objeto = new Configuracion ($lang);
                    $objeto->nuevoCons ($this->params, $peticion);
                    break;
                case "borratipocons":
                    $objeto = new Configuracion ($lang);
                    $objeto->borraCons ($this->params, $peticion);
                    break;
                case "vertipocons":
                    $objeto = new Configuracion ($lang);
                    $objeto->verCons ($this->params, $peticion);
                    break;
                case "modtipocons":
                    $objeto = new Configuracion ($lang);
                    $objeto->modificaCons ($this->params, $peticion);
                    break;
                case "tiporecetas":
                    $objeto = new Configuracion ($lang);
                    $objeto->listaRecetas ($this->params, $peticion);
                    break;
                case "altatiporec":
                    $objeto = new Configuracion ($lang);
                    $objeto->nuevaReceta ($this->params, $peticion);
                    break;
                case "modtiporec":
                    $objeto = new Configuracion ($lang);
                    $objeto->verReceta ($this->params, $peticion);
                    break;
                case "edittiporec":
                    $objeto = new Configuracion ($lang);
                    $objeto->editaReceta ($this->params, $peticion);
                    break;
                case "borratiporec":
                    $objeto = new Configuracion ($lang);
                    $objeto->borraReceta ($this->params, $peticion);
                    break;
                case "grupoimgs":
                    $objeto = new Configuracion ($lang);
                    $objeto->listaGrupoImgs ($this->params, $peticion);
                    break;
                case "nuevogrupoimg":
                    $objeto = new Configuracion ($lang);
                    $objeto->nuevoGrupoImgs ($this->params, $peticion);
                    break;
                case "altagrupoimg":
                    $objeto = new Configuracion ($lang);
                    $objeto->altaGrupoImgs ($this->params, $peticion);
                    break;
                case "borragrupoimg":
                    $objeto = new Configuracion ($lang);
                    $objeto->borraGrupoImgs ($this->params, $peticion);
                    break;
                default:
                	$this->dispatchEmpleado();
                	break;
    		}
    	}
    	
    	function dispatchAdmin(){
    		$peticion = $this->params->getParam("cod");
            $lang = $this->params->getParam("lang");
            
            if (($lang != "es_ES") && ($lang != "en_GB") && ($lang != "de_DE") && ($lang != "fr_FR") && ($lang != "it_IT") && ($lang != "pt_PT"))
            {
			    $lang = LANG_LOCALE_DEFAULT;
		    }
		    
		    Utils::log_info("Starting dispatch as admin for $peticion request.");
             
            switch($peticion)
            {
            	case "nuevoempleado":
                    $objeto = new Personal ($lang);
                    $objeto->muestraFormulario ($this->params, $peticion);
                    break;
                case "altaempleado":
                    $objeto = new Personal ($lang);
                    $objeto->nuevo ($this->params, $peticion);
                    break;
                case "modemp":
                    $objeto = new Personal ($lang);
                    $objeto->muestraModificar ($this->params, $peticion);
                    break;
                case "actualizaempleado":
                    $objeto = new Personal ($lang);
                    $objeto->actualizar ($this->params, $peticion);
                    break;
                case "verModPassEmp":
                    $objeto = new Personal ($lang);
                    $objeto->index ($this->params, $peticion);
                    break;
                case "actualizaPassEmp":
                    $objeto = new Personal ($lang);
                    $objeto->actualizaPass ($this->params, $peticion);
                    break;
                case "actualizapagopac":
                    $objeto = new Contabilidad ($lang);
                    $objeto->muestraEditarPago ($this->params, $peticion);
                    break;
                case "listafacturas":
                	$objeto = new Contabilidad ($lang);
                	$objeto->listaFacturas ($this->params, $peticion);
                	break;
                case "borraemp":
                    $objeto = new Personal ($lang);
                    $objeto->borrar ($this->params, $peticion);
                    break;
                case "admin":
                    $objeto = new ClinicAdmin ($lang);
                    $objeto->index ($this->params, $peticion);
                    break;
                case "log":
                    $objeto = new Logger ($lang);
                    $objeto->index ($this->params, $peticion);
                    break;
                case "verlog":
                    $objeto = new Logger ($lang);
                    $objeto->ver ($this->params, $peticion);
                    break;
                case "copia":
                    $objeto = new ClinicAdmin ($lang);
                    $objeto->copiasIndex ($this->params, $peticion);
                    break;
                case "crearcopia":
                    $objeto = new ClinicAdmin ($lang);
                    $objeto->copiar ($this->params, $peticion);
                    break;
                case "restaurar":
                    $objeto = new ClinicAdmin ($lang);
                    $objeto->copiasIndex ($this->params, $peticion);
                    break;
                case "restaurazip":
                    $objeto = new ClinicAdmin ($lang);
                    $objeto->restaurar ($this->params, $peticion);
                    break;
                default:
                	$this->dispatchSubAdmin();
                	break;
            }
    	}
    }
?>