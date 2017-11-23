<?php /* Smarty version 2.6.20, created on 2009-10-13 19:39:13
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/abrirvisita.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/abrirvisita.phtml', 1, false),array('function', 'counter', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/abrirvisita.phtml', 103, false),array('function', 'math', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/abrirvisita.phtml', 115, false),array('function', 'html_options', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/abrirvisita.phtml', 123, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/abrirvisita.phtml', 3, false),array('modifier', 'regex_replace', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/abrirvisita.phtml', 79, false),array('modifier', 'default', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/visitas/abrirvisita.phtml', 108, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'visitas'), $this);?>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/header.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/header.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

<script type="text/javascript" src="<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/fckeditor.js"></script>
<script type="text/javascript">
<?php echo '
<!--
function FCKeditor_OnComplete( editorInstance )
{
	editorInstance.Events.AttachEvent( \'OnBlur\'	, FCKeditor_OnBlur ) ;
	editorInstance.Events.AttachEvent( \'OnFocus\', FCKeditor_OnFocus ) ;
}

function FCKeditor_OnBlur( editorInstance )
{
	editorInstance.ToolbarSet.Collapse() ;
}

function FCKeditor_OnFocus( editorInstance )
{
	editorInstance.ToolbarSet.Expand() ;
}
function borrar(num)
{
  var x = document.getElementById ("formulario");
  //'; ?>

  x.action = "<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borralineav/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
/num." + num;
  //<?php echo '
  x.submit();
}
function linea()
{
  var x = document.getElementById ("formulario");
  '; ?>

    x.action = "<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevalineav/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
";
  <?php echo '
    x.submit();
}
function fsa ()
{
	var x = document.getElementById ("formulario");
	'; ?>

    x.action = "<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.fsa/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
";
  <?php echo '
    x.submit();
}
function servicio()
{
  var x = document.getElementsByName ("txtUnitario");
  var y = document.getElementsByName ("selServicio");
  var txt = y[0].options[y[0].selectedIndex].text;
  var primero = txt.lastIndexOf ("-");
  primero += 2;
  var ultimo = txt.lastIndexOf ("€");
  var cadena = txt.slice (primero, ultimo);
  x[0].value= cadena ;  
}
function loaded(){}
-->
'; ?>

</script>

<div class="contenidos">
  <div class="col_izq">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto10']; ?>
</span>
    <p><?php echo $this->_config[0]['vars']['texto11']; ?>
</p>
  </div>
  <div class="col_central">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto12']; ?>
</span>
    <?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/visitas/pac_info.phtml") : smarty_modifier_cat($_tmp, "gbdapp/visitas/pac_info.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
    <p><?php echo $this->_config[0]['vars']['texto13']; ?>
</p>
    <form id="formulario" enctype="multipart/form-data" method="POST" action="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevavisita/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
">
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto14']; ?>
</legend>
        <p><?php echo $this->_config[0]['vars']['texto16']; ?>
</p><input type="text" name="txtAsiento" value="<?php echo $this->_tpl_vars['datos']['asiento']; ?>
"/>
        <input type="button" value="<?php echo $this->_config[0]['vars']['texto90']; ?>
" onclick="fsa()"><br />
        <p><?php echo $this->_config[0]['vars']['texto17']; ?>
</p>
          <script type="text/javascript">
            var oFCKeditor = new FCKeditor('txtMotivo','100%','200','MyToolbar','<?php echo ((is_array($_tmp=$this->_tpl_vars['datos']['motivo'])) ? $this->_run_mod_handler('regex_replace', true, $_tmp, "/[\r\n]/", "") : smarty_modifier_regex_replace($_tmp, "/[\r\n]/", "")); ?>
');
            oFCKeditor.BasePath = "<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/";
            oFCKeditor.Config['ToolbarStartExpanded'] = false ;
            oFCKeditor.Create();
          </script><br />
        <p><?php echo $this->_config[0]['vars']['texto18']; ?>
</p>
          <script type="text/javascript">
            var oFCKeditor1 = new FCKeditor('txtDiag','100%','200','MyToolbar','<?php echo ((is_array($_tmp=$this->_tpl_vars['datos']['diagnostico'])) ? $this->_run_mod_handler('regex_replace', true, $_tmp, "/[\r\n]/", "") : smarty_modifier_regex_replace($_tmp, "/[\r\n]/", "")); ?>
');
            oFCKeditor1.BasePath = "<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/";
            oFCKeditor1.Config['ToolbarStartExpanded'] = false ;
            oFCKeditor1.Create();
          </script><br />
        <p><?php echo $this->_config[0]['vars']['texto19']; ?>
</p>
            <table border="0" width="98%">
              <tr>
                <th colspan="2"><?php echo $this->_config[0]['vars']['texto66']; ?>
</th>
                <th><?php echo $this->_config[0]['vars']['texto72']; ?>
</th>
                <th><?php echo $this->_config[0]['vars']['texto67']; ?>
</th>
                <th><?php echo $this->_config[0]['vars']['texto68']; ?>
</th>
                <th>&nbsp;</th>
              </tr>
              <tr>
                <th colspan="5" class="lineahor">&nbsp;</th>
              </tr>
              <?php echo smarty_function_counter(array('assign' => 'numlinea','start' => 1,'skip' => 1), $this);?>

              <?php $this->assign('total', 0); ?>
                <?php if (is_array ( $this->_tpl_vars['lineas'] )): ?>
                  <?php $_from = $this->_tpl_vars['lineas']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['llave'] => $this->_tpl_vars['linea']):
?>
                    <tr>
                      <td colspan="2"><?php echo $this->_tpl_vars['numlinea']; ?>
.&nbsp;<?php echo ((is_array($_tmp=@$this->_tpl_vars['linea']['servicio'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_config[0]['vars']['texto57']) : smarty_modifier_default($_tmp, @$this->_config[0]['vars']['texto57'])); ?>
</td>
                      <td align="center"><?php echo $this->_tpl_vars['linea']['unitario']; ?>
</td>
                      <td align="center"><?php echo $this->_tpl_vars['linea']['cantidad']; ?>
</td>
                      <td align="right"><?php echo $this->_tpl_vars['linea']['total']; ?>
 €.</td>
                      <td><input type="button" value="<?php echo $this->_config[0]['vars']['borrar']; ?>
" onclick="borrar(<?php echo $this->_tpl_vars['llave']; ?>
)">
                    </tr>
                  <?php echo smarty_function_counter(array(), $this);?>

                  <?php echo smarty_function_math(array('equation' => "x + y",'x' => $this->_tpl_vars['total'],'y' => $this->_tpl_vars['linea']['total'],'assign' => 'total'), $this);?>

                  <?php endforeach; endif; unset($_from); ?>
                <?php endif; ?>
              <tr>
                <td colspan="2"><?php echo $this->_tpl_vars['numlinea']; ?>
.&nbsp;
                  <?php if (is_array ( $this->_tpl_vars['servicios'] )): ?>
                    <select name="selServicio" onchange="servicio()">
                      <option label="<?php echo $this->_config[0]['vars']['texto45']; ?>
" value=0><?php echo $this->_config[0]['vars']['texto45']; ?>
</option>
                      <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['servicios'],'selected' => 0), $this);?>

                    </select>
                  <?php else: ?>
                    <?php echo $this->_config[0]['vars']['texto43']; ?>

                    <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.servicios><?php echo $this->_config[0]['vars']['texto44']; ?>
</a>
                  <?php endif; ?>
                </td>
                <td><input type="text" name="txtUnitario"></td>
                <td><input type="text" name="txtCuantos" value="1"></td>
                <td><input type="button" value="<?php echo $this->_config[0]['vars']['aceptar']; ?>
" onclick="linea()"/></td>
              </tr>
              <tr>
                <td colspan="5" class="lineahor">&nbsp;</td>
              </tr>
              <tr>
                <th colspan="3" align="center"><?php echo $this->_config[0]['vars']['texto68']; ?>
</th>
                <th><?php echo $this->_tpl_vars['total']; ?>
 €.</th>
                <th>&nbsp;</th>
              </tr>
            </table>
        <br />
        <p><?php echo $this->_config[0]['vars']['texto20']; ?>
</p>
        <script type="text/javascript">
          var oFCKeditor2 = new FCKeditor('txtObservaciones','100%','200','MyToolbar','<?php echo ((is_array($_tmp=$this->_tpl_vars['datos']['observaciones'])) ? $this->_run_mod_handler('regex_replace', true, $_tmp, "/[\r\n]/", "") : smarty_modifier_regex_replace($_tmp, "/[\r\n]/", "")); ?>
');
          oFCKeditor2.BasePath = "<?php echo $this->_tpl_vars['req_base']; ?>
js/fckeditor/";
          oFCKeditor2.Config['ToolbarStartExpanded'] = false ;
          oFCKeditor2.Create();
        </script><br />
    </fieldset>
      <fieldset><legend><?php echo $this->_config[0]['vars']['texto46']; ?>
</legend>
        <p><?php echo $this->_config[0]['vars']['texto47']; ?>
</p>
          <?php if (is_array ( $this->_tpl_vars['pers'] )): ?>
            <select name="selPers[]" multiple="multiple">
              <option label="<?php echo $this->_config[0]['vars']['texto48']; ?>
" value=0><?php echo $this->_config[0]['vars']['texto48']; ?>
</option>
              <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['pers'],'selected' => 0), $this);?>

            </select>
          <?php else: ?>
            <p><?php echo $this->_config[0]['vars']['texto49']; ?>
 <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevoempleado><?php echo $this->_config[0]['vars']['texto50']; ?>
</a></p>
          <?php endif; ?>
        <br />
        <p><?php echo $this->_config[0]['vars']['texto51']; ?>
</p>
          <?php if (is_array ( $this->_tpl_vars['dres'] )): ?>
            <select name="selDres[]" multiple="multiple">
              <option label="<?php echo $this->_config[0]['vars']['texto52']; ?>
" value=0><?php echo $this->_config[0]['vars']['texto52']; ?>
</option>
              <?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['dres'],'selected' => 0), $this);?>

            </select>
          <?php else: ?>
            <p><?php echo $this->_config[0]['vars']['texto53']; ?>
 <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.nuevodr><?php echo $this->_config[0]['vars']['texto54']; ?>
</a></p>
          <?php endif; ?>
        <br />
        <p><?php echo $this->_config[0]['vars']['texto55']; ?>
</p>
      </fieldset>
      <input type="hidden" name="txtPrecio" value=<?php echo $this->_tpl_vars['total']; ?>
 />
      <input type="submit" value=<?php echo $this->_config[0]['vars']['aceptar']; ?>
 />
      <input type="reset" value=<?php echo $this->_config[0]['vars']['borrar']; ?>
 />
      <input type="button" value=<?php echo $this->_config[0]['vars']['cancelar']; ?>
 onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.pacientes'" />
    </form>
  </div>

</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>