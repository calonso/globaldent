<?php
    /**
    * Fichero que proteje de la descarga de archivos del portal no autorizada.
    * 
    * @package Presentacion
    * @subpackage Acceso
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (18 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del archivo de configuracion
    */
    include_once "conf/conf.inc";
    /**
    * Inclusion del archivo Error para denegar el acceso
    */
    include_once PATH_BASE."src/acceso/Error.inc";
    
    session_start();
    if(isset ($_SESSION[id]))
    {
        $aux = explode ("/", $_SERVER[PATH_INFO]);
        switch ($aux[1])
        {
          case "libros":
          case "casos":
          case "tesis":
          case "articulos":
            $file = "./publi".$_SERVER[PATH_INFO];
            break;
          case "fotopers":
            $file = "./imagenes/".$_SESSION[id_usr]."/id".$aux[2]."/fotopers";
            break; 
          case "fotoemp":
            $file = "./imagenes/".$_SESSION[id_usr]."/pers".$aux[2]."/fotopers";
            break;
          case "fotopac":
            $file = "./imagenes/".$_SESSION[id_usr]."/id".$aux[2]."/im".$aux[3];
            break; 
          case "logo":
            $file = "./imagenes/".$_SESSION[id_usr]."/logoclinica.jpg";
            break;
          case "fp":
          	$file = "./imagenes/".$_SESSION[id_usr]."/id".$aux[2]."/fpres".$aux[3];
          	//header('Content-Type: image/png'');
          	break;
          case "fc":
          	$file = "./imagenes/".$_SESSION[id_usr]."/id".$aux[2]."/fcons".$aux[3];
          	break;
          case "fcr":
          	$file = "./imagenes/".$_SESSION[id_usr]."/id".$aux[2]."/fconsr".$aux[3];
          	break;
        }
        readfile ($file);   
    }else
    {
        $objeto = new Error();
        $objeto->dispatch();   
    }
        
?>