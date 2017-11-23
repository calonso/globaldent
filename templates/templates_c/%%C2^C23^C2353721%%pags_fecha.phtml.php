<?php /* Smarty version 2.6.20, created on 2009-06-22 22:12:00
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/common/pags_fecha.phtml */ ?>
<script type="text/javascript">
<!--
<?php echo '
  function siguiente(fecha){
    var myDate = new Date();
    var partes = new Array();
    partes = fecha.split("-",3);
    partes[1] --;
    myDate.setFullYear(partes[2],partes[1],partes[0]);
    myDate.setDate(myDate.getDate() + 1);
    paginar (myDate, "a");
  }
  
  function anterior(fecha){
    var myDate = new Date();
    var partes = new Array();
    partes = fecha.split("-",3);
    partes[1] --;
    myDate.setFullYear(partes[2],partes[1],partes[0]);
    myDate.setDate(myDate.getDate() - 1);
    paginar (myDate, "d");
  }
  function paginar(myDate, order){
    var str = document.URL;
    var fecha = myDate.getDate() + "-" + (myDate.getMonth() + 1) + "-" + myDate.getFullYear(); 
    document.location = str.replace(/\\/fecha\\.\\d{1,2}-\\d{1,2}-\\d{4}\\/order.[a|d]/g, "") + "/fecha." + fecha + "/order." + order;
  }
'; ?>

-->
</script>

<?php if (isset ( $this->_tpl_vars['fechas'] ) && isset ( $this->_tpl_vars['numero'] )): ?>
<div class="pags">
  <?php if ($this->_tpl_vars['fechas']['curr'] == 'ultimo'): ?>
    <?php if ($this->_tpl_vars['numero'] != 0): ?>
      <input type="button" value="<" onclick="anterior('<?php echo $this->_tpl_vars['fechas']['primera']; ?>
')" />
      <input class="der" type="button" value=">" disabled="disabled" /> 
    <?php endif; ?>
  <?php else: ?>
    <?php if ($this->_tpl_vars['numero'] != 0): ?>
      <input type="button" value="<" onclick="anterior('<?php echo $this->_tpl_vars['fechas']['primera']; ?>
')" />
      <input class="der" type="button" value=">" onclick="siguiente('<?php echo $this->_tpl_vars['fechas']['ultima']; ?>
')" />  
    <?php else: ?>
      <?php if ($this->_tpl_vars['order'] == 'a'): ?>
        <input type="button" value="<" onclick="anterior('<?php echo $this->_tpl_vars['fechas']['curr']; ?>
')" />
        <input class="der" type="button" value=">" disabled="disabled" />    
      <?php else: ?>
        <input type="button" value="<" disabled="disabled" />
        <input class="der" type="button" value=">" onclick="siguiente('<?php echo $this->_tpl_vars['fechas']['curr']; ?>
')" />
      <?php endif; ?>
    <?php endif; ?>
  <?php endif; ?>
</div>
<?php endif; ?>