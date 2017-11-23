<?php /* Smarty version 2.6.20, created on 2009-10-08 21:08:25
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/verModPassEmp.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/verModPassEmp.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/verModPassEmp.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'personal'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
<?php echo '
<script type="text/javascript">
  function verificar()
  {
    var pass = document.formulario.txtPass.value;
    var conf = document.formulario.txtPass2.value;

    if(pass == conf && pass.length != 0) {
      document.formulario.submit();
    }else {
      alert("Las contraseñas introducidas son distintas o esta vacia.");
      document.formulario.reset();
    }
  }
  function loaded(){}
</script>
'; ?>


  <div class="contenidos">
    <div class="col_izq">
      <p><?php echo $this->_config[0]['vars']['texto83']; ?>
</p>
    </div>
    <div class="col_central">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto84']; ?>
</span>
      <?php if (isset ( $this->_tpl_vars['id'] )): ?>
      <form name="formulario" enctype="multipart/form-data" method="POST" action=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.actualizaPassEmp/id.<?php echo $this->_tpl_vars['id']; ?>
>
        <?php if ($this->_tpl_vars['privilegios'] == 4): ?>
          <fieldset><legend><?php echo $this->_config[0]['vars']['texto92']; ?>
</legend>
            <p><?php echo $this->_config[0]['vars']['texto93']; ?>
</p><input type="radio" name="RPrivilegios" value="Empleado" checked="checked"><br />
            <p><?php echo $this->_config[0]['vars']['texto94']; ?>
</p><input type="radio" name="RPrivilegios" value="SubAdmin"><br />
            <p><?php echo $this->_config[0]['vars']['texto95']; ?>
</p><input type="radio" name="RPrivilegios" value="Admin"><br />
          </fieldset>
          <fieldset><legend><?php echo $this->_config[0]['vars']['texto67']; ?>
</legend>
        <?php else: ?>
          <fieldset><legend><?php echo $this->_config[0]['vars']['texto67']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto85']; ?>
<input type="password" name="txtAnt" /></p><br />
        <?php endif; ?>
        <p><?php echo $this->_config[0]['vars']['texto86']; ?>
<input type="password" name="txtPass" /></p><br />
        <p><?php echo $this->_config[0]['vars']['texto87']; ?>
<input type="password" name="txtPass2" /></p>
        </fieldset>
        <input type="button" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 onclick="verificar()"/>
        <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
        <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.personal'">
      </form>
      <?php else: ?>
        <p><?php echo $this->_config[0]['vars']['texto88']; ?>
</p>
      <?php endif; ?>  
    </div>

</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>