<?php /* Smarty version 2.6.20, created on 2009-10-08 20:48:16
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/pac_info.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'count_characters', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/pac_info.phtml', 4, false),)), $this); ?>
<div class="pac_info">
  <span class="intro"><?php echo $this->_config[0]['vars']['texto5']; ?>
</span>
  <?php if (is_array ( $this->_tpl_vars['paciente'] )): ?>
    <?php if (((is_array($_tmp=$this->_tpl_vars['paciente']['extension'])) ? $this->_run_mod_handler('count_characters', true, $_tmp) : smarty_modifier_count_characters($_tmp)) > 0): ?>
      <div class="fotopers">
        <img class="obj" src="$req_base}file.php/fotopers/<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/<?php echo $this->_tpl_vars['paciente']['extension']; ?>
" width="80" height="80" />
      </div>
    <?php else: ?>
      <div class="fotopers">
        <img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
foto.jpg width="60" height="60">
      </div>
    <?php endif; ?>
    <p><?php echo $this->_tpl_vars['paciente']['nombre']; ?>
 <?php echo $this->_tpl_vars['paciente']['apellido']; ?>
 <?php echo $this->_tpl_vars['paciente']['apellido2']; ?>
</p>
    <p><?php echo $this->_config[0]['vars']['texto9']; ?>
 <?php echo $this->_tpl_vars['paciente']['telefono_fijo']; ?>
 / <?php echo $this->_tpl_vars['paciente']['telefono_movil']; ?>
 / <?php echo $this->_tpl_vars['paciente']['telefono_trabajo']; ?>
</p>
    <br />
    <fieldset><legend><?php echo $this->_config[0]['vars']['texto7']; ?>
</legend>
    <p><?php echo $this->_tpl_vars['paciente']['alertas_medicas']; ?>
</p>
    </fieldset>
    <fieldset><legend><?php echo $this->_config[0]['vars']['texto8']; ?>
</legend>
    <p><?php echo $this->_tpl_vars['paciente']['observaciones']; ?>
</p>
    </fieldset>
    <fieldset><legend><?php echo $this->_config[0]['vars']['texto60']; ?>
</legend>
    <p><?php echo $this->_tpl_vars['paciente']['alto_riesgo']; ?>
</p>
    </fieldset>
  <?php else: ?>
    <p><?php echo $this->_config[0]['vars']['texto6']; ?>
</p>
  <?php endif; ?>
</div>