<?php /* Smarty version 2.6.20, created on 2009-10-08 21:05:40
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/actividademp.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/actividademp.phtml', 1, false),array('function', 'counter', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/actividademp.phtml', 19, false),array('function', 'math', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/actividademp.phtml', 55, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/actividademp.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'personal'), $this);?>


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
    <span class="intro"><?php echo $this->_config[0]['vars']['texto59']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['texto60']; ?>
</p>
      <?php if (is_array ( $this->_tpl_vars['visitas'] )): ?>
        <?php $this->assign('mes', $this->_tpl_vars['visitas'][0]['mes']); ?>
        <?php echo smarty_function_counter(array('assign' => 'total_vis','start' => 0,'skip' => 1), $this);?>

        <?php $this->assign('total_pre', 0); ?>
        <fieldset><legend><?php echo $this->_tpl_vars['mes']; ?>
</legend>
        <table border="0" width="90%">
        <?php $_from = $this->_tpl_vars['visitas']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['llave'] => $this->_tpl_vars['vis']):
?>
          <?php if ($this->_tpl_vars['mes'] != $this->_tpl_vars['vis']['mes']): ?>
          <tr>
            <th class="lineahor" colspan="4">&nbsp;</th>
          </tr>
          <tr>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto62']; ?>
</th>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto63']; ?>
</th>
          </tr>
          <tr>
            <td colspan="2" align="center"><?php echo $this->_tpl_vars['total_vis']; ?>
</td>
            <td colspan="2" align="center"><?php echo $this->_tpl_vars['total_pre']; ?>
 €.</td>
          </tr>
          <?php echo smarty_function_counter(array('assign' => 'total_vis','start' => 0,'skip' => 1), $this);?>

          <?php $this->assign('total_pre', 0); ?>
            </table>
            </fieldset>
            <?php $this->assign('mes', $this->_tpl_vars['vis']['mes']); ?>
            <fieldset><legend><?php echo $this->_tpl_vars['mes']; ?>
</legend>
            <table border="0" width="90%">
          <?php endif; ?>
          <tr>
            <td><?php echo $this->_tpl_vars['vis']['fecha']; ?>
</td>
            <td colspan="2">
              <?php if (is_array ( $this->_tpl_vars['vis']['tratamiento'] )): ?>
                <?php $_from = $this->_tpl_vars['vis']['tratamiento']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['linea']):
?>
                  <p><?php echo $this->_tpl_vars['linea']['cantidad']; ?>
 x <?php echo $this->_tpl_vars['linea']['servicio']; ?>
 (<?php echo $this->_tpl_vars['linea']['total']; ?>
) €</p><br />
                <?php endforeach; endif; unset($_from); ?>
              <?php endif; ?>
            </td>
            <td><?php echo $this->_tpl_vars['vis']['precio']; ?>
 €.</td>
          </tr>
          <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['total_pre'],'y' => $this->_tpl_vars['vis']['precio'],'assign' => 'total_pre'), $this);?>

          <?php echo smarty_function_counter(array(), $this);?>
     
        <?php endforeach; endif; unset($_from); ?>
          <tr>
            <th class="lineahor" colspan="4">&nbsp;</th>
          </tr>
          <tr>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto62']; ?>
</th>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto63']; ?>
</th>
          </tr>
          <tr>
            <td colspan="2" align="center"><?php echo $this->_tpl_vars['total_vis']; ?>
</td>
            <td colspan="2" align="center"><?php echo $this->_tpl_vars['total_pre']; ?>
 €.</td>
          </tr>
         </table>    
        </fieldset>  
      <?php else: ?>
        <p><?php echo $this->_config[0]['vars']['texto61']; ?>
</p>
      <?php endif; ?>
    </div>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpers/id.<?php echo $this->_tpl_vars['id']; ?>
><?php echo $this->_config[0]['vars']['texto64']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.listaempleados><?php echo $this->_config[0]['vars']['texto65']; ?>
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