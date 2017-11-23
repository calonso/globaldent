<?php /* Smarty version 2.6.20, created on 2009-06-24 20:19:52
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/consentimientos/cons.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/consentimientos/cons.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/consentimientos/cons.phtml', 3, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/consentimientos/cons.phtml', 37, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'consentimientos'), $this);?>


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
    <span class="intro"><?php echo $this->_config[0]['vars']['texto1']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['texto2']; ?>
</p>
    <?php if (is_array ( $this->_tpl_vars['firmados'] )): ?>
    <table border="0" cellspacing="2" width="90%">
      <tr>
        <th colspan="6"><?php echo $this->_config[0]['vars']['texto12']; ?>
</th>
      </tr>
      <tr>
        <th><?php echo $this->_config[0]['vars']['texto5']; ?>
</th>
        <th colspan="2"><?php echo $this->_config[0]['vars']['texto4']; ?>
</th>
        <th colspan="3">&nbsp;</th>
      </tr>
      <tr>
        <th colspan="6" class="lineahor">&nbsp;</th>
      </tr>
      <?php $_from = $this->_tpl_vars['firmados']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['cons']):
?>
        <tr>
          <td align="center"><?php echo $this->_tpl_vars['cons']['fecha']; ?>
</td>
          <td colspan="2" align="center"><?php echo ((is_array($_tmp=@$this->_tpl_vars['cons']['nombre'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_config[0]['vars']['texto14']) : smarty_modifier_default($_tmp, @$this->_config[0]['vars']['texto14'])); ?>
</td>
          <td align="center">
            <input type="button" value="<?php echo $this->_config[0]['vars']['texto16']; ?>
" onclick="abrir('<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.vercons/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/cons.<?php echo $this->_tpl_vars['cons']['id_consentimiento']; ?>
')" />
          </td>
          <td colspan="2" align="right">  
			<a href="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevoconsr/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/cons.<?php echo $this->_tpl_vars['cons']['id_consentimiento']; ?>
"><img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
sign_logoX.png" alt="<?php echo $this->_config[0]['vars']['texto20']; ?>
"/></a>
          </td>
        </tr>
      <?php endforeach; endif; unset($_from); ?>
    </table>  
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto3']; ?>
</p>
    <?php endif; ?>
    <br />
    <?php if (is_array ( $this->_tpl_vars['resto'] )): ?>
    <table border="0" cellspacing="5" width="90%">
    <tr>
        <th colspan="4"><?php echo $this->_config[0]['vars']['texto13']; ?>
</th>
      </tr>
      <tr>
        <th colspan="2"><?php echo $this->_config[0]['vars']['texto4']; ?>
</th>
        <th colspan="2">&nbsp;</th>
      </tr>
      <tr>
        <th colspan="4" class="lineahor">&nbsp;</th>
      </tr>
      <?php $_from = $this->_tpl_vars['resto']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['cons']):
?>
        <tr>
          <td colspan="3"><?php echo $this->_tpl_vars['cons']['nombre']; ?>
</td>
          <td align="right">
            <a href="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevocons/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/cons.<?php echo $this->_tpl_vars['cons']['id_consentimiento']; ?>
"><img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
sign_logo.png" alt="<?php echo $this->_config[0]['vars']['texto7']; ?>
"/></a>
          </td>
        </tr>
      <?php endforeach; endif; unset($_from); ?>
    </table>  
    <?php else: ?>
      <?php if (is_array ( $this->_tpl_vars['firmados'] )): ?>
        <p><?php echo $this->_config[0]['vars']['texto15']; ?>
</p>
      <?php else: ?>
        <p><?php echo $this->_config[0]['vars']['texto8']; ?>
</p>
        <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.tipocons><?php echo $this->_config[0]['vars']['texto6']; ?>
</a>
      <?php endif; ?>
    <?php endif; ?>
    <?php if (is_array ( $this->_tpl_vars['revocados'] )): ?>
      <table border="0" cellspacing="2" width="98%">
        <tr>
          <th colspan="5"><?php echo $this->_config[0]['vars']['texto21']; ?>
</th>
        </tr>
        <tr>
          <td colspan="5" class="lineahor">&nbsp;</td>
        </tr>
        <tr>
          <td><?php echo $this->_config[0]['vars']['texto5']; ?>
</td>
          <td><?php echo $this->_config[0]['vars']['texto22']; ?>
</td>
          <td colspan="2"><?php echo $this->_config[0]['vars']['texto4']; ?>
</td>
          <td>&nbsp;</td>
        </tr>
        <?php $_from = $this->_tpl_vars['revocados']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['cons']):
?>
          <tr>
            <td><?php echo $this->_tpl_vars['cons']['fecha_r']; ?>
</td>
            <td><?php echo $this->_tpl_vars['cons']['fecha']; ?>
</td>
            <td colspan="2"><?php echo $this->_tpl_vars['cons']['nombre']; ?>
</td>
            <td align="right">
              <input type="button" value="<?php echo $this->_config[0]['vars']['texto16']; ?>
" onclick="abrir('<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verconsr/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/cons.<?php echo $this->_tpl_vars['cons']['id_consentimiento']; ?>
')" />
            </td>
          </tr>
        <?php endforeach; endif; unset($_from); ?>
      </table>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto23']; ?>
</p>
    <?php endif; ?>
  </div>
  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.historia/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto9']; ?>
</a></li> 
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto10']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.listapacientes><?php echo $this->_config[0]['vars']['texto11']; ?>
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