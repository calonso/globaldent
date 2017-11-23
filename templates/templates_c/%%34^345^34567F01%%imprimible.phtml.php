<?php /* Smarty version 2.6.20, created on 2009-10-08 20:55:47
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/imprimible.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/imprimible.phtml', 1, false),array('function', 'counter', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/imprimible.phtml', 35, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/imprimible.phtml', 14, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/presupuestos/imprimible.phtml', 39, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'presupuestos'), $this);?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
	<title><?php echo $this->_config[0]['vars']['tituloapp']; ?>
</title>
	<link href="<?php echo $this->_tpl_vars['req_base']; ?>
css/estilos_aplicacion.css" rel="stylesheet" type="text/css" />
	<link rel="shortcut icon" href="<?php echo $this->_tpl_vars['img_path_base']; ?>
favicon.ico">
</head>
<body class="imprimible">

    <span class="intro"><?php echo $this->_config[0]['vars']['texto45']; ?>
</span>
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/presupuestos/cabeceraver.phtml") : smarty_modifier_cat($_tmp, "gbdapp/presupuestos/cabeceraver.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <table border="0" width="90%">
      <tr>
        <td colspan="5">&nbsp;</td>
      </tr>
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
		<img src="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/fp/<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/<?php echo $this->_tpl_vars['datos']['id_presupuesto']; ?>
" width="300" height="300" />
      <p><?php echo $this->_config[0]['vars']['texto35']; ?>
</p>
    </div>
  <?php else: ?>
    <p><?php echo $this->_config[0]['vars']['texto46']; ?>
</p>
  <?php endif; ?>
  
</body>
</html>