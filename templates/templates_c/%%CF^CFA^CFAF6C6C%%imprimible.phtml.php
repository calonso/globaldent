<?php /* Smarty version 2.6.20, created on 2009-10-08 20:46:46
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/imprimible.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/imprimible.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/recetas/imprimible.phtml', 14, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'recetas'), $this);?>

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

    <span class="intro"><?php echo $this->_config[0]['vars']['texto40']; ?>
</span>
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/recetas/cabeceraver.phtml") : smarty_modifier_cat($_tmp, "gbdapp/recetas/cabeceraver.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto24']; ?>
</legend>
        <?php echo $this->_tpl_vars['datos']['resumen']; ?>

      </fieldset>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto25']; ?>
</legend>
        <?php echo $this->_tpl_vars['datos']['texto']; ?>

      </fieldset>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto26']; ?>
</legend>
        <?php echo $this->_tpl_vars['datos']['observaciones']; ?>

      </fieldset>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto23']; ?>
</p>
    <?php endif; ?>

</body>
</html>