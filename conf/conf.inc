<?php
    /**
    * 
    * Archivo de configuración incluido en todos los módulos necesarios para personalizar el funcionamiento de la aplicación
    * 
    * @package conf
    * @author Carlos Alonso Pérez DNI: 70868503-Y  <cartecko1@terra.es>
    * @version 1.0 (5 - Diciembre - 2007)
    */
    
    
    /**
    * Nombre del servidor
    */
    define ("DB_SERVIDOR", "localhost");
    /**
    * Nombre de la base de datos
    */
    define ("DB_BD", "gbd");
    /**
    * Nombre del usuario
    */
    define ("DB_USUARIO", "root");
    /**
    * Password
    */
    define ("DB_CLAVE", "root");
    
    /**
    * Path absoluto donde se guardan los archivos del site
    */
    define ("PATH_BASE", $_SERVER['DOCUMENT_ROOT']."/globaldent/");
    /**
    * Request base del site
    */ 
    define ("REQ_BASE", "https://192.168.1.35/globaldent/"); 
    /**
    * Path donde se localizan los archivos de texto
    */
    define ("PATH_LANG", $_SERVER['DOCUMENT_ROOT']."/globaldent/lang/"); 
    /**
    * Path donde se guardan los templates
    */
    define ("TPL_PATH_BASE", $_SERVER['DOCUMENT_ROOT']."/globaldent/templates/templates/web/"); 
    /**
    * Path donde se solicitan las imagenes
    */
    define  ("IMG_PATH_BASE", REQ_BASE."img/");	
    /**
    * Habilita o no el cacheo de smarty
    */
    define ("SMARTY_CACHING", false);	
    /**
    * Idioma por defecto
    */
    define ("LANG_LOCALE_DEFAULT", "es_ES"); 
    /**
    * Estado del entorno DEV = desarrollo, PRO = producción, TEST = pruebas
    */
    define ("ENVIRONMENT", "TEST"); 
    /**
    * Número máximo de filas que se mostraán en búsquedas y listados
    */
    define ("MAX_FILAS", 20);   
    /**
    * Formato de fecha seleccionado por el usuario
    */
    define ("FORMATO_FECHA", "dd-mm-aaaa");
    /**
    * Número de gabinetes con que cuenta la clínica, debido al uso de smarty, esta variable es +1 de lo que el usuario introduce. 
    */
    define ("GABINETES", 7);
    /**
    * Constante para el alta
    */
    define ("LOG_ALTA", 1);
    /**
    * Constante para la baja
    */
    define ("LOG_BAJA", 2);
    /**
    * Constante para la modificacion
    */
    define ("LOG_MODIFICACION", 3);
    /**
    * Constante para el acceso
    */
    define ("LOG_LOGIN", 4);
    /**
    * Constante para la desconexión
    */
    define ("LOG_LOGOUT", 5);
    /**
    * Constante para actuaciones prohibidas
    */
    define ("LOG_FORBIDDEN", 6);
    /**
    * Constante de administrador absoluto
    */
    define ("CLINICADMIN", 4);
    /**
    * Constante de segundo administrador
    */
    define ("SUBADMIN", 5);
    /**
    * Constante para el personal
    */
    define ("EMPLEADO", 6); 
    /**
    * Constante de administrador del portal
    */
    define ("ADMIN", 9);
?>