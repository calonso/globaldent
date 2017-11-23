<?php /* Smarty version 2.6.20, created on 2009-10-08 20:43:20
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/vis_info.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/vis_info.phtml', 9, false),)), $this); ?>
<div class="pac_info">
  <span class="intro"><?php echo $this->_config[0]['vars']['texto17']; ?>
</span>
  <?php if (is_array ( $this->_tpl_vars['visita'] )): ?>
    <p><?php echo $this->_config[0]['vars']['texto11']; ?>
 <?php echo $this->_tpl_vars['visita']['fecha']; ?>
</p>
    <br />
    <fieldset><legend><?php echo $this->_config[0]['vars']['texto12']; ?>
</legend>
    <?php if (is_array ( $this->_tpl_vars['visita']['lineas'] )): ?>
      <?php $_from = $this->_tpl_vars['visita']['lineas']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['servicio']):
?>
        <p><?php echo ((is_array($_tmp=@$this->_tpl_vars['servicio']['servicio'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_config[0]['vars']['texto13']) : smarty_modifier_default($_tmp, @$this->_config[0]['vars']['texto13'])); ?>
(<?php echo $this->_tpl_vars['servicio']['cantidad']; ?>
)</p><br />
      <?php endforeach; endif; unset($_from); ?>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto14']; ?>
</p>
    <?php endif; ?>
    </fieldset>
    <fieldset><legend><?php echo $this->_config[0]['vars']['texto15']; ?>
</legend>
    <p><?php echo $this->_tpl_vars['visita']['observaciones']; ?>
</p>
    </fieldset>
  <?php else: ?>
    <p><?php echo $this->_config[0]['vars']['texto16']; ?>
</p>
  <?php endif; ?>
</div>