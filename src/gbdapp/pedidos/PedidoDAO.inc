<?php
    /**
    * Fichero que recoje la implementacion de la clase PedidoDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Pedidos
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (23 - Enero - 2008)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase PedidoDAO. Implementa toda la lógica de acceso a datos para el objeto Pedido
    * @package Acceso a Datos
    * @subpackage Pedidos
    */
    class PedidoDAO extends DAO
    {
        /**
        * Constructor de la clase. Llama al constructor de la clase padre.
        * @return void
        */
        function PedidoDAO()
        {
            parent::DAO();
            return;
        }
        function nuevo ($datos)
        {
            foreach ($datos as $indice => $valor)
            {   
                if($valor)
                {
                    $campos .= "$indice"." ,";
                    if(strncmp ($indice, "id_", 3))
                        $valor = $this->crypter->cifrar ($valor);
                    $valores .= "'$valor'"." ,";
                }
            }
            
            $campos = substr($campos, 0, strlen($campos)-2);
            $valores = substr ($valores, 0, strlen($valores)-2);
            
            $sentencia = "insert into pedido ($campos) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;   
        }
        function borrar ($datos)
        {
                   
        }
        function ver ($datos)
        {
                  
        }
        function modificar ($datos)
        {
                     
        }
        function listado ($id, $pagina = -1)
        {
               
        }
        function buscar ($datos)
        {
                
        } 
        function bloquear ($datos)
        {
        
        } 
    }
?>