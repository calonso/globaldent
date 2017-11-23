<?php
    /**
    * Archivo que recoge la implementación de la clase LineSet, que sera un contenedor de lineas de visita, presupuesto y factura
    * 
    * @package GBD
    * @subpackage Common
    * @author Carlos Alonso Pérez DNI: 70868503-Y <cartecko1@terra.es
    * @version: 1.0 (10 - Diciembre - 2007)
    */

    /**
    * Inclusion de la clase Params encargada del manejo de los parametros de peticion
    */
    include_once PATH_BASE."src/acceso/Params.inc";
    
    define ('NUM_SERVICES_PARAM', 'txtCuantos');
    define ('UNIT_PRICE_PARAM', 'txtUnitario');
    define ('SERVICE_ID_PARAM', 'selServicio');
    define ('NUM_LINES_PARAM', 'txtNumLines');
    define ('TEXT_PARAM', 'texto');
    
    class LineSet {
    	
    	private $lines;
    	
    	function LineSet($params) {
            $this->lines = array();
            $numLines = $params->getParam(NUM_LINES_PARAM);
            $i = 1;
            while ($numLines > 0) {
            	$test = $params->getParam(NUM_SERVICES_PARAM.$i);
                if (!empty($test)){
                    $line = new Line($params->getParam(SERVICE_ID_PARAM.$i),
                                    $params->getParam(NUM_SERVICES_PARAM.$i),
                                    $params->getParam(UNIT_PRICE_PARAM.$i),
                                    $params->getParam(TEXT_PARAM.$i));
                    array_push($this->lines, $line);
                	--$numLines;
                }
                ++$i;
            }
    	}
    	function getLines() {
    		return $this->lines;
    	}
    }
    
    class Line {
    	/**
    	 * The service id
    	 */
        private $id;     
        /**
         * The amount of services
         */
        private $num;
        /**
         * The unitary price of the service
         */   
        private $unitPrice;
        /**
         * The total price of the line
         */
        private $total;
        /**
         * The text if is a detailed line
         */
        private $text;
        
        public function Line ($id, $num, $unitPrice, $text) {
            $this->num = $num;
            $this->unitPrice = $unitPrice;
            $this->total = $num * $unitPrice;
            $this->id = $id;
            $this->text = $text;		
        }
        
        public function getId() {
        	return $this->id;
        }
        public function getNum() {
            return $this->num;
        }
        public function getUnitPrice() {
            return $this->unitPrice;
        }
        public function getTotal() {
            return $this->total;
        }
        public function getText() {
            return $this->text;
        }
    }
?>