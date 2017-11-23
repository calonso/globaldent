<?php /* Smarty version 2.6.20, created on 2009-10-08 18:43:46
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/cabeceraver.phtml */ ?>
<div class="pac_info">
  <div class="logoclinica">
    <img class="obj" src="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/logo" width="120" height="90" />
  </div>
  <div class="numpres">
  <p><?php echo $this->_config[0]['vars']['texto12']; ?>
</p>
  <p><?php echo $this->_tpl_vars['datos']['numero']; ?>
</p>
  </div>
  <?php if (is_array ( $this->_tpl_vars['paciente'] )): ?>
  <p><?php echo $this->_config[0]['vars']['texto8']; ?>
<?php echo $this->_tpl_vars['paciente']['apellido']; ?>
&nbsp;<?php echo $this->_tpl_vars['paciente']['apellido2']; ?>
,&nbsp;<?php echo $this->_tpl_vars['paciente']['nombre']; ?>
</p>
  <p><?php echo $this->_config[0]['vars']['texto9']; ?>
<?php echo $this->_tpl_vars['paciente']['direccion']; ?>
</p>
  <p><?php echo $this->_config[0]['vars']['texto10']; ?>
<?php echo $this->_tpl_vars['paciente']['telefono_fijo']; ?>
/<?php echo $this->_tpl_vars['paciente']['telefono_movil']; ?>
</p>
  <p><?php echo $this->_config[0]['vars']['texto11']; ?>
<?php echo $this->_tpl_vars['datos']['fecha']; ?>
</p>
  <p><?php echo $this->_config[0]['vars']['texto62']; ?>
<?php echo $this->_tpl_vars['clinica']['reg_sanidad']; ?>
</p>
  <?php endif; ?>
</div>