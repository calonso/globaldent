<?php
  /**
  * Archivo padre del que heredarán sus propiedades todos los objetos DAO, y que les provee de la información necesaria
  * para conectar con la base de datos y realizar sus consultas.
  * 
  * @package Acceso a Datos
  * @subpackage Base
  * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es
  * @version: 1.0 (5 - Diciembre - 2007)
  */
  
  /**
  * Inclusion del archivo de configuracion
  */
  include_once PATH_BASE."conf/conf.inc";
  /**
  * Inclusion de la biblioteca EzSQL
  */
  include_once PATH_BASE."src/db/ezsql/mysql/ez_sql_mysql.php";
  /**
  * Inclusion de la biblioteca mysql
  */
  include_once PATH_BASE."src/db/mysql.inc";
  
  
  /**
  * 
  * Clase que trabaja junto con los objetos DAO para facilitarles el acceso a la base de datos, conectandolos con la clase
  * EzSQL que además facilita cacheo de consultas y operaciones de Debug
  * 
  *  @package Acceso a Datos
  *  @subpackage Base
  */
  class DBManager
  {
    /**
    * Almacenará la variable empleada para conectarse con la BD.
    * @var EzSQL 
    */
    protected $conexion;
    
    /**
    * Constructor de la clase, crea un nuevo objeto de su clase asociada EzSQL que usará como elemento de conexión con la BD.
    * Establece una conexión con el servidor de bases de datos y selecciona al mismo tiempo la base de datos.
    * 
    * @return bool opciones
    *   - TRUE si todo es correcto.
    *   - FALSE si no puede conectarse con la base de datos del servidor.
    */
    function DBManager()
    {
        //$this->conexion = new ezSQL_mysql (DB_USUARIO, DB_CLAVE, DB_BD, DB_SERVIDOR);
        //$conectado = $this->conexion->quick_connect (DB_USUARIO, DB_CLAVE, DB_BD, DB_SERVIDOR);
        //return $conectado;
        $this->conexion = new mysql();
    }
    /**
    * Función que emplearán los objetos DAO para realizar las peticiones de tipo insert, delete o update, es decir, que no devuelvan
    * una cantidad significante de datos.
    * 
    * @param string solicitud es la query que debe mandar a la base de datos.
    * @return int opciones 
    *   - id recibido de la base de datos para el nuevo objeto insertado.
    *   - número de columnas afectadas por la sentencia delete o update.
    *   - cero en caso de error
    */
    function hacer_peticion ($solicitud)
    {
        $cols = $this->conexion->query ($solicitud); 
        
        if($this->conexion->insert_id)     
            return $this->conexion->insert_id;
        else
            return $cols;            
    }
    /**
    * Función que emplearán los objetos DAO para realizar las consultas de tipo select a la base de datos, es decir, que devuelvan una 
    * cantidad significante de datos.
    * 
    * @param string solicitud es la query que debe mandar a la base de datos
    * @return array|int opciones
    *   - array asociativo con los datos recogidos si la consulta tuvo éxito, junto con el numero de datos para paginación. 
    *   - cero si la consulta no devolvió ningún dato.
    */
    function recoger_datos ($solicitud)
    {
        if($datos = $this->conexion->get_results($solicitud, ARRAY_A)){   
            return array ($this->conexion->num_rows, $datos);
        }else{
            return 0;
        }         
    }
  }
?>