<?php /* Smarty version 2.6.20, created on 2009-10-08 20:32:33
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/dres/listadr.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/dres/listadr.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/dres/listadr.phtml', 3, false),array('modifier', 'upper', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/dres/listadr.phtml', 22, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'dres'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

  <script type="text/javascript">
  <!--
  <?php echo '
  function loaded(){}
  '; ?>
 
  // -->
  </script>

<div class="contenidos">
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto40']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['texto41']; ?>
</p>
    <div class="letras">
      <ul>
        <?php $_from = $this->_tpl_vars['todas']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['letra']):
?>
          <?php $this->assign('encontrada', 0); ?>
          <?php $_from = $this->_tpl_vars['letras']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['valida']):
?>
            <?php if (((is_array($_tmp=$this->_tpl_vars['valida'])) ? $this->_run_mod_handler('upper', true, $_tmp) : smarty_modifier_upper($_tmp)) == $this->_tpl_vars['letra']): ?>
              <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.listadr/let.<?php echo $this->_tpl_vars['letra']; ?>
><?php echo $this->_tpl_vars['letra']; ?>
</a></li>
              <?php $this->assign('encontrada', 1); ?>
            <?php endif; ?>
          <?php endforeach; endif; unset($_from); ?>
          <?php if ($this->_tpl_vars['encontrada'] == 0): ?>
            <li><?php echo $this->_tpl_vars['letra']; ?>
</li>
          <?php endif; ?>
        <?php endforeach; endif; unset($_from); ?>
      </ul>
    </div>
    <?php if ($this->_tpl_vars['codigo'] != 0): ?>
    <div class="tablabusqueda">
      <?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['doctor']):
?>
        <div class="lineabusqueda">
          <div class="lineaopts">
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verdr/id.<?php echo $this->_tpl_vars['doctor']['id_dr_externo']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icover.ico alt="<?php echo $this->_config[0]['vars']['ver']; ?>
" title="<?php echo $this->_config[0]['vars']['ver']; ?>
" /></a>
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.moddr/id.<?php echo $this->_tpl_vars['doctor']['id_dr_externo']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoedit.png alt="<?php echo $this->_config[0]['vars']['modificar']; ?>
" title="<?php echo $this->_config[0]['vars']['modificar']; ?>
" /></a>
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borrardr/id.<?php echo $this->_tpl_vars['doctor']['id_dr_externo']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoborrar.ico alt="<?php echo $this->_config[0]['vars']['borrar']; ?>
" title="<?php echo $this->_config[0]['vars']['borrar']; ?>
" height="16" width="16"/></a>
          </div>
          <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verdr/id.<?php echo $this->_tpl_vars['doctor']['id_dr_externo']; ?>
><?php echo $this->_tpl_vars['doctor']['apellido']; ?>
 <?php echo $this->_tpl_vars['doctor']['apellido2']; ?>
, <?php echo $this->_tpl_vars['doctor']['nombre']; ?>
</a>
        </div> 
      <?php endforeach; endif; unset($_from); ?>
    </div>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto42']; ?>
</p>
    <?php endif; ?>
  </div>
  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevodr><?php echo $this->_config[0]['vars']['texto2']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.buscadr><?php echo $this->_config[0]['vars']['texto31']; ?>
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