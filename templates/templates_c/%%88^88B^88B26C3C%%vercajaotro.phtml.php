<?php /* Smarty version 2.6.20, created on 2009-10-08 21:09:18
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/vercajaotro.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/vercajaotro.phtml', 1, false),array('function', 'counter', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/vercajaotro.phtml', 24, false),array('function', 'math', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/vercajaotro.phtml', 49, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/conta/vercajaotro.phtml', 3, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'conta'), $this);?>


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
      <span class="intro"><?php echo $this->_config[0]['vars']['texto4']; ?>
<?php echo $this->_tpl_vars['dias']['hoy']; ?>
</span>
      <?php $this->assign('total_tarj', 0); ?>
      <?php $this->assign('total_efect', 0); ?>
      <?php if (is_array ( $this->_tpl_vars['visitas'] )): ?>
        <?php echo smarty_function_counter(array('assign' => 'total_vis','start' => 0,'skip' => 1), $this);?>

        <table border="0" cellspadding="0" cellspacing="2" width="100%">
          <tr>
            <th><?php echo $this->_config[0]['vars']['texto7']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto8']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto9']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto10']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto6']; ?>
</th>
          </tr>
          <tr>
            <td colspan="5">&nbsp;</td>
          </tr>
        <?php $_from = $this->_tpl_vars['visitas']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['visita']):
?>
          <?php $this->assign('linea', 0); ?>
          <tr>
            <td><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['visita']['id_paciente']; ?>
><?php echo $this->_tpl_vars['visita']['paciente']; ?>
</a></td>
            <td>
              <?php if (isset ( $this->_tpl_vars['visita']['tratamiento'] )): ?>
                <?php echo $this->_tpl_vars['visita']['tratamiento']; ?>

              <?php else: ?>
                <?php echo $this->_config[0]['vars']['texto24']; ?>

              <?php endif; ?>
            </td>
            <td class="pendiente" align="center"><?php echo $this->_tpl_vars['visita']['precio']; ?>
 €</td>
            <td align="center"><?php echo $this->_tpl_vars['visita']['pagos']['tarj']; ?>
/<?php echo $this->_tpl_vars['visita']['pagos']['efect']; ?>
</td>
            <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['visita']['pagos']['tarj'],'y' => $this->_tpl_vars['total_tarj'],'assign' => 'total_tarj'), $this);?>

            <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['visita']['pagos']['efect'],'y' => $this->_tpl_vars['total_efect'],'assign' => 'total_efect'), $this);?>

            <?php if ($this->_tpl_vars['visita']['saldo'] < 0): ?>
              <td align="center" class="pendiente"><?php echo $this->_tpl_vars['visita']['saldo']; ?>
</td>
            <?php else: ?>
              <td align="center"><?php echo $this->_tpl_vars['visita']['saldo']; ?>
</td>
            <?php endif; ?>
          </tr>
          <tr>
            <td colspan="5">&nbsp;</td>
          </tr>
          <?php echo smarty_function_counter(array(), $this);?>

        <?php endforeach; endif; unset($_from); ?>
        </table>
      <?php else: ?>
        <p><?php echo $this->_config[0]['vars']['texto5']; ?>
</p>
      <?php endif; ?>
      <?php if (is_array ( $this->_tpl_vars['pagos'] )): ?>
        <table border="0" cellspacing="2" cellspadding="0" width="98%">
          <tr>
            <th colspan="3"><?php echo $this->_config[0]['vars']['texto28']; ?>
</th>
          </tr>
          <tr>
            <th colspan="3" class="lineahor">&nbsp;</th>
          </tr>
          <tr>
            <th><?php echo $this->_config[0]['vars']['texto7']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto10']; ?>
</th>
            <th><?php echo $this->_config[0]['vars']['texto6']; ?>
</th>
          </tr>
          <?php $_from = $this->_tpl_vars['pagos']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['pago']):
?>
            <tr>
              <td><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpac/id.<?php echo $this->_tpl_vars['pago']['id_paciente']; ?>
><?php echo $this->_tpl_vars['pago']['paciente']; ?>
</a></td>
              <td align="center"><?php echo $this->_tpl_vars['pago']['tarj']; ?>
/<?php echo $this->_tpl_vars['pago']['efect']; ?>
</td>
              <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['pago']['tarj'],'y' => $this->_tpl_vars['total_tarj'],'assign' => 'total_tarj'), $this);?>

              <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['pago']['efect'],'y' => $this->_tpl_vars['total_efect'],'assign' => 'total_efect'), $this);?>

            <?php if ($this->_tpl_vars['pago']['saldo'] < 0): ?>
              <td align="center" class="pendiente"><?php echo $this->_tpl_vars['pago']['saldo']; ?>
</td>
            <?php else: ?>
              <td align="center"><?php echo $this->_tpl_vars['pago']['saldo']; ?>
</td>
            <?php endif; ?>
            </tr>
            <tr>
              <td colspan="3">&nbsp;</td>
            </tr>
          <?php endforeach; endif; unset($_from); ?>
        </table>
      <?php else: ?> 
        <p><?php echo $this->_config[0]['vars']['texto27']; ?>
</p>
      <?php endif; ?>
        <table border="0" cellspacing="2" width="98%"> 
          <tr>
            <td colspan="7">&nbsp;</td>
          </tr>
          <tr>
            <th colspan="7"><?php echo $this->_config[0]['vars']['texto14']; ?>
</th>
          </tr>
          <tr>
            <td colspan="7">&nbsp;</td>
          </tr>
          <tr>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto11']; ?>
</th>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto29']; ?>
</th>
            <th>&nbsp;</th>
            <th colspan="2"><?php echo $this->_config[0]['vars']['texto12']; ?>
</th>
          </tr>
          <tr>
            <td colspan="7">&nbsp;</td>
          </tr>
          <tr>
            <td colspan="2" align="center"><?php echo $this->_tpl_vars['total_vis']; ?>
</td>
            <td colspan="2" align="center"><?php echo $this->_tpl_vars['total_tarj']; ?>
 €</td>
            <td>&nbsp;</td>
            <td colspan="2" align="center"><?php echo $this->_tpl_vars['total_efect']; ?>
 €</td>
          </tr>
        </table>
        
    </div>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/recuadro_header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/recuadro_header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <div id="calendar-container" class="calendario"></div>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.vercaja/f.<?php echo $this->_tpl_vars['dias']['mannana']; ?>
><?php echo $this->_config[0]['vars']['texto19']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.vercaja><?php echo $this->_config[0]['vars']['texto20']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.vercaja/f.<?php echo $this->_tpl_vars['dias']['ayer']; ?>
><?php echo $this->_config[0]['vars']['texto21']; ?>
</a></li>
      <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.verpendientes><?php echo $this->_config[0]['vars']['texto22']; ?>
</a></li>
    <script type="text/javascript">
    <?php echo '
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
index.php/cod.vercaja/f." + d + "-" + m + "-" + y;
    <?php echo '
    }
    };
    Calendar.setup(
    {
    flat : "calendar-container", // ID of the parent element
    flatCallback : dateChanged, // our callback function
    date : "'; ?>
<?php echo $this->_tpl_vars['dias']['cal']; ?>
<?php echo '"
    }
    );
    '; ?>

    </script>
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