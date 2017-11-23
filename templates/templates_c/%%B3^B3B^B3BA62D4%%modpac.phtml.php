<?php /* Smarty version 2.6.20, created on 2009-10-08 18:39:30
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/modpac.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/modpac.phtml', 1, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/modpac.phtml', 42, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/modpac.phtml', 3, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/modpac.phtml', 57, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'pacientes'), $this);?>


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
      <span class="intro"><?php echo $this->_config[0]['vars']['texto49']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto50']; ?>
</p>
    </div>
    <div class="col_central">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto51']; ?>
</span>
      <?php if (isset ( $this->_tpl_vars['datos'] )): ?>
        <p><?php echo $this->_config[0]['vars']['texto52']; ?>
</p>
        <div id='paciente_errorloc' class='error_strings'></div>  
        <form name="paciente" enctype="multipart/form-data" method="POST" action="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.actualizapaciente/id.<?php echo $this->_tpl_vars['datos']['id_paciente']; ?>
">
          <fieldset><legend><?php echo $this->_config[0]['vars']['texto9']; ?>
</legend>
            <p><?php echo $this->_config[0]['vars']['texto10']; ?>
</p><input type="text" name="txtNombre" value="<?php echo $this->_tpl_vars['datos']['nombre']; ?>
" ><br />
            <p><?php echo $this->_config[0]['vars']['texto11']; ?>
</p><input type="text" name="txtApe" value="<?php echo $this->_tpl_vars['datos']['apellido']; ?>
" ><br />
            <p><?php echo $this->_config[0]['vars']['texto12']; ?>
</p><input type="text" name="txtApe2" value="<?php echo $this->_tpl_vars['datos']['apellido2']; ?>
" ><br />
            <p><?php echo $this->_config[0]['vars']['texto13']; ?>
</p><input type="text" name="txtDNI" value="<?php echo $this->_tpl_vars['datos']['dni']; ?>
" ><br />
            <p><?php echo $this->_config[0]['vars']['texto14']; ?>
</p><input type="text" name="txtFechanac" value="<?php echo $this->_tpl_vars['datos']['fecha_nacimiento']; ?>
" ><br />
            <p><?php echo $this->_config[0]['vars']['texto15']; ?>
</p><input type="text" name="txtProf" value="<?php echo $this->_tpl_vars['datos']['profesion']; ?>
" ><br /> 
            <input type="hidden" name="MAX_FILE_SIZE" value="2000000">
            <p><?php echo $this->_config[0]['vars']['texto69']; ?>
</p><input type="file" name="fileFoto"><br />  
          </fieldset>
          <fieldset><legend><?php echo $this->_config[0]['vars']['texto16']; ?>
</legend>
            <p><?php echo $this->_config[0]['vars']['texto17']; ?>
</p><input type="text" name="txtDir" value="<?php echo $this->_tpl_vars['datos']['direccion']; ?>
" ><br />
            <p><?php echo $this->_config[0]['vars']['texto18']; ?>
</p><input type="text" name="txtCP" value="<?php echo $this->_tpl_vars['datos']['cp']; ?>
" ><br />
            <p><?php echo $this->_config[0]['vars']['texto19']; ?>
</p><input type="text" name="txtCiudad" value="<?php echo $this->_tpl_vars['datos']['ciudad']; ?>
" ><br />
            <p><?php echo $this->_config[0]['vars']['texto20']; ?>
</p>
              <?php if (isset ( $this->_tpl_vars['provincias'] )): ?>
                <select name="selProv">
                  <option label=<?php echo $this->_config[0]['vars']['texto21']; ?>
 value=0><?php echo $this->_config[0]['vars']['texto21']; ?>
</option>
                  <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['provincias'],'selected' => $this->_tpl_vars['datos']['id_provincia']), $this);?>

                </select>
              <?php else: ?>
                <p><?php echo $this->_config[0]['vars']['texto22']; ?>
</p>
              <?php endif; ?><br />
            <p><?php echo $this->_config[0]['vars']['texto23']; ?>
</p><input type="text" name="txtTelfijo" value="<?php echo $this->_tpl_vars['datos']['telefono_fijo']; ?>
" ><br />
            <p><?php echo $this->_config[0]['vars']['texto24']; ?>
</p><input type="text" name="txtMovil" value="<?php echo $this->_tpl_vars['datos']['telefono_movil']; ?>
" ><br />
            <p><?php echo $this->_config[0]['vars']['texto25']; ?>
</p><input type="text" name="txtTeltrab" value="<?php echo $this->_tpl_vars['datos']['telefono_trabajo']; ?>
" ><br />
            <p><?php echo $this->_config[0]['vars']['texto26']; ?>
</p><input type="text" name="txtEmail" value="<?php echo $this->_tpl_vars['datos']['email']; ?>
" ><br />
          </fieldset>
          <fieldset><legend><?php echo $this->_config[0]['vars']['texto27']; ?>
</legend>
            <p><?php echo $this->_config[0]['vars']['texto28']; ?>
</p>
              <?php if (isset ( $this->_tpl_vars['dres'] )): ?>
                <select name="selDr">
                  <option label=<?php echo $this->_config[0]['vars']['texto29']; ?>
 value=0><?php echo $this->_config[0]['vars']['texto29']; ?>
</option>
                  <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['dres'],'selected' => ((is_array($_tmp=@$this->_tpl_vars['datos']['id_dr_referidor'])) ? $this->_run_mod_handler('default', true, $_tmp, 0) : smarty_modifier_default($_tmp, 0))), $this);?>

                </select>
              <?php else: ?>
                <p><?php echo $this->_config[0]['vars']['texto30']; ?>
</p>
              <?php endif; ?><br />
            <p><?php echo $this->_config[0]['vars']['texto31']; ?>
</p>
              <?php if (isset ( $this->_tpl_vars['pacs'] )): ?>
                <select name="selPac">
                  <option label=<?php echo $this->_config[0]['vars']['texto32']; ?>
 value=0><?php echo $this->_config[0]['vars']['texto32']; ?>
</option>
                  <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['pacs'],'selected' => ((is_array($_tmp=@$this->_tpl_vars['datos']['id_paciente_referidor'])) ? $this->_run_mod_handler('default', true, $_tmp, 0) : smarty_modifier_default($_tmp, 0))), $this);?>

                </select>
              <?php else: ?>
                <p><?php echo $this->_config[0]['vars']['texto33']; ?>
</p>
              <?php endif; ?><br />
            <p><?php echo $this->_config[0]['vars']['texto34']; ?>
</p><textarea name="txtAlertas"><?php echo $this->_tpl_vars['datos']['alertas_medicas']; ?>
</textarea><br />
            <p><?php echo $this->_config[0]['vars']['texto35']; ?>
</p><textarea name="txtObservaciones"><?php echo $this->_tpl_vars['datos']['observaciones']; ?>
</textarea><br />
          </fieldset>
          <input type="submit" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 />
          <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
          <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.pacientes'" />
        </form>
      <?php else: ?>
        <?php echo $this->_config[0]['vars']['texto47']; ?>

      <?php endif; ?>
  </div>
</div>

<script type="text/javascript">
<!--
	var validator = new Validator("paciente");
	validator.addValidation("txtNombre", "req", "<?php echo $this->_config[0]['vars']['error0']; ?>
");
	validator.addValidation("txtNombre", "alpha_s", "<?php echo $this->_config[0]['vars']['error1']; ?>
");
	validator.addValidation("txtNombre", "maxlen=40", "<?php echo $this->_config[0]['vars']['error2']; ?>
");
	validator.addValidation("txtApe", "req", "<?php echo $this->_config[0]['vars']['error3']; ?>
");
	validator.addValidation("txtApe", "alpha_s", "<?php echo $this->_config[0]['vars']['error4']; ?>
");
	validator.addValidation("txtApe", "maxlen=45", "<?php echo $this->_config[0]['vars']['error5']; ?>
");
	validator.addValidation("txtApe2", "alpha_s", "<?php echo $this->_config[0]['vars']['error6']; ?>
");
	validator.addValidation("txtApe2", "maxlen=45", "<?php echo $this->_config[0]['vars']['error7']; ?>
");
	validator.addValidation("txtDNI", "alnum", "<?php echo $this->_config[0]['vars']['error8']; ?>
");
	validator.addValidation("txtDNI", "maxlen=9", "<?php echo $this->_config[0]['vars']['error8']; ?>
");
	validator.addValidation("txtFechanac", "<?php echo 'regexp=^[0-9]{1,2}-[0-9]{1,2}-[0-9]{4}$'; ?>
", "<?php echo $this->_config[0]['vars']['error9']; ?>
");
	validator.addValidation("selProv", "dontselect=0", "<?php echo $this->_config[0]['vars']['error22']; ?>
");
	validator.addValidation("txtProf", "maxlen=250", "<?php echo $this->_config[0]['vars']['error10']; ?>
");
	validator.addValidation("txtDir", "maxlen=150", "<?php echo $this->_config[0]['vars']['error11']; ?>
");
	validator.addValidation("txtCP", "maxlen=5", "<?php echo $this->_config[0]['vars']['error12']; ?>
");
	validator.addValidation("txtCP", "num", "<?php echo $this->_config[0]['vars']['error13']; ?>
");
	validator.addValidation("txtCiudad", "maxlen=200", "<?php echo $this->_config[0]['vars']['error14']; ?>
");
	validator.addValidation("txtTelfijo", "maxlen=13", "<?php echo $this->_config[0]['vars']['error15']; ?>
");
	validator.addValidation("txtTelfijo", "num", "<?php echo $this->_config[0]['vars']['error16']; ?>
");
	validator.addValidation("txtMovil", "maxlen=13", "<?php echo $this->_config[0]['vars']['error17']; ?>
");
	validator.addValidation("txtMovil", "num", "<?php echo $this->_config[0]['vars']['error18']; ?>
");
	validator.addValidation("txtTeltrab", "maxlen=13", "<?php echo $this->_config[0]['vars']['error19']; ?>
");
	validator.addValidation("txtTeltrab", "num", "<?php echo $this->_config[0]['vars']['error20']; ?>
");
	validator.addValidation("txtEmail", "email", "<?php echo $this->_config[0]['vars']['error21']; ?>
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