<?php /* Smarty version 2.6.20, created on 2009-06-18 17:22:13
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/common/header.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/common/header.phtml', 33, false),)), $this); ?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
	<title><?php echo $this->_config[0]['vars']['titulopagina']; ?>
</title>
	<link href="<?php echo $this->_tpl_vars['req_base']; ?>
css/estilos_portal.css" rel="stylesheet" type="text/css" />
	<link rel="shortcut icon" href="<?php echo $this->_tpl_vars['img_path_base']; ?>
favicon.ico" />
</head>

<body>
	<div class="cabecera">
		<table border="0" cellpadding="0" cellspacing="0">
			<tr>
				<td rowspan="2" width="900px">
					<img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
logo_gbd.jpg" alt="Logo GlobalDent" width="700" height="150"/>
				</td>
				<td align="center">
				  <?php if ($this->_tpl_vars['autenticado'] == 1): ?>
				    <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.logout><img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
btn_logout.jpg" alt="Logout" width="200" height="50" /></a>
				  <?php else: ?>
					 <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.login><img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
btn_usuarios.jpg" alt="Acceso Usuarios" width="200" height="50" /></a>
					<?php endif; ?>
				</td>
			</tr>
			<tr>
				<td align="center">
					<a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.loginapp><img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
btn_clinicas.jpg" alt="Acceso Clinicas" width="200" height="50"  /></a>
				</td>
			</tr>
		</table>
	</div>
	
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "common/navbar.phtml") : smarty_modifier_cat($_tmp, "common/navbar.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>