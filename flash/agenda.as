package com.globaldent.actionscript.agenda {
	public class Cita {
		private var _paciente:String;
		private var _duracion:int = 1;
		
		public function Cita(paciente:String, duracion:int = 1) {
  		_paciente = paciente;
  		_duracion = duracion;
  	}
  	
  	public function getDuracion (): int {
  		return _duracion
  	}
  	
  	public function getPaciente (): String {
  		return _paciente;
  	}
	}
}