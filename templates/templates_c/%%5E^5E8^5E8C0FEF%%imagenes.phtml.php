<?php /* Smarty version 2.6.20, created on 2009-10-08 20:42:51
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/imagenes/imagenes.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/imagenes/imagenes.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/imagenes/imagenes.phtml', 3, false),)), $this); ?>
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
    <p><?php echo $this->_config[0]['vars']['texto2']; ?>
</p>
    <p><?php echo $this->_config[0]['vars']['texto30']; ?>
</p>
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
      <?php $this->assign('tipo', $this->_tpl_vars['datos'][0]['tipoimg']); ?>
      <fieldset><legend><?php echo $this->_tpl_vars['tipo']; ?>
</legend>
      <?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['imag']):
?>
        <?php if ($this->_tpl_vars['tipo'] != $this->_tpl_vars['imag']['tipoimg']): ?>
          </fieldset>
          <?php $this->assign('tipo', $this->_tpl_vars['imag']['tipoimg']); ?>
          <fieldset><legend><?php echo $this->_tpl_vars['tipo']; ?>
</legend>
        <?php endif; ?>
        <?php if (isset ( $this->_tpl_vars['imag']['extension'] )): ?>
        <div class="imagen">
          <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verimagen/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/img.<?php echo $this->_tpl_vars['imag']['id_imagen']; ?>
>
          <img class="obj" src="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/fotopac/<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/<?php echo $this->_tpl_vars['imag']['id_imagen']; ?>
/<?php echo $this->_tpl_vars['imag']['extension']; ?>
" width="80" height="80" />
          </a>
          <p><?php echo $this->_tpl_vars['imag']['fecha']; ?>
</p>
        </div>
        <?php else: ?>
          <p><?php echo $this->_config[0]['vars']['texto29']; ?>
</p>
        <?php endif; ?>
      <?php endforeach; endif; unset($_from); ?>
      </fieldset>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto3']; ?>
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
index.php/cod.nuevaimagen/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto4']; ?>
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