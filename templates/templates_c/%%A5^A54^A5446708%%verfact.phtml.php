<?php /* Smarty version 2.6.20, created on 2009-10-29 19:41:36
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/verfact.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/verfact.phtml', 1, false),array('function', 'counter', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/verfact.phtml', 39, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/verfact.phtml', 3, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/verfact.phtml', 43, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'facturas'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript">
<?php echo '
<!--
  function abrir(dir)
  {
    window.open(dir);
  }
function loaded(){}
-->
'; ?>

</script>

<div class="contenidos">
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto33']; ?>
</span>
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/facturas/cabeceraver.phtml") : smarty_modifier_cat($_tmp, "gbdapp/facturas/cabeceraver.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <table border="0" width="100%">
      <tr>
        <th colspan="6">&nbsp;</th>
      </tr>
      <tr>
        <td colspan="6">&nbsp;</td>
      </tr>
      <tr>
        <th colspan="2"><?php echo $this->_config[0]['vars']['texto15']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto61']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto14']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto16']; ?>
</th>
        <th>&nbsp;</th>
      </tr>
      <tr>
        <td colspan="6" class="lineahor">&nbsp;</td>
      </tr>
      <?php echo smarty_function_counter(array('assign' => 'numlinea','start' => 1,'skip' => 1), $this);?>

        <?php if (is_array ( $this->_tpl_vars['lineas'] )): ?>
          <?php $_from = $this->_tpl_vars['lineas']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['llave'] => $this->_tpl_vars['linea']):
?>
            <tr>
              <td colspan="2"><?php echo $this->_tpl_vars['numlinea']; ?>
.&nbsp;<?php echo ((is_array($_tmp=@$this->_tpl_vars['linea']['servicio'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_config[0]['vars']['texto20']) : smarty_modifier_default($_tmp, @$this->_config[0]['vars']['texto20'])); ?>
</td>
              <td><?php echo $this->_tpl_vars['linea']['texto']; ?>
</td>
              <td align="center"><?php echo $this->_tpl_vars['linea']['cantidad']; ?>
</td>
              <td align="right"><?php echo $this->_tpl_vars['linea']['total']; ?>
 €.</td>
            </tr>
          <?php echo smarty_function_counter(array(), $this);?>

          <?php endforeach; endif; unset($_from); ?>
        <?php endif; ?>
      <tr>
        <td colspan="6" class="lineahor">&nbsp;</td>
      </tr>
      <tr>
        <th colspan="3"><?php echo $this->_config[0]['vars']['texto20']; ?>
</th>
        <th colspan="2"><?php echo $this->_tpl_vars['datos']['total']; ?>
 €.</th>
        <th>&nbsp;</th>
      </tr>
    </table>
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
      <li><input type="button" value="<?php echo $this->_config[0]['vars']['texto35']; ?>
" onclick="abrir('<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verfact/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/fact.<?php echo $this->_tpl_vars['datos']['id_factura']; ?>
/imp.1')" /></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modfact/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/fact.<?php echo $this->_tpl_vars['datos']['id_factura']; ?>
><?php echo $this->_config[0]['vars']['texto21']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borrafact/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/fact.<?php echo $this->_tpl_vars['datos']['id_factura']; ?>
><?php echo $this->_config[0]['vars']['texto36']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto49']; ?>
</a></li>
    <?php endif; ?>
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