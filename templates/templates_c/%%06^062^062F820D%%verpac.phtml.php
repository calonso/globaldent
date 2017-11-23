<?php /* Smarty version 2.6.20, created on 2009-06-20 19:13:56
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/verpac.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/verpac.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/verpac.phtml', 3, false),array('modifier', 'count_characters', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/verpac.phtml', 21, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/verpac.phtml', 84, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'pacientes'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript" src="<?php echo $this->_tpl_vars['req_base']; ?>
/js/motionpack.js"></script>
  <script type="text/javascript">
  <!--
  <?php echo '
  function loaded(){}
  '; ?>
 
  // -->
  </script>

  <div class="contenidos">
    <div class="col_central">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto41']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto42']; ?>
</p>
      <?php if (isset ( $this->_tpl_vars['datos'] )): ?>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto9']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto10']; ?>
<?php echo $this->_tpl_vars['datos']['nombre']; ?>
</p><br />
          <?php if (((is_array($_tmp=$this->_tpl_vars['datos']['extension'])) ? $this->_run_mod_handler('count_characters', true, $_tmp) : smarty_modifier_count_characters($_tmp)) > 0): ?>
          <div class="fotopers">
            <object data="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/fotopers/<?php echo $this->_tpl_vars['datos']['id_paciente']; ?>
/<?php echo $this->_tpl_vars['datos']['extension']; ?>
" type="image/<?php echo $this->_tpl_vars['datos']['extension']; ?>
" width="160px" height="160px">para abrir click aqui:
              <a href="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/fotopers/<?php echo $this->_tpl_vars['datos']['id_paciente']; ?>
/<?php echo $this->_tpl_vars['datos']['extension']; ?>
">foto</a>
            </object>
          </div>
          <?php else: ?>
          <div class="fotopers">
            <img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
foto.jpg width="60" height="60">
          </div>
          <?php endif; ?>
          <p><?php echo $this->_config[0]['vars']['texto11']; ?>
<?php echo $this->_tpl_vars['datos']['apellido']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto12']; ?>
<?php echo $this->_tpl_vars['datos']['apellido2']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto13']; ?>
<?php echo $this->_tpl_vars['datos']['dni']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto14']; ?>
<?php echo $this->_tpl_vars['datos']['fecha_nacimiento']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto15']; ?>
<?php echo $this->_tpl_vars['datos']['profesion']; ?>
</p><br />
        </fieldset>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto16']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto17']; ?>
<?php echo $this->_tpl_vars['datos']['direccion']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto18']; ?>
<?php echo $this->_tpl_vars['datos']['cp']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto19']; ?>
<?php echo $this->_tpl_vars['datos']['ciudad']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto20']; ?>
<?php echo $this->_tpl_vars['datos']['provincia']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto23']; ?>
<?php echo $this->_tpl_vars['datos']['telefono_fijo']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto24']; ?>
<?php echo $this->_tpl_vars['datos']['telefono_movil']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto25']; ?>
<?php echo $this->_tpl_vars['datos']['telefono_trabajo']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto26']; ?>
<?php echo $this->_tpl_vars['datos']['email']; ?>
</p><br />
        </fieldset>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto27']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto83']; ?>
</p>
          	<?php if ($this->_tpl_vars['datos']['num_citas'] > 0): ?>
          		<a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.agenda/dia.<?php echo $this->_tpl_vars['datos']['cita']['0']['fecha']; ?>
><?php echo $this->_config[0]['vars']['texto85']; ?>
 <?php echo $this->_tpl_vars['datos']['cita']['0']['fecha']; ?>
 <?php echo $this->_config[0]['vars']['texto86']; ?>
 <?php echo $this->_tpl_vars['datos']['cita']['0']['hora']; ?>
 <?php echo $this->_config[0]['vars']['texto87']; ?>
 <?php echo $this->_tpl_vars['datos']['cita']['0']['gabinete']; ?>
</a>
          		<?php if ($this->_tpl_vars['datos']['num_citas'] > 1): ?>
          			<a href="javascript:slide('citas')">(<?php echo $this->_config[0]['vars']['texto88']; ?>
)</a>
          			<div id="citas" style="display:none; overflow:hidden;">
          				<?php unset($this->_sections['ind']);
$this->_sections['ind']['name'] = 'ind';
$this->_sections['ind']['loop'] = is_array($_loop=$this->_tpl_vars['datos']['cita']) ? count($_loop) : max(0, (int)$_loop); unset($_loop);
$this->_sections['ind']['start'] = (int)1;
$this->_sections['ind']['step'] = ((int)1) == 0 ? 1 : (int)1;
$this->_sections['ind']['show'] = true;
$this->_sections['ind']['max'] = $this->_sections['ind']['loop'];
if ($this->_sections['ind']['start'] < 0)
    $this->_sections['ind']['start'] = max($this->_sections['ind']['step'] > 0 ? 0 : -1, $this->_sections['ind']['loop'] + $this->_sections['ind']['start']);
else
    $this->_sections['ind']['start'] = min($this->_sections['ind']['start'], $this->_sections['ind']['step'] > 0 ? $this->_sections['ind']['loop'] : $this->_sections['ind']['loop']-1);
if ($this->_sections['ind']['show']) {
    $this->_sections['ind']['total'] = min(ceil(($this->_sections['ind']['step'] > 0 ? $this->_sections['ind']['loop'] - $this->_sections['ind']['start'] : $this->_sections['ind']['start']+1)/abs($this->_sections['ind']['step'])), $this->_sections['ind']['max']);
    if ($this->_sections['ind']['total'] == 0)
        $this->_sections['ind']['show'] = false;
} else
    $this->_sections['ind']['total'] = 0;
if ($this->_sections['ind']['show']):

            for ($this->_sections['ind']['index'] = $this->_sections['ind']['start'], $this->_sections['ind']['iteration'] = 1;
                 $this->_sections['ind']['iteration'] <= $this->_sections['ind']['total'];
                 $this->_sections['ind']['index'] += $this->_sections['ind']['step'], $this->_sections['ind']['iteration']++):
$this->_sections['ind']['rownum'] = $this->_sections['ind']['iteration'];
$this->_sections['ind']['index_prev'] = $this->_sections['ind']['index'] - $this->_sections['ind']['step'];
$this->_sections['ind']['index_next'] = $this->_sections['ind']['index'] + $this->_sections['ind']['step'];
$this->_sections['ind']['first']      = ($this->_sections['ind']['iteration'] == 1);
$this->_sections['ind']['last']       = ($this->_sections['ind']['iteration'] == $this->_sections['ind']['total']);
?>
          					<a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.agenda/dia.<?php echo $this->_tpl_vars['datos']['cita'][$this->_sections['ind']['index']]['fecha']; ?>
><?php echo $this->_config[0]['vars']['texto85']; ?>
 <?php echo $this->_tpl_vars['datos']['cita'][$this->_sections['ind']['index']]['fecha']; ?>
 <?php echo $this->_config[0]['vars']['texto86']; ?>
 <?php echo $this->_tpl_vars['datos']['cita'][$this->_sections['ind']['index']]['hora']; ?>
 <?php echo $this->_config[0]['vars']['texto87']; ?>
 <?php echo $this->_tpl_vars['datos']['cita'][$this->_sections['ind']['index']]['gabinete']; ?>
</a><br />
          				<?php endfor; endif; ?>
          			</div>
          		<?php endif; ?>
          	<?php else: ?>
          		<p><?php echo $this->_config[0]['vars']['texto84']; ?>
</p>
          	<?php endif; ?>
          <br />
          <p><?php echo $this->_config[0]['vars']['texto28']; ?>
</p>
            <?php if (isset ( $this->_tpl_vars['datos']['nombre_dr_referidor'] )): ?>
              <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verdr/id.<?php echo $this->_tpl_vars['datos']['id_dr_referidor']; ?>
><?php echo $this->_tpl_vars['datos']['nombre_dr_referidor']; ?>
</a>
            <?php else: ?>
              <p><?php echo $this->_config[0]['vars']['texto44']; ?>
</p>
            <?php endif; ?><br />
          <p><?php echo $this->_config[0]['vars']['texto31']; ?>
</p>
            <?php if (isset ( $this->_tpl_vars['datos']['nombre_pac_referidor'] )): ?>
              <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['datos']['id_paciente_referidor']; ?>
><?php echo $this->_tpl_vars['datos']['nombre_pac_referidor']; ?>
</a>
            <?php else: ?>
              <p><?php echo $this->_config[0]['vars']['texto44']; ?>
</p>
            <?php endif; ?><br />
          <p><?php echo $this->_config[0]['vars']['texto55']; ?>
</p>
            <?php if (isset ( $this->_tpl_vars['datos']['referidos'] )): ?>
              <?php $_from = $this->_tpl_vars['datos']['referidos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['referido']):
?>
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['referido']['id']; ?>
><?php echo $this->_tpl_vars['referido']['nombre']; ?>
</a>
              <?php endforeach; endif; unset($_from); ?>
            <?php else: ?>
              <p><?php echo $this->_config[0]['vars']['texto44']; ?>
</p>
            <?php endif; ?><br />
          <p><?php echo $this->_config[0]['vars']['texto34']; ?>
<?php echo ((is_array($_tmp=@$this->_tpl_vars['datos']['alertas_medicas'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_config[0]['vars']['texto44']) : smarty_modifier_default($_tmp, @$this->_config[0]['vars']['texto44'])); ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto35']; ?>
<?php echo ((is_array($_tmp=@$this->_tpl_vars['datos']['observaciones'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_config[0]['vars']['texto44']) : smarty_modifier_default($_tmp, @$this->_config[0]['vars']['texto44'])); ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto73']; ?>
<?php echo ((is_array($_tmp=@$this->_tpl_vars['datos']['alto_riesgo'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_config[0]['vars']['texto44']) : smarty_modifier_default($_tmp, @$this->_config[0]['vars']['texto44'])); ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto48']; ?>
<?php echo $this->_tpl_vars['datos']['fecha_alta']; ?>
</p><br />
        </fieldset>
      <?php else: ?>
        <?php echo $this->_config[0]['vars']['texto43']; ?>

      <?php endif; ?>  
  </div>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <?php if (isset ( $this->_tpl_vars['datos'] )): ?>
        <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.historia/id.<?php echo $this->_tpl_vars['datos']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto70']; ?>
</a></li>
        <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.historiaecon/id.<?php echo $this->_tpl_vars['datos']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto79']; ?>
</a></li>
        <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modpac/id.<?php echo $this->_tpl_vars['datos']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto45']; ?>
</a></li>
        <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borrapac/id.<?php echo $this->_tpl_vars['datos']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto46']; ?>
</a></li>
      <?php endif; ?>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevopaciente><?php echo $this->_config[0]['vars']['texto2']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.buscapacientes><?php echo $this->_config[0]['vars']['texto3']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.listapacientes><?php echo $this->_config[0]['vars']['texto4']; ?>
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