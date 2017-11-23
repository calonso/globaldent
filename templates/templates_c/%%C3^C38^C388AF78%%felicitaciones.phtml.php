<?php /* Smarty version 2.6.20, created on 2009-11-04 19:59:17
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/felicitaciones.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/felicitaciones.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/felicitaciones.phtml', 3, false),array('modifier', 'count_characters', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/pacientes/felicitaciones.phtml', 12, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'pacientes'), $this);?>


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
var emails = [
<?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['pac']):
?>
    <?php if (((is_array($_tmp=$this->_tpl_vars['pac']['email'])) ? $this->_run_mod_handler('count_characters', true, $_tmp) : smarty_modifier_count_characters($_tmp)) > 0): ?>
        "<?php echo $this->_tpl_vars['pac']['email']; ?>
",
    <?php endif; ?> 
<?php endforeach; endif; unset($_from); ?>
];
  <!--
  <?php echo '

  function multiple() {
	    for (var i = 0 ; i < emails.length ; ++i) {
	    	var mailto_link = \'mailto:\' + emails[i];
	    	var win = window.open(mailto_link,\'emailWindow\');
	    	if (win && win.open &&!win.closed) win.close();
	    }
  }
  
  function dateChanged(calendar) {
      // Beware that this function is called even if the end-user only
      // changed the month/year. In order to determine if a date was
      // clicked you can use the dateClicked property of the calendar:
      if (calendar.dateClicked) {
      // OK, a date was clicked, redirect to /yyyy/mm/dd/index.php
          var y = calendar.date.getFullYear();
          var m = calendar.date.getMonth(); // integer, 0..11
          m = m+1;
          var d = calendar.date.getDate(); // integer, 1..31
          // redirect...
          '; ?>

          document.location = "<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.felicitaciones/date." + d + "-" + m + "-" + y;
          <?php echo '
          //window.location = "/" + y + "/" + m + "/" + d + "/index.php";
      }
  }
		  

  function loaded(){
	  Calendar.setup(
			  {
			    flat         : "calendar-container", // ID of the parent element
			    flatCallback : dateChanged           // our callback function
			  }
			  );}
  '; ?>
 
  // -->
  </script>

  <div class="contenidos">
    <div class="col_central">
    <?php if (is_array ( $this->_tpl_vars['datos'] )): ?>
        <table border="0" width="100%">
            <tr>
                <th><?php echo $this->_config[0]['vars']['texto90']; ?>
</th>
                <th><?php echo $this->_config[0]['vars']['texto26']; ?>
</th>
            </tr>
            <?php $_from = $this->_tpl_vars['datos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['pac']):
?>
            <tr>
                <td><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['pac']['id_paciente']; ?>
><?php echo $this->_tpl_vars['pac']['apellido']; ?>
 <?php echo $this->_tpl_vars['pac']['apellido2']; ?>
, <?php echo $this->_tpl_vars['pac']['nombre']; ?>
</a></td>
                <?php if (((is_array($_tmp=$this->_tpl_vars['pac']['email'])) ? $this->_run_mod_handler('count_characters', true, $_tmp) : smarty_modifier_count_characters($_tmp)) > 0): ?>
                    <td><a href="mailto:<?php echo $this->_tpl_vars['pac']['email']; ?>
"><?php echo $this->_config[0]['vars']['texto92']; ?>
</a></td>
                <?php else: ?>
                    <td><?php echo $this->_config[0]['vars']['texto91']; ?>
</td>
                <?php endif; ?>
            </tr>    
            <?php endforeach; endif; unset($_from); ?>
        </table>
    <?php else: ?>
        <p><?php echo $this->_config[0]['vars']['texto43']; ?>
</p>    
    <?php endif; ?>
    <input type="button" value="<?php echo $this->_config[0]['vars']['texto94']; ?>
" onclick="multiple()" />
    </div>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <li><?php echo $this->_config[0]['vars']['texto93']; ?>
</li>
      <li><div id="calendar-container"></div></li>
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