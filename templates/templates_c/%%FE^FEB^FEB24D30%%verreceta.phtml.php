<?php /* Smarty version 2.6.20, created on 2009-10-08 20:43:20
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/verreceta.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/verreceta.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/verreceta.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'recetas'), $this);?>


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
    <span class="intro"><?php echo $this->_config[0]['vars']['texto40']; ?>
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
    <br />
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
    <fieldset><legend><?php echo $this->_config[0]['vars']['texto24']; ?>
</legend>
      <?php echo $this->_tpl_vars['datos']['resumen']; ?>

    </fieldset>
    <fieldset><legend><?php echo $this->_config[0]['vars']['texto25']; ?>
</legend>
      <?php echo $this->_tpl_vars['datos']['texto']; ?>

    </fieldset>
    <fieldset><legend><?php echo $this->_config[0]['vars']['texto26']; ?>
</legend>
      <?php echo $this->_tpl_vars['datos']['observaciones']; ?>

    </fieldset>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto23']; ?>
</p>
    <?php endif; ?>
  </div>
  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <li><input type="button" value="<?php echo $this->_config[0]['vars']['texto31']; ?>
" onclick="window.open('<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verreceta/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['visita']['id_visita']; ?>
/r.<?php echo $this->_tpl_vars['datos']['id_receta']; ?>
/imp.1')"></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borrareceta/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['visita']['id_visita']; ?>
/r.<?php echo $this->_tpl_vars['datos']['id_receta']; ?>
><?php echo $this->_config[0]['vars']['texto36']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.historia/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto37']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto38']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.listapacientes><?php echo $this->_config[0]['vars']['texto39']; ?>
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