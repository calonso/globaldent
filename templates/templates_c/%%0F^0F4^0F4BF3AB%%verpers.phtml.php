<?php /* Smarty version 2.6.20, created on 2009-10-08 21:05:14
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/verpers.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/verpers.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/verpers.phtml', 3, false),array('modifier', 'count_characters', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/personal/verpers.phtml', 19, false),)), $this); ?>
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
      <span class="intro"><?php echo $this->_config[0]['vars']['texto34']; ?>
</span>
      <p><?php echo $this->_config[0]['vars']['texto35']; ?>
</p>
      <?php if (isset ( $this->_tpl_vars['datos'] )): ?>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto9']; ?>
</legend>
          <?php if (((is_array($_tmp=$this->_tpl_vars['datos']['extension'])) ? $this->_run_mod_handler('count_characters', true, $_tmp) : smarty_modifier_count_characters($_tmp)) > 0): ?>
          <div class="fotopers">
            <object data="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/fotoemp/<?php echo $this->_tpl_vars['datos']['id_personal']; ?>
/<?php echo $this->_tpl_vars['datos']['extension']; ?>
" type="image/<?php echo $this->_tpl_vars['datos']['extension']; ?>
" width="160px" height="160px">para abrir click aqui:
              <a href="<?php echo $this->_tpl_vars['req_base']; ?>
file.php/fotoemp/<?php echo $this->_tpl_vars['datos']['id_personal']; ?>
/<?php echo $this->_tpl_vars['datos']['extension']; ?>
">foto</a>
            </object>
          </div>
          <?php else: ?>
          <div class="fotopers">
            <img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
foto.jpg width="60" height="60">
          </div>
          <?php endif; ?>
          <p><?php echo $this->_config[0]['vars']['texto10']; ?>
<?php echo $this->_tpl_vars['datos']['nombre']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto11']; ?>
<?php echo $this->_tpl_vars['datos']['apellido']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto12']; ?>
<?php echo $this->_tpl_vars['datos']['apellido2']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto13']; ?>
<?php echo $this->_tpl_vars['datos']['dni']; ?>
</p><br />  
        </fieldset>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto15']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto16']; ?>
<?php echo $this->_tpl_vars['datos']['direccion']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto17']; ?>
<?php echo $this->_tpl_vars['datos']['cp']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto18']; ?>
<?php echo $this->_tpl_vars['datos']['ciudad']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto19']; ?>
<?php echo $this->_tpl_vars['datos']['provincia']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto22']; ?>
<?php echo $this->_tpl_vars['datos']['telefono']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto23']; ?>
<?php echo $this->_tpl_vars['datos']['movil']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto24']; ?>
<?php echo $this->_tpl_vars['datos']['email']; ?>
</p><br />
        </fieldset>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto92']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto67']; ?>
<?php echo $this->_tpl_vars['datos']['login']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto92']; ?>
:
          <?php if ($this->_tpl_vars['datos']['privilegios'] == 4): ?>
            <?php echo $this->_config[0]['vars']['texto95']; ?>
</p>
          <?php elseif ($this->_tpl_vars['datos']['privilegios'] == 5): ?>
            <?php echo $this->_config[0]['vars']['texto94']; ?>
</p>
          <?php elseif ($this->_tpl_vars['datos']['privilegios'] == 6): ?>
            <?php echo $this->_config[0]['vars']['texto93']; ?>
</p>
          <?php else: ?>
            <?php echo $this->_config[0]['vars']['texto96']; ?>
</p>
          <?php endif; ?>
        </fieldset>
        <fieldset><legend><?php echo $this->_config[0]['vars']['texto25']; ?>
</legend>
          <p><?php echo $this->_config[0]['vars']['texto26']; ?>
<?php echo $this->_tpl_vars['datos']['num_colegiado']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto27']; ?>
<?php echo $this->_tpl_vars['datos']['especialidad']; ?>
</p><br />
          <p><?php echo $this->_config[0]['vars']['texto28']; ?>
</p><br /><div class="texto"><?php echo $this->_tpl_vars['datos']['curriculum']; ?>
</div><br />
        </fieldset>
      <?php else: ?>
        <?php echo $this->_config[0]['vars']['texto36']; ?>

      <?php endif; ?>
  </div>
  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <?php if (isset ( $this->_tpl_vars['datos'] )): ?>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.actividademp/id.<?php echo $this->_tpl_vars['datos']['id_personal']; ?>
><?php echo $this->_config[0]['vars']['texto58']; ?>
</a></li>
      <?php if ($this->_tpl_vars['puedoModificar'] == 1): ?>
        <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.modemp/id.<?php echo $this->_tpl_vars['datos']['id_personal']; ?>
><?php echo $this->_config[0]['vars']['texto37']; ?>
</a></li>
        <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verModPassEmp/id.<?php echo $this->_tpl_vars['datos']['id_personal']; ?>
><?php echo $this->_config[0]['vars']['texto82']; ?>
</a></li>
      <?php endif; ?>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borraemp/id.<?php echo $this->_tpl_vars['datos']['id_personal']; ?>
><?php echo $this->_config[0]['vars']['texto38']; ?>
</a></li>
    <?php endif; ?>
    <?php if ($this->_tpl_vars['privilegios'] == 4): ?>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevoempleado><?php echo $this->_config[0]['vars']['texto2']; ?>
</a></li>
    <?php endif; ?>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.buscaempleados><?php echo $this->_config[0]['vars']['texto3']; ?>
</a></li>
    <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.listaempleados><?php echo $this->_config[0]['vars']['texto4']; ?>
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