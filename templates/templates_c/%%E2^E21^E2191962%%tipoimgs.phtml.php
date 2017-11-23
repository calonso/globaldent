<?php /* Smarty version 2.6.20, created on 2009-10-08 20:36:24
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/tipoimgs.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/tipoimgs.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conf/tipoimgs.phtml', 3, false),)), $this); ?>
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
    <div class="col_central">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto22']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto23']; ?>
</p>
      <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
        <div class="tablabusqueda">
          <div class="lineabusqueda">
            <div class="primera"><?php echo $this->_config[0]['vars']['texto5']; ?>
</div>
            <div class="tratamiento"><?php echo $this->_config[0]['vars']['texto14']; ?>
</div>
            <div class="indentar">&nbsp;</div>
          </div>
        <?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['tipo']):
?>
          <div class="lineabusqueda">
            <div class="lineaopts">
              <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borratipo/id.<?php echo $this->_tpl_vars['tipo']['id_tipo_imagen']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoborrar.ico alt="<?php echo $this->_config[0]['vars']['borrar']; ?>
" width="16" height="16" title="<?php echo $this->_config[0]['vars']['borrar']; ?>
" /></a>
            </div>
            <div class="primera"><?php echo $this->_tpl_vars['tipo']['nombre']; ?>
</div>
            <div class="tratamiento"><?php echo $this->_tpl_vars['tipo']['descripcion']; ?>
</div>
          </div>
        <?php endforeach; endif; unset($_from); ?>
        </div>
      <?php else: ?>
        <p><?php echo $this->_config[0]['vars']['texto25']; ?>
</p>
      <?php endif; ?>
    </div>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevotipoimg><?php echo $this->_config[0]['vars']['texto24']; ?>
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