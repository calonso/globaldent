<?php /* Smarty version 2.6.20, created on 2009-10-08 20:32:21
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/dres/buscadr.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/dres/buscadr.phtml', 1, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/dres/buscadr.phtml', 35, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/dres/buscadr.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'dres'), $this);?>


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
      <span class="intro"><?php echo $this->_config[0]['vars']['texto24']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto25']; ?>
</p>
    </div>
    <div class="col_central">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto26']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto27']; ?>
</p>
      <form enctype="multipart/form-data" method="POST" action="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.busquedadr">
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto9']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['nombre']; ?>
</p><input type="text" name="txtNombre"><br />
          <p><?php echo $this->_config[0]['vars']['apellido']; ?>
</p><input type="text" name="txtApe"><br />
          <p><?php echo $this->_config[0]['vars']['apellido2']; ?>
</p><input type="text" name="txtApe2"><br />
          <p><?php echo $this->_config[0]['vars']['dni']; ?>
</p><input type="text" name="txtDNI"><br />
          <p><?php echo $this->_config[0]['vars']['fechanac']; ?>
</p><input type="text" name="txtFechanac"><br />
        </fieldset>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto10']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['direccion']; ?>
</p><input type="text" name="txtDir"><br />
          <p><?php echo $this->_config[0]['vars']['cp']; ?>
</p><input type="text" name="txtCP"><br />
          <p><?php echo $this->_config[0]['vars']['ciudad']; ?>
</p><input type="text" name="txtCiudad"><br />
          <p><?php echo $this->_config[0]['vars']['provincia']; ?>
</p><select name="selProv">
            <option label="<?php echo $this->_config[0]['vars']['texto11']; ?>
" value="0"><?php echo $this->_config[0]['vars']['texto11']; ?>
</option>
            <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['provincias'],'selected' => 0), $this);?>

            </select><br />
          <p><?php echo $this->_config[0]['vars']['telcli']; ?>
</p><input type="text" name="txtTelcli"><br />
          <p><?php echo $this->_config[0]['vars']['movil']; ?>
</p><input type="text" name="txtMovil"><br />
          <p><?php echo $this->_config[0]['vars']['telcasa']; ?>
</p><input type="text" name="txtTelcasa"><br /> 
          <p><?php echo $this->_config[0]['vars']['email']; ?>
</p><input type="text" name="txtEmail"><br />
          <p><?php echo $this->_config[0]['vars']['fax']; ?>
</p><input type="text" name="txtFax"><br />  
        </fieldset>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto12']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['especialidad']; ?>
</p><input type="text" name="txtEspecialidad"><br />
        </fieldset>
        <input type="submit" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 />
        <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
        <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.dres'" />
      </form>
  </div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>