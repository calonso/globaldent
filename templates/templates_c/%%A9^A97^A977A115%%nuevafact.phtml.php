<?php /* Smarty version 2.6.20, created on 2009-11-01 11:36:57
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/nuevafact.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/nuevafact.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/nuevafact.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'facturas'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script language="JavaScript" src="<?php echo $this->_tpl_vars['req_base']; ?>
js/TableManager.js" type="text/javascript"></script>

<script type="text/javascript">
var tableManager;
var services = [
    <?php $_from = $this->_tpl_vars['servicios']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['key'] => $this->_tpl_vars['service']):
?>
         new Option("<?php echo $this->_tpl_vars['service']; ?>
", "<?php echo $this->_tpl_vars['key']; ?>
"),
    <?php endforeach; endif; unset($_from); ?>
    ];
<?php echo '
<!--
function loaded(){
    tableManager = new TableManager(services, \'formTable\', \'formulario\', \'numLines\', \'total\');
}
'; ?>

</script>

<div class="contenidos">
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto7']; ?>
</span>
    <form id="formulario" enctype="multipart/form-data" method="POST" action=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.guardafact/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/facturas/cabecera.phtml") : smarty_modifier_cat($_tmp, "gbdapp/facturas/cabecera.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/facturas/formTable.phtml") : smarty_modifier_cat($_tmp, "gbdapp/facturas/formTable.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    </form>
  </div>
</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>