<?php /* Smarty version 2.6.20, created on 2009-06-23 20:10:33
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/noautorizado/noautorizado.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/noautorizado/noautorizado.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/noautorizado/noautorizado.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'noautorizado'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "/common/header.phtml") : smarty_modifier_cat($_tmp, "/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<div class="contenedor">
  <span class="intro"><?php echo $this->_config[0]['vars']['intro']; ?>
</span><br />
  <p><?php echo $this->_config[0]['vars']['texto']; ?>
</p>
  <p><?php echo $this->_config[0]['vars']['texto1']; ?>

  <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.login><img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
btn_usuarios.jpg" alt="boton acceso" height="50" align="middle"/> </a>
  </p>
</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "/common/footer.phtml") : smarty_modifier_cat($_tmp, "/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>