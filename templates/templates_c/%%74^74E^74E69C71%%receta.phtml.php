<?php /* Smarty version 2.6.20, created on 2009-10-08 20:48:25
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/receta.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/receta.phtml', 1, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/receta.phtml', 50, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/receta.phtml', 3, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/receta.phtml', 50, false),array('modifier', 'regex_replace', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/receta.phtml', 60, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'recetas'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript" src="<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/fckeditor.js"></script>
<script type="text/javascript">
<?php echo '
function cargar ()
{
  var x = document.getElementById ("sel");
  var id = x.options[x.selectedIndex].value;
  var dir = location.href;
  document.location= dir + "/tp." + id;
}
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
function loaded(){}
'; ?>

</script>

<div class="contenidos">
  <div class="col_izq">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto1']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['texto2']; ?>
</p>
    <p><?php echo $this->_config[0]['vars']['texto3']; ?>
</p>
  </div>
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto4']; ?>
</span>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/recetas/pac_info.phtml") : smarty_modifier_cat($_tmp, "gbdapp/recetas/pac_info.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/recetas/vis_info.phtml") : smarty_modifier_cat($_tmp, "gbdapp/recetas/vis_info.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <p><?php echo $this->_config[0]['vars']['texto22']; ?>
</p>
    <form enctype="multipart/form-data" method="POST" action=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevareceta/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['visita']['id_visita']; ?>
>
    <p><?php echo $this->_config[0]['vars']['texto18']; ?>
</p>
    <?php if (is_array ( $this->_tpl_vars['tiposrec'] )): ?>
      <select name="selReceta" id="sel" onchange="cargar()">
        <option label="<?php echo $this->_config[0]['vars']['texto19']; ?>
" value="0"><?php echo $this->_config[0]['vars']['texto19']; ?>
</option>
        <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['tiposrec'],'selected' => ((is_array($_tmp=@$this->_tpl_vars['idtipo'])) ? $this->_run_mod_handler('default', true, $_tmp, 0) : smarty_modifier_default($_tmp, 0))), $this);?>

      </select>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto20']; ?>
</p>
      <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.tiporecetas><?php echo $this->_config[0]['vars']['texto21']; ?>
</a>
    <?php endif; ?>
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
    <fieldset><legend><?php echo $this->_config[0]['vars']['texto24']; ?>
</legend>
    <p><?php echo $this->_config[0]['vars']['texto27']; ?>
</p>
    <script type="text/javascript">
      var oFCKeditor = new FCKeditor('txtResumen','100%','200','MyToolbar','<?php echo ((is_array($_tmp=$this->_tpl_vars['datos']['resumen'])) ? $this->_run_mod_handler('regex_replace', true, $_tmp, "/[\r\n]/", ' ') : smarty_modifier_regex_replace($_tmp, "/[\r\n]/", ' ')); ?>
');
      oFCKeditor.BasePath = "<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/";
      oFCKeditor.Config['ToolbarStartExpanded'] = false ;
      oFCKeditor.Create();
    </script>
    </fieldset>
    <fieldset><legend><?php echo $this->_config[0]['vars']['texto25']; ?>
</legend>
    <p><?php echo $this->_config[0]['vars']['texto28']; ?>
</p>
    <script type="text/javascript">
      var oFCKeditor = new FCKeditor('txtTexto','100%','300','MyToolbar','<?php echo ((is_array($_tmp=$this->_tpl_vars['datos']['texto'])) ? $this->_run_mod_handler('regex_replace', true, $_tmp, "/[\r\n]/", ' ') : smarty_modifier_regex_replace($_tmp, "/[\r\n]/", ' ')); ?>
');
      oFCKeditor.BasePath = "<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/";
      oFCKeditor.Config['ToolbarStartExpanded'] = false ;
      oFCKeditor.Create();
    </script>
    </fieldset>
    <fieldset><legend><?php echo $this->_config[0]['vars']['texto26']; ?>
</legend>
    <p><?php echo $this->_config[0]['vars']['texto29']; ?>
</p>
    <script type="text/javascript">
      var oFCKeditor = new FCKeditor('txtObservaciones','100%','200','MyToolbar','');
      oFCKeditor.BasePath = "<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/";
      oFCKeditor.Config['ToolbarStartExpanded'] = false ;
      oFCKeditor.Create();
    </script>
    </fieldset>
    <input type="submit" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 />
    <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
    <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.vervisita/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['visita']['id_visita']; ?>
'" />
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto23']; ?>
</p>
    <?php endif; ?>
    </form>
  </div>
</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>