<?php
    
    /**
    * Fichero que recoje la implementacion de la clase GrupoImgsDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Configuracion
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (15 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase GrupoImgsDAO. Implementa toda la lógica de acceso a datos para las opciones configurables
    * @package Acceso a Datos
    * @subpackage Configuracion
    */
    class GrupoImgsDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function GrupoImgsDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
        	$datos[nombre] = $this->crypter->corregir($datos[nombre]);
        	
            $valores = COMILLA.$datos[nombre].COMILLA.COMA.
            	$datos[id_usuario];
            
            $sentencia = "insert into grupo_imagenes (nombre, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from grupo_imagenes where id_usuario = $idusr and id_grupo_imagenes = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($id)
        {
       
        }
        function modificar ($datos)
        {

        }
        function listado ($id, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_grupo_imagenes, nombre from grupo_imagenes where id_usuario = '$idusr'";
            
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