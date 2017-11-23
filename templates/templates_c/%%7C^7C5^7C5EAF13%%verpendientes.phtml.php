<?php /* Smarty version 2.6.20, created on 2009-10-08 21:10:26
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/verpendientes.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/verpendientes.phtml', 1, false),array('function', 'counter', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/verpendientes.phtml', 61, false),array('function', 'math', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/verpendientes.phtml', 78, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/verpendientes.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'conta'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript">
<?php echo '
<!--
function pagar (idp)
{
	//'; ?>

	var err1 = "<?php echo $this->_config[0]['vars']['error3']; ?>
<br />";
	var err2 = "<?php echo $this->_config[0]['vars']['error4']; ?>
<br />";
	var err3 = "<?php echo $this->_config[0]['vars']['error1']; ?>
<br />";
	var err4 = "<?php echo $this->_config[0]['vars']['error2']; ?>
<br />";
	//<?php echo '
	var err = "";
	var canSend = true;
	var x = document.getElementById (idp + "Tarj").value;
	var y = document.getElementById (idp + "Met").value;

	var charPos = x.search("[^0-9]");
	if(x.length > 0){
		if(charPos >= 0){
			err += err1;
			canSend = false;	
		}
	} else {
		err += err2;
		canSend = false;
	}
	charPos = y.search("[^0-9]");
	if(y.length > 0){
		if(charPos >= 0){
			err += err3;
			canSend = false;	
		}
	} else {
		err += err4;
		canSend = false;
	}
	if(canSend){
		document.fpago.idpaciente.value = idp;
		document.fpago.tarjeta.value = x;
		document.fpago.efectivo.value = y;
		document.fpago.submit();
	} else {
		show_errs("formulario_errorloc", err);
	}
}
function loaded(){}
-->
'; ?>

</script>
  <div class="contenidos">
    <div class="col_central">
      <span class="intro"><?php echo $this->_config[0]['vars']['texto15']; ?>
</span>
       <div id='formulario_errorloc' class='error_strings'></div>
      <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
        <p><?php echo $this->_config[0]['vars']['texto16']; ?>
</p>
        <?php $this->assign('total_pend', 0); ?>
        <?php echo smarty_function_counter(array('assign' => 'total_vis','start' => 0,'skip' => 1), $this);?>

        <table cellspadding="0" cellspacing="2" border="0" width="98%">
          <tr>
            <th><?php echo $this->_config[0]['vars']['texto7']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto6']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto10']; ?>
</th>
          </tr>
          <tr>
            <td colspan="3" class="lineahor">&nbsp;</td>
          </tr>
          <tr>
            <td colspan="3">&nbsp;</td>
          </tr>
        <?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['paciente']):
?>
          <tr>
            <td><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_tpl_vars['paciente']['apellido']; ?>
 <?php echo $this->_tpl_vars['paciente']['apellido2']; ?>
, <?php echo $this->_tpl_vars['paciente']['nombre']; ?>
</a></td>
            <td class="pendiente" align="center"><?php echo $this->_tpl_vars['paciente']['saldo']; ?>
 €.</td>
            <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['paciente']['saldo'],'y' => $this->_tpl_vars['total_pend'],'assign' => 'total_pend'), $this);?>

            <td align="center"> 
              <input type="text" id="<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
Tarj" size="5" value="0"/>
              <input type="text" id="<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
Met" size="5" value="0"/> 
              <input type="button" value=<?php echo $this->_config[0]['vars']['texto25']; ?>
 onclick="pagar(<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
)"/>
            </td>
          </tr>
          <tr>
            <td colspan="3">&nbsp;</td>
          </tr>
          <?php echo smarty_function_counter(array(), $this);?>

        <?php endforeach; endif; unset($_from); ?>
          <tr>
            <td colspan="3">&nbsp;</td>
          </tr>
          <tr>
            <th colspan="3"><?php echo $this->_config[0]['vars']['texto18']; ?>
</th>
          </tr>
          <tr>
            <td colspan="3" class="lineahor">&nbsp;</td>
          </tr>
          <tr>
            <th><?php echo $this->_config[0]['vars']['texto11']; ?>
</th>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto13']; ?>
</th>
          </tr>
          <tr>
            <td colspan="3">&nbsp;</td>
          </tr>
          <tr>
            <td align="center"><?php echo $this->_tpl_vars['total_vis']; ?>
</td>
            <td class="pendiente" colspan="2" align="center"><?php echo $this->_tpl_vars['total_pend']; ?>
 €</td>
          </tr>
        </table>
        <form name="fpago" enctype="multipart/form-data" action="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.pagavisita">
          <input type="hidden" name="idpaciente" value="0" />
          <input type="hidden" name="efectivo" value="0" />
          <input type="hidden" name="tarjeta" value="0" />
        </form>
      <?php else: ?>
        <p><?php echo $this->_config[0]['vars']['texto17']; ?>
</p>
      <?php endif; ?>
    </div>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.vercaja><?php echo $this->_config[0]['vars']['texto23']; ?>
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