<?php /* Smarty version 2.6.20, created on 2009-10-08 18:43:46
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/verpres.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/verpres.phtml', 1, false),array('function', 'counter', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/verpres.phtml', 52, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/verpres.phtml', 3, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/verpres.phtml', 56, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'presupuestos'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript">
//<?php echo '
function abrir(dir)
{
  window.open(dir);
}
function getHashData()
{
	return null;
}
function loaded()
{
	var s = document.Sign;
	if (s != null){
		'; ?>

		var str = "<?php echo $this->_tpl_vars['datos']['firma']; ?>
";
		<?php echo '
		if(str.length > 0){
			document.Sign.openSign1(str);
		}
	}
}
//'; ?>

</script>

<div class="contenidos">
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto45']; ?>
</span>
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/presupuestos/cabeceraver.phtml") : smarty_modifier_cat($_tmp, "gbdapp/presupuestos/cabeceraver.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <table border="0" width="100%">
      <tr>
        <th colspan="2"><?php echo $this->_config[0]['vars']['texto13']; ?>
</th>
        <th colspan="3">&nbsp;</th>
      </tr>
      <tr>
        <td colspan="5">&nbsp;</td>
      </tr>
      <tr>
        <th colspan="2"><?php echo $this->_config[0]['vars']['texto14']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto15']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto16']; ?>
</th>
        <th>&nbsp;</th>
      </tr>
      <tr>
        <td colspan="5" class="lineahor">&nbsp;</td>
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
              <td align="center"><?php echo $this->_tpl_vars['linea']['cantidad']; ?>
</td>
              <td align="right"><?php echo $this->_tpl_vars['linea']['total']; ?>
 €.</td>
            </tr>
          <?php echo smarty_function_counter(array(), $this);?>

          <?php endforeach; endif; unset($_from); ?>
        <?php endif; ?>
      <tr>
        <td colspan="5" class="lineahor">&nbsp;</td>
      </tr>
      <tr>
        <th colspan="3"><?php echo $this->_config[0]['vars']['texto16']; ?>
</th>
        <th><?php echo $this->_tpl_vars['datos']['total']; ?>
 €.</th>
        <th>&nbsp;</th>
      </tr>
    </table>
    <b><?php echo $this->_config[0]['vars']['texto21']; ?>
</b><p><?php echo $this->_config[0]['vars']['texto22']; ?>
 <?php echo $this->_tpl_vars['datos']['validez']; ?>
 <?php echo $this->_config[0]['vars']['texto36']; ?>
</p>
    <ol>
      <li><?php echo $this->_config[0]['vars']['texto23']; ?>
</li>
      <li><?php echo $this->_config[0]['vars']['texto24']; ?>
</li>
    </ol>
    <b><?php echo $this->_config[0]['vars']['texto25']; ?>
</b><p><?php echo $this->_config[0]['vars']['texto26']; ?>
</p>
    <ol>
      <li><?php echo $this->_config[0]['vars']['texto27']; ?>
</li>
      <li><?php echo $this->_config[0]['vars']['texto28']; ?>
</li>
    </ol>
    <b><?php echo $this->_config[0]['vars']['texto29']; ?>
</b><p><?php echo $this->_config[0]['vars']['texto30']; ?>
</p>
    <p><b><?php echo $this->_config[0]['vars']['texto31']; ?>
</b><?php echo $this->_tpl_vars['datos']['duracion']; ?>
 <?php echo $this->_config[0]['vars']['texto37']; ?>
</p>
    <p><?php echo $this->_config[0]['vars']['texto33']; ?>
</p>
    <div class="firmas">
       
	<APPLET classid=clsid:8AD9C840-044E-11D1-B3E9-00805F499D93 code="integrisign.webclient.WebSign" width=125 height=65 name="Sign" codebase="<?php echo $this->_tpl_vars['req_base']; ?>
lib/" archive="websignsunjvm.jar" MAYSCRIPT>
	  <PARAM NAME="borderstyle" VALUE="1" >
	  <PARAM NAME="scriptable" VALUE="true" >
	  <PARAM NAME="cache_option" VALUE="Plugin" >
	  <PARAM NAME="cache_archive" VALUE="websignsunjvm.jar" >
	  <PARAM NAME="cache_version" VALUE="7.5.0.3" >
	  <?php echo $this->_config[0]['vars']['error6']; ?>

	</APPLET> 
	
      <p><?php echo $this->_config[0]['vars']['texto35']; ?>
</p>
    </div>
  <?php else: ?>
    <p><?php echo $this->_config[0]['vars']['texto46']; ?>
</p>
  <?php endif; ?>
  </div>
  
  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
      <li><input type="button" value="<?php echo $this->_config[0]['vars']['texto48']; ?>
" onclick="abrir('<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpres/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/pres.<?php echo $this->_tpl_vars['datos']['id_presupuesto']; ?>
/imp.1')" /></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modpres/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/pres.<?php echo $this->_tpl_vars['datos']['id_presupuesto']; ?>
><?php echo $this->_config[0]['vars']['texto61']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borrapres/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/pres.<?php echo $this->_tpl_vars['datos']['id_presupuesto']; ?>
><?php echo $this->_config[0]['vars']['texto47']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevopres/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_config[0]['vars']['texto52']; ?>
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