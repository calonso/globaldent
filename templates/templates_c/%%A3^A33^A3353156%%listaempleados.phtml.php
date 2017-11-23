<?php /* Smarty version 2.6.20, created on 2009-10-08 21:04:49
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/listaempleados.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/listaempleados.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/listaempleados.phtml', 3, false),array('modifier', 'upper', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/listaempleados.phtml', 22, false),array('modifier', 'count_characters', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/listaempleados.phtml', 42, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'personal'), $this);?>


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
    <span class="intro"><?php echo $this->_config[0]['vars']['texto55']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['texto56']; ?>
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
index.php/cod.listaempleados/let.<?php echo $this->_tpl_vars['letra']; ?>
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
    <?php if (isset ( $this->_tpl_vars['datos'] )): ?>
    <div class="tablabusqueda">
      <?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['empleado']):
?>
        <div class="lineabusqueda">
          <div class="lineaopts">
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpers/id.<?php echo $this->_tpl_vars['empleado']['id_personal']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icover.ico alt="<?php echo $this->_config[0]['vars']['ver']; ?>
" title="<?php echo $this->_config[0]['vars']['ver']; ?>
" /></a>
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modemp/id.<?php echo $this->_tpl_vars['empleado']['id_personal']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoedit.png alt="<?php echo $this->_config[0]['vars']['modificar']; ?>
" title="<?php echo $this->_config[0]['vars']['modificar']; ?>
" /></a>
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borraemp/id.<?php echo $this->_tpl_vars['empleado']['id_personal']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoborrar.ico alt="<?php echo $this->_config[0]['vars']['borrar']; ?>
" title="<?php echo $this->_config[0]['vars']['borrar']; ?>
" height="16" width="16"/></a>
          </div>
          <?php if (((is_array($_tmp=$this->_tpl_vars['empleado']['extension'])) ? $this->_run_mod_handler('count_characters', true, $_tmp) : smarty_modifier_count_characters($_tmp)) > 0): ?>
          <div class="fotopers">
            <object data="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/fotoemp/<?php echo $this->_tpl_vars['empleado']['id_personal']; ?>
/<?php echo $this->_tpl_vars['empleado']['extension']; ?>
" type="image/<?php echo $this->_tpl_vars['empleado']['extension']; ?>
" width="60px" height="60px">para abrir click aqui:
              <a href="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/fotoemp/<?php echo $this->_tpl_vars['paciente']['id_personal']; ?>
/<?php echo $this->_tpl_vars['empleado']['extension']; ?>
">foto</a>
            </object>
          </div>
          <?php else: ?>
          <div class="fotopers">
            <img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
foto.jpg width="60" height="60">
          </div>
          <?php endif; ?>
          <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpers/id.<?php echo $this->_tpl_vars['empleado']['id_personal']; ?>
><?php echo $this->_tpl_vars['empleado']['apellido']; ?>
 <?php echo $this->_tpl_vars['empleado']['apellido2']; ?>
, <?php echo $this->_tpl_vars['empleado']['nombre']; ?>
</a>
        </div> 
      <?php endforeach; endif; unset($_from); ?>
    </div>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto57']; ?>
</p>
    <?php endif; ?>
  </div>
  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <?php if ($this->_tpl_vars['privilegios'] == 4): ?>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevoempleado><?php echo $this->_config[0]['vars']['texto2']; ?>
</a></li>
    <?php endif; ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.buscaempleados><?php echo $this->_config[0]['vars']['texto3']; ?>
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