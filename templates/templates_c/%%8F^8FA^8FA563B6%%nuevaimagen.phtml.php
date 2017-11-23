<?php /* Smarty version 2.6.20, created on 2009-10-08 20:36:05
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/imagenes/nuevaimagen.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/imagenes/nuevaimagen.phtml', 1, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/imagenes/nuevaimagen.phtml', 30, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/imagenes/nuevaimagen.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'imagenes'), $this);?>


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
    <span class="intro"><?php echo $this->_config[0]['vars']['texto11']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['texto12']; ?>
</p>
  </div>
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto13']; ?>
</span>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/imagenes/pac_info.phtml") : smarty_modifier_cat($_tmp, "gbdapp/imagenes/pac_info.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <p><?php echo $this->_config[0]['vars']['texto14']; ?>
</p>
    <form enctype="multipart/form-data" method="POST" action="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.altaimagen/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
">
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto15']; ?>
</legend>
        <input type="hidden" name="MAX_FILE_SIZE" value="2000000" />
        <p><?php echo $this->_config[0]['vars']['texto16']; ?>
</p><input type="file" name="fileFoto" />
        <p><?php echo $this->_config[0]['vars']['texto17']; ?>
</p>
          <?php if (is_array ( $this->_tpl_vars['tipos'] )): ?>
            <select name="selTipo">
              <option label=<?php echo $this->_config[0]['vars']['texto18']; ?>
 value=0><?php echo $this->_config[0]['vars']['texto18']; ?>
</option>
              <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['tipos'],'selected' => 0), $this);?>

            </select>
          <?php else: ?>
            <p><?php echo $this->_config[0]['vars']['texto19']; ?>
</p>
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.tipoimgs><?php echo $this->_config[0]['vars']['texto20']; ?>
</a>
          <?php endif; ?><br />
        <p><?php echo $this->_config[0]['vars']['texto45']; ?>
</p>
          <?php if (is_array ( $this->_tpl_vars['grupos'] )): ?>
            <select name="selGrupo">
              <option label=<?php echo $this->_config[0]['vars']['texto42']; ?>
 value=0><?php echo $this->_config[0]['vars']['texto42']; ?>
</option>
              <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['grupos'],'selected' => 0), $this);?>

            </select>
          <?php else: ?>
            <p><?php echo $this->_config[0]['vars']['texto43']; ?>
</p>
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.grupoimgs><?php echo $this->_config[0]['vars']['texto44']; ?>
</a>
          <?php endif; ?><br />
        <p><?php echo $this->_config[0]['vars']['texto21']; ?>
</p><textarea name="txtComentarios"></textarea><br />
      </fieldset>
      <input type="submit" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 />
      <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
      <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.imagenes/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
'">
    </form>
  </div>
</div>
    
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>