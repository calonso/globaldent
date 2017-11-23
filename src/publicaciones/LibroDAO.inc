<?php
    /**
    * Fichero que recoje la implementacion de la clase LibroDAO.
    * 
    * @package Acceso a Datos
    * @subpackage Publicaciones
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es>
    * @version: 1.0 (13 - Diciembre - 2007)
    */
    
    /**
    * Inclusion del fichero DAO del que se heredaran todas las caracteristicas
    */
    include_once PATH_BASE."src/db/DAO.inc";
    
    /**
    * Clase LibroDAO. Implementa toda la lógica de acceso a datos para los objetos libro
    * @package Acceso a Datos
    * @subpackage Publicaciones
    */
    class LibroDAO extends DAO
    {
        /**
        * Constructor de la clase. Crea un objeto de la clase padre e inicializa las variables 
        * @return void  
        */
        function LibroDAO ()
        {
            parent::DAO();   
            void;
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
            
            $sentencia = "insert into libro ($campos) values ($valores)";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;
        }
        function borrar ($id)
        {
            $sentencia = "delete from libro where id_libro = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;
        }
        function ver ($id)
        {
            $sentencia = "select * from libro where id_libro = '$id'";
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
            $id = $datos[id_libro];
            foreach ($datos as $indice => $valor)
            {
                if(strncmp($indice, "id_", 3))
                {
                    $valor = $this->crypter->cifrar($valor);
                    $parejas .= "$indice = '$valor', ";
                }    
            }
            $parejas = substr ($parejas, 0, strlen($parejas) -2);
            $sentencia = "update libro set $parejas where id_libro = $id";
            $this->datos = $this->DBManager->hacer_peticion ($sentencia);
            return $this->datos;
        }
        function listado ($id, $pagina = -1)
        {
            if($id == 0)
                $sentencia = "select id_libro, titulo, autor, fecha, id_usuario from libro order by id_libro desc";
            else
                $sentencia = "select id_libro, titulo, autor, fecha, id_usuario from libro where id_usuario = '$id' order by id_libro desc";
            
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
                switch($indice)
                {
                    case "titulo":
                    case "autor":
                    case "fecha":
                        $parejas .= "$indice LIKE '%$valor%' and ";
                        break;
                    default:
                        $parejas .= "$indice = '$valor' and ";
                        break;
                }   
            }
            $parejas = substr($parejas, 0, strlen($parejas)-5);
            
            $sentencia1 = "select * from libro order by id_libro asc";
            $devuelto = $this->DBManager->recoger_datos ($sentencia1);
            if(is_array($devuelto))
            {
                $mitabla = "busqueda".$_SESSION[id_usr];
                $sentencia1 = "CREATE TEMPORARY TABLE $mitabla LIKE libro";
                $this->DBManager->hacer_peticion ($sentencia1);
                
                $this->datos = $devuelto[1];
                foreach ($this->datos as $elemento => $array)
                {
                    $valores = "(";
                    foreach ($array as $indice => $valor)
                    {
                        if (strncmp ($indice, "id_", 3))
                        {
                            $valor = $this->crypter->descifrar ($valor);
                            $this->datos[$elemento][$indice] = $valor; 
                            $valores .= "'".$this->datos[$elemento][$indice]."', ";  
                        }else
                            $valores .= $this->datos[$elemento][$indice].", ";                              
                    } 
                    $valores = substr ($valores, 0, strlen($valores)-2);
                    $valores .= ")";
                    $sentencia1 = "insert into $mitabla values $valores";
                    $this->DBManager->hacer_peticion ($sentencia1);  
                }
                $sentencia = "select id_libro, titulo, autor, fecha, id_usuario from $mitabla where $parejas order by id_libro desc";
                $devolver = $this->DBManager->recoger_datos($sentencia);
                return $devolver;
            }else
                return 0;                   
        }
        function bloquear ($datos)
        {
        
        }
    }
?>