<?php
    /**
    * Fichero que recoje la implementacion de la clase TipoConsDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Configuracion
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (23 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase TipoConsDAO. Implementa toda la lógica de acceso a datos para el objeto Tipo de Consentimiento
    * @package Acceso a Datos
    * @subpackage Configuracion
    */
    class TipoConsDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function TipoConsDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
            $valores = COMILLA.$datos[nombre].COMILLA.COMA.
           		COMILLA.$datos[descripcion].COMILLA.COMA.
           		COMILLA.$datos[texto_incluido].COMILLA.COMA.
           		$datos[id_usuario];
             
            $sentencia = "insert into tipo_consentimiento (nombre, descripcion, texto_incluido, id_usuario) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "delete from tipo_consentimiento where id_usuario = $idusr and id_tipo_consentimiento = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;        
        }
        function ver ($id)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from tipo_consentimiento where id_usuario = $idusr and id_tipo_consentimiento = $id";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                return $devuelto[1];
            }else
                return 0;       
        }
        function modificar ($datos)
        {
            $id = $datos[id_tipo_consentimiento];
            $idusr = $_SESSION[id_usr];
            foreach ($datos as $indice => $valor)
            {
            	$parejas .= "$indice = '$valor', ";  
            } 
            $parejas = substr ($parejas, 0, strlen($parejas) -2);
            $sentencia = "update tipo_consentimiento set $parejas where id_usuario = $idusr and id_tipo_consentimiento = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            if($this->datos == 1)
                return $id;
            return $this->datos;         
        }
        function listado ($id, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_tipo_consentimiento, nombre, texto_incluido from tipo_consentimiento where id_usuario = '$idusr' order by id_tipo_consentimiento asc";
            
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
            foreach ($datos as $idtipo)
            {
                $cadena .= "'".$idtipo."', ";   
            }
            $cadena = substr ($cadena, 0, strlen($cadena) -2);
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_tipo_consentimiento, nombre from tipo_consentimiento where id_usuario = '$idusr' and id_tipo_consentimiento not in ($cadena)";       
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                return $devuelto[1];
            }else
                return 0;
        }
        function bloquear ($datos)
        {
        
        } 
    }
?>