<?php /* Smarty version 2.6.20, created on 2009-06-18 17:22:50
         compiled from C:/dev/apache/htsdocs/globaldent/templates/templates/web/gbdapp/common/navbar.phtml */ ?>
<div class="pestanas">
		<ul>
		  <li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.home>
        <?php if ($this->_tpl_vars['on'] == 1): ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_inicio_on.jpg"  height="49"/>
			 <?php else: ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_inicio.jpg"  height="45"/>
			<?php endif; ?>
			</a></li>
			<?php if ($this->_tpl_vars['privilegios'] == 4): ?>
			<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.admin>
        <?php if ($this->_tpl_vars['on'] == 9): ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_admin_on.jpg"  height="49"/>
			 <?php else: ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_admin.jpg"  height="45"/>
			<?php endif; ?>
			</a></li>
			<?php endif; ?>
			<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.agenda>
        <?php if ($this->_tpl_vars['on'] == 2): ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_agenda_on.jpg"  height="49"/>
			 <?php else: ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_agenda.jpg"  height="45"/>
			<?php endif; ?>
			</a></li>
			<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.pacientes>
        <?php if ($this->_tpl_vars['on'] == 3): ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_pacientes_on.jpg"  height="49"/>
			 <?php else: ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_pacientes.jpg"  height="45"/>
			<?php endif; ?>
			</a></li>
			<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.dres>
        <?php if ($this->_tpl_vars['on'] == 4): ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_dres_on.jpg"  height="49"/>
			 <?php else: ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_dres.jpg"  height="45"/>
			<?php endif; ?>
			</a></li>
			<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.personal>
        <?php if ($this->_tpl_vars['on'] == 5): ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_personal_on.jpg"  height="49"/>
			 <?php else: ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_personal.jpg"  height="45"/>
			<?php endif; ?>
			</a></li>
			<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.pedidos>
        <?php if ($this->_tpl_vars['on'] == 6): ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_pedidos_on.jpg"  height="49"/>
			 <?php else: ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_pedidos.jpg"  height="45"/>
			<?php endif; ?>
			</a></li>
			<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.conta>
        <?php if ($this->_tpl_vars['on'] == 7): ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_conta_on.jpg"  height="49"/>
			 <?php else: ?>
			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_conta.jpg"  height="45"/>
			<?php endif; ?>
			</a></li>
			<?php if ($this->_tpl_vars['privilegios'] == 5 || $this->_tpl_vars['privilegios'] == 4): ?>
  			<li><a href=<?php echo $this->_tpl_vars['req_base']; ?>
index.php/cod.conf>
          <?php if ($this->_tpl_vars['on'] == 8): ?>
  			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_conf_on.jpg"  height="49"/>
  			 <?php else: ?>
  			   <img src="<?php echo $this->_tpl_vars['img_path_base']; ?>
tab_conf.jpg"  height="45"/>
  			<?php endif; ?>
			 </a></li>
			<?php endif; ?>
		</ul>
	</div>