<?php /* Smarty version 2.6.20, created on 2009-10-08 20:47:54
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/cabeceraver.phtml */ ?>
<div class="pac_info">
  <div class="logoclinica">
    <img class="obj" src="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/logo" width="120" height="90" />
  </div>
  <?php if (is_array ( $this->_tpl_vars['paciente'] )): ?>
  <p><?php echo $this->_config[0]['vars']['texto41']; ?>
<?php echo $this->_tpl_vars['paciente']['apellido']; ?>
&nbsp;<?php echo $this->_tpl_vars['paciente']['apellido2']; ?>
,&nbsp;<?php echo $this->_tpl_vars['paciente']['nombre']; ?>
</p>
  <?php endif; ?>
  <?php if (is_array ( $this->_tpl_vars['clinica'] )): ?>
  <p><?php echo $this->_config[0]['vars']['texto42']; ?>
<?php echo $this->_tpl_vars['clinica']['direccion']; ?>
</p>
  <p><?php echo $this->_tpl_vars['clinica']['cp']; ?>
 <?php echo $this->_tpl_vars['clinica']['ciudad']; ?>
</p>
  <p><?php echo $this->_config[0]['vars']['texto43']; ?>
<?php echo $this->_tpl_vars['clinica']['telefono']; ?>
</p>
  <p><?php echo $this->_config[0]['vars']['texto47']; ?>
<?php echo $this->_tpl_vars['clinica']['reg_sanidad']; ?>
</p>
  <?php endif; ?>
  <?php if (is_array ( $this->_tpl_vars['visita'] )): ?>
  <p><?php echo $this->_config[0]['vars']['texto44']; ?>
<?php echo $this->_tpl_vars['visita']['fecha']; ?>
</p>
  <?php endif; ?>
</div>