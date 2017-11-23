<?php /* Smarty version 2.6.20, created on 2009-10-08 21:02:09
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/dres/verdr.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/dres/verdr.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/dres/verdr.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'dres'), $this);?>


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
      <span class="intro"><?php echo $this->_config[0]['vars']['texto18']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto19']; ?>
</p>
      <?php if ($this->_tpl_vars['codigo'] != 0): ?>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto9']; ?>
</legend>
        <p><?php echo $this->_config[0]['vars']['nombre']; ?>
<?php echo $this->_tpl_vars['datos']['nombre']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['apellido']; ?>
<?php echo $this->_tpl_vars['datos']['apellido']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['apellido2']; ?>
<?php echo $this->_tpl_vars['datos']['apellido2']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['dni']; ?>
<?php echo $this->_tpl_vars['datos']['dni']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['fechanac']; ?>
<?php echo $this->_tpl_vars['datos']['fecha_nacimiento']; ?>
</p><br />
      </fieldset>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto10']; ?>
</legend>
        <p><?php echo $this->_config[0]['vars']['direccion']; ?>
<?php echo $this->_tpl_vars['datos']['direccion']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['cp']; ?>
<?php echo $this->_tpl_vars['datos']['cp']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['ciudad']; ?>
<?php echo $this->_tpl_vars['datos']['ciudad']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['provincia']; ?>
<?php echo $this->_tpl_vars['datos']['provincia']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['telcli']; ?>
<?php echo $this->_tpl_vars['datos']['telefono_clinica']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['movil']; ?>
<?php echo $this->_tpl_vars['datos']['telefono_movil']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['telcasa']; ?>
<?php echo $this->_tpl_vars['datos']['telefono_casa']; ?>
</p><br /> 
        <p><?php echo $this->_config[0]['vars']['email']; ?>
<?php echo $this->_tpl_vars['datos']['email']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['fax']; ?>
<?php echo $this->_tpl_vars['datos']['fax']; ?>
</p><br />  
      </fieldset>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto12']; ?>
</legend>
        <p><?php echo $this->_config[0]['vars']['especialidad']; ?>
<?php echo $this->_tpl_vars['datos']['especialidad']; ?>
</p><br />
      </fieldset>
      <?php else: ?>
        <?php echo $this->_config[0]['vars']['texto29']; ?>

      <?php endif; ?>
    </div>  
    
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <?php if ($this->_tpl_vars['codigo'] != 0): ?>
        <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.moddr/id.<?php echo $this->_tpl_vars['datos']['id_dr_externo']; ?>
><?php echo $this->_config[0]['vars']['texto20']; ?>
</a></li>
        <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borrardr/id.<?php echo $this->_tpl_vars['datos']['id_dr_externo']; ?>
><?php echo $this->_config[0]['vars']['texto21']; ?>
</a></li>
      <?php endif; ?>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.listadr><?php echo $this->_config[0]['vars']['texto22']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.buscadr><?php echo $this->_config[0]['vars']['texto23']; ?>
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