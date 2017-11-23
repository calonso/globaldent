<?php /* Smarty version 2.6.20, created on 2009-06-20 19:13:28
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/common/pags.phtml */ ?>
<script type="text/javascript">
<!--
<?php echo '
  function siguiente(pag){
    pag = pag + 1;
    arreglar(pag);
  }
  function anterior(pag){
    pag = pag - 1;
    arreglar(pag);
  }
  function arreglar(pag){
    var str = document.URL;
    document.location = str.replace(/\\/pag\\.\\d/g, "") + "/pag." + pag;
  }
'; ?>

-->
</script>
<?php if (isset ( $this->_tpl_vars['pag'] ) && isset ( $this->_tpl_vars['numero'] )): ?>
<div class="pags">
  <?php if ($this->_tpl_vars['pag'] > 0): ?>
    <input type="button" value="<" onclick="anterior(<?php echo $this->_tpl_vars['pag']; ?>
)" />
  <?php else: ?>
    <input type="button" value="<" disabled="disabled" />
  <?php endif; ?>
  <?php if ($this->_tpl_vars['numero'] > $this->_tpl_vars['max_lineas']): ?>
    <input class="der" type="button" value=">" onclick="siguiente(<?php echo $this->_tpl_vars['pag']; ?>
)" />
  <?php else: ?>
    <input class="der" type="button" value=">" disabled="disabled" />
  <?php endif; ?>
</div>
<?php endif; ?>