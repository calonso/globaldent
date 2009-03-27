<?php
    /**
    * Archivo que recoje la implementacion de la clase Empleado
    * 
    * @package Presentacion
    * @subpackage Acceso
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es
    * @version: 1.0 (28 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del fichero Dispatcher, padre de este, del que heredará su estructura
    */
    include_once PATH_BASE."src/acceso/Dispatcher.inc";
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
    * Clase Privado, implementa la lógica de transferencia de control para las peticiones que le conciernen.
    * 
    * @package Presentacion
    * @subpackage Acceso
    */
    class Empleado extends Dispatcher
    {
        /**
        * Constructor de la clase, crea un objeto de la clase padre para obtener todas sus propiedades
        * @return void
        */
        function Empleado()
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
                case "home":
                case "accesoapp":
                    $objeto = new Home ($lang);
                    $objeto->muestraHomeApp ($this->params, $file);
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
                    $objeto = new noAutorizado ($lang);
                    $objeto->denegar ($this->params, $peticion);
                    break;    
            }
            return;
        }
    }
?>