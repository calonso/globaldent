<?php /* Smarty version 2.6.20, created on 2009-10-08 20:40:34
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/imagenes/verimagen.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/imagenes/verimagen.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/imagenes/verimagen.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'imagenes'), $this);?>


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
    <span class="intro"><?php echo $this->_config[0]['vars']['texto1']; ?>
</span>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/imagenes/pac_info.phtml") : smarty_modifier_cat($_tmp, "gbdapp/imagenes/pac_info.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <p><?php echo $this->_config[0]['vars']['texto33']; ?>
</p>
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto15']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto35']; ?>
<?php echo $this->_tpl_vars['datos']['fecha']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto17']; ?>
<?php echo $this->_tpl_vars['datos']['tipoimg']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto45']; ?>
<?php echo $this->_tpl_vars['datos']['grupoimg']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto21']; ?>
<?php echo $this->_tpl_vars['datos']['comentarios']; ?>
</p><br />
        </fieldset>
        <?php if (isset ( $this->_tpl_vars['datos']['extension'] )): ?>
        <div class="foto">
        <img class="obj" src="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/fotopac/<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/<?php echo $this->_tpl_vars['datos']['id_imagen']; ?>
/<?php echo $this->_tpl_vars['datos']['extension']; ?>
" width="400" height="400" />
        </div>
      <?php else: ?>
        <p><?php echo $this->_config[0]['vars']['texto34']; ?>
</p>
      <?php endif; ?>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto34']; ?>
</p>
    <?php endif; ?>
  </div>
  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
  <?php if (is_array ( $this->_tpl_vars['paciente'] )): ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borraimagen/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/img.<?php echo $this->_tpl_vars['datos']['id_imagen']; ?>
><?php echo $this->_config[0]['vars']['texto36']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevaimagen/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto4']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.imagenes/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto38']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto31']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.historia/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto32']; ?>
</a></li>
  <?php endif; ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.listapacientes><?php echo $this->_config[0]['vars']['texto10']; ?>
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