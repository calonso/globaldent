<?php /* Smarty version 2.6.20, created on 2009-06-24 20:19:54
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/consentimientos/cabecera.phtml */ ?>
<div class="pac_info">
  <div class="logoclinica">
    <img src=<?php echo $this->_tpl_vars['req_base']; ?>
file.php/logo width="100" height="110" />
  </div>
  <?php if (is_array ( $this->_tpl_vars['paciente'] )): ?>
  <p><?php echo $this->_tpl_vars['paciente']['apellido']; ?>
&nbsp;<?php echo $this->_tpl_vars['paciente']['apellido2']; ?>
,&nbsp;<?php echo $this->_tpl_vars['paciente']['nombre']; ?>
</p>
  <p><?php echo $this->_tpl_vars['paciente']['dni']; ?>
</p>
  <p><?php echo $this->_tpl_vars['paciente']['direccion']; ?>
</p>
  <p><?php echo $this->_tpl_vars['paciente']['telefono_fijo']; ?>
/<?php echo $this->_tpl_vars['paciente']['telefono_movil']; ?>
</p>
  <?php endif; ?>
</div>