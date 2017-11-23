<?php /* Smarty version 2.6.20, created on 2009-06-20 19:13:28
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/listapacientes.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/listapacientes.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/listapacientes.phtml', 3, false),array('modifier', 'upper', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/listapacientes.phtml', 33, false),array('modifier', 'count_characters', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/listapacientes.phtml', 54, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'pacientes'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript">
<!--
<?php echo '
function confirmar(id)
{
  '; ?>

  var enlace = "<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borrapac/id." + id;
  var x = confirm ("<?php echo $this->_config[0]['vars']['texto75']; ?>
");
  <?php echo '
  if (x == true)
  {
    location.href = enlace;
  }
}
function loaded(){}
'; ?>

-->
</script>

<div class="contenidos">
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto58']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['texto59']; ?>
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
index.php/cod.listapacientes/let.<?php echo $this->_tpl_vars['letra']; ?>
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
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/pags.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/pags.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <div class="tablabusqueda">
      <?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['paciente']):
?>
        <div class="lineabusqueda">
          <div class="lineaopts">
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icover.ico alt="<?php echo $this->_config[0]['vars']['ver']; ?>
" title="<?php echo $this->_config[0]['vars']['ver']; ?>
" /></a>
            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modpac/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoedit.png alt="<?php echo $this->_config[0]['vars']['modificar']; ?>
" title="<?php echo $this->_config[0]['vars']['modificar']; ?>
" /></a>
            <img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoborrar.ico alt="<?php echo $this->_config[0]['vars']['borrar']; ?>
" title="<?php echo $this->_config[0]['vars']['borrar']; ?>
" height="16" width="16" onclick="confirmar(<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
)"/>
          </div>
          <?php if (((is_array($_tmp=$this->_tpl_vars['paciente']['extension'])) ? $this->_run_mod_handler('count_characters', true, $_tmp) : smarty_modifier_count_characters($_tmp)) > 0): ?>
          <div class="fotopers">
            <object data="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/fotopers/<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/<?php echo $this->_tpl_vars['paciente']['extension']; ?>
" type="image/<?php echo $this->_tpl_vars['paciente']['extension']; ?>
" width="60px" height="60px">para abrir click aqui:
              <a href="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/fotopers/<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/<?php echo $this->_tpl_vars['paciente']['extension']; ?>
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
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
><?php echo $this->_tpl_vars['paciente']['apellido']; ?>
 <?php echo $this->_tpl_vars['paciente']['apellido2']; ?>
, <?php echo $this->_tpl_vars['paciente']['nombre']; ?>
</a>
        </div> 
      <?php endforeach; endif; unset($_from); ?>
    </div>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/pags.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/pags.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto60']; ?>
</p>
    <?php endif; ?>
  </div>
  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevopaciente><?php echo $this->_config[0]['vars']['texto2']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.buscapacientes><?php echo $this->_config[0]['vars']['texto3']; ?>
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