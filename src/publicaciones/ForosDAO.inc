<?php
    /**
    * Fichero ForosDAO. Recoge la implementacion de la clase ForosDAO
    * 
    * @package Acceso a Datos
    * @subpackage Publicaciones
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (13 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del archivo DAO del que se heredaran propiedades y estructura
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase ForosDAO. Implementa toda la lógica de acceso a los datos de los foro
    * @package Acceso a Datos
    * @subpackage Publicaciones
    */
    class ForosDAO extends DAO
    {
        /**
        * Constructor de la clase. Crea un objeto de la clase padre e inicializa las variables
        * @return void   
        */
        function ForosDAO ()
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
            
            $sentencia = "insert into foro ($campos) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;    
        }
        function borrar ($datos)
        {
            $sentencia = "delete from foro where id_foro = '$datos'";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;
        }
        function ver ($datos)
        {
           
        }
        function modificar ($datos)
        {
        
        }
        function listado ($id, $pagina = -1)
        {
            if($id == 0)
                $sentencia = "select id_foro, nombre from foro order by id_foro desc";
            else
                $sentencia = "select id_foro, nombre from foro where id_tipo_foro = '$id' order by id_foro desc";
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
            foreach ($datos as $indice => $valor)
            {
                if (strncmp ($indice, "id_", 3))
                    $valor = $this->crypter->cifrar ($valor);
                $parejas .= "$indice = '$valor' and ";   
            }
            $parejas = substr($parejas, 0, strlen($parejas)-5);
            $sentencia = "select id_foro, nombre from foro where $parejas";
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
                return array($devuelto[0], $this->datos);
            }else               
                return 0;
        }
        function bloquear ($datos)
        {
        
        }
    }
?>