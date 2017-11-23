<?php /* Smarty version 2.6.20, created on 2009-10-08 20:33:54
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/vervisita.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/vervisita.phtml', 1, false),array('function', 'counter', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/vervisita.phtml', 35, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/vervisita.phtml', 3, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/vervisita.phtml', 39, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'visitas'), $this);?>


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
    <span class="intro"><?php echo $this->_config[0]['vars']['texto32']; ?>
</span>
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/visitas/pac_info.phtml") : smarty_modifier_cat($_tmp, "gbdapp/visitas/pac_info.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <p><?php echo $this->_config[0]['vars']['texto33']; ?>
</p>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto14']; ?>
</legend>
        <p><?php echo $this->_config[0]['vars']['texto15']; ?>
<?php echo $this->_tpl_vars['datos']['fecha']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['texto16']; ?>
<?php echo $this->_tpl_vars['datos']['asiento']; ?>
</p><br />
        <p><?php echo $this->_config[0]['vars']['texto17']; ?>
</p><div class="texto"><?php echo $this->_tpl_vars['datos']['motivo']; ?>
</div><br />
        <p><?php echo $this->_config[0]['vars']['texto18']; ?>
</p><div class="texto"><?php echo $this->_tpl_vars['datos']['diagnostico']; ?>
</div><br />
        <p><?php echo $this->_config[0]['vars']['texto19']; ?>
</p>
        <table border="0" width="90%">
          <tr>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto66']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto67']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto68']; ?>
</th>
            <th>&nbsp;</th>
          </tr>
          <tr>
            <th colspan="4" class="lineahor">&nbsp;</th>
          </tr>
        <?php echo smarty_function_counter(array('assign' => 'numlinea','start' => 1,'skip' => 1), $this);?>

        <?php if (is_array ( $this->_tpl_vars['lineas'] )): ?>
          <?php $_from = $this->_tpl_vars['lineas']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['llave'] => $this->_tpl_vars['linea']):
?>
            <tr>
              <td colspan="2"><?php echo $this->_tpl_vars['numlinea']; ?>
.&nbsp;<?php echo ((is_array($_tmp=@$this->_tpl_vars['linea']['servicio'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_config[0]['vars']['texto57']) : smarty_modifier_default($_tmp, @$this->_config[0]['vars']['texto57'])); ?>
</td>
              <td align="center"><?php echo $this->_tpl_vars['linea']['cantidad']; ?>
</td>
              <td align="center"><?php echo $this->_tpl_vars['linea']['total']; ?>
 €.</td>
            </tr>
          <?php echo smarty_function_counter(array(), $this);?>

          <?php endforeach; endif; unset($_from); ?>
        <?php endif; ?>
        <tr>
          <td colspan="4" class="lineahor">&nbsp;</td>
        </tr>
        <tr>
          <th colspan="3" align="center"><?php echo $this->_config[0]['vars']['texto68']; ?>
</th>
          <th><?php echo $this->_tpl_vars['datos']['precio']; ?>
 €.</th>
          <th>&nbsp;</th>
        </tr>
      </table>
        <p><?php echo $this->_config[0]['vars']['texto20']; ?>
</p>
          <div class="texto"><?php echo $this->_tpl_vars['datos']['observaciones']; ?>
</div><br />
      </fieldset>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto46']; ?>
</legend>
        <p><?php echo $this->_config[0]['vars']['texto47']; ?>

          <?php if (is_array ( $this->_tpl_vars['datos']['asistentes'] )): ?>
            <?php $_from = $this->_tpl_vars['datos']['asistentes']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['asist']):
?>
              <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpers/id.<?php echo $this->_tpl_vars['asist']['id_personal']; ?>
><?php echo $this->_tpl_vars['asist']['nombre']; ?>
</a>
            <?php endforeach; endif; unset($_from); ?>
          <?php else: ?>
            <?php echo $this->_config[0]['vars']['texto56']; ?>

          <?php endif; ?></p><br />
        <p><?php echo $this->_config[0]['vars']['texto51']; ?>

          <?php if (is_array ( $this->_tpl_vars['datos']['colaboradores'] )): ?>
            <?php $_from = $this->_tpl_vars['datos']['colaboradores']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['colab']):
?>
              <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verdr/id.<?php echo $this->_tpl_vars['colab']['id_dr']; ?>
><?php echo $this->_tpl_vars['colab']['nombre']; ?>
</a>
            <?php endforeach; endif; unset($_from); ?>
          <?php else: ?>
            <?php echo $this->_config[0]['vars']['texto56']; ?>

          <?php endif; ?></p><br />
      </fieldset>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto34']; ?>
</p>
    <?php endif; ?>
  </div>
  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modvisita/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['datos']['id_visita']; ?>
><?php echo $this->_config[0]['vars']['texto35']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borravisita/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['datos']['id_visita']; ?>
><?php echo $this->_config[0]['vars']['texto36']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.receta/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['datos']['id_visita']; ?>
><?php echo $this->_config[0]['vars']['texto59']; ?>
</a></li>
    <?php endif; ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.historia/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto37']; ?>
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