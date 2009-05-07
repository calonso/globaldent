DROP TABLE IF EXISTS `grupo_imagenes`;
CREATE TABLE  `grupo_imagenes` (
  `id_grupo_imagenes` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(255) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_grupo_imagenes`),
  KEY `id_usuario` (`id_usuario`),
  CONSTRAINT `grupo_imagenes_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci;