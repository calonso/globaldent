<?php /* Smarty version 2.6.20, created on 2009-10-14 19:31:16
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/agenda/abrircita.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/agenda/abrircita.phtml', 1, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/agenda/abrircita.phtml', 48, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/agenda/abrircita.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'agenda'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript">
//<?php echo '
<!--
function enviar()
{
  document.formulario.txtFecha.disabled = false;
  document.formulario.txtHora.disabled = false;
  document.formulario.txtAsiento.disabled = false;
}
function loaded(){}
function fsa() {
	var x = document.getElementById ("selPac");
	var id = x.options[x.selectedIndex].value;
	'; ?>

    var fsa = [
    <?php $_from = $this->_tpl_vars['fsa']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['id']):
?>
     "<?php echo $this->_tpl_vars['id']; ?>
",
     <?php endforeach; endif; unset($_from); ?>];
    <?php echo '
    for (var i = 0; i < fsa.length ; ++i) {
        if (id == fsa[i]){
        	'; ?>

            alert("<?php echo $this->_config[0]['vars']['texto39']; ?>
");
            <?php echo '
        }
    }
}
// --> '; ?>

</script>

<div class="contenidos">
  <div class="col_izq">
    <?php echo $this->_config[0]['vars']['texto5']; ?>

  </div>
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto6']; ?>
</span>
    <div id='formulario_errorloc' class='error_strings'></div>
    <form name="formulario" enctype="multipart/form-data" method="POST" action=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevacita>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto7']; ?>
</legend>
        <p><?php echo $this->_config[0]['vars']['paciente']; ?>
</p>
        <?php if (is_array ( $this->_tpl_vars['pacs'] )): ?>
          <select name="selPac" id="selPac" onchange="fsa()">
            <option label="<?php echo $this->_config[0]['vars']['texto23']; ?>
" value="0"><?php echo $this->_config[0]['vars']['texto23']; ?>
</option>
            <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['pacs'],'selected' => 0), $this);?>

          </select>
          <?php else: ?>
            <p><?php echo $this->_config[0]['vars']['texto21']; ?>
</p>
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevopaciente><?php echo $this->_config[0]['vars']['texto22']; ?>
</a>
          <?php endif; ?><br />
        <p><?php echo $this->_config[0]['vars']['fecha']; ?>
<input type="text" name="txtFecha" value="<?php echo $this->_tpl_vars['datos']['fecha']; ?>
" disabled="true"></p><br />
        <p><?php echo $this->_config[0]['vars']['asiento']; ?>
<input type="text" name="txtAsiento" value="<?php echo $this->_tpl_vars['datos']['asiento']; ?>
" disabled="true"></p><br />
        <p><?php echo $this->_config[0]['vars']['hora']; ?>
<input type="text" name="txtHora" value="<?php echo $this->_tpl_vars['datos']['hora']; ?>
" disabled="true"></p><br />
        <p><?php echo $this->_config[0]['vars']['duracion']; ?>
<input type="text" name="txtDuracion" value="1"><?php echo $this->_config[0]['vars']['texto26']; ?>
</p><br />
        <div class="areatexto">
            <label><?php echo $this->_config[0]['vars']['observaciones']; ?>
</label><textarea name="txtObservaciones" rows="2" cols="40"></textarea>
        </div>
        <p><?php echo $this->_config[0]['vars']['texto19']; ?>
<input type="text" name="txtTipo" /><?php echo $this->_config[0]['vars']['texto20']; ?>
</p><br />
        </fieldset>
        <input type="submit" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
>
        <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
>
        <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.agenda'">
    </form>
  </div>
</div>

<script type="text/javascript">
<!--
	var validator = new Validator("formulario");
	validator.addValidation("selPac", "dontselect=0", "<?php echo $this->_config[0]['vars']['error6']; ?>
");
	validator.addValidation("txtDuracion", "num", "<?php echo $this->_config[0]['vars']['error0']; ?>
");
	validator.addValidation("txtDuracion", "lt=29", "<?php echo $this->_config[0]['vars']['error1']; ?>
");
	validator.addValidation("txtObservaciones", "alnum_s", "<?php echo $this->_config[0]['vars']['error2']; ?>
");
	validator.addValidation("txtObservaciones", "maxlen=200", "<?php echo $this->_config[0]['vars']['error3']; ?>
");
	validator.addValidation("txtTipo", "maxlen=20", "<?php echo $this->_config[0]['vars']['error5']; ?>
");
	validator.EnableOnPageErrorDisplaySingleBox();
	validator.EnableMsgsTogether();
	validator.setAddnlValidationFunction("enviar"); 
//-->
</script>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>