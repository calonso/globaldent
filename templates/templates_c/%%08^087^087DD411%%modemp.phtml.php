<?php /* Smarty version 2.6.20, created on 2009-10-08 21:08:11
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/modemp.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/modemp.phtml', 1, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/modemp.phtml', 66, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/modemp.phtml', 3, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/modemp.phtml', 66, false),array('modifier', 'regex_replace', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/modemp.phtml', 80, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'personal'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript" src="<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/fckeditor.js"></script>
<script type="text/javascript">
<?php echo '
<!--
function FCKeditor_OnComplete( editorInstance )
{
	editorInstance.Events.AttachEvent( \'OnBlur\'	, FCKeditor_OnBlur ) ;
	editorInstance.Events.AttachEvent( \'OnFocus\', FCKeditor_OnFocus ) ;
}

function FCKeditor_OnBlur( editorInstance )
{
	editorInstance.ToolbarSet.Collapse() ;
}

function FCKeditor_OnFocus( editorInstance )
{
	editorInstance.ToolbarSet.Expand() ;
}
function verificar(){
  var login = document.formulario.txtLogin.value;
  if(login.length == 0){
    alert ("El login no puede estar vacio");
  }else {
    document.formulario.submit();
  }
}
function loaded(){}
-->
'; ?>

</script>

  <div class="contenidos">
    <div class="col_izq">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto39']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto40']; ?>
</p>
    </div>
    <div class="col_central">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto41']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto42']; ?>
</p>
      <?php if (isset ( $this->_tpl_vars['datos'] )): ?>
      <form name="formulario" enctype="multipart/form-data" method="POST" action="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.actualizaempleado/id.<?php echo $this->_tpl_vars['datos']['id_personal']; ?>
">
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto9']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto10']; ?>
</p><input type="text" name="txtNombre" value="<?php echo $this->_tpl_vars['datos']['nombre']; ?>
" ><br />
          <p><?php echo $this->_config[0]['vars']['texto11']; ?>
</p><input type="text" name="txtApe" value="<?php echo $this->_tpl_vars['datos']['apellido']; ?>
" ><br />
          <p><?php echo $this->_config[0]['vars']['texto12']; ?>
</p><input type="text" name="txtApe2" value="<?php echo $this->_tpl_vars['datos']['apellido2']; ?>
" ><br />
          <p><?php echo $this->_config[0]['vars']['texto13']; ?>
</p><input type="text" name="txtDNI" value="<?php echo $this->_tpl_vars['datos']['dni']; ?>
" ><br />
          <input type="hidden" name="MAX_FILE_SIZE" value="2000000">
          <p><?php echo $this->_config[0]['vars']['texto14']; ?>
</p><input type="file" name="fileFoto" />  
        </fieldset>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto66']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto67']; ?>
</p><input type="text" name="txtLogin" value="<?php echo $this->_tpl_vars['datos']['login']; ?>
"><br />
        </fieldset>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto15']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto16']; ?>
</p><input type="text" name="txtDir" value="<?php echo $this->_tpl_vars['datos']['direccion']; ?>
" ><br />
          <p><?php echo $this->_config[0]['vars']['texto17']; ?>
</p><input type="text" name="txtCP" value="<?php echo $this->_tpl_vars['datos']['cp']; ?>
" ><br />
          <p><?php echo $this->_config[0]['vars']['texto18']; ?>
</p><input type="text" name="txtCiudad" value="<?php echo $this->_tpl_vars['datos']['ciudad']; ?>
" ><br />
          <p><?php echo $this->_config[0]['vars']['texto19']; ?>
</p>
            <?php if (isset ( $this->_tpl_vars['provincias'] )): ?>
              <select name="selProv">
                <option label=<?php echo $this->_config[0]['vars']['texto20']; ?>
 value=0><?php echo $this->_config[0]['vars']['texto20']; ?>
</option>
                <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['provincias'],'selected' => ((is_array($_tmp=@$this->_tpl_vars['datos']['id_provincia'])) ? $this->_run_mod_handler('default', true, $_tmp, 0) : smarty_modifier_default($_tmp, 0))), $this);?>

              </select>
            <?php else: ?>
              <p><?php echo $this->_config[0]['vars']['texto21']; ?>
</p>
            <?php endif; ?><br />
          <p><?php echo $this->_config[0]['vars']['texto22']; ?>
</p><input type="text" name="txtTelfijo" value="<?php echo $this->_tpl_vars['datos']['telefono']; ?>
" ><br />
          <p><?php echo $this->_config[0]['vars']['texto23']; ?>
</p><input type="text" name="txtMovil" value="<?php echo $this->_tpl_vars['datos']['movil']; ?>
" ><br />
          <p><?php echo $this->_config[0]['vars']['texto24']; ?>
</p><input type="text" name="txtEmail" value="<?php echo $this->_tpl_vars['datos']['email']; ?>
" ><br />
        </fieldset>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto25']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto26']; ?>
</p><input type="text" name="txtNumcol" value="<?php echo $this->_tpl_vars['datos']['num_colegiado']; ?>
" ><br />
          <p><?php echo $this->_config[0]['vars']['texto27']; ?>
</p><input type="text" name="txtEspecialidad" value="<?php echo $this->_tpl_vars['datos']['especialidad']; ?>
" ><br />
          <p><?php echo $this->_config[0]['vars']['texto28']; ?>
</p>
          <script type="text/javascript">
            var oFCKeditor = new FCKeditor('txtCV','100%','200','MyToolbar','<?php echo ((is_array($_tmp=$this->_tpl_vars['datos']['curriculum'])) ? $this->_run_mod_handler('regex_replace', true, $_tmp, "/[\r\n]/", "") : smarty_modifier_regex_replace($_tmp, "/[\r\n]/", "")); ?>
');
            oFCKeditor.BasePath = "<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/";
            oFCKeditor.Config['ToolbarStartExpanded'] = false ;
            oFCKeditor.Create();
          </script><br />
        </fieldset>
        <input type="button" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 onclick="verificar()"/>
        <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
        <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.personal'" />
      </form>
      <?php else: ?>
        <?php echo $this->_config[0]['vars']['texto36']; ?>

      <?php endif; ?>
  </div>
  
</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>