<?php /* Smarty version 2.6.20, created on 2009-06-24 20:23:12
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/consentimientos/nuevocons.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/consentimientos/nuevocons.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/consentimientos/nuevocons.phtml', 3, false),array('modifier', 'regex_replace', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/consentimientos/nuevocons.phtml', 29, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'consentimientos'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript">
//<!--<?php echo '
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
		var img = document.getElementsByName ("txtSignImage");
		info[0].value = x;
		img[0].value = y;
	}
}
function getHashData()
{
	//'; ?>

	return '<?php echo ((is_array($_tmp=((is_array($_tmp=$this->_tpl_vars['datos']['texto_incluido'])) ? $this->_run_mod_handler('regex_replace', true, $_tmp, "/\r\n/", ' ') : smarty_modifier_regex_replace($_tmp, "/\r\n/", ' ')))) ? $this->_run_mod_handler('regex_replace', true, $_tmp, "/\'/", "\"") : smarty_modifier_regex_replace($_tmp, "/\'/", "\"")); ?>
';
	//<?php echo '
}
function loaded(){}
//'; ?>
 -->
</script>

<div class="contenidos">
	<div class="col_izq">
	    <span class="intro"><?php echo $this->_config[0]['vars']['texto27']; ?>
</span>
    	<p><?php echo $this->_config[0]['vars']['texto28']; ?>
</p>
	</div>
	<div class="col_central">
	  <span class="intro"><?php echo $this->_config[0]['vars']['texto17']; ?>
</span>
	  <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
	    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/consentimientos/cabecera.phtml") : smarty_modifier_cat($_tmp, "gbdapp/consentimientos/cabecera.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
	    <div id='formulario_errorloc' class='error_strings'></div>
	    <p><?php echo $this->_tpl_vars['datos']['texto_incluido']; ?>
</p>
	    <blockquote class="firmas">
		   <APPLET classid=clsid:8AD9C840-044E-11D1-B3E9-00805F499D93 code="integrisign.webclient.WebSign" width=125 height=65 name="Sign" codebase="<?php echo $this->_tpl_vars['req_base']; ?>
lib/" archive="websignsunjvm.jar" MAYSCRIPT>
			  <PARAM NAME="borderstyle" VALUE="1" >
			  <PARAM NAME="scriptable" VALUE="true" >
			  <PARAM NAME="cache_option" VALUE="Plugin" >
			  <PARAM NAME="cache_archive" VALUE="websignsunjvm.jar" >
			  <PARAM NAME="cache_version" VALUE="7.5.0.3" >
			  <?php echo $this->_config[0]['vars']['errorSignApplet']; ?>

			</APPLET> 
			<input type="button" value="<?php echo $this->_config[0]['vars']['texto7']; ?>
" onclick="firmar()"/>
	      	<p><?php echo $this->_config[0]['vars']['texto19']; ?>
</p>
	    </blockquote>
	 	<form name="formulario" enctype="multipart/form-data" method="POST" action=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.firmacons/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/cons.<?php echo $this->_tpl_vars['datos']['id_tipo_consentimiento']; ?>
>
        	<input type="hidden" name="txtSignData" />
        	<input type="hidden" name="txtSignImage" />
            <input type="submit" value="<?php echo $this->_config[0]['vars']['texto29']; ?>
" />
        </form>
	  <?php else: ?>
	    <p><?php echo $this->_config[0]['vars']['texto8']; ?>
</p>
	  <?php endif; ?>
  </div>
</div>

<script type="text/javascript">
//<!--
	var validator = new Validator("formulario");
	validator.addValidation("txtSignData", "req", "<?php echo $this->_config[0]['vars']['error1']; ?>
");
	validator.EnableOnPageErrorDisplaySingleBox();
	validator.EnableMsgsTogether();
//-->
</script>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>