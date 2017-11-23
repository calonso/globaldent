<?php /* Smarty version 2.6.20, created on 2009-10-08 20:30:15
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/agenda/nuevacita.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/agenda/nuevacita.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/agenda/nuevacita.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'agenda'), $this);?>


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
  <?php if ($this->_tpl_vars['codigo'] >= 1): ?>
    <p><?php echo $this->_config[0]['vars']['texto8']; ?>
</p>
    <p><?php echo $this->_config[0]['vars']['texto29']; ?>
<a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.agenda/dia.<?php echo $this->_tpl_vars['fecha']; ?>
><?php echo $this->_config[0]['vars']['texto30']; ?>
</a><?php echo $this->_config[0]['vars']['texto31']; ?>
</p>
  <?php elseif ($this->_tpl_vars['codigo'] == -1): ?>
    <?php echo $this->_config[0]['vars']['texto25']; ?>

  <?php else: ?>
    <?php echo $this->_config[0]['vars']['texto9']; ?>

  <?php endif; ?>
</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>