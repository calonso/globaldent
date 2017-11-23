<?php /* Smarty version 2.6.20, created on 2009-10-08 21:11:55
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/listafacturas.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/listafacturas.phtml', 1, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/listafacturas.phtml', 26, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/listafacturas.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'conta'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

  <script type="text/javascript">
  <!--
  <?php echo '
  function loaded(){}
  function change(){
	  var x = document.getElementById ("sel");
	  var yr = x.options[x.selectedIndex].value;
	  var dir = location.href;
	  document.location= dir + "/year." + yr;
  }
  '; ?>
 
  // -->
  </script>

<div class="contenidos">
  <div class="col_central">
  <span class="intro"><?php echo $this->_config[0]['vars']['texto38']; ?>
</span>
  <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
  Viendo facturas del año
  <?php if (is_array ( $this->_tpl_vars['years'] )): ?>
 	<select id="sel" onchange="change()">
    <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['years'],'selected' => $this->_tpl_vars['selected']), $this);?>

    </select>
  <?php endif; ?>
  <br />
  <table border="0" cellspacing="0" cellspadding="0" width="90%">
  	<tr>
  		<th><?php echo $this->_config[0]['vars']['texto40']; ?>
</th>
  		<th><?php echo $this->_config[0]['vars']['texto41']; ?>
</th>
  		<th><?php echo $this->_config[0]['vars']['texto7']; ?>
</th>
  		<th><?php echo $this->_config[0]['vars']['texto42']; ?>
</th>
  		<th><?php echo $this->_config[0]['vars']['texto43']; ?>
</th>
  	</tr>
  	<tr>
  		<td class="lineahor" colspan="5">&nbsp;</td>
  	</tr>
  	<?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['fact']):
?>
  		<tr>
  			<td><?php echo $this->_tpl_vars['fact']['fecha']; ?>
</td>
  			<td align="center"><?php echo $this->_tpl_vars['fact']['numero']; ?>
</td>
  			<td align="center"><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['fact']['id_paciente']; ?>
><?php echo $this->_tpl_vars['fact']['nombre']; ?>
</a></td>
  			<td align="center"><?php echo $this->_tpl_vars['fact']['total']; ?>
 €</td>
  			<td align="center">
  				<a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verfact/id.<?php echo $this->_tpl_vars['fact']['id_paciente']; ?>
/fact.<?php echo $this->_tpl_vars['fact']['id_factura']; ?>
>
  					<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icover.ico alt="<?php echo $this->_config[0]['vars']['ver']; ?>
" />
             	</a>
             	<a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modfact/id.<?php echo $this->_tpl_vars['fact']['id_paciente']; ?>
/fact.<?php echo $this->_tpl_vars['fact']['id_factura']; ?>
>
  					<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoedit.png alt="<?php echo $this->_config[0]['vars']['modificar']; ?>
" />
  				</a>
            	<a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borrafact/id.<?php echo $this->_tpl_vars['fact']['id_paciente']; ?>
/fact.<?php echo $this->_tpl_vars['fact']['id_factura']; ?>
>
              		<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoborrar.ico alt="<?php echo $this->_config[0]['vars']['borrar']; ?>
" width="16" height="16"/>
             	</a>
  			</td>
  		</tr>
  	<?php endforeach; endif; unset($_from); ?>
  </table>
  <?php else: ?>
  	<p><?php echo $this->_config[0]['vars']['texto39']; ?>
</p>
  <?php endif; ?>
  </div>
</div>