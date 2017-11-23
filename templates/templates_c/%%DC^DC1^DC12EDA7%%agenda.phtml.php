<?php /* Smarty version 2.6.20, created on 2009-10-14 19:54:41
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/agenda/agenda.phtml */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'config_load', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/agenda/agenda.phtml', 1, false),array('modifier', 'cat', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/agenda/agenda.phtml', 3, false),array('modifier', 'regex_replace', 'C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/agenda/agenda.phtml', 151, false),)), $this); ?>
<?php echo smarty_function_config_load(array('file' => $this->_tpl_vars['lang_file'],'section' => 'agenda'), $this);?>


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
var patron = new RegExp("bloqagenda");
var patron2 = new RegExp ("desbloqagenda");
if (patron.test(location.href) || patron2.test(location.href))
  location.href= "<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.agenda";
<?php if (isset ( $this->_tpl_vars['bloqueado'] ) && $this->_tpl_vars['bloqueado'] == false): ?>
  alert("Elimine primero las citas dadas para bloquear.");
<?php endif; ?>
<?php echo '
function confirmar(id)
{
  '; ?>

  var enlace = "<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borrarcita/id." + id;
  var x = confirm ("<?php echo $this->_config[0]['vars']['texto24']; ?>
");
  <?php echo '
  if (x == true)
  {
    location.href = enlace;
  }
}
function abrir()
{
  window.open(location.href + "/imp.1");
}

function cerrar(e)
{
      	element = document.getElementById(e).style;
      	if(element.visibility == \'\'){
      		element.visibility = \'visible\';
      	} else {
			element.visibility == \'hidden\' ? element.visibility = \'visible\' : 
				element.visibility=\'hidden\';
		}    
}
var calendario = Calendar(1, "'; ?>
<?php echo $this->_tpl_vars['dias']['cal']; ?>
<?php echo '", dateChanged, onClose);

function onClose(){
	calendar.hide();
}

function calendar(){
	calendario = calendar.create();
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
index.php/cod.agenda/dia." + d + "-" + m + "-" + y;
    	<?php echo '
    	//window.location = "/" + y + "/" + m + "/" + d + "/index.php";
    }
}

function loaded(){}
//-->
</script>
'; ?>


<div class="contenidos">
    <span class="intro"><?php echo $this->_config[0]['vars']['texto1']; ?>
 <?php echo $this->_tpl_vars['dias']['hoy']; ?>
</span>
    <br /><br />
    <?php if ($this->_tpl_vars['gabinetes'] > 0): ?>
    <div class="pasar">	
    	<ul>
    		<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.agenda/dia.<?php echo $this->_tpl_vars['dias']['ayer']; ?>
>&lt;&lt;<?php echo $this->_config[0]['vars']['texto3']; ?>
</a></li>
    		<li><a id="show_d" href="javascript:calendar()">Calendario</a></li>
    		<li><a href="javascript:abrir();">Imprimir</a></li>
    		<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.agenda/dia.<?php echo $this->_tpl_vars['dias']['mannana']; ?>
><?php echo $this->_config[0]['vars']['texto2']; ?>
&gt;&gt;</a></li>
    	</ul>
    </div>
    <table border="3" cellspacing="3" cellpadding="1" width="1000px">
      <tr>
        <td>&nbsp;</td>
        <?php unset($this->_sections['numerogab']);
$this->_sections['numerogab']['name'] = 'numerogab';
$this->_sections['numerogab']['loop'] = is_array($_loop=$this->_tpl_vars['gabinetes']) ? count($_loop) : max(0, (int)$_loop); unset($_loop);
$this->_sections['numerogab']['start'] = (int)1;
$this->_sections['numerogab']['show'] = true;
$this->_sections['numerogab']['max'] = $this->_sections['numerogab']['loop'];
$this->_sections['numerogab']['step'] = 1;
if ($this->_sections['numerogab']['start'] < 0)
    $this->_sections['numerogab']['start'] = max($this->_sections['numerogab']['step'] > 0 ? 0 : -1, $this->_sections['numerogab']['loop'] + $this->_sections['numerogab']['start']);
else
    $this->_sections['numerogab']['start'] = min($this->_sections['numerogab']['start'], $this->_sections['numerogab']['step'] > 0 ? $this->_sections['numerogab']['loop'] : $this->_sections['numerogab']['loop']-1);
if ($this->_sections['numerogab']['show']) {
    $this->_sections['numerogab']['total'] = min(ceil(($this->_sections['numerogab']['step'] > 0 ? $this->_sections['numerogab']['loop'] - $this->_sections['numerogab']['start'] : $this->_sections['numerogab']['start']+1)/abs($this->_sections['numerogab']['step'])), $this->_sections['numerogab']['max']);
    if ($this->_sections['numerogab']['total'] == 0)
        $this->_sections['numerogab']['show'] = false;
} else
    $this->_sections['numerogab']['total'] = 0;
if ($this->_sections['numerogab']['show']):

            for ($this->_sections['numerogab']['index'] = $this->_sections['numerogab']['start'], $this->_sections['numerogab']['iteration'] = 1;
                 $this->_sections['numerogab']['iteration'] <= $this->_sections['numerogab']['total'];
                 $this->_sections['numerogab']['index'] += $this->_sections['numerogab']['step'], $this->_sections['numerogab']['iteration']++):
$this->_sections['numerogab']['rownum'] = $this->_sections['numerogab']['iteration'];
$this->_sections['numerogab']['index_prev'] = $this->_sections['numerogab']['index'] - $this->_sections['numerogab']['step'];
$this->_sections['numerogab']['index_next'] = $this->_sections['numerogab']['index'] + $this->_sections['numerogab']['step'];
$this->_sections['numerogab']['first']      = ($this->_sections['numerogab']['iteration'] == 1);
$this->_sections['numerogab']['last']       = ($this->_sections['numerogab']['iteration'] == $this->_sections['numerogab']['total']);
?>
        <td>
          <?php $this->assign('ind', $this->_sections['numerogab']['index']); ?>
          <a href="javascript:cerrar('<?php echo ((is_array($_tmp=$this->_tpl_vars['ind'])) ? $this->_run_mod_handler('cat', true, $_tmp, 'gab') : smarty_modifier_cat($_tmp, 'gab')); ?>
');"><?php echo $this->_config[0]['vars']['gabinete']; ?>
<?php echo $this->_tpl_vars['ind']; ?>
</a>
          
          <div class="menu" id="<?php echo ((is_array($_tmp=$this->_tpl_vars['ind'])) ? $this->_run_mod_handler('cat', true, $_tmp, 'gab') : smarty_modifier_cat($_tmp, 'gab')); ?>
">
          	<ul>
          		<li><p>Gabinete <?php echo $this->_tpl_vars['ind']; ?>
</p></li>
            	<li>
            	  <?php if ($this->_tpl_vars['bloqueos'][$this->_tpl_vars['ind']]['AM'] >= 1): ?>
		            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.desbloqagenda/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/p.1/a.<?php echo $this->_sections['numerogab']['index']; ?>
/id.<?php echo $this->_tpl_vars['bloqueos'][$this->_tpl_vars['ind']]['AM']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
clock_am.jpg title="<?php echo $this->_config[0]['vars']['texto35']; ?>
"></a> 
		          <?php else: ?>
		            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.bloqagenda/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/p.1/a.<?php echo $this->_sections['numerogab']['index']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
clock_no_am.jpg title="<?php echo $this->_config[0]['vars']['texto34']; ?>
"></a>
		          <?php endif; ?>
		          <?php if ($this->_tpl_vars['bloqueos'][$this->_tpl_vars['ind']]['PM'] >= 1): ?>
		            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.desbloqagenda/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/p.2/a.<?php echo $this->_sections['numerogab']['index']; ?>
/id.<?php echo $this->_tpl_vars['bloqueos'][$this->_tpl_vars['ind']]['PM']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
clock_pm.jpg title="<?php echo $this->_config[0]['vars']['texto37']; ?>
"></a> 
		          <?php else: ?>
		            <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.bloqagenda/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/p.2/a.<?php echo $this->_sections['numerogab']['index']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
clock_no_pm.jpg title="<?php echo $this->_config[0]['vars']['texto36']; ?>
"></a>
		          <?php endif; ?>
            	</li>
            	<li><a href="javascript:cerrar('<?php echo ((is_array($_tmp=$this->_tpl_vars['ind'])) ? $this->_run_mod_handler('cat', true, $_tmp, 'gab') : smarty_modifier_cat($_tmp, 'gab')); ?>
');">Cerrar</a></li>
            </ul>
         </div>
        </td>
        <?php endfor; endif; ?>
      </tr>
    <?php $_from = $this->_tpl_vars['horas']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['i'] => $this->_tpl_vars['hora']):
?>
      <tr>
        <td>
          <?php echo $this->_tpl_vars['hora']; ?>

        </td>
        <?php unset($this->_sections['asiento']);
$this->_sections['asiento']['name'] = 'asiento';
$this->_sections['asiento']['loop'] = is_array($_loop=$this->_tpl_vars['gabinetes']) ? count($_loop) : max(0, (int)$_loop); unset($_loop);
$this->_sections['asiento']['start'] = (int)1;
$this->_sections['asiento']['show'] = true;
$this->_sections['asiento']['max'] = $this->_sections['asiento']['loop'];
$this->_sections['asiento']['step'] = 1;
if ($this->_sections['asiento']['start'] < 0)
    $this->_sections['asiento']['start'] = max($this->_sections['asiento']['step'] > 0 ? 0 : -1, $this->_sections['asiento']['loop'] + $this->_sections['asiento']['start']);
else
    $this->_sections['asiento']['start'] = min($this->_sections['asiento']['start'], $this->_sections['asiento']['step'] > 0 ? $this->_sections['asiento']['loop'] : $this->_sections['asiento']['loop']-1);
if ($this->_sections['asiento']['show']) {
    $this->_sections['asiento']['total'] = min(ceil(($this->_sections['asiento']['step'] > 0 ? $this->_sections['asiento']['loop'] - $this->_sections['asiento']['start'] : $this->_sections['asiento']['start']+1)/abs($this->_sections['asiento']['step'])), $this->_sections['asiento']['max']);
    if ($this->_sections['asiento']['total'] == 0)
        $this->_sections['asiento']['show'] = false;
} else
    $this->_sections['asiento']['total'] = 0;
if ($this->_sections['asiento']['show']):

            for ($this->_sections['asiento']['index'] = $this->_sections['asiento']['start'], $this->_sections['asiento']['iteration'] = 1;
                 $this->_sections['asiento']['iteration'] <= $this->_sections['asiento']['total'];
                 $this->_sections['asiento']['index'] += $this->_sections['asiento']['step'], $this->_sections['asiento']['iteration']++):
$this->_sections['asiento']['rownum'] = $this->_sections['asiento']['iteration'];
$this->_sections['asiento']['index_prev'] = $this->_sections['asiento']['index'] - $this->_sections['asiento']['step'];
$this->_sections['asiento']['index_next'] = $this->_sections['asiento']['index'] + $this->_sections['asiento']['step'];
$this->_sections['asiento']['first']      = ($this->_sections['asiento']['iteration'] == 1);
$this->_sections['asiento']['last']       = ($this->_sections['asiento']['iteration'] == $this->_sections['asiento']['total']);
?>
        <?php $this->assign('num', $this->_sections['asiento']['index']); ?>
        <?php $this->assign('puesto', 0); ?>
        <?php $_from = $this->_tpl_vars['citas'][$this->_tpl_vars['i']]; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['cita']):
?>
          <?php if ($this->_tpl_vars['cita']['gabinete'] == $this->_tpl_vars['num']): ?>
            <?php if ($this->_tpl_vars['cita']['bloqueado'] == true): ?>
              <?php $this->assign('puesto', 1); ?>
              <td class="bloqueada" align="center" rowspan="<?php echo $this->_tpl_vars['cita']['duracion']; ?>
">
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.borranolog/id.<?php echo $this->_tpl_vars['cita']['id_cita']; ?>
><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoborrar.ico title="Borrar" width="16" height="16" /></a>
              </td>
            <?php else: ?>
              <td rowspan="<?php echo $this->_tpl_vars['cita']['duracion']; ?>
" style="background-color: <?php echo $this->_tpl_vars['cita']['color']; ?>
">
              	<table border="0" width="100%">
              		<tr>
              			<td>
              			<a href="javascript:cerrar('<?php echo $this->_tpl_vars['cita']['id_cita']; ?>
');"><?php echo $this->_tpl_vars['cita']['paciente']; ?>
</a>
			                <?php $this->assign('puesto', 1); ?>
			                <?php if ($this->_tpl_vars['cita']['duracion'] > 1): ?>
			                  <?php $this->assign("gab".($this->_tpl_vars['num']), $this->_tpl_vars['cita']['duracion']); ?>
			                <?php endif; ?>
			                <?php if ($this->_tpl_vars['cita']['fsa'] == 1): ?>
			                <img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoatencion.png alt="FSA" width="16" height="16"/>
			                <?php endif; ?>
			                <div class="menu" id="<?php echo $this->_tpl_vars['cita']['id_cita']; ?>
">
			                	<ul>
			                		<li><p><?php echo $this->_tpl_vars['cita']['paciente']; ?>
</p></li>
			                		<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.historia/id.<?php echo $this->_tpl_vars['cita']['id_paciente']; ?>
>Ir a la historia</a></li>
			                		<li><p>Tipo de cita: <?php echo ((is_array($_tmp=$this->_tpl_vars['cita']['tipo'])) ? $this->_run_mod_handler('regex_replace', true, $_tmp, "/\+/", ' ') : smarty_modifier_regex_replace($_tmp, "/\+/", ' ')); ?>
</p></li>
			                		<li><p><?php echo $this->_config[0]['vars']['observaciones']; ?>
<?php echo $this->_tpl_vars['cita']['observaciones']; ?>
</p></li>
			                		<li>
			                			<a href="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.colorcita/id.<?php echo $this->_tpl_vars['cita']['id_cita']; ?>
/c.DA251D/dia.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
"><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
red.png /></a>
			                			<a href="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.colorcita/id.<?php echo $this->_tpl_vars['cita']['id_cita']; ?>
/c.96FF96/dia.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
"><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
green.png /></a>
			                			<a href="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.colorcita/id.<?php echo $this->_tpl_vars['cita']['id_cita']; ?>
/c.FFFFFF/dia.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
"><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
white.png /></a>
			                			<a href="<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.colorcita/id.<?php echo $this->_tpl_vars['cita']['id_cita']; ?>
/c.0093DD/dia.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
"><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
blue.png /></a>
			                		</li>
			                		<li><a href="javascript:confirmar(<?php echo $this->_tpl_vars['cita']['id_cita']; ?>
);"><img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
icoborrar.ico alt="Borrar" width="16" height="16" onclick="confirmar(<?php echo $this->_tpl_vars['cita']['id_cita']; ?>
)"/>  Borrar</a></li>
			                		<li><a href="javascript:cerrar('<?php echo $this->_tpl_vars['cita']['id_cita']; ?>
');">Cerrar</a></li>
			                	</ul>
			                </div>
              			</td>
              			<td align="right">
              				<p style="font-size: 70%"><?php echo ((is_array($_tmp=$this->_tpl_vars['cita']['tipo'])) ? $this->_run_mod_handler('regex_replace', true, $_tmp, "/\+/", ' ') : smarty_modifier_regex_replace($_tmp, "/\+/", ' ')); ?>
</p>
              			</td>
              		</tr>
              	</table>
                
              </td>
            <?php endif; ?>
          <?php endif; ?>
        <?php endforeach; endif; unset($_from); ?>
        <?php if ($this->_tpl_vars['puesto'] == 0): ?>
          <?php if ($this->_tpl_vars['num'] == 1): ?>
            <?php if ($this->_tpl_vars['gab1'] > 1): ?>
              <?php $this->assign('gab1', $this->_tpl_vars['gab1']-1); ?>
            <?php else: ?>
              <td>
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.abrircita/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/h.<?php echo $this->_tpl_vars['hora']; ?>
/a.<?php echo $this->_sections['asiento']['index']; ?>
>
                	<div class="citaLibre">
                		<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
pix_trans.png />
                	</div>
                </a>
              </td>
            <?php endif; ?>
          <?php endif; ?>
          <?php if ($this->_tpl_vars['num'] == 2): ?>
            <?php if ($this->_tpl_vars['gab2'] > 1): ?>
              <?php $this->assign('gab2', $this->_tpl_vars['gab2']-1); ?>
            <?php else: ?>
              <td>
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.abrircita/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/h.<?php echo $this->_tpl_vars['hora']; ?>
/a.<?php echo $this->_sections['asiento']['index']; ?>
>
                	<div class="citaLibre">
                		<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
pix_trans.png />
                	</div>
                </a>
              </td>
            <?php endif; ?>
          <?php endif; ?>
          <?php if ($this->_tpl_vars['num'] == 3): ?>
            <?php if ($this->_tpl_vars['gab3'] > 1): ?>
              <?php $this->assign('gab3', $this->_tpl_vars['gab3']-1); ?>
            <?php else: ?>
              <td>
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.abrircita/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/h.<?php echo $this->_tpl_vars['hora']; ?>
/a.<?php echo $this->_sections['asiento']['index']; ?>
>
                	<div class="citaLibre">
                		<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
pix_trans.png />
                	</div>
                </a>
              </td>
            <?php endif; ?>
          <?php endif; ?>
          <?php if ($this->_tpl_vars['num'] == 4): ?>
            <?php if ($this->_tpl_vars['gab4'] > 1): ?>
              <?php $this->assign('gab4', $this->_tpl_vars['gab4']-1); ?>
            <?php else: ?>
              <td>
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.abrircita/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/h.<?php echo $this->_tpl_vars['hora']; ?>
/a.<?php echo $this->_sections['asiento']['index']; ?>
>
                	<div class="citaLibre">
                		<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
pix_trans.png />
                	</div>
                </a>
              </td>
            <?php endif; ?>
          <?php endif; ?>
          <?php if ($this->_tpl_vars['num'] == 5): ?>
            <?php if ($this->_tpl_vars['gab5'] > 1): ?>
              <?php $this->assign('gab5', $this->_tpl_vars['gab5']-1); ?>
            <?php else: ?>
              <td>
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.abrircita/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/h.<?php echo $this->_tpl_vars['hora']; ?>
/a.<?php echo $this->_sections['asiento']['index']; ?>
>
                	<div class="citaLibre">
                		<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
pix_trans.png />
                	</div>
                </a>
              </td>
            <?php endif; ?>
          <?php endif; ?>
          <?php if ($this->_tpl_vars['num'] == 6): ?>
            <?php if ($this->_tpl_vars['gab6'] > 1): ?>
              <?php $this->assign('gab6', $this->_tpl_vars['gab6']-1); ?>
            <?php else: ?>
              <td>
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.abrircita/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/h.<?php echo $this->_tpl_vars['hora']; ?>
/a.<?php echo $this->_sections['asiento']['index']; ?>
>
                	<div class="citaLibre">
                		<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
pix_trans.png />
                	</div>
                </a>
              </td>
            <?php endif; ?>
          <?php endif; ?>
          <?php if ($this->_tpl_vars['num'] == 7): ?>
            <?php if ($this->_tpl_vars['gab7'] > 1): ?>
              <?php $this->assign('gab7', $this->_tpl_vars['gab7']-1); ?>
            <?php else: ?>
              <td>
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.abrircita/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/h.<?php echo $this->_tpl_vars['hora']; ?>
/a.<?php echo $this->_sections['asiento']['index']; ?>
>
                	<div class="citaLibre">
                		<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
pix_trans.png />
                	</div>
                </a>
              </td>
            <?php endif; ?>
          <?php endif; ?>
          <?php if ($this->_tpl_vars['num'] == 8): ?>
            <?php if ($this->_tpl_vars['gab8'] > 1): ?>
              <?php $this->assign('gab8', $this->_tpl_vars['gab8']-1); ?>
            <?php else: ?>
              <td>
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.abrircita/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/h.<?php echo $this->_tpl_vars['hora']; ?>
/a.<?php echo $this->_sections['asiento']['index']; ?>
>
                	<div class="citaLibre">
                		<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
pix_trans.png />
                	</div>
                </a>
              </td>
            <?php endif; ?>
          <?php endif; ?>
          <?php if ($this->_tpl_vars['num'] == 9): ?>
            <?php if ($this->_tpl_vars['gab9'] > 1): ?>
              <?php $this->assign('gab9', $this->_tpl_vars['gab9']-1); ?>
            <?php else: ?>
              <td>
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.abrircita/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/h.<?php echo $this->_tpl_vars['hora']; ?>
/a.<?php echo $this->_sections['asiento']['index']; ?>
>
                	<div class="citaLibre">
                		<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
pix_trans.png />
                	</div>
                </a>
              </td>
            <?php endif; ?>
          <?php endif; ?>
          <?php if ($this->_tpl_vars['num'] == 10): ?>
            <?php if ($this->_tpl_vars['gab10'] > 1): ?>
              <?php $this->assign('gab10', $this->_tpl_vars['gab10']-1); ?>
            <?php else: ?>
              <td>
                <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.abrircita/f.<?php echo $this->_tpl_vars['dias']['hoy']; ?>
/h.<?php echo $this->_tpl_vars['hora']; ?>
/a.<?php echo $this->_sections['asiento']['index']; ?>
>
                	<div class="citaLibre">
                		<img src=<?php echo $this->_tpl_vars['img_path_base']; ?>
pix_trans.png />
                	</div>
                </a>
              </td>
            <?php endif; ?>
          <?php endif; ?>
          
        <?php endif; ?>
        <?php endfor; endif; ?>
      </tr>
    <?php endforeach; endif; unset($_from); ?>
    </table>
    <div class="pasar">	
    	<ul>
    		<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.agenda/dia.<?php echo $this->_tpl_vars['dias']['ayer']; ?>
>&lt;&lt;<?php echo $this->_config[0]['vars']['texto3']; ?>
</a></li>
    		<li><a id="show_d2" href="javascript:calendar()">Calendario</a></li>
    		<li><a href="javascript:abrir();">Imprimir</a></li>
    		<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.agenda/dia.<?php echo $this->_tpl_vars['dias']['mannana']; ?>
><?php echo $this->_config[0]['vars']['texto2']; ?>
&gt;&gt;</a></li>
    	</ul>
    </div>
    <?php else: ?>
      <p><?php echo $this->_config[0]['vars']['texto27']; ?>
</p>
      <a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.datosclinica><?php echo $this->_config[0]['vars']['texto28']; ?>
</a>
    <?php endif; ?>
    
<?php echo '
<script type="text/javascript">
<!--
    Calendar.setup({
        align          :    "Tl",           // alignment (defaults to "Bl")
        singleClick    :    true,
    	date           :    "'; ?>
<?php echo $this->_tpl_vars['dias']['cal']; ?>
<?php echo '",
    	button		   :    "show_d",
    	onSelect       :    dateChanged,
    	showOthers     :    true,
    	onClose        :    onClose
    });
    
    Calendar.setup({
        align          :    "Tl",           // alignment (defaults to "Bl")
        singleClick    :    true,
    	date           :    "'; ?>
<?php echo $this->_tpl_vars['dias']['cal']; ?>
<?php echo '",
    	button		   :    "show_d2",
    	onSelect       :    dateChanged,
    	showOthers     :    true,
    	onClose        :    onClose
    });
//-->	
</script>
'; ?>

</div>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ((is_array($_tmp=$this->_tpl_vars['tpl_path_base'])) ? $this->_run_mod_handler('cat', true, $_tmp, "gbdapp/common/footer.phtml") : smarty_modifier_cat($_tmp, "gbdapp/common/footer.phtml")), 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>