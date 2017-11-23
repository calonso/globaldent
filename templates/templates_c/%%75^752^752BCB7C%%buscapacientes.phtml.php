<?php /* Smarty version 2.6.20, created on 2009-06-22 19:02:53
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/buscapacientes.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/buscapacientes.phtml', 1, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/buscapacientes.phtml', 38, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/buscapacientes.phtml', 3, false),)), $this); ?>
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
      <span class="intro"><?php echo $this->_config[0]['vars']['texto61']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto62']; ?>
</p>
    </div>
    <div class="col_central">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto63']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto64']; ?>
</p>
      <form enctype="multipart/form-data" method="POST" action="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.busquedapacientes">
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto9']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto10']; ?>
</p><input type="text" name="txtNombre" ><br />
          <p><?php echo $this->_config[0]['vars']['texto11']; ?>
</p><input type="text" name="txtApe" ><br />
          <p><?php echo $this->_config[0]['vars']['texto12']; ?>
</p><input type="text" name="txtApe2" ><br />
          <p><?php echo $this->_config[0]['vars']['texto13']; ?>
</p><input type="text" name="txtDNI" ><br />
          <p><?php echo $this->_config[0]['vars']['texto14']; ?>
</p><input type="text" name="txtFechanac" ><br />
          <p><?php echo $this->_config[0]['vars']['texto15']; ?>
</p><input type="text" name="txtProf" ><br />  
        </fieldset>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto16']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto17']; ?>
</p><input type="text" name="txtDir" ><br />
          <p><?php echo $this->_config[0]['vars']['texto18']; ?>
</p><input type="text" name="txtCP" ><br />
          <p><?php echo $this->_config[0]['vars']['texto19']; ?>
</p><input type="text" name="txtCiudad" ><br />
          <p><?php echo $this->_config[0]['vars']['texto20']; ?>
</p>
            <?php if (isset ( $this->_tpl_vars['provincias'] )): ?>
              <select name="selProv">
                <option label=<?php echo $this->_config[0]['vars']['texto21']; ?>
 value=0><?php echo $this->_config[0]['vars']['texto21']; ?>
</option>
                <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['provincias'],'selected' => 0), $this);?>

              </select>
            <?php else: ?>
              <p><?php echo $this->_config[0]['vars']['texto22']; ?>
</p>
            <?php endif; ?><br />
          <p><?php echo $this->_config[0]['vars']['texto23']; ?>
</p><input type="text" name="txtTelfijo" ><br />
          <p><?php echo $this->_config[0]['vars']['texto24']; ?>
</p><input type="text" name="txtMovil" ><br />
          <p><?php echo $this->_config[0]['vars']['texto25']; ?>
</p><input type="text" name="txtTeltrab" ><br />
          <p><?php echo $this->_config[0]['vars']['texto26']; ?>
</p><input type="text" name="txtEmail" ><br />
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
                <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['dres'],'selected' => 0), $this);?>

              </select>
              <p><?php echo $this->_config[0]['vars']['texto76']; ?>
</p><input type="checkbox" name="referido">
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
                <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['pacs'],'selected' => 0), $this);?>

              </select>
            <?php else: ?>
              <p><?php echo $this->_config[0]['vars']['texto33']; ?>
</p>
            <?php endif; ?><br />
          <p><?php echo $this->_config[0]['vars']['texto80']; ?>
</p>
            <?php if (is_array ( $this->_tpl_vars['grupoImagenes'] )): ?>
              <select name="selGrupo">
                <option label=<?php echo $this->_config[0]['vars']['texto81']; ?>
 value=0><?php echo $this->_config[0]['vars']['texto81']; ?>
</option>
                <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['grupoImagenes'],'selected' => 0), $this);?>

              </select>
            <?php else: ?>
              <p><?php echo $this->_config[0]['vars']['texto82']; ?>
</p>
            <?php endif; ?><br />
          <p><?php echo $this->_config[0]['vars']['texto34']; ?>
</p><textarea name="txtAlertas"></textarea><br />
          <p><?php echo $this->_config[0]['vars']['texto35']; ?>
</p><textarea name="txtObservaciones"></textarea><br />
          <p><?php echo $this->_config[0]['vars']['texto48']; ?>
</p><input type="text" name="txtFechaAlta"> dd-mm-yyyy
        </fieldset>
        <input type="submit" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 />
        <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
        <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.pacientes'" />
      </form>
  </div>
  
</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>