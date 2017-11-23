<?php /* Smarty version 2.6.20, created on 2009-06-22 22:12:00
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/historiaecon.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/historiaecon.phtml', 1, false),array('function', 'math', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/historiaecon.phtml', 72, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/historiaecon.phtml', 3, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/historiaecon.phtml', 66, false),)), $this); ?>
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
    <span class="intro"><?php echo $this->_config[0]['vars']['texto74']; ?>
</span>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/visitas/pac_info.phtml") : smarty_modifier_cat($_tmp, "gbdapp/visitas/pac_info.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <p><?php echo $this->_config[0]['vars']['texto82']; ?>
</p>
    <form enctype="multipart/form-data" method="POST" action="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.pagavisita">
      <input type="hidden" name="idpaciente" value="<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
" />
      <label><?php echo $this->_config[0]['vars']['texto84']; ?>
</label><input type="text" name="tarjeta" value="0" />
      <label><?php echo $this->_config[0]['vars']['texto83']; ?>
</label><input type="text" name="efectivo" value="0" />
      <input type="submit" value="<?php echo $this->_config[0]['vars']['aceptar']; ?>
" >
    </form>
    
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
      <p><?php echo $this->_config[0]['vars']['texto73']; ?>
</p>
      <p><?php echo $this->_config[0]['vars']['texto85']; ?>
<?php echo $this->_tpl_vars['fechas']['primera']; ?>
<?php echo $this->_config[0]['vars']['texto86']; ?>
<?php echo $this->_tpl_vars['fechas']['ultima']; ?>
</p>
      <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/pags_fecha.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/pags_fecha.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <?php $this->assign('saldo', $this->_tpl_vars['saldoAnt']); ?>
      <table border="0" width="90%" cellspacing="4" cellpadding="0">
        <tr>
          <th><?php echo $this->_config[0]['vars']['texto15']; ?>
</th>
          <th colspan="2"><?php echo $this->_config[0]['vars']['texto27']; ?>
</th>
          <th><?php echo $this->_config[0]['vars']['texto68']; ?>
</th>
          <th><?php echo $this->_config[0]['vars']['texto75']; ?>
</th>
          <th><?php echo $this->_config[0]['vars']['texto76']; ?>
</th>
          <?php if ($this->_tpl_vars['privilegios'] == 4): ?>
          	<th><?php echo $this->_config[0]['vars']['texto89']; ?>
</th>
          <?php else: ?>
           	<th>&nbsp;</th>
          <?php endif; ?>
        </tr>
        <tr>
          <td colspan="7" class="lineahor">&nbsp;</td>
        </tr>
        <tr>
          <td colspan="7">&nbsp;</td>
        </tr>
        <tr>
          <td>&nbsp;</td>
          <td colspan="3"><?php echo $this->_config[0]['vars']['texto88']; ?>
<?php echo $this->_tpl_vars['fechas']['primera']; ?>
</td>
          <td>&nbsp;</td>
          <td><?php echo $this->_tpl_vars['saldoAnt']; ?>
</td>
          <td>&nbsp;</td>
        </tr>
        <tr>
          <td colspan="7">&nbsp;</td>
        </tr> 
      <?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['llave'] => $this->_tpl_vars['visita']):
?>
        <tr>
          <td><?php echo $this->_tpl_vars['visita']['fecha']; ?>
</td>
          <?php if ($this->_tpl_vars['visita']['id_visita'] > 0): ?>
            <td colspan="2">
              <?php if (is_array ( $this->_tpl_vars['visita']['tratamiento'] )): ?>
              <?php $_from = $this->_tpl_vars['visita']['tratamiento']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['servicio']):
?>
                <?php echo $this->_tpl_vars['servicio']['cantidad']; ?>
 x <?php echo ((is_array($_tmp=@$this->_tpl_vars['servicio']['servicio'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_config[0]['vars']['texto57']) : smarty_modifier_default($_tmp, @$this->_config[0]['vars']['texto57'])); ?>
 (<?php echo $this->_tpl_vars['servicio']['total']; ?>
 €)<br />
              <?php endforeach; endif; unset($_from); ?>
              <?php endif; ?>
            </td>
            <td align="center"><?php echo $this->_tpl_vars['visita']['precio']; ?>
</td>
            <td align="center">--</td>
            <?php echo smarty_function_math(array('equation' => "x - y",'x' => $this->_tpl_vars['saldo'],'y' => ((is_array($_tmp=@$this->_tpl_vars['visita']['precio'])) ? $this->_run_mod_handler('default', true, $_tmp, '0') : smarty_modifier_default($_tmp, '0')),'assign' => 'saldo'), $this);?>

            <td><?php echo $this->_tpl_vars['saldo']; ?>
</td>
            <?php if ($this->_tpl_vars['privilegios'] == 4): ?>
	            <td>
	            	<a href="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modvisita/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['visita']['id_visita']; ?>
"><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoedit.png alt="<?php echo $this->_config[0]['vars']['modificar']; ?>
" title="<?php echo $this->_config[0]['vars']['modificar']; ?>
" /></a>
	            	<a href="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borravisita/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['visita']['id_visita']; ?>
"><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoborrar.ico alt="<?php echo $this->_config[0]['vars']['borrar']; ?>
" title="<?php echo $this->_config[0]['vars']['borrar']; ?>
" height=16 width=16 /></a>
	            </td>
            <?php else: ?>
            	<td>&nbsp;</td>
            <?php endif; ?>
          <?php else: ?>
            <td colspan="2" align="center">---</td>
            <td align="center">--</td>
            <td align="center"><?php echo $this->_tpl_vars['visita']['tarj']; ?>
/<?php echo $this->_tpl_vars['visita']['ef']; ?>
</td>
            <?php echo smarty_function_math(array('equation' => "x + y + z",'x' => $this->_tpl_vars['saldo'],'y' => $this->_tpl_vars['visita']['tarj'],'z' => $this->_tpl_vars['visita']['ef'],'assign' => 'saldo'), $this);?>

            <td><?php echo $this->_tpl_vars['saldo']; ?>
</td>
            <?php if ($this->_tpl_vars['privilegios'] == 4): ?>
	            <td>
	            	<a href="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.actualizapagopac/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/idp.<?php echo $this->_tpl_vars['visita']['id_pago']; ?>
"><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoedit.png alt="<?php echo $this->_config[0]['vars']['modificar']; ?>
" title="<?php echo $this->_config[0]['vars']['modificar']; ?>
" /></a>
	            	<a href="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borrapagopac/idpaciente.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/idp.<?php echo $this->_tpl_vars['visita']['id_pago']; ?>
"><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoborrar.ico alt="<?php echo $this->_config[0]['vars']['borrar']; ?>
" title="<?php echo $this->_config[0]['vars']['borrar']; ?>
" height=16 width=16 /></a>
	            </td>
            <?php else: ?>
            	<td>&nbsp;</td>
            <?php endif; ?>
          <?php endif; ?>
          
        </tr>
        <tr>
          <td colspan="7">&nbsp;</td>
        </tr>  
      <?php endforeach; endif; unset($_from); ?>
        <tr>
          <td colspan="7" class="lineahor">&nbsp;</td>
        </tr>
        <tr>
          <th colspan="4"><?php echo $this->_config[0]['vars']['texto76']; ?>
</th>
          <?php if ($this->_tpl_vars['saldo'] >= 0): ?>
          	<th colspan="2"><?php echo $this->_tpl_vars['saldo']; ?>
 €</th>
          <?php else: ?>
          	<th colspan="2" class="pendiente"><?php echo $this->_tpl_vars['saldo']; ?>
 €</th>
          <?php endif; ?>
          <td>&nbsp;</td>
        </tr>
      </table>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto87']; ?>
<?php echo $this->_tpl_vars['fechas']['curr']; ?>
</p>
    <?php endif; ?>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/pags_fecha.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/pags_fecha.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    
  </div>

  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
  <?php if (is_array ( $this->_tpl_vars['paciente'] )): ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.presupuestos/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto77']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.facturas/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto78']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto63']; ?>
</a></li>
  <?php endif; ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.listapacientes><?php echo $this->_config[0]['vars']['texto61']; ?>
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