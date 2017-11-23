<?php /* Smarty version 2.6.20, created on 2009-06-22 22:12:06
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/cabecera.phtml */ ?>
<div class="pac_info">
  <div class="logoclinica">
    <img src=<?php echo $this->_tpl_vars['req_base']; ?>
file.php/logo width="100" height="110" />
  </div>
  <div class="numpres">
  <p><?php echo $this->_config[0]['vars']['texto12']; ?>
</p>
  <input type="text" name="txtNumero" value="<?php echo $this->_tpl_vars['presup']['numero']; ?>
" disabled="disabled">
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
<?php echo $this->_tpl_vars['fecha']; ?>
</p>
  <?php endif; ?>
</div>