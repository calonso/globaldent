<?php /* Smarty version 2.6.20, created on 2009-06-22 19:02:05
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/altapaciente.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/altapaciente.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/altapaciente.phtml', 3, false),)), $this); ?>
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
    <?php if ($this->_tpl_vars['codigo'] == 0): ?>
      <p><?php echo $this->_config[0]['vars']['texto36']; ?>
</p>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto37']; ?>
</p>
      <p><?php echo $this->_config[0]['vars']['texto38']; ?>
<a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['codigo']; ?>
><?php echo $this->_config[0]['vars']['texto39']; ?>
</a><?php echo $this->_config[0]['vars']['texto40']; ?>
</p>
    <?php endif; ?>
  </div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>