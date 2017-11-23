<?php /* Smarty version 2.6.20, created on 2009-10-28 18:00:04
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/cabecera.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/cabecera.phtml', 9, false),)), $this); ?>
<div class="clin_info">
  <div class="logoclinica">
    <img src=<?php echo $this->_tpl_vars['req_base']; ?>
file.php/logo type="image/jpeg" width="100" height="110" />
  </div>
  <div class="numpres">
  <p><?php echo $this->_config[0]['vars']['texto12']; ?>
</p>
  <input type="text" name="txtNumero" value="<?php echo $this->_tpl_vars['fact']['numero']; ?>
" disabled="disabled"/>
  <p><?php echo $this->_config[0]['vars']['texto11']; ?>
</p>
  <input type="text" name="txtFecha" value="<?php echo ((is_array($_tmp=@$this->_tpl_vars['fact']['fecha'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_tpl_vars['fechaFact']) : smarty_modifier_default($_tmp, @$this->_tpl_vars['fechaFact'])); ?>
" />
  </div>
  <?php if (is_array ( $this->_tpl_vars['clinica'] )): ?>
  <p><?php echo $this->_tpl_vars['clinica']['nombre']; ?>
</p>
  <p><?php echo $this->_tpl_vars['clinica']['especialidad']; ?>
</p>
  <p><?php echo $this->_config[0]['vars']['texto13']; ?>
<?php echo $this->_tpl_vars['clinica']['nif']; ?>
</p>
  <p><?php echo $this->_tpl_vars['clinica']['direccion']; ?>
&nbsp;<?php echo $this->_tpl_vars['clinica']['cp']; ?>
&nbsp;<?php echo $this->_tpl_vars['clinica']['ciudad']; ?>
</p>
  <p><?php echo $this->_config[0]['vars']['texto23']; ?>
<?php echo $this->_tpl_vars['clinica']['telefono']; ?>
</p>
  <?php endif; ?>
</div>
<?php if (is_array ( $this->_tpl_vars['paciente'] )): ?>
  <div class="pac_info">
    <p><?php echo $this->_config[0]['vars']['texto8']; ?>
<input type="text" name="txtNombre" value="<?php echo $this->_tpl_vars['fact']['nombre_pagador']; ?>
" /></p>
    <p><?php echo $this->_config[0]['vars']['texto9']; ?>
<?php echo $this->_tpl_vars['paciente']['direccion']; ?>
</p>
    <p><?php echo $this->_config[0]['vars']['texto59']; ?>
<?php echo $this->_tpl_vars['paciente']['ciudad']; ?>
</p>
    <p><?php echo $this->_config[0]['vars']['texto58']; ?>
<?php echo $this->_tpl_vars['paciente']['cp']; ?>
</p>
    <p><?php echo $this->_config[0]['vars']['texto60']; ?>
<?php echo $this->_tpl_vars['paciente']['provincia']; ?>
</p>
    <p><?php echo $this->_config[0]['vars']['texto25']; ?>
<input type="text" name="txtDNI" value="<?php echo $this->_tpl_vars['fact']['dni_pagador']; ?>
" /></p>
  </div>
<?php endif; ?>