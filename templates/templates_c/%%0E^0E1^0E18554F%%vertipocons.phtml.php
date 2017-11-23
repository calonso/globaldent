<?php /* Smarty version 2.6.20, created on 2009-06-23 20:03:35
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/vertipocons.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/vertipocons.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/vertipocons.phtml', 3, false),array('modifier', 'regex_replace', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/vertipocons.phtml', 38, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'conf'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript" src="<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/fckeditor.js"></script>
  <script type="text/javascript">
  <!--
  <?php echo '
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
 
  // -->
  </script>

  <div class="contenidos">
    <div class="col_central">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto78']; ?>
</span>
      <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
      <p><?php echo $this->_config[0]['vars']['texto79']; ?>
</p>
      <form enctype="multipart/form-data" method="POST" action=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modtipocons/id.<?php echo $this->_tpl_vars['datos']['id_tipo_consentimiento']; ?>
>
        <p><?php echo $this->_config[0]['vars']['texto68']; ?>
<input type="text" name="txtNombre" value="<?php echo $this->_tpl_vars['datos']['nombre']; ?>
"/></p><br />
        <p><?php echo $this->_config[0]['vars']['texto69']; ?>
</p>
        <script type="text/javascript">
            var oFCKeditor = new FCKeditor('txtTexto','100%','400','MyToolbar','<?php echo ((is_array($_tmp=$this->_tpl_vars['datos']['texto_incluido'])) ? $this->_run_mod_handler('regex_replace', true, $_tmp, "/[\r\n]/", "") : smarty_modifier_regex_replace($_tmp, "/[\r\n]/", "")); ?>
');
            oFCKeditor.BasePath = "<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/";
            oFCKeditor.Config['ToolbarStartExpanded'] = false ;
            oFCKeditor.Create();
         </script>
        <input type="submit" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 />
        <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
        <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.tipocons'">
      </form>
      <?php else: ?>
        <p><?php echo $this->_config[0]['vars']['texto80']; ?>
</p>
      <?php endif; ?>
    </div>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.tipocons><?php echo $this->_config[0]['vars']['volver']; ?>
</a></li>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
  </div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>