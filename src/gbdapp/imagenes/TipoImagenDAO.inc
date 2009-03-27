<?php
    
    /**
    * Fichero que recoje la implementacion de la clase TipoImagenDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Imagenes
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (15 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase TipoImagenDAO. Implementa toda la lógica de acceso a datos para el objeto TipoImagen
    * @package Acceso a Datos
    * @subpackage Imagenes
    */
    class TipoImagenDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function TipoImagenDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
			$valores = COMILLA.$datos[nombre].COMILLA.COMA.
				COMILLA.$datos[descripcion].COMILLA.COMA.
				$datos[id_usuario];
            
            $sentencia = "insert into tipo_imagen (nombre, descripcion, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from tipo_imagen where id_usuario = $idusr and id_tipo_imagen = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from tipo_imagen where id_usuario = $idusr and id_tipo_imagen = $id";
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
            $sentencia = "select id_tipo_imagen, nombre, descripcion from tipo_imagen where id_usuario = $idusr order by id_tipo_imagen asc";
            
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