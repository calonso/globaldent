<?php /* Smarty version 2.6.20, created on 2009-06-18 17:22:50
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/common/header.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/common/header.phtml', 22, false),)), $this); ?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
	<title><?php echo $this->_config[0]['vars']['tituloapp']; ?>
</title>
	<link href="<?php echo $this->_tpl_vars['req_base']; ?>
css/estilos_aplicacion.css" rel="stylesheet" type="text/css" />
	<link rel="shortcut icon" href="<?php echo $this->_tpl_vars['img_path_base']; ?>
favicon.ico" />
	<script language="JavaScript" src="<?php echo $this->_tpl_vars['req_base']; ?>
js/gen_validatorv31.js" type="text/javascript"></script>
	<script language="JavaScript" src="<?php echo $this->_tpl_vars['req_base']; ?>
js/utils.js" type="text/javascript"></script>
</head>

<body onLoad="loaded()">
	<div class="cabecera" >
	<img class="obj" src="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/logo" width="220" height="150" />
	<p><?php echo $this->_config[0]['vars']['textoheaderapp']; ?>
</p>
    <p><?php echo $this->_tpl_vars['fecha']; ?>
</p>
	</div>
	<div class="salir">
	 <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.logout><img class="salir" src="<?php echo $this->_tpl_vars['img_path_base']; ?>
btn_salir.jpg" alt="Salir" /></a>
	</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/navbar.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/navbar.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>