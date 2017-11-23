<?php /* Smarty version 2.6.20, created on 2009-10-31 16:32:59
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/facturas/formTable.phtml */ ?>
<input type="button" value="+" onClick="tableManager.newLine(tableManager)" />
<table id="formTable" border="0" width="100%">
    <tr>
        <th colspan="7">&nbsp;</th>
    </tr>
    <tr>
        <td colspan="7">&nbsp;</td>
    </tr>
    <tr>
        <th colspan="2"><?php echo $this->_config[0]['vars']['texto15']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto61']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto53']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto14']; ?>
</th>
        <th><?php echo $this->_config[0]['vars']['texto16']; ?>
</th>
        <th>&nbsp;</th>
    </tr>
    <tr>
        <td colspan="7" class="lineahor">&nbsp;</td>
    </tr>
    <!-- Lineas -->
    <tr>
        <td colspan="7" class="lineahor">&nbsp;</td>
    </tr>
    <tr>
        <th colspan="5"><?php echo $this->_config[0]['vars']['texto20']; ?>
</th>
        <th>0 €.</th>
        <th>&nbsp;</th>
    </tr>
    </table>   
    <input id="total" type="hidden" name="txtTotal" />
    <input id="numLines" type="hidden" name="txtNumLines" />
    <input type="submit" value="<?php echo $this->_config[0]['vars']['texto22']; ?>
" />
    <input type="button" value="<?php echo $this->_config[0]['vars']['cancelar']; ?>
" onclick="document.location='<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.facturas/id.<?php echo $this->_tpl_vars['paciente']['id_paciente']; ?>
'">
    