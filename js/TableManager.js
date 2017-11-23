
TableManager = function TableManager(services, tableId, formId, numLinesHiddenFieldId, totalFieldId) {
	//Input names constants
	this.selectName = 'selServicio';
	this.textName = 'texto';
	this.unitaryName = 'txtUnitario';
	this.quantityName = 'txtCuantos';
	//Index constants
	this.serviceIndex = 0;
	this.detailsIndex = 1;
	this.unitPriceIndex = 2;
	this.quantityIndex = 3;
	this.totalIndex = 4;
	//Lines counts the total number of lines added while lineNumber, the last line added. 
	//lineNumber is never decremented to give the inputs a unique name
	//Lines is decremented when a line is deleted
	this.lines = 0;
	this.lineNumber = 0;
	this.services = services;
	//Page fields
	this.table = document.getElementById(tableId);
	this.form = document.getElementById(formId);
	this.numLinesHiddenField = document.getElementById(numLinesHiddenFieldId);
	this.totalField = document.getElementById(totalFieldId);
	//Methods
	this.init = function init (data, numLines, instance) {
		var theRow;
		var index = this.table.rows.length - 2;
		for (var i = 0 ; i < numLines ; ++i) {
			theRow = this.newLine(instance);
			//Fill the row
			theRow.cells[this.serviceIndex].childNodes[1].selectedIndex = this.indexForOptionId(data[i][this.serviceIndex]);
			theRow.cells[this.detailsIndex].childNodes[0].value = data[i][this.detailsIndex];
			theRow.cells[this.unitPriceIndex].childNodes[0].value = data[i][this.unitPriceIndex];
			theRow.cells[this.quantityIndex].childNodes[0].value = data[i][this.quantityIndex];
			theRow.cells[this.totalIndex].childNodes[0].nodeValue = data[i][this.totalIndex];
			this.setLinePrice(i + 1, index);
			++index;
		}
	};
	
	this.indexForOptionId = function indexForOptionId(id) {
		var option;
		for (var i = 0 ; i < this.services.length ; ++i) {
			option = this.services[i];
			if (option.value == id) {
				//Return i+1 as the 0 is for the intial select service... option
				return i+1;
			}
		}
	};
	
	this.newLine = function newLine(instance) {
	    
	    var numRows = this.table.rows.length;
	    var index = numRows - 2;
	    var currLine = this.lineNumber + 1;
	    var newRow = this.table.insertRow(index);
	    
	    var leftCell = newRow.insertCell(0);
	    leftCell.colSpan = 2;
	    var textNode = document.createTextNode(currLine + '. ');
	    leftCell.appendChild(textNode);
	    var selector = document.createElement('select');
	    selector.name = this.selectName + currLine;
	    selector.onchange = function () {instance.service(currLine, index);};
	    selector.options[0] = new Option("Seleccione un servicio...", "0");
	    var opt;
	    for (var i = 0 ; i < services.length ; ++i) {
	        opt = services[i];
	        selector.options[i + 1] = new Option(opt.text, opt.value); 
	    }
	    this.form.appendChild(selector);
	    leftCell.appendChild(selector);

	    var textCell = newRow.insertCell(1);
	    var input = document.createElement('input');
	    input.name = this.textName + currLine;
	    input.type = 'text';
	    input.maxLength = 200;
	    this.form.appendChild(input);
	    textCell.appendChild(input);

	    var secondCell = newRow.insertCell(2);
	    var input = document.createElement('input');
	    input.name = this.unitaryName + currLine;
	    input.type = 'text';
	    input.onchange = function () {instance.setLinePrice(currLine, index);};
	    this.form.appendChild(input);
	    secondCell.appendChild(input);

	    var thirdCell = newRow.insertCell(3);
	    var input = document.createElement('input');
	    input.name = this.quantityName + currLine;
	    input.type = 'text';
	    input.value = '1';
	    input.onchange = function () {instance.setLinePrice(currLine, index);};
	    this.form.appendChild(input);
	    thirdCell.appendChild(input);

	    var fourthCell = newRow.insertCell(4);
	    var p = document.createTextNode(0);
	    fourthCell.appendChild(p);

	    var fifthCell = newRow.insertCell(5);
	    var input = document.createTextNode('0');
	    var input = document.createElement('input');
	    input.type = 'button';
	    input.value = '-';
	    input.onclick = function () {instance.delLine(index);};
	    fifthCell.appendChild(input);

	    ++this.lines;
	    ++this.lineNumber;
	    
	    this.numLinesHiddenField.value = this.lines;
	    
	    return newRow;
	};
	this.delLine = function delLine(index) {
		this.table.deleteRow(index);
		--this.lines;
		this.numLinesHiddenField.value = lines;
	};
	this.service = function service(line, index)
	{
	  var num = document.getElementsByName (this.quantityName + line);
	  var x = document.getElementsByName (this.unitaryName + line);
	  var y = document.getElementsByName (this.selectName + line);
	  var txt = y[0].options[y[0].selectedIndex].text;
	  var primero = txt.lastIndexOf ("-");
	  primero += 2;
	  var ultimo = txt.lastIndexOf ("€");
	  var cadena = txt.slice (primero, ultimo);
	  x[0].value= cadena ;  

	  this.setLinePrice(line, index);
	};
	this.setLinePrice = function setLinePrice (line, index) {
		  var num = document.getElementsByName (this.quantityName + line);
		  var unit = document.getElementsByName (this.unitaryName + line);

		  var row = this.table.rows[index];
		  var cell = row.cells[4];
		  var price = parseFloat(num[0].value) * parseFloat(unit[0].value);
		  cell.childNodes[0].nodeValue = price; 
		  
		  this.setFullPrice();
	};
	this.setFullPrice = function setFullPrice () {
	    var price = 0;
	    var row;
	    var fullPrice = 0;
	    var cell;
		for (var i = 0 ; i < this.lines ; ++i) {
		    row = this.table.rows[4 + i];
		    cell = row.cells[4];
		    fullPrice += parseFloat(cell.childNodes[0].nodeValue);
		}
		row = this.table.rows[this.table.rows.length -1];
		cell = row.cells[1];
		cell.childNodes[0].nodeValue = fullPrice + " €";

		this.totalField.value = fullPrice;
	};
};
