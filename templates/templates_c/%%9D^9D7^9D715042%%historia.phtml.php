<?php /* Smarty version 2.6.20, created on 2009-10-19 18:54:47
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/historia.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/historia.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/historia.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'visitas'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript">
<!--
<?php echo '
function confirmar(id)
{
  '; ?>

  var enlace = "<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borravisita/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis." + id;
  var x = confirm ("<?php echo $this->_config[0]['vars']['texto81']; ?>
");
  <?php echo '
  if (x == true)
  {
    location.href = enlace;
  }
}
function loaded(){}
'; ?>

-->
</script>

<div class="contenidos">
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto1']; ?>
</span>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/visitas/pac_info.phtml") : smarty_modifier_cat($_tmp, "gbdapp/visitas/pac_info.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
      <p><?php echo $this->_config[0]['vars']['texto2']; ?>
</p>
      <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/pags_inverse.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/pags_inverse.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <table border="0" width="90%" cellspacing="4" cellpadding="0">
        <tr>
          <th><?php echo $this->_config[0]['vars']['texto15']; ?>
</th>
          <th colspan="2"><?php echo $this->_config[0]['vars']['texto27']; ?>
</th>
          <th><?php echo $this->_config[0]['vars']['texto58']; ?>
</th>
          <th>&nbsp;</th>
        </tr>
        <tr>
          <td colspan="5" class="lineahor">&nbsp;</td>
        </tr>
        <tr>
          <td colspan="5">&nbsp;</td>
        </tr>
      <?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['llave'] => $this->_tpl_vars['visita']):
?>
        <tr>
          <td><?php echo $this->_tpl_vars['visita']['fecha']; ?>
</td>
          <td colspan="2">
            <?php if (is_array ( $this->_tpl_vars['visita']['tratamiento'] )): ?>
	            <?php $_from = $this->_tpl_vars['visita']['tratamiento']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['servicio']):
?>
	              <?php echo $this->_tpl_vars['servicio']['cantidad']; ?>
 x <?php echo $this->_tpl_vars['servicio']['servicio']; ?>
<br />
	            <?php endforeach; endif; unset($_from); ?>
            <?php elseif ($this->_tpl_vars['visita']['fsa'] == 1): ?>
              <?php echo $this->_config[0]['vars']['texto90']; ?>

            <?php else: ?>
              <?php echo $this->_config[0]['vars']['texto57']; ?>

            <?php endif; ?>
          </td>
          <td align="center" colspan="2"><?php echo $this->_tpl_vars['visita']['observaciones']; ?>
</td>
          <td>
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.vervisita/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['visita']['id_visita']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icover.ico alt=<?php echo $this->_config[0]['vars']['ver']; ?>
></a>
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modvisita/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['visita']['id_visita']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoedit.png alt=<?php echo $this->_config[0]['vars']['modificar']; ?>
 width="16"></a>
            <img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoborrar.ico alt=<?php echo $this->_config[0]['vars']['borrar']; ?>
 width="16" onclick="confirmar(<?php echo $this->_tpl_vars['visita']['id_visita']; ?>
)" /></a>
          </td>
        </tr>
        <?php if (is_array ( $this->_tpl_vars['visita']['recetas'] )): ?>
        <tr>
          <td>&nbsp;</td>
          <td><?php echo $this->_config[0]['vars']['texto64']; ?>
</td>
          <td colspan="3" class="lineahor">&nbsp;</td>
          <td>&nbsp;</td>
        </tr>
          <?php $_from = $this->_tpl_vars['visita']['recetas']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['receta']):
?>
          <tr>
            <td>&nbsp;</td>
            <td>&nbsp;</td>
            <td><?php echo $this->_tpl_vars['receta']['nombre']; ?>
</td>
            <td>
              <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verreceta/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['visita']['id_visita']; ?>
/r.<?php echo $this->_tpl_vars['receta']['id_receta']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icover.ico alt=<?php echo $this->_config[0]['vars']['ver']; ?>
></a>
              <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borrareceta/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/vis.<?php echo $this->_tpl_vars['visita']['id_visita']; ?>
/r.<?php echo $this->_tpl_vars['receta']['id_receta']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoborrar.ico alt=<?php echo $this->_config[0]['vars']['borrar']; ?>
 width="16"></a>
            </td>
            <td>&nbsp;</td>
          </tr>
          <?php endforeach; endif; unset($_from); ?>
        <?php endif; ?>
        <tr>
          <td colspan="5">&nbsp;</td>
        </tr>  
      <?php endforeach; endif; unset($_from); ?>
      </table>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/pags_inverse.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/pags_inverse.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto3']; ?>
</p>
    <?php endif; ?>
  </div>

  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
  <?php if (is_array ( $this->_tpl_vars['paciente'] )): ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.abrirvisita/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto4']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.imagenes/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto62']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.cons/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto65']; ?>
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