<?php
    /**
    * Fichero que recoje la implementacion de la clase TipoRecetaDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Configuracion
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (29 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase TipoRecetaDAO. Implementa toda la lógica de acceso a datos para el objeto Tipo de Receta
    * @package Acceso a Datos
    * @subpackage Configuracion
    */
    class TipoRecetaDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function TipoRecetaDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
        	$datos[nombre] = $this->crypter->corregir($datos[nombre]);
            $datos[texto] = $this->crypter->corregir($datos[textoo]);
            $datos[resumen] = $this->crypter->corregir($datos[resumen]);
        	
            $valores = COMILLA.$datos[nombre].COMILLA.COMA.
            	COMILLA.$datos[texto].COMILLA.COMA.
            	COMILLA.$datos[resumen].COMILLA.COMA.
            	$datos[id_usuario];
            
            $sentencia = "insert into tipo_receta (nombre, texto, resumen, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from tipo_receta where id_usuario = $idusr and id_tipo_receta = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from tipo_receta where id_usuario = $idusr and id_tipo_receta = $id";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                return $devuelto[1];
            }else
                return 0;       
        }
        function modificar ($datos)
        {
            $id = $datos[id_tipo_receta];
            $idusr = $_SESSION[id_usr];
            foreach ($datos as $indice => $valor)
            {
                $valor = $this->crypter->corregir($valor);
                $parejas .= "$indice = '$valor', ";
            } 
            $parejas = substr ($parejas, 0, strlen($parejas) -2);
            $sentencia = "update tipo_receta set $parejas where id_usuario = $idusr and id_tipo_receta = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            if($this->datos == 1)
                return $id;
            return $this->datos;         
        }
        function listado ($id, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_tipo_receta, nombre from tipo_receta where id_usuario = '$idusr' order by id_tipo_receta asc";
            
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