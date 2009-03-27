<?php
  /**
    * Fichero MensajeDAO. Recoge la implementacion de la clase MensajeDAO
    * 
    * @package Acceso a Datos
    * @subpackage Publicaciones
    * @author Carlos Alonso Pérez DNI: 70868503-Y
    * @version 1.0 (20 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del archivo DAO del que se heredaran propiedades y estructura
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase MensajeDAO. Implementa toda la lógica de acceso a los datos de los mensajes
    * @package Acceso a Datos
    * @subpackage Publicaciones
    */
    class MensajeDAO extends DAO
    {
        /**
        * Constructor de la clase. Crea un objeto de la clase padre e inicializa las variables
        * @return void   
        */
        function MensajeDAO ()
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
            
            $sentencia = "insert into mensaje ($campos) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;    
        }
        function borrar ($datos)
        {
        
        }
        function ver ($datos)
        {
            foreach ($datos as $indice => $valor)
            {
                if(strncmp ($indice, "id_", 3))
                    $valor = $this->crypter->cifrar ($valor);   
                $parejas .= "$indice = '$valor' and ";
            }
            $parejas = substr($parejas, 0, strlen ($parejas) -5);
            $sentencia = "select * from mensaje where $parejas order by id_mensaje asc";
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
        function modificar ($datos)
        {
        
        }
        function listado ($id, $pagina = -1)
        {
            $sentencia = "select id_mensaje, titulo, fecha, hora, id_usuario, id_padre from mensaje where id_foro = $id order by id_mensaje asc";
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