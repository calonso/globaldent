<?php
    
    /**
    * Fichero que recoje la implementacion de la clase ImagenDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Imagenes
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (16 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase ImagenDAO. Implementa toda la lógica de acceso a datos para el objeto Imagen
    * @package Acceso a Datos
    * @subpackage Imagenes
    */
    class ImagenDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function ServicioDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
        	$datos[fecha] = $this->crypter->corregir($datos[fecha]);
        	$datos[comentarios] = $this->crypter->corregir($datos[comentarios]);
        	$datos[extension] = $this->crypter->corregir($datos[extension]);
        	
            $valores = $datos[id_tipo].COMA.
            	COMILLA.$datos[fecha].COMILLA.COMA.
            	$datos[id_paciente].COMA.
            	COMILLA.$datos[comentarios].COMILLA.COMA.
            	COMILLA.$datos[extension].COMILLA.COMA.
            	$datos[id_grupo_imagen].COMA.
            	$datos[id_usuario];
            
            $sentencia = "insert into imagen (id_tipo, fecha, id_paciente, comentarios, extension, id_grupo_imagen, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($datos)
        {
            $id = $datos[id_imagen];
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from imagen where id_usuario = $idusr and id_imagen = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($datos)
        {
            $id = $datos[id_imagen];
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_imagen, fecha, comentarios, g.nombre as grupoimg, t.nombre as tipoimg, extension from imagen as img
                inner join tipo_imagen as t on (img.id_tipo = t.id_tipo_imagen)
                inner join grupo_imagenes as g on (img.id_grupo_imagen = g.id_grupo_imagenes)
                where img.id_usuario = '$idusr' and id_imagen = '$id'";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                return $devuelto[1];
            }else
                return 0;       
        }
        function modificar ($datos)
        {
                 
        }
        function listado ($id, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_imagen, id_tipo, extension, fecha from imagen where 
            	id_usuario = $idusr and id_paciente = $id order by id_tipo, id_imagen asc";
            
            if($pagina != -1)
            {   
                $inf = $pagina * MAX_FILAS;
                $sup = MAX_FILAS;
                $sentencia .= " limit $inf, $sup";
            }
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            return $devuelto;    
        }
        function buscar ($datos)
        {
                
        }  
        function bloquear ($datos)
        {
        
        }
    }
?>