<?php /* Smarty version 2.6.20, created on 2009-06-18 17:22:50
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/acceso/index.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/acceso/index.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/acceso/index.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'gbdapp'), $this);?>


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
    <div class="inicio">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto5']; ?>
</span>
      <ul>
        <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.agenda><?php echo $this->_config[0]['vars']['texto6']; ?>
</a></li>
        <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.conf><?php echo $this->_config[0]['vars']['texto9']; ?>
</a></li>
        <?php if ($this->_tpl_vars['privilegios'] == 4): ?>
          <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.suscripcion><?php echo $this->_config[0]['vars']['texto7']; ?>
</a></li>
        <?php endif; ?>
        <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.logout><?php echo $this->_config[0]['vars']['texto8']; ?>
</a></li>
      </ul>
    </div>
  </div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>