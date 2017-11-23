<?php /* Smarty version 2.6.20, created on 2009-10-08 18:45:01
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/datosclinica.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/datosclinica.phtml', 1, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/datosclinica.phtml', 34, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/datosclinica.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'conf'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

  <script type="text/javascript">
  <!--
  <?php echo '
  function loaded(){}
  '; ?>
 
  // -->
  </script>

  <div class="contenidos">
    <div class="col_izq">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto38']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto39']; ?>
</p>
    </div>
    <div class="col_central">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto40']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto41']; ?>
</p>
      <div id='clinica_errorloc' class='error_strings'></div>  
      <form name="clinica" enctype="multipart/form-data" method="POST" action=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.actualizadatosclinica>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto40']; ?>
</legend>
        <p><?php echo $this->_config[0]['vars']['texto42']; ?>
<p><input type="text" name="txtNombre" value="<?php echo $this->_tpl_vars['datos']['nombre']; ?>
" /><br />
        <p><?php echo $this->_config[0]['vars']['texto43']; ?>
<p><input type="text" name="txtEspecialidad" value="<?php echo $this->_tpl_vars['datos']['especialidad']; ?>
" /><br />
        <p><?php echo $this->_config[0]['vars']['texto44']; ?>
<p><input type="text" name="txtNif" value="<?php echo $this->_tpl_vars['datos']['nif']; ?>
" /><br />
        <p><?php echo $this->_config[0]['vars']['texto45']; ?>
<p><input type="text" name="txtDireccion" value="<?php echo $this->_tpl_vars['datos']['direccion']; ?>
" /><br />
        <p><?php echo $this->_config[0]['vars']['texto46']; ?>
<p><input type="text" name="txtCP" value="<?php echo $this->_tpl_vars['datos']['cp']; ?>
" /><br />
        <p><?php echo $this->_config[0]['vars']['texto47']; ?>
<p><input type="text" name="txtCiudad" value="<?php echo $this->_tpl_vars['datos']['ciudad']; ?>
" /><br />
        <p><?php echo $this->_config[0]['vars']['texto48']; ?>
<p>
          <?php if (is_array ( $this->_tpl_vars['provincias'] )): ?>
            <select name="selProv">
            <option label="<?php echo $this->_config[0]['vars']['texto49']; ?>
" value="0"><?php echo $this->_config[0]['vars']['texto49']; ?>
</option>
            <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['provincias'],'selected' => $this->_tpl_vars['datos']['id_provincia']), $this);?>

            </select>
          <?php else: ?>
            <p><?php echo $this->_config[0]['vars']['texto50']; ?>
</p>
          <?php endif; ?><br />
        <p><?php echo $this->_config[0]['vars']['texto51']; ?>
<p><input type="text" name="txtTelefono" value="<?php echo $this->_tpl_vars['datos']['telefono']; ?>
" /><br />
      </fieldset>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto52']; ?>
</legend>
        <p><?php echo $this->_config[0]['vars']['texto53']; ?>
<p><input type="text" name="txtGabinetes" value="<?php echo $this->_tpl_vars['datos']['gabinetes']; ?>
" /><br />
        <p><?php echo $this->_config[0]['vars']['texto101']; ?>
<p><input type="text" name="txtRegSanidad" value="<?php echo $this->_tpl_vars['datos']['reg_sanidad']; ?>
" /><br />
      </fieldset>
        <input type="submit" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 />
        <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
        <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.conf'" /> 
      </form>
    </div>
  </div>
  
  <script type="text/javascript">
<!--
	var validator = new Validator("clinica");
	validator.addValidation("txtNombre", "req", "<?php echo $this->_config[0]['vars']['error0']; ?>
");
	validator.addValidation("txtNombre", "maxlen=200", "<?php echo $this->_config[0]['vars']['error1']; ?>
");
	validator.addValidation("txtEspecialidad", "maxlen=200", "<?php echo $this->_config[0]['vars']['error2']; ?>
");
	validator.addValidation("txtNif", "req", "<?php echo $this->_config[0]['vars']['error3']; ?>
");
	validator.addValidation("txtNif", "maxlen=9", "<?php echo $this->_config[0]['vars']['error4']; ?>
");
	validator.addValidation("txtDireccion", "maxlen=200", "<?php echo $this->_config[0]['vars']['error5']; ?>
");
	validator.addValidation("txtCP", "maxlen=5", "<?php echo $this->_config[0]['vars']['error6']; ?>
");
	validator.addValidation("txtCP", "num", "<?php echo $this->_config[0]['vars']['error7']; ?>
");
	validator.addValidation("txtCiudad", "maxlen=200", "<?php echo $this->_config[0]['vars']['error8']; ?>
");
	validator.addValidation("selProv", "dontselect=0", "<?php echo $this->_config[0]['vars']['error9']; ?>
");
	validator.addValidation("txtTelefono", "num", "<?php echo $this->_config[0]['vars']['error10']; ?>
");
	validator.addValidation("txtTelefono", "maxlen=13", "<?php echo $this->_config[0]['vars']['error11']; ?>
");
	validator.addValidation("txtGabinetes", "num", "<?php echo $this->_config[0]['vars']['error12']; ?>
");
	validator.addValidation("txtGabinetes", "maxlen=2", "<?php echo $this->_config[0]['vars']['error13']; ?>
");
	validator.addValidation("txtRegSanidad", "req", "<?php echo $this->_config[0]['vars']['error14']; ?>
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