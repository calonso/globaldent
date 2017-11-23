<?php /* Smarty version 2.6.20, created on 2009-10-08 21:02:51
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/usuarios/suscripcion.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/usuarios/suscripcion.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/usuarios/suscripcion.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'usuarios'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
<div class="contenidos">
  <?php if ($this->_tpl_vars['resultados'] >= 1): ?>
    <div class="col_central">
      <span class="intro"><?php echo $this->_config[0]['vars']['datos']; ?>
</span>
      <fieldset><legend><?php echo $this->_config[0]['vars']['datosp']; ?>
</legend>
      <p><?php echo $this->_config[0]['vars']['nombre']; ?>
 <?php echo $this->_tpl_vars['usuario']['nombre']; ?>
</p><br />
      <p><?php echo $this->_config[0]['vars']['apellidos']; ?>
 <?php echo $this->_tpl_vars['usuario']['apellido']; ?>
 <?php echo $this->_tpl_vars['usuario']['apellido2']; ?>
</p><br />
      </fieldset>
      <fieldset><legend><?php echo $this->_config[0]['vars']['datosc']; ?>
</legend>
      <p><?php echo $this->_config[0]['vars']['telefono']; ?>
 <?php echo $this->_tpl_vars['usuario']['telefono']; ?>
</p><br />
      <p><?php echo $this->_config[0]['vars']['email']; ?>
 <?php echo $this->_tpl_vars['usuario']['email']; ?>
</p><br />
      </fieldset>
      <fieldset><legend><?php echo $this->_config[0]['vars']['datossus']; ?>
</legend>
      <p><?php echo $this->_config[0]['vars']['fechafin']; ?>
 <?php echo $this->_tpl_vars['usuario']['fin_suscripcion']; ?>
</p><br />
      <?php $_from = $this->_tpl_vars['pagos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['elemento']):
?>
      <p><?php echo $this->_config[0]['vars']['fecha']; ?>
<?php echo $this->_tpl_vars['elemento']['fecha']; ?>
</p>
      <p><?php echo $this->_config[0]['vars']['tarjeta']; ?>
<?php echo $this->_tpl_vars['elemento']['numero_tarjeta']; ?>
</p>
      <p><?php echo $this->_config[0]['vars']['caducidad']; ?>
<?php echo $this->_tpl_vars['elemento']['caducidad']; ?>
</p>
      <p><?php echo $this->_config[0]['vars']['importe']; ?>
<?php echo $this->_tpl_vars['elemento']['importe']; ?>
 €.</p><br />
      <?php endforeach; endif; unset($_from); ?>
    </div>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <li><!--<a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.pago><?php echo $this->_config[0]['vars']['nuevopago']; ?>
</a>--><?php echo $this->_config[0]['vars']['nuevopago']; ?>
</li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modificar><?php echo $this->_config[0]['vars']['modificardatos']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modificarpass><?php echo $this->_config[0]['vars']['modificarpass']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.logout><?php echo $this->_config[0]['vars']['salir']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.home><?php echo $this->_config[0]['vars']['volver']; ?>
</a></li>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
  <?php else: ?>
    <span class="intro"><?php echo $this->_config[0]['vars']['error']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['fichaerror']; ?>
</p>
  <?php endif; ?>
</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>