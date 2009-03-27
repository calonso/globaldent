<?php
  /**
    * Archivo que recoje la implementacion de la clase Admin
    * 
    * @package Negocio
    * @subpackage Administracion
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es
    * @version: 1.0 (28 - Diciembre - 2007)
    */
    
    /**
    * Inclusion de la clase Copier para tener acceso a la logica de acceso a datos
    */
    include_once PATH_BASE."src/gbdapp/admin/Copier.inc";
    
    include_once PATH_BASE."src/gbdapp/personal/PersonalDAO.inc";
    
    //include_once PATH_BASE."src/gbdapp/admin/zipfile.inc";
    
    class ClinicAdmin extends DisplayManager 
    {
        /** Almacenará la referencia a su objeto dao */
        private $dao;
        
        private $carpeta;
        
        /**
        * Constructor de la clase, inicializa las variables
        */
        function ClinicAdmin($lang)
        {
            /*
            * Establece una capacidad de memoria para el script de 24M
            * y un tiempo de respuesta de 120segundos (2 minutos)
            */
            ini_set("memory_limit","1024M");
            set_time_limit  (6000);
            
            parent::DisplayManager();
            $this->path = TPL_PATH_BASE."gbdapp/admin/";
            
            $lang_file = PATH_LANG.$lang."/site.lng";
            $this->smarty->assign ('lang_file', $lang_file);
            
            $this->smarty->assign('on', 9);
            
            $this->smarty->assign('privilegios', $_SESSION[privilegios]);
            
            $this->dao = new Copier();
            
            $this->carpeta = PATH_BASE."imagenes/".$_SESSION[id_usr]."/";

            return; 
        }
        
        /**
        * Muestra la página principal de administración
        */
        function index($params, $file) 
        {
            $file = "index";
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }   
        
        /** 
        * Muestra la página principal de la copia de seguridad
        */
        function copiasIndex($params, $file)
        {
            $this->smarty->display ($this->path.$file.".phtml");
            return;
        }
        
        /**
        * Crea una copia de seguridad de los datos
        */
        function copiar ($params, $file)
        {
            $this->crearZip();
            
            header('Content-Type: application/octet-stream');
            header('Content-Disposition: attachment; filename=backup.zip');
            readfile ($this->carpeta."backup.zip");
            unlink($this->carpeta."backup.zip");
            return;
        }
        
        /**
        * Funcion que crea un archivo Zip conteniendo un backup de todos los datos
        */
        function crearZip ()
        {
           $tablas = array("usuario", "personal", "dr_externo", "opciones", "servicio", "tipo_imagen", "tipo_consentimiento", 
                "tipo_receta", "pedido", "log", "paciente", "pagopac", "cita", "visita", "factura", "presupuesto", "consentimiento", 
                "consentimiento_revocado", "colaborador", "asistente", "receta", "linea_factura", "linea_presupuesto", "linea_visita");
            
            $fich = fopen($this->carpeta."backup.sql", 'w+');
            $zip = new ZipArchive();
            
            if($zip->open ($this->carpeta."backup.zip", ZIPARCHIVE::CREATE)!=TRUE)
                exit("no se pudo abrir el archivo backup.zip");
           
           
            foreach ($tablas as $tabla)
            {
                /*$limit = 0;
                $data = $this->dao->consultar ($tabla);
                $total = (int)$data[1][0][total];
                $recogidos = 0; 
                //echo "$tabla total de: $total<br />";
                while ($recogidos < $total)
                {   //Mientras queden registros por recoger
                    //echo "voy con $recogidos hasta $total<br />";
                    //echo "vuelta: $recogidos y $total<br />";
                    $this->datos = $this->dao->copiar ($tabla, $limit);
                    if ($this->datos < 0)
                    {
                        $error = true;
                        break;
                    }else if ($this->datos[0] > 0) {
                        $recogidos += $this->datos[0];
                        //echo "recojo: ".$this->datos[0]." limite: $limit y llevo: $recogidos <br />";
                        $this->escribir ($fich, $this->datos[1], $tabla);
                    }else
                        break;
                    $limit += 100;
                }
                if($error){
                    $this->smarty->assign ('codigo', $this->datos);
                    break;
                } */
            	$this->dao->migrate($tabla, $fich);
            }    
            fclose($fich);
            
            $this->archivar ($zip, $this->carpeta, "");
            if ($zip->close()!=TRUE)
            {
                   exit("no cierra");
            } 
            //unlink($this->carpeta."backup.sql");
            
        }
        
        /**
        * Escribe un array al fichero
        */
        function escribir ($fichero, $datos, $tabla)
        {
            //echo "escribir";
            //print_r ($datos);
            $cadena = "insert into $tabla ";
            $llaves = array_keys($datos[0]);
            
            $campos = "(";
            foreach ($llaves as $campo)
            {
                $campos .= $campo.", ";   
            }
            $campos = substr($campos, 0, strlen($campos) -2);
            $campos .= ") values ";
            
            $cadena .= $campos;
            
            foreach ($datos as $linea)
            {
                $valores = "(";
                foreach ($linea as $valor)
                {
                    $valores .= $valor.", "; 
                }
                $valores = substr ($valores, 0, strlen($valores)-2);
                $valores .= "), ";
                $cadena .= $valores;
            }   
            $cadena = substr($cadena, 0, strlen ($cadena) - 2);
            $cadena .= ";\n";
            //echo "escribo: $cadena<br />";    

            $cadena = preg_replace('/,[\s*](?=,)/', ', NULL', $cadena, -1);
			$cadena = preg_replace('/,[\s*]\)/', ', NULL)', $cadena, -1);
            
            fwrite($fichero, $cadena, strlen($cadena));
        }
        
        /**
        * Funcion que archiva todos los archivos y carpetas que encuentra a partir del parámetro recibido en un fichero zip
        * apuntado por el recibido en el primer parámetro, usando como ruta base para el fichero zip la cadena recibida como
        * tercer parámetro
        */
        function archivar ($file, $dir, $base)
        {
            //$idusr = $_SESSION[id_usr];
            //system("tar -cvvf --exclude=torestore* backup.tar imagenes/$idusr/");
//            $aux = scandir ($dir);
//            foreach ($aux as $carpeta)
//            {   
//                if(($carpeta != '.') && ($carpeta != '..')) 
//                {
//                    if (is_dir ($dir.$carpeta))
//                    {
//                        if($file->addEmptyDir($base.$carpeta)!=TRUE)
//                            exit("no puede dir $base$carpeta");
//                        
//                        $this->archivar ($file, $dir."/".$carpeta."/", $base.$carpeta."/");
//                    }else { 
//                        if(strpos($carpeta, "torestore.zip") === FALSE)
//                        {   //Si no se encuentra torestore.zip en la carpeta, se almacena
//                            if($file->addFile($dir."/".$carpeta, $base.$carpeta)!=TRUE)
//                                exit("no puede addFile $dir/$carpeta como $base/$carpeta");
//                        } 
//                    }
//                }     
//            }
		
			$file->addFile($dir."/backup.sql", $base."backup.sql");
            return;
        }
        
        /**
        * Funcion que restaura los datos a partir del archivo recibido
        */
        function restaurar ($params, $file)
        {
            
            $this->smarty->assign ('codigo', 0);
            if(is_uploaded_file($_FILES[fileZip][tmp_name]))
            {
                if(move_uploaded_file($_FILES[fileZip][tmp_name], $this->carpeta."backup.sql"))
                {
                   /* //$this->crearZip();
                    $this->smarty->assign('codigo', 1);
                    try{
                        $this->restore($this->carpeta."torestore.zip"); 
                    } catch (Exception $e) {
                        $this->smarty->assign('codigo', -1);
                        $this->restore($this->carpeta."backup.zip");
                    } 
                    unlink($this->carpeta."backup.sql");    
                    unlink($this->carpeta."torestore.zip");
                    unlink($this->carpeta."backup.zip");*/
                	$this->dao->script($this->carpeta."backup.sql");
                }
            }
            $this->smarty->display($this->path.$file.".phtml");
            
        }
        
        function restore ($path)
        {
            $borrado = @$this->dao->borrar($_SESSION[id_usr]);
            
            $this->rm_recursive($this->carpeta);
           
            $zip = new ZipArchive();
            $zip->open($path);
            $zip->extractTo($this->carpeta);
            $zip->close;
            
            $sql = $this->dao->script($this->carpeta."backup.sql");
            
        }
        /**
        * Funcion que borra todas las carpetas y subcarpetas a partir del directorio especificado
        */
        function rm_recursive($filepath)
        {
            if (is_dir($filepath) && !is_link($filepath))
            {
                if ($dh = opendir($filepath))
                {
                    while (($sf = readdir($dh)) !== false)
                    {
                        if ($sf == '.' || $sf == '..')
                        {
                            continue;
                        }
                        if (!$this->rm_recursive($filepath.'/'.$sf))
                        {
                            throw new Exception($filepath.'/'.$sf.' could not be deleted.');
                        }
                    }
                    closedir($dh);
                }
                return @rmdir($filepath);
            }
            //Si torestore.zip no se encuentra en la cadena, retorna el valor del borrado
            if((strpos($filepath, "torestore.zip") === FALSE) && (strpos($filepath, "backup.zip") === FALSE)){
                return unlink($filepath);
            }else
            //Si se encontrara, se devuelve TRUE para continuar la ejecucion del bucle, conservando el archivo
                return TRUE;
        }
    }
?>