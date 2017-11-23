<?php /* Smarty version 2.6.20, created on 2009-10-08 18:40:56
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/cabeceraver.phtml */ ?>
<div class="clin_info">
  <div class="logoclinica">
    <img src=<?php echo $this->_tpl_vars['req_base']; ?>
file.php/logo type="image/jpeg" width="100" height="110" />
  </div>
  <div class="numpres">
  <p><?php echo $this->_config[0]['vars']['texto12']; ?>
</p>
  <p><?php echo $this->_tpl_vars['datos']['numero']; ?>
</p>
  <p><?php echo $this->_config[0]['vars']['texto11']; ?>
<?php echo $this->_tpl_vars['datos']['fecha']; ?>
</p>
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
  <?php else: ?>
  <?php endif; ?>
</div>
<div class="pac_info">
  <?php if (is_array ( $this->_tpl_vars['paciente'] )): ?>
  <p><?php echo $this->_config[0]['vars']['texto8']; ?>
<?php echo $this->_tpl_vars['datos']['nombre_pagador']; ?>
</p>
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
<?php echo $this->_tpl_vars['datos']['dni_pagador']; ?>
</p>
  <?php endif; ?>
</div>