<?php /* Smarty version 2.6.20, created on 2009-06-18 17:22:13
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/acceso/login.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/acceso/login.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/acceso/login.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'gbdapp'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "common/header.phtml") : smarty_modifier_cat($_tmp, "common/header.phtml")), 'smarty_include_vars' => array()));
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

  <div class="contenedor">
		<div class="col_izq">
			<p><?php echo $this->_config[0]['vars']['texto1']; ?>
</p>
			<p><?php echo $this->_config[0]['vars']['texto2']; ?>
</p>
			<a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.registroapp><img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
btn_registroapp.jpg" alt="boton de registro" /></a>
			<br /><br /><br />
		</div>
		<div class="col_central">
			<span class="intro"><?php echo $this->_config[0]['vars']['texto3']; ?>
</span>
			<form enctype="multipart/form-data" method="post" action="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.accesoapp">
				<fieldset><legend><?php echo $this->_config[0]['vars']['texto4']; ?>
</legend>
				<?php echo $this->_config[0]['vars']['login']; ?>
 <input type="text"  name="txtLogin"/><br />
				<?php echo $this->_config[0]['vars']['pass']; ?>
 <input type="password" name="txtPass"/><br />
				</fieldset>
				<input type="submit" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 />
				<input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
				<input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.gestion'"/>
			</form>
		</div>
	</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "common/footer.phtml") : smarty_modifier_cat($_tmp, "common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>