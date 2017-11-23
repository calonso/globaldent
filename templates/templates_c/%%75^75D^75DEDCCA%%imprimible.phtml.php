<?php /* Smarty version 2.6.20, created on 2009-10-08 21:11:19
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/imprimible.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/imprimible.phtml', 1, false),array('function', 'counter', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/imprimible.phtml', 18, false),array('function', 'math', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/imprimible.phtml', 44, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'conta'), $this);?>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
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
      <br /><br />

      <span class="intro"><?php echo $this->_config[0]['vars']['texto4']; ?>
<?php echo $this->_tpl_vars['dias']['hoy']; ?>
</span>
      <?php $this->assign('total_tarj', 0); ?>
      <?php $this->assign('total_efect', 0); ?>
      <?php if (is_array ( $this->_tpl_vars['visitas'] )): ?>
        <?php echo smarty_function_counter(array('assign' => 'total_vis','start' => 0,'skip' => 1), $this);?>

        <table border="0" cellspadding="0" cellspacing="2" width="100%">
          <tr>
            <th><?php echo $this->_config[0]['vars']['texto7']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto8']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto9']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto10']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto6']; ?>
</th>
            <th>&nbsp;</th>
          </tr>
          <tr>
            <td colspan="6">&nbsp;</td>
          </tr>
        <?php $_from = $this->_tpl_vars['visitas']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['visita']):
?>
          <?php $this->assign('linea', 0); ?>
          <tr>
            <td><?php echo $this->_tpl_vars['visita']['paciente']; ?>
</td>
            <td>
              <?php if (isset ( $this->_tpl_vars['visita']['tratamiento'] )): ?>
                <?php echo $this->_tpl_vars['visita']['tratamiento']; ?>

              <?php else: ?>
                <?php echo $this->_config[0]['vars']['texto24']; ?>

              <?php endif; ?>
            </td>
            <td class="pendiente" align="center"><?php echo $this->_tpl_vars['visita']['precio']; ?>
 €</td>
            <td align="center"><?php echo $this->_tpl_vars['visita']['pagos']['tarj']; ?>
/<?php echo $this->_tpl_vars['visita']['pagos']['efect']; ?>
</td>
            <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['visita']['pagos']['tarj'],'y' => $this->_tpl_vars['total_tarj'],'assign' => 'total_tarj'), $this);?>

            <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['visita']['pagos']['efect'],'y' => $this->_tpl_vars['total_efect'],'assign' => 'total_efect'), $this);?>

            <?php if ($this->_tpl_vars['visita']['saldo'] < 0): ?>
              <td align="center" class="pendiente"><?php echo $this->_tpl_vars['visita']['saldo']; ?>
</td>
            <?php else: ?>
              <td align="center"><?php echo $this->_tpl_vars['visita']['saldo']; ?>
</td>
            <?php endif; ?>
          </tr>
          <tr>
            <td colspan="6">&nbsp;</td>
          </tr>
          <?php echo smarty_function_counter(array(), $this);?>

        <?php endforeach; endif; unset($_from); ?>
        </table>
      <?php else: ?>
        <p><?php echo $this->_config[0]['vars']['texto5']; ?>
</p>
      <?php endif; ?>
      
      <?php if (is_array ( $this->_tpl_vars['pagos'] )): ?>
        <table border="0" cellspacing="2" cellspadding="0" width="98%">
          <tr>
            <th colspan="3"><?php echo $this->_config[0]['vars']['texto28']; ?>
</th>
          </tr>
          <tr>
            <th colspan="3" class="lineahor">&nbsp;</th>
          </tr>
          <tr>
            <th><?php echo $this->_config[0]['vars']['texto7']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto10']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto6']; ?>
</th>
          </tr>
          <?php $_from = $this->_tpl_vars['pagos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['pago']):
?>
            <tr>
              <td><?php echo $this->_tpl_vars['pago']['apellido']; ?>
 <?php echo $this->_tpl_vars['pago']['apellido2']; ?>
, <?php echo $this->_tpl_vars['pago']['nombre']; ?>
</td>
              <td align="center"><?php echo $this->_tpl_vars['pago']['tarj']; ?>
/<?php echo $this->_tpl_vars['pago']['efect']; ?>
</td>
              <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['pago']['tarj'],'y' => $this->_tpl_vars['total_tarj'],'assign' => 'total_tarj'), $this);?>

              <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['pago']['efect'],'y' => $this->_tpl_vars['total_efect'],'assign' => 'total_efect'), $this);?>

            <?php if ($this->_tpl_vars['pago']['saldo'] <= 0): ?>
              <td align="center" class="pendiente"><?php echo $this->_tpl_vars['pago']['saldo']; ?>
</td>
            <?php else: ?>
              <td align="center"><?php echo $this->_tpl_vars['pago']['saldo']; ?>
</td>
            <?php endif; ?>
            </tr>
            <tr>
              <td colspan="3">&nbsp;</td>
            </tr>
          <?php endforeach; endif; unset($_from); ?>
        </table>
      <?php else: ?> 
        <p><?php echo $this->_config[0]['vars']['texto27']; ?>
</p>
      <?php endif; ?>
        <table border="0" cellspacing="2" width="98%"> 
          <tr>
            <td colspan="7">&nbsp;</td>
          </tr>
          <tr>
            <th colspan="7"><?php echo $this->_config[0]['vars']['texto14']; ?>
</th>
          </tr>
          <tr>
            <td colspan="7">&nbsp;</td>
          </tr>
          <tr>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto11']; ?>
</th>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto29']; ?>
</th>
            <th>&nbsp;</th>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto12']; ?>
</th>
          </tr>
          <tr>
            <td colspan="7">&nbsp;</td>
          </tr>
          <tr>
            <td colspan="2" align="center"><?php echo $this->_tpl_vars['total_vis']; ?>
</td>
            <td colspan="2" align="center"><?php echo $this->_tpl_vars['total_tarj']; ?>
 €</td>
            <td>&nbsp;</td>
            <td colspan="2" align="center"><?php echo $this->_tpl_vars['total_efect']; ?>
 €</td>
          </tr>
        </table>

        <br /><br />

</body>
</html>