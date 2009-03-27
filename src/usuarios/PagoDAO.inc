<?php
    /**
    * Fichero que recoje la implementacion de la clase PagoDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Usuarios
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (25 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase PagoDAO. Implementa toda la lógica de acceso a datos referente a los pagos para el objeto Usuario
    * @package Acceso a Datos
    * @subpackage Usuarios
    */
    class PagoDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function PagoDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
            foreach ($datos as $indice => $valor)
            {   
                $campos .= "$indice"." ,";
                if(strncmp ($indice, "id_", 3))
                    $valor = $this->crypter->cifrar ($valor);
                $valores .= "'$valor'"." ,";
            }
            
            $campos = substr($campos, 0, strlen($campos)-2);
            $valores = substr ($valores, 0, strlen($valores)-2);
            
            $sentencia = "insert into pago ($campos) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($datos)
        {
               
        }
        function ver ($id)
        {
            
        }
        function modificar ($datos)
        {
            
        }
        function listado ($id, $pagina = -1)
        {
            if($id == 0)
                $sentencia = "select * from pago order by id_usuario desc, id_pago asc";
            else
                $sentencia = "select * from pago where id_usuario = '$id' order by id_pago desc";
            if($pagina != -1)
            {   
                $inf = $pagina * MAX_FILAS;
                $sup = MAX_FILAS;
                $sentencia .= " limit $inf, $sup";
            }
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
                return array ($devuelto[0], $this->datos);
            }else
                return 0;
            
        }
        function buscar ($datos)
        {
            
        }
        function bloquear ($datos)
        {
        
        }  
    }
?>