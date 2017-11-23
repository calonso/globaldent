<?php /* Smarty version 2.6.20, created on 2009-10-08 20:37:06
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/nuevogrupoimg.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/nuevogrupoimg.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/nuevogrupoimg.phtml', 3, false),)), $this); ?>
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
    <span class="intro"><?php echo $this->_config[0]['vars']['texto108']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['texto109']; ?>
</p>
  </div>
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto110']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['texto111']; ?>
</p>
      <form enctype="multipart/form-data" method="POST" action="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.altagrupoimg">
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto112']; ?>
</legend>
        <p><?php echo $this->_config[0]['vars']['texto113']; ?>
</p><input type="text" name="txtNombre" /><br />
      </fieldset>
      <input type="submit" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 />
      <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
      <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.grupoimgs'" />
    </form>
  </div>

</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>