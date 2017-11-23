<?php /* Smarty version 2.6.20, created on 2009-10-08 21:03:39
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/log/verlog.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/log/verlog.phtml', 1, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/log/verlog.phtml', 40, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/log/verlog.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'log'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<style type="text/css">@import url(<?php echo $this->_tpl_vars['req_base']; ?>
js/calendario/estilos/calendar-system.css);</style>
<script type="text/javascript" src="<?php echo $this->_tpl_vars['req_base']; ?>
js/calendario/calendar.js"></script>
<script type="text/javascript" src="<?php echo $this->_tpl_vars['req_base']; ?>
js/calendario/calendar-es.js"></script>
<script type="text/javascript" src="<?php echo $this->_tpl_vars['req_base']; ?>
js/calendario/calendar-setup.js"></script>

  <script type="text/javascript">
  <!--
  <?php echo '
  function loaded(){}
  '; ?>
 
  // -->
  </script>

<div class="contenidos">
  <div class="col_central">
    <?php if ($this->_tpl_vars['numLineas'] > 0): ?>
      <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/pags.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/pags.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <?php $_from = $this->_tpl_vars['inlogs']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['linea']):
?>
        <p class="log_line"><?php echo $this->_tpl_vars['linea']['nom']; ?>
 <?php echo $this->_tpl_vars['linea']['apellido']; ?>
 <?php echo $this->_tpl_vars['linea']['apellido2']; ?>
 -> <?php echo $this->_tpl_vars['linea']['accion']; ?>
 <?php echo $this->_tpl_vars['linea']['detalles']; ?>
 a las <?php echo $this->_tpl_vars['linea']['fecha']; ?>
</p>
      <?php endforeach; endif; unset($_from); ?>
      <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/pags.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/pags.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <?php else: ?>
      Ningun registro
    <?php endif; ?>
  </div>


  <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
  <?php if (isset ( $this->_tpl_vars['logs'] )): ?>
        <form enctype="multipart/form-data" method="POST" action="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verlog">
        
          <p><?php echo $this->_config[0]['vars']['texto3']; ?>
</p>
        <?php if (isset ( $this->_tpl_vars['pers'] )): ?>
          <select name="selPers[]" multiple="multiple">
            <option label=<?php echo $this->_config[0]['vars']['texto3']; ?>
 value=0><?php echo $this->_config[0]['vars']['texto3']; ?>
</option>
            <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['pers'],'selected' => 0), $this);?>

          </select>
        <?php else: ?>
          <p><?php echo $this->_config[0]['vars']['texto4']; ?>
</p>
        <?php endif; ?><br />
        
        
          <p><?php echo $this->_config[0]['vars']['texto5']; ?>
</p>
          <select name="selTipos[]" multiple="multiple">
            <option label=<?php echo $this->_config[0]['vars']['texto5']; ?>
 value=0><?php echo $this->_config[0]['vars']['texto5']; ?>
</option>
            <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['logs'],'selected' => 0), $this);?>

          </select>
        
         <p><?php echo $this->_config[0]['vars']['texto7']; ?>

         <input type="text" name="fechaIni" />
         </p>
         
         <p><?php echo $this->_config[0]['vars']['texto8']; ?>

         <input type="text" name="fechaFin" />
         </p>
         
          <input type="submit" value=<?php echo $this->_config[0]['vars']['texto9']; ?>
 />
        </form>
      </div>
      
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto6']; ?>
</p>
    <?php endif; ?>
  
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