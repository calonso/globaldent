<?php
  /**
  * Archivo que recoge la implementación de la clase abstracta DAO, cuyos métodos serán redefinidos por sus hijas para cada caso particular.
  * 
  * @package Acceso a Datos
  * @subpackage Base
  * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es
  * @version: 1.0 (5 - Diciembre - 2007)
  */
  define ("COMILLA", "'");
  define ("COMA", ", ");
  /**
  * Inclusion del archivo de configuracion
  */
  include_once PATH_BASE."conf/conf.inc";
  /**
  * Inclusion del archivo DBManager
  */
  include_once PATH_BASE."src/db/DBManager.inc";
  /**
  * Inclusion del archivo de encriptación y cifrado
  */
  include_once PATH_BASE."src/db/Crypter.inc";
  
  /**
  * Esta clase simplemente marca una estructura común que tendrán todos los objetos y clases DAO.
  * 
  * @package Acceso a Datos
  * @subpackage Base
  * @abstract
  */
  abstract class DAO
  {
      /**
      *  Se empleará para enviar y recibir información con los objetos de la capa de negocio.
      *  @var array 
      */
      protected $datos;
      /**
      *  Se empleará como manejador del objeto que cifrará/descifrará los datos de la BD.
      *  @var resource 
      */ 
      protected $crypter;
      /**
      *  Referencia al objeto DBManager que le ayudara a acceder a la BD.
      * @var resource
      */
      protected $DBManager;
      /**
      * Constructor de la clase. Inicializa las variables.
      * @return void
      */
      function DAO()
      {
          $this->datos = array();
          $this->crypter = new Crypter();
          $this->DBManager = new DBManager();
          return;   
      }
      /**
      * Funcion que agrega un nuevo elemento en la base de datos
      * @param array Array donde se reciben los datos necesarios para la operacion
      * @return int opciones
      *     - El nuevo id que ha recibido el objeto en la base de datos
      *     - Cero si ocurrio error
      * @abstract
      */
      abstract function nuevo($datos);
      /**
      *  Función que borra un elemento de la base de datos
      *  @param array Array donde se reciben los datos necesarios para la operacion
      *  @return int opciones
      *     - Uno si se eliminó correctamente, determinando que una columna fue afectada
      *     - Cero si ocurrió error, determinando que nincuna columna fue afectada
      * @abstract
      */
      abstract function borrar($id);
      /**
      *  Función que recoge todos los datos asociados a un registro
      * @param array Array donde se reciben los datos necesarios para la operacion
      *  @return array|int opciones
      *     - Array asociativo con todos los detalles del registro
      *     - Cero si ocurrió error.
      * @abstract
      */
      abstract function ver($id);
      /**
      *  Función que modifica o actualiza los datos de un registro
      * @param array Array donde se reciben los datos necesarios para la operacion
      *  @return int opciones
      *     - Uno si se modificó correctamente, determinando que una columna fue afectada
      *     - Cero si ocurrió error, determinando que nincuna columna fue afectada
      * @abstract
      */
      abstract function modificar($datos);
      /**
      *  Función que obtiene un listado de todos los registros
      * @param array Array donde se reciben los datos necesarios para la operacion
      *  @return array|int opciones
      *     - Array si se encontraron registros
      *     - Cero si ocurrió error o ningun registro fue encontrado
      * @abstract
      */
      abstract function listado($id, $pagina = 0);
      /**
      *  Función que busca uno o varios elementos de la base de datos
      * @param array Array donde se reciben los datos necesarios para la operacion
      *  @return array|int opciones
      *     - Array con los datos si se encontro al menos un registro
      *     - Cero si ocurrió error o ningun registro fue encontrado
      * @abstract
      */
      abstract function buscar($datos);
      /**
      * Funcion que inicia una transaccion 
      */
      function start ()
      {
        $sentencia = "START TRANSACTION";
        $this->DBManager->hacer_peticion ($sentencia);   
      }
      /**
      * Funcion que confirma una transaccion 
      */
      function commit ()
      {
        $sentencia ="COMMIT";
        $this->DBManager->hacer_peticion ($sentencia);   
      }
      /**
      * Funcion que cancela los cambios de una transaccion
      */
      function rollback ()
      {
        $sentencia ="ROLLBACK";
        $this->DBManager->hacer_peticion ($sentencia);    
      }
  } 
?>