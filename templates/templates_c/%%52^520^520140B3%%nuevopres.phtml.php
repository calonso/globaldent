<?php /* Smarty version 2.6.20, created on 2009-06-22 22:12:06
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/nuevopres.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/nuevopres.phtml', 1, false),array('function', 'counter', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/nuevopres.phtml', 250, false),array('function', 'math', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/nuevopres.phtml', 262, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/nuevopres.phtml', 270, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/nuevopres.phtml', 3, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/nuevopres.phtml', 255, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'presupuestos'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript">
//<?php echo '
//<!--
function borrar(num)
{
  var x = document.getElementById ("formulario");
  //'; ?>

    x.action = "<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borralineap/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/num." + num;
  //<?php echo '
  x.submit();
}
function loaded()
{
	var s = document.Sign;
	if (s != null){
		//'; ?>

		var str = "<?php echo $this->_tpl_vars['presup']['firma']; ?>
";
		//<?php echo '
		if(str.length > 0){
			s.openSign1(str);
		}
	}
}
function linea()
{
	//'; ?>

	var err1 = "<?php echo $this->_config[0]['vars']['error1']; ?>
<br />";
	var err2 = "<?php echo $this->_config[0]['vars']['error2']; ?>
<br />";
	var err3 = "<?php echo $this->_config[0]['vars']['error3']; ?>
<br />";
	var err4 = "<?php echo $this->_config[0]['vars']['error4']; ?>
<br />";
	var err5 = "<?php echo $this->_config[0]['vars']['error5']; ?>
<br />";
	var action = "<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevalineap/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
";
	//<?php echo '
	var canSend = true;
	var err = "";
	var z = document.getElementsByName ("txtUnitario");
	var k = document.getElementsByName ("txtCuantos");
	var y = document.getElementsByName ("selServicio");
	z = z[0].value;
	k = k[0].value;
	y = y[0].selectedIndex;

	if(y == 0){
		err += err5;
		canSend = false;
	}
	var charPos = z.search("[^0-9]");
	if(z.length > 0){
		if(charPos >= 0){
			err += err3;
			canSend = false;	
		}
	} else {
		err += err1;
		canSend = false;
	}
	charPos = k.search("[^0-9]");
	if(k.length > 0){
		if(charPos >= 0){
			err += err4;
			canSend = false;	
		}
	} else {
		err += err2;
		canSend = false;
	}
	if(canSend){
	  var x = document.getElementById ("formulario");
	  x.action = action;
	  x.submit();
	} else {
		show_errs("formulario_errorloc", err);
	}
}

function servicio()
{
  var x = document.getElementsByName ("txtUnitario");
  var y = document.getElementsByName ("selServicio");
  if (y[0].selectedIndex != 0) {
	  var txt = y[0].options[y[0].selectedIndex].text;
	  var primero = txt.lastIndexOf ("-");
	  primero += 2;
	  var ultimo = txt.lastIndexOf ("€");
	  var cadena = txt.slice (primero, ultimo);
	  x[0].value= cadena ;  
  } else {
	x[0].value = 0;
  }
}
function firmar()
{
	if(document.Sign.isSigned()){
		document.Sign.clear();
	}
    document.Sign.setSignThickness(2);
    //'; ?>

    var nombre = "<?php echo $this->_tpl_vars['paciente']['apellido']; ?>
" + " " + "<?php echo $this->_tpl_vars['paciente']['apellido2']; ?>
" + ", " + "<?php echo $this->_tpl_vars['paciente']['nombre']; ?>
";
	document.Sign.signNowEx(<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
,nombre,"none","none","<?php echo $this->_tpl_vars['paciente']['direccion']; ?>
","<?php echo $this->_tpl_vars['paciente']['dni']; ?>
",true);
	//<?php echo '
	if(document.Sign.isSigned()){
		var x = document.Sign.getString();
		var y = document.Sign.getPNGString(x, 200, 200, true);
		var info = document.getElementsByName ("txtSignData");
		var image = document.getElementsByName ("txtSignImage");
		info[0].value = x;
		image[0].value = y;
	}
}
function getHashData()
{
	var hashstr = "";
	var line = document.getElementById("line");
	if (line != null){
		while(line.nodeName == "TR"
				&& line.attributes != null 
				&& line.attributes.getNamedItem("id") != null 
				&& line.attributes.getNamedItem("id").nodeValue == "line"){
			var cells = line.childNodes;
			var num = cells.length;
			for (var i = 0 ; i < num ; ++i){
				var aux = cells.item(i);
				if(aux.nodeName == "TD"){
					var cellNode = aux.childNodes[0];
					if(cellNode.nodeType == 3){
						//If is a text node
  						hashstr += trim(cellNode.data);
					}
				}
			}
			do {
				//While we find a text node, get next sibling looking for a row
				line = line.nextSibling;
			} while (line.nodeType == 3);
		}
	}
	hashstr += "D" + document.formulario.txtDuracion.value + 
				"V" + document.formulario.txtValidez.value;
  	return hashstr;	
}
function checkIntegrityAndSubmit()
{
	//'; ?>

	var err1 = "<?php echo $this->_config[0]['vars']['texto64']; ?>
<br />";
	var err2 = "<?php echo $this->_config[0]['vars']['texto65']; ?>
<br />";
	var err3 = "<?php echo $this->_config[0]['vars']['texto67']; ?>
<br />";
	var err4 = "<?php echo $this->_config[0]['vars']['texto66']; ?>
<br />";
	var err9 = "<?php echo $this->_config[0]['vars']['error9']; ?>
<br />";
	var err10 = "<?php echo $this->_config[0]['vars']['error10']; ?>
<br />";
	var err11 = "<?php echo $this->_config[0]['vars']['error11']; ?>
<br />";
	var err12 = "<?php echo $this->_config[0]['vars']['error12']; ?>
<br />";
	//<?php echo '
	var err = "";
	var canSend = true;
	if(document.Sign.isSigned()){
		switch(document.Sign.verifyDocument()){
		case 0:
			break;
		case 1:
			err += err1;
			canSend = false;
			break;
		case 2: 
			err += err2;
			canSend = false;
			break;
		case 4:
			err += err4;
			canSend = false;
			break;
		case 3:
		default:
			err += err3;
			canSend = false;
			break;
		}
	} else {
		err += err4;
		canSend = false;
	}

	var k = document.getElementsByName ("txtDuracion");
	var y = document.getElementsByName ("txtValidez");
	k = k[0].value;
	y = y[0].value;

	var charPos = k.search("[^0-9]");
	if(k.length > 0){
		if(charPos >= 0){
			err += err9;
			canSend = false;	
		}
	} else {
		err += err10;
		canSend = false;
	}
	charPos = y.search("[^0-9]");
	if(y.length > 0){
		if(charPos >= 0){
			err += err11;
			canSend = false;	
		}
	} else {
		err += err12;
		canSend = false;
	}
	if(canSend){
		document.getElementById ("formulario").submit();
	} else {
		show_errs("formulario_errorloc", err);
	}
}
-->
//'; ?>

</script>

<div class="contenidos">
  <div class="col_izq">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto5']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['texto6']; ?>
</p>
  </div>
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto7']; ?>
</span>
    <div id='formulario_errorloc' class='error_strings'></div>
    <form id="formulario" name="formulario" enctype="multipart/form-data" method="POST" action=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.guardapres/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/presupuestos/cabecera.phtml") : smarty_modifier_cat($_tmp, "gbdapp/presupuestos/cabecera.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <table border="0" width="100%">
      <tr>
        <th colspan="3"><?php echo $this->_config[0]['vars']['texto13']; ?>
</th>
        <th colspan="3">&nbsp;</th>
      </tr>
      <tr>
        <td colspan="6">&nbsp;</td>
      </tr>
      <tr>
        <th colspan="2"><?php echo $this->_config[0]['vars']['texto14']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto56']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto15']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto16']; ?>
</th>
        
        <th>&nbsp;</th>
      </tr>
      <tr>
        <td colspan="6" class="lineahor">&nbsp;</td>
      </tr>
      <?php echo smarty_function_counter(array('assign' => 'numlinea','start' => 1,'skip' => 1), $this);?>

      <?php $this->assign('total', 0); ?>
        <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
          <?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['llave'] => $this->_tpl_vars['linea']):
?>
            <tr id="line">
              <td colspan="2"><?php echo $this->_tpl_vars['numlinea']; ?>
.&nbsp;<?php echo ((is_array($_tmp=@$this->_tpl_vars['linea']['servicio'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_config[0]['vars']['texto20']) : smarty_modifier_default($_tmp, @$this->_config[0]['vars']['texto20'])); ?>
</td>
              <td><?php echo $this->_tpl_vars['linea']['unitario']; ?>
</p>
              <td align="center"><?php echo $this->_tpl_vars['linea']['cantidad']; ?>
</td>
              <td align="right"><?php echo $this->_tpl_vars['linea']['total']; ?>
 €.</td>
              <td><input type="button" value="<?php echo $this->_config[0]['vars']['borrar']; ?>
" onclick="borrar(<?php echo $this->_tpl_vars['llave']; ?>
)">
            </tr>
          <?php echo smarty_function_counter(array(), $this);?>

          <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['total'],'y' => $this->_tpl_vars['linea']['total'],'assign' => 'total'), $this);?>

          <?php endforeach; endif; unset($_from); ?>
        <?php endif; ?>
      <tr>
        <td colspan="2"><?php echo $this->_tpl_vars['numlinea']; ?>
.&nbsp;
          <?php if (is_array ( $this->_tpl_vars['servicios'] )): ?>
            <select name="selServicio" onchange="servicio()">
              <option label="<?php echo $this->_config[0]['vars']['texto17']; ?>
" value=0><?php echo $this->_config[0]['vars']['texto17']; ?>
</option>
              <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['servicios'],'selected' => 0), $this);?>

            </select>
          <?php else: ?>
            <?php echo $this->_config[0]['vars']['texto18']; ?>

            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.servicios><?php echo $this->_config[0]['vars']['texto19']; ?>
</a>
          <?php endif; ?>
        </td>
        <td><input type="text" name="txtUnitario" value="0"/></td>
        <td><input type="text" name="txtCuantos" value="1" /></td>
        <td><input type="button" value="<?php echo $this->_config[0]['vars']['aceptar']; ?>
" onclick="linea()"/></td>
      </tr>
      <tr>
        <td colspan="5" class="lineahor">&nbsp;</td>
      </tr>
      <tr>
        <th colspan="3"><?php echo $this->_config[0]['vars']['texto16']; ?>
</th>
        <th><?php echo $this->_tpl_vars['total']; ?>
 €.</th>
        <th>&nbsp;</th>
      </tr>
    </table>
    <b><?php echo $this->_config[0]['vars']['texto21']; ?>
</b><p><?php echo $this->_config[0]['vars']['texto22']; ?>
 <input type="text" name="txtValidez" value="<?php echo ((is_array($_tmp=@$this->_tpl_vars['presup']['validez'])) ? $this->_run_mod_handler('default', true, $_tmp, 6) : smarty_modifier_default($_tmp, 6)); ?>
" /><?php echo $this->_config[0]['vars']['texto36']; ?>
</p>
    <ol>
      <li><?php echo $this->_config[0]['vars']['texto23']; ?>
</li>
      <li><?php echo $this->_config[0]['vars']['texto24']; ?>
</li>
    </ol>
    <b><?php echo $this->_config[0]['vars']['texto25']; ?>
</b><p><?php echo $this->_config[0]['vars']['texto26']; ?>
</p>
    <ol>
      <li><?php echo $this->_config[0]['vars']['texto27']; ?>
</li>
      <li><?php echo $this->_config[0]['vars']['texto28']; ?>
</li>
    </ol>
    <b><?php echo $this->_config[0]['vars']['texto29']; ?>
</b><p><?php echo $this->_config[0]['vars']['texto30']; ?>
</p>
    <p><b><?php echo $this->_config[0]['vars']['texto31']; ?>
</b><input type="text" name="txtDuracion" value="<?php echo ((is_array($_tmp=@$this->_tpl_vars['presup']['duracion'])) ? $this->_run_mod_handler('default', true, $_tmp, 30) : smarty_modifier_default($_tmp, 30)); ?>
" /><?php echo $this->_config[0]['vars']['texto37']; ?>
</p>
    <p><?php echo $this->_config[0]['vars']['texto33']; ?>
</p>
    <div class="firmas">
    <APPLET classid=clsid:8AD9C840-044E-11D1-B3E9-00805F499D93 code="integrisign.webclient.WebSign" width=125 height=65 name="Sign" codebase="<?php echo $this->_tpl_vars['req_base']; ?>
lib/" archive="websignsunjvm.jar" MAYSCRIPT>
	  <PARAM NAME="borderstyle" VALUE="1" >
	  <PARAM NAME="scriptable" VALUE="true" >
	  <PARAM NAME="cache_option" VALUE="Plugin" >
	  <PARAM NAME="cache_archive" VALUE="websignsunjvm.jar" >
	  <PARAM NAME="cache_version" VALUE="7.5.0.3" >
	  <?php echo $this->_config[0]['vars']['error6']; ?>

	</APPLET> 
	
      <input type="button" value="<?php echo $this->_config[0]['vars']['texto63']; ?>
" onclick="firmar()"/>
      <br />
      <p><?php echo $this->_config[0]['vars']['texto35']; ?>
</p>
    </div>   
      <input type="hidden" name="txtSignData" value="<?php echo $this->_tpl_vars['presup']['firma']; ?>
"/>
      <input type="hidden" name="txtSignImage" value="<?php echo $this->_tpl_vars['presup']['image']; ?>
"/>
      <input type="hidden" name="txtTotal" value="<?php echo $this->_tpl_vars['total']; ?>
" />
      <input type="button" value="<?php echo $this->_config[0]['vars']['texto38']; ?>
" onclick="checkIntegrityAndSubmit()"/>
      <input type="button" value="<?php echo $this->_config[0]['vars']['cancelar']; ?>
" onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.presupuestos/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
'">
    </form>
  </div>
</div>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>