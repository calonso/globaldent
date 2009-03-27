<?php
    /**
    * Fichero que recoje la implementacion de la clase ConsentimientoRevocadoDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Consentimientos
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (6 - Febrero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase ConsentimientoRevocadoDAO. Implementa toda la lógica de acceso a datos para el objeto Consentimiento Revocado
    * @package Acceso a Datos
    * @subpackage Consentimientos
    */
    class ConsentimientoRevocadoDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function ConsentimientoRevocadoDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
            $valores = $datos[id_tipo_consentimiento].COMA.
            	$datos[id_paciente].COMA.
            	COMILLA.$datos[fecha].COMILLA.COMA.
            	COMILLA.$datos[fecha_r].COMILLA.COMA.
            	COMILLA.$datos[extension].COMILLA.COMA.
            	COMILLA.$datos[extension_r].COMILLA.COMA.
            	$datos[id_usuario];
            
            $sentencia = "insert into consentimiento_revocado (id_tipo_consentimiento, id_paciente, fecha, fecha_r, extension, extension_r, id_usuario)."
            	 ."values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($datos)
        {
                    
        }
        function ver ($datos)
        {
            $id = $datos[id_consentimiento];
            $idp = $datos [id_paciente];
            $idusr = $_SESSION[id_usr];
            $sentencia = "select * from consentimiento_revocado where id_usuario = $idusr and id_consentimiento = $id";
            $devuelto = $this->DBManager->recoger_datos ($sentencia);
            if(is_array($devuelto))
            {
                $this->datos = $devuelto[1];
                foreach ($this->datos as $elemento => $array)
                {
                    foreach ($array as $indice => $valor)
                    {
                        if (strncmp ($indice, "id_", 3))
                        {
                            $valor = $this->crypter->descifrar ($valor);
                            $this->datos[$elemento][$indice] = $valor;   
                        }
                    }   
                }
                return $this->datos;
            }else
                return 0;       
        }
        function modificar ($datos)
        {
                     
        }
        function listado ($id, $pagina = -1)
        {
            $idusr = $_SESSION[id_usr];
            $sentencia = "select id_consentimiento, id_tipo_consentimiento, fecha, fecha_r from consentimiento_revocado where id_usuario = '$idusr' and id_paciente = '$id' order by id_consentimiento desc";
            
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