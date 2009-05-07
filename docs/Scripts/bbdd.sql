-- phpMyAdmin SQL Dump
-- version 2.11.1
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tiempo de generación: 10-06-2008 a las 12:26:07
-- Versión del servidor: 5.0.45
-- Versión de PHP: 5.2.4

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- Base de datos: `gbd`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `articulo`
--

CREATE TABLE `articulo` (
  `id_articulo` int(10) unsigned NOT NULL auto_increment,
  `titulo` varchar(40) collate latin1_spanish_ci NOT NULL,
  `autor` varchar(255) collate latin1_spanish_ci NOT NULL,
  `numero` varchar(32) collate latin1_spanish_ci default NULL,
  `volumen` varchar(32) collate latin1_spanish_ci default NULL,
  `paginas` varchar(32) collate latin1_spanish_ci default NULL,
  `organizacion` varchar(40) collate latin1_spanish_ci default NULL,
  `issn` varchar(255) collate latin1_spanish_ci default NULL,
  `mes` varchar(32) collate latin1_spanish_ci default NULL,
  `año` varchar(32) collate latin1_spanish_ci default NULL,
  `tirada` varchar(32) collate latin1_spanish_ci default NULL,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned default NULL,
  PRIMARY KEY  (`id_articulo`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `articulo`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `asistente`
--

CREATE TABLE `asistente` (
  `id_visita_medica` int(10) unsigned NOT NULL,
  `id_personal` int(10) unsigned NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_visita_medica`,`id_personal`),
  KEY `id_visita_medica` (`id_visita_medica`),
  KEY `id_personal` (`id_personal`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci;

--
-- Volcar la base de datos para la tabla `asistente`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `carta`
--

CREATE TABLE `carta` (
  `id_carta` int(10) unsigned NOT NULL auto_increment,
  `id_tipo_carta` int(10) unsigned NOT NULL,
  `id_paciente` int(10) unsigned NOT NULL,
  `texto` text collate latin1_spanish_ci,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `comentarios` text collate latin1_spanish_ci,
  PRIMARY KEY  (`id_carta`),
  KEY `id_tipo_carta` (`id_tipo_carta`),
  KEY `id_paciente` (`id_paciente`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `carta`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `caso`
--

CREATE TABLE `caso` (
  `id_caso` int(10) unsigned NOT NULL auto_increment,
  `titulo` varchar(40) collate latin1_spanish_ci NOT NULL,
  `autor` varchar(255) collate latin1_spanish_ci NOT NULL,
  `descripcion` varchar(255) collate latin1_spanish_ci default NULL,
  `tratamiento` varchar(255) collate latin1_spanish_ci default NULL,
  `duracion` varchar(40) collate latin1_spanish_ci default NULL,
  `observaciones` varchar(255) collate latin1_spanish_ci default NULL,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned default NULL,
  PRIMARY KEY  (`id_caso`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `caso`
--
-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cita`
--

CREATE TABLE `cita` (
  `id_cita` int(10) unsigned NOT NULL auto_increment,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `hora` varchar(32) collate latin1_spanish_ci NOT NULL,
  `duracion` varchar(32) collate latin1_spanish_ci NOT NULL,
  `gabinete` varchar(32) collate latin1_spanish_ci NOT NULL,
  `paciente` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_paciente` int(10) unsigned default NULL,
  `observaciones` text collate latin1_spanish_ci,
  `tipo` varchar(32) collate latin1_spanish_ci default NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_cita`),
  KEY `id_usuario` (`id_usuario`),
  KEY `id_paciente` (`id_paciente`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `cita`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `colaborador`
--

CREATE TABLE `colaborador` (
  `id_visita_medica` int(10) unsigned NOT NULL,
  `id_dr_colaborador` int(100) unsigned NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_visita_medica`,`id_dr_colaborador`),
  KEY `id_visita_medica` (`id_visita_medica`),
  KEY `id_dr_colaborador` (`id_dr_colaborador`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;

--
-- Volcar la base de datos para la tabla `colaborador`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `consentimiento`
--

CREATE TABLE `consentimiento` (
  `id_consentimiento` int(10) unsigned NOT NULL auto_increment,
  `id_tipo_consentimiento` int(10) unsigned NOT NULL,
  `id_paciente` int(10) unsigned NOT NULL,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `extension` varchar(32) collate latin1_spanish_ci default NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_consentimiento`),
  KEY `id_tipo_consentimiento` (`id_tipo_consentimiento`),
  KEY `id_paciente` (`id_paciente`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `consentimiento`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `consentimiento_revocado`
--

CREATE TABLE `consentimiento_revocado` (
  `id_consentimiento` int(10) unsigned NOT NULL auto_increment,
  `id_tipo_consentimiento` int(10) unsigned NOT NULL,
  `id_paciente` int(10) unsigned NOT NULL,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `fecha_r` varchar(32) collate latin1_spanish_ci NOT NULL,
  `extension` varchar(32) collate latin1_spanish_ci default NULL,
  `extensionr` varchar(32) collate latin1_spanish_ci default NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_consentimiento`),
  KEY `id_tipo_consentimiento` (`id_tipo_consentimiento`),
  KEY `id_paciente` (`id_paciente`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `consentimiento_revocado`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `dr_externo`
--

CREATE TABLE `dr_externo` (
  `id_dr_externo` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(45) collate latin1_spanish_ci default NULL,
  `apellido` varchar(50) collate latin1_spanish_ci default NULL,
  `apellido2` varchar(50) collate latin1_spanish_ci default NULL,
  `dni` varchar(32) collate latin1_spanish_ci default NULL,
  `direccion` varchar(255) collate latin1_spanish_ci default NULL,
  `cp` varchar(32) collate latin1_spanish_ci default NULL,
  `ciudad` varchar(45) collate latin1_spanish_ci default NULL,
  `id_provincia` int(2) unsigned default NULL,
  `telefono_clinica` varchar(32) collate latin1_spanish_ci default NULL,
  `telefono_movil` varchar(32) collate latin1_spanish_ci default NULL,
  `telefono_casa` varchar(32) collate latin1_spanish_ci default NULL,
  `fax` varchar(32) collate latin1_spanish_ci default NULL,
  `email` varchar(255) collate latin1_spanish_ci default NULL,
  `fecha_nacimiento` varchar(32) collate latin1_spanish_ci default NULL,
  `especialidad` text collate latin1_spanish_ci,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_dr_externo`),
  KEY `id_usuario` (`id_usuario`),
  KEY `id_provincia` (`id_provincia`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `dr_externo`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `factura`
--

CREATE TABLE `factura` (
  `id_factura` int(10) unsigned NOT NULL auto_increment,
  `numero` varchar(40) collate latin1_spanish_ci NOT NULL,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `nombre_pagador` varchar(255) collate latin1_spanish_ci default NULL,
  `dni_pagador` varchar(32) collate latin1_spanish_ci default NULL,
  `total` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_paciente` int(10) unsigned default NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_factura`),
  KEY `id_paciente` (`id_paciente`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `factura`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `formato_fecha`
--

CREATE TABLE `formato_fecha` (
  `id_formato_fecha` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(40) collate latin1_spanish_ci NOT NULL,
  PRIMARY KEY  (`id_formato_fecha`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=3 ;

--
-- Volcar la base de datos para la tabla `formato_fecha`
--

INSERT INTO `formato_fecha` (`id_formato_fecha`, `nombre`) VALUES
(1, 'dd-mm-aaaa'),
(2, 'aaaa-mm-dd');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `foro`
--

CREATE TABLE `foro` (
  `id_foro` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(255) collate latin1_spanish_ci NOT NULL,
  `id_tipo_foro` int(2) NOT NULL,
  PRIMARY KEY  (`id_foro`),
  KEY `id_tipo_foro` (`id_tipo_foro`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `foro`
--
-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `idioma`
--

CREATE TABLE `idioma` (
  `id_idioma` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(255) collate latin1_spanish_ci NOT NULL,
  PRIMARY KEY  (`id_idioma`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=3 ;

--
-- Volcar la base de datos para la tabla `idioma`
--

INSERT INTO `idioma` (`id_idioma`, `nombre`) VALUES
(1, 'Español'),
(2, 'Inglés');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `imagen`
--

CREATE TABLE `imagen` (
  `id_imagen` int(10) unsigned NOT NULL auto_increment,
  `id_tipo` int(2) unsigned NOT NULL,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_paciente` int(10) unsigned NOT NULL,
  `comentarios` text collate latin1_spanish_ci,
  `extension` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_imagen`),
  KEY `id_paciente` (`id_paciente`),
  KEY `id_tipo` (`id_tipo`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `imagen`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `justificante`
--

CREATE TABLE `justificante` (
  `id_justificante` int(10) unsigned NOT NULL auto_increment,
  `motivo` text collate latin1_spanish_ci,
  `observaciones` text collate latin1_spanish_ci,
  `texto` text collate latin1_spanish_ci,
  `id_visita_medica` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_justificante`),
  KEY `id_visita_medica` (`id_visita_medica`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `justificante`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `libro`
--

CREATE TABLE `libro` (
  `id_libro` int(10) unsigned NOT NULL auto_increment,
  `titulo` varchar(40) collate latin1_spanish_ci NOT NULL,
  `autor` varchar(255) collate latin1_spanish_ci NOT NULL,
  `editorial` varchar(255) collate latin1_spanish_ci default NULL,
  `isbn` varchar(255) collate latin1_spanish_ci default NULL,
  `año` varchar(32) collate latin1_spanish_ci default NULL,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned default NULL,
  PRIMARY KEY  (`id_libro`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `libro`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `linea_factura`
--

CREATE TABLE `linea_factura` (
  `id_linea` int(10) unsigned NOT NULL auto_increment,
  `id_factura` int(10) unsigned NOT NULL,
  `id_servicio` int(10) unsigned NOT NULL,
  `cantidad` varchar(32) collate latin1_spanish_ci default NULL,
  `total` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_linea`),
  KEY `id_factura` (`id_factura`),
  KEY `id_servicio` (`id_servicio`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `linea_factura`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `linea_presupuesto`
--

CREATE TABLE `linea_presupuesto` (
  `id_linea` int(10) unsigned NOT NULL auto_increment,
  `id_presupuesto` int(10) unsigned NOT NULL,
  `id_servicio` int(10) unsigned NOT NULL,
  `cantidad` varchar(32) collate latin1_spanish_ci default NULL,
  `total` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_linea`),
  KEY `id_presupuesto` (`id_presupuesto`),
  KEY `id_servicio` (`id_servicio`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `linea_presupuesto`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `linea_visita`
--

CREATE TABLE `linea_visita` (
  `id_linea` int(10) unsigned NOT NULL auto_increment,
  `id_visita` int(10) unsigned NOT NULL,
  `id_servicio` int(10) unsigned default NULL,
  `cantidad` varchar(32) collate latin1_spanish_ci NOT NULL,
  `total` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_linea`),
  KEY `id_visita` (`id_visita`),
  KEY `id_usuario` (`id_usuario`),
  KEY `id_servicio` (`id_servicio`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `linea_visita`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `log`
--

CREATE TABLE `log` (
  `id_log` int(11) NOT NULL auto_increment,
  `id_usuario` int(10) unsigned NOT NULL,
  `id_personal` int(10) unsigned default NULL,
  `nombre` varchar(32) collate latin1_spanish_ci NOT NULL,
  `detalles` text collate latin1_spanish_ci NOT NULL,
  `fecha` datetime NOT NULL,
  `id_tipo_log` int(10) NOT NULL,
  PRIMARY KEY  (`id_log`),
  KEY `id_usuario` (`id_usuario`),
  KEY `id_personal` (`id_personal`),
  KEY `id_tipo_log` (`id_tipo_log`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `log`
--
-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `mensaje`
--

CREATE TABLE `mensaje` (
  `id_mensaje` int(10) unsigned NOT NULL auto_increment,
  `titulo` varchar(40) collate latin1_spanish_ci NOT NULL,
  `texto` text collate latin1_spanish_ci NOT NULL,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `hora` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned default NULL,
  `id_foro` int(10) unsigned NOT NULL,
  `id_padre` int(10) default NULL,
  PRIMARY KEY  (`id_mensaje`),
  KEY `id_usuario` (`id_usuario`),
  KEY `id_foro` (`id_foro`),
  KEY `id_padre` (`id_padre`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `mensaje`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `opciones`
--

CREATE TABLE `opciones` (
  `id_opts` int(10) unsigned NOT NULL auto_increment,
  `id_usuario` int(10) unsigned NOT NULL,
  `nombre` varchar(255) collate latin1_spanish_ci default NULL,
  `especialidad` varchar(255) collate latin1_spanish_ci default NULL,
  `nif` varchar(32) collate latin1_spanish_ci default NULL,
  `direccion` varchar(255) collate latin1_spanish_ci default NULL,
  `telefono` varchar(32) collate latin1_spanish_ci default NULL,
  `cp` varchar(32) collate latin1_spanish_ci default NULL,
  `ciudad` varchar(32) collate latin1_spanish_ci default NULL,
  `id_provincia` int(10) unsigned default NULL,
  `gabinetes` varchar(32) collate latin1_spanish_ci default NULL,
  `extension` varchar(32) collate latin1_spanish_ci default NULL,
  `extensionf` varchar(32) collate latin1_spanish_ci default NULL,
  PRIMARY KEY  (`id_opts`),
  KEY `id_usuario` (`id_usuario`),
  KEY `id_provincia` (`id_provincia`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `opciones`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `paciente`
--

CREATE TABLE `paciente` (
  `id_paciente` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(45) collate latin1_spanish_ci default NULL,
  `apellido` varchar(50) collate latin1_spanish_ci default NULL,
  `apellido2` varchar(50) collate latin1_spanish_ci default NULL,
  `direccion` varchar(255) collate latin1_spanish_ci default NULL,
  `ciudad` varchar(45) collate latin1_spanish_ci default NULL,
  `id_provincia` int(2) unsigned default NULL,
  `cp` varchar(32) collate latin1_spanish_ci default NULL,
  `telefono_fijo` varchar(32) collate latin1_spanish_ci default NULL,
  `telefono_trabajo` varchar(32) collate latin1_spanish_ci default NULL,
  `telefono_movil` varchar(32) collate latin1_spanish_ci default NULL,
  `profesion` varchar(45) collate latin1_spanish_ci default NULL,
  `dni` varchar(32) collate latin1_spanish_ci default NULL,
  `fecha_nacimiento` varchar(32) collate latin1_spanish_ci default NULL,
  `email` varchar(255) collate latin1_spanish_ci default NULL,
  `alertas_medicas` text collate latin1_spanish_ci,
  `alto_riesgo` text collate latin1_spanish_ci,
  `observaciones` text collate latin1_spanish_ci,
  `extension` varchar(32) collate latin1_spanish_ci default NULL,
  `id_paciente_referidor` int(10) unsigned default NULL,
  `id_dr_referidor` int(10) unsigned default NULL,
  `fecha_alta` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_paciente`),
  KEY `id_provincia` (`id_provincia`),
  KEY `id_paciente_referidor` (`id_paciente_referidor`),
  KEY `id_dr_referidor` (`id_dr_referidor`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `paciente`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pago`
--

CREATE TABLE `pago` (
  `id_pago` int(10) unsigned NOT NULL auto_increment,
  `numero_tarjeta` varchar(32) collate latin1_spanish_ci NOT NULL,
  `caducidad` varchar(32) collate latin1_spanish_ci NOT NULL,
  `importe` varchar(32) collate latin1_spanish_ci NOT NULL,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned default NULL,
  PRIMARY KEY  (`id_pago`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `pago`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pagopac`
--

CREATE TABLE `pagopac` (
  `id_pago` int(100) unsigned NOT NULL auto_increment,
  `id_paciente` int(10) unsigned NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  `total_tarjeta` varchar(32) collate latin1_spanish_ci NOT NULL default '0',
  `total_efectivo` varchar(32) collate latin1_spanish_ci NOT NULL default '0',
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  PRIMARY KEY  (`id_pago`),
  KEY `id_paciente` (`id_paciente`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `pagopac`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pedido`
--

CREATE TABLE `pedido` (
  `id_pedido` int(10) unsigned NOT NULL auto_increment,
  `numero` varchar(32) collate latin1_spanish_ci default NULL,
  `fecha_pedido` varchar(32) collate latin1_spanish_ci default NULL,
  `proveedor` varchar(45) collate latin1_spanish_ci default NULL,
  `fecha_recibido` varchar(32) collate latin1_spanish_ci default NULL,
  `observaciones` text character set latin1 collate latin1_general_ci,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_pedido`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `pedido`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `personal`
--

CREATE TABLE `personal` (
  `id_personal` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(45) collate latin1_spanish_ci default NULL,
  `apellido` varchar(50) collate latin1_spanish_ci default NULL,
  `apellido2` varchar(50) collate latin1_spanish_ci default NULL,
  `dni` varchar(32) collate latin1_spanish_ci default NULL,
  `direccion` varchar(255) collate latin1_spanish_ci default NULL,
  `cp` varchar(32) collate latin1_spanish_ci default NULL,
  `ciudad` varchar(45) collate latin1_spanish_ci default NULL,
  `id_provincia` int(2) unsigned default NULL,
  `telefono` varchar(32) collate latin1_spanish_ci default NULL,
  `movil` varchar(32) collate latin1_spanish_ci default NULL,
  `email` varchar(32) collate latin1_spanish_ci default NULL,
  `num_colegiado` varchar(32) collate latin1_spanish_ci default NULL,
  `especialidad` varchar(255) character set latin1 collate latin1_general_ci default NULL,
  `fecha_alta` varchar(32) collate latin1_spanish_ci NOT NULL,
  `curriculum` text collate latin1_spanish_ci,
  `extension` varchar(32) collate latin1_spanish_ci default NULL,
  `login` varchar(32) collate latin1_spanish_ci NOT NULL,
  `password` varchar(32) collate latin1_spanish_ci NOT NULL,
  `privilegios` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_personal`),
  KEY `id_usuario` (`id_usuario`),
  KEY `id_provincia` (`id_provincia`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `personal`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `presupuesto`
--

CREATE TABLE `presupuesto` (
  `id_presupuesto` int(10) unsigned NOT NULL auto_increment,
  `id_paciente` int(10) unsigned NOT NULL,
  `numero` varchar(40) collate latin1_spanish_ci default NULL,
  `fecha` varchar(32) collate latin1_spanish_ci default NULL,
  `validez` varchar(32) collate latin1_spanish_ci default NULL,
  `duracion` varchar(32) collate latin1_spanish_ci default NULL,
  `total` varchar(32) collate latin1_spanish_ci default NULL,
  `objetivo` text collate latin1_spanish_ci,
  `extension` varchar(32) collate latin1_spanish_ci default NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_presupuesto`),
  KEY `id_paciente` (`id_paciente`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `presupuesto`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `provincia`
--

CREATE TABLE `provincia` (
  `id_provincia` int(2) unsigned NOT NULL auto_increment,
  `provincia` varchar(255) collate latin1_spanish_ci default NULL,
  PRIMARY KEY  (`id_provincia`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=53 ;

--
-- Volcar la base de datos para la tabla `provincia`
--

INSERT INTO `provincia` (`id_provincia`, `provincia`) VALUES
(1, 'Alava'),
(2, 'Albacete'),
(3, 'Alicante'),
(4, 'Almeria'),
(5, 'Asturias'),
(6, 'Avila'),
(7, 'Badajoz'),
(8, 'Barcelona'),
(9, 'Burgos'),
(10, 'Caceres'),
(11, 'Cadiz'),
(12, 'Cantabria'),
(13, 'Castellon'),
(14, 'Ceuta'),
(15, 'Ciudad Real'),
(16, 'Cordoba'),
(17, 'Cuenca'),
(18, 'Gerona'),
(19, 'Granada'),
(20, 'Guadalajara'),
(21, 'Guipuzcoa'),
(22, 'Huelva'),
(23, 'Huesca'),
(24, 'Islas Baleares'),
(25, 'Jaen'),
(26, 'La Coruna'),
(27, 'La Rioja'),
(28, 'Las Palmas'),
(29, 'Leon'),
(30, 'Lerida'),
(31, 'Lugo'),
(32, 'Madrid'),
(33, 'Malaga'),
(34, 'Melilla'),
(35, 'Murcia'),
(36, 'Navarra'),
(37, 'Orense'),
(38, 'Palencia'),
(39, 'Pontevedra'),
(40, 'Salamanca'),
(41, 'Santa Cruz de Tenerife'),
(42, 'Segovia'),
(43, 'Sevilla'),
(44, 'Soria'),
(45, 'Tarragona'),
(46, 'Teruel'),
(47, 'Toledo'),
(48, 'Valencia'),
(49, 'Valladolid'),
(50, 'Vizcaya'),
(51, 'Zamora'),
(52, 'Zaragoza');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `receta`
--

CREATE TABLE `receta` (
  `id_receta` int(10) unsigned NOT NULL auto_increment,
  `observaciones` text collate latin1_spanish_ci,
  `id_visita_medica` int(10) unsigned NOT NULL,
  `id_paciente` int(10) unsigned NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  `resumen` text collate latin1_spanish_ci,
  `texto` text collate latin1_spanish_ci NOT NULL,
  `id_tipo_receta` int(10) unsigned default NULL,
  PRIMARY KEY  (`id_receta`),
  KEY `id_visita_medica` (`id_visita_medica`),
  KEY `id_paciente` (`id_paciente`),
  KEY `id_usuario` (`id_usuario`),
  KEY `id_tipo_receta` (`id_tipo_receta`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `receta`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `servicio`
--

CREATE TABLE `servicio` (
  `id_servicio` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(255) character set latin1 collate latin1_general_ci NOT NULL,
  `precio_unitario` varchar(32) collate latin1_spanish_ci default NULL,
  `descripcion` text collate latin1_spanish_ci,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_servicio`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `servicio`
--
-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tesis`
--

CREATE TABLE `tesis` (
  `id_tesis` int(10) unsigned NOT NULL auto_increment,
  `titulo` varchar(40) collate latin1_spanish_ci NOT NULL,
  `autor` varchar(255) collate latin1_spanish_ci NOT NULL,
  `directores` varchar(255) collate latin1_spanish_ci NOT NULL,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `id_usuario` int(10) unsigned default NULL,
  PRIMARY KEY  (`id_tesis`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `tesis`
--
-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipo_carta`
--

CREATE TABLE `tipo_carta` (
  `id_tipo_carta` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(255) collate latin1_spanish_ci NOT NULL,
  `descripcion` varchar(255) collate latin1_spanish_ci default NULL,
  `texto_incluido` text collate latin1_spanish_ci,
  PRIMARY KEY  (`id_tipo_carta`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `tipo_carta`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipo_consentimiento`
--

CREATE TABLE `tipo_consentimiento` (
  `id_tipo_consentimiento` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(255) collate latin1_spanish_ci NOT NULL,
  `descripcion` varchar(255) collate latin1_spanish_ci default NULL,
  `texto_incluido` text collate latin1_spanish_ci,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_tipo_consentimiento`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `tipo_consentimiento`
--
-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipo_foro`
--

CREATE TABLE `tipo_foro` (
  `id_tipo_foro` int(2) NOT NULL auto_increment,
  `nombre` varchar(32) collate latin1_spanish_ci NOT NULL,
  PRIMARY KEY  (`id_tipo_foro`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=9 ;

--
-- Volcar la base de datos para la tabla `tipo_foro`
--

INSERT INTO `tipo_foro` (`id_tipo_foro`, `nombre`) VALUES
(1, 'Odontologia'),
(2, 'Periodoncia - Implantes'),
(3, 'Endodoncia'),
(4, 'Ortodoncia'),
(5, 'Cirugía'),
(6, 'Prótesis'),
(7, 'Estética'),
(8, 'Otros');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipo_imagen`
--

CREATE TABLE `tipo_imagen` (
  `id_tipo_imagen` int(2) unsigned NOT NULL auto_increment,
  `nombre` varchar(45) collate latin1_spanish_ci NOT NULL,
  `descripcion` varchar(255) collate latin1_spanish_ci default NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_tipo_imagen`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `tipo_imagen`
--
-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipo_log`
--

CREATE TABLE `tipo_log` (
  `id_tipo_log` int(10) NOT NULL auto_increment,
  `nombre` varchar(32) collate latin1_spanish_ci NOT NULL,
  PRIMARY KEY  (`id_tipo_log`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=6 ;

--
-- Volcar la base de datos para la tabla `tipo_log`
--

INSERT INTO `tipo_log` (`id_tipo_log`, `nombre`) VALUES
(1, 'Alta'),
(2, 'Baja'),
(3, 'Modificacion'),
(4, 'Acceso'),
(5, 'Desconexion'),
(6, 'Accion no permitida');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipo_receta`
--

CREATE TABLE `tipo_receta` (
  `id_tipo_receta` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(255) collate latin1_spanish_ci NOT NULL,
  `texto` text collate latin1_spanish_ci NOT NULL,
  `resumen` text collate latin1_spanish_ci,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_tipo_receta`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `tipo_receta`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuario`
--

CREATE TABLE `usuario` (
  `id_usuario` int(10) unsigned NOT NULL auto_increment,
  `nombre` varchar(40) collate latin1_spanish_ci NOT NULL,
  `apellido` varchar(40) collate latin1_spanish_ci NOT NULL,
  `apellido2` varchar(40) collate latin1_spanish_ci NOT NULL,
  `login` varchar(32) collate latin1_spanish_ci NOT NULL,
  `password` varchar(32) collate latin1_spanish_ci NOT NULL,
  `telefono` varchar(32) collate latin1_spanish_ci default NULL,
  `email` varchar(255) collate latin1_spanish_ci NOT NULL,
  `privilegios` varchar(32) collate latin1_spanish_ci NOT NULL,
  `fin_suscripcion` varchar(32) collate latin1_spanish_ci default NULL,
  PRIMARY KEY  (`id_usuario`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `usuario`
--
-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `visita`
--

CREATE TABLE `visita` (
  `id_visita` int(10) unsigned NOT NULL auto_increment,
  `fecha` varchar(32) collate latin1_spanish_ci NOT NULL,
  `asiento` varchar(32) collate latin1_spanish_ci NOT NULL,
  `motivo` varchar(255) collate latin1_spanish_ci default NULL,
  `diagnostico` varchar(255) collate latin1_spanish_ci default NULL,
  `observaciones` varchar(255) collate latin1_spanish_ci default NULL,
  `precio` varchar(32) collate latin1_spanish_ci default NULL,
  `id_paciente` int(10) unsigned NOT NULL,
  `id_usuario` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id_visita`),
  KEY `id_paciente` (`id_paciente`),
  KEY `id_usuario` (`id_usuario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_spanish_ci AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `visita`
--


--
-- Filtros para las tablas descargadas (dump)
--

--
-- Filtros para la tabla `articulo`
--
ALTER TABLE `articulo`
  ADD CONSTRAINT `articulo_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE SET NULL;

--
-- Filtros para la tabla `asistente`
--
ALTER TABLE `asistente`
  ADD CONSTRAINT `asistente_ibfk_5` FOREIGN KEY (`id_visita_medica`) REFERENCES `visita` (`id_visita`) ON DELETE CASCADE,
  ADD CONSTRAINT `asistente_ibfk_6` FOREIGN KEY (`id_personal`) REFERENCES `personal` (`id_personal`) ON DELETE CASCADE,
  ADD CONSTRAINT `asistente_ibfk_7` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `carta`
--
ALTER TABLE `carta`
  ADD CONSTRAINT `carta_ibfk_1` FOREIGN KEY (`id_tipo_carta`) REFERENCES `tipo_carta` (`id_tipo_carta`) ON DELETE CASCADE,
  ADD CONSTRAINT `carta_ibfk_2` FOREIGN KEY (`id_paciente`) REFERENCES `paciente` (`id_paciente`) ON DELETE CASCADE;

--
-- Filtros para la tabla `caso`
--
ALTER TABLE `caso`
  ADD CONSTRAINT `caso_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE SET NULL;

--
-- Filtros para la tabla `cita`
--
ALTER TABLE `cita`
  ADD CONSTRAINT `cita_ibfk_2` FOREIGN KEY (`id_paciente`) REFERENCES `paciente` (`id_paciente`) ON DELETE CASCADE,
  ADD CONSTRAINT `cita_ibfk_3` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `colaborador`
--
ALTER TABLE `colaborador`
  ADD CONSTRAINT `colaborador_ibfk_3` FOREIGN KEY (`id_visita_medica`) REFERENCES `visita` (`id_visita`) ON DELETE CASCADE,
  ADD CONSTRAINT `colaborador_ibfk_4` FOREIGN KEY (`id_dr_colaborador`) REFERENCES `dr_externo` (`id_dr_externo`) ON DELETE CASCADE,
  ADD CONSTRAINT `colaborador_ibfk_5` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `consentimiento`
--
ALTER TABLE `consentimiento`
  ADD CONSTRAINT `consentimiento_ibfk_3` FOREIGN KEY (`id_tipo_consentimiento`) REFERENCES `tipo_consentimiento` (`id_tipo_consentimiento`) ON DELETE CASCADE,
  ADD CONSTRAINT `consentimiento_ibfk_4` FOREIGN KEY (`id_paciente`) REFERENCES `paciente` (`id_paciente`) ON DELETE CASCADE,
  ADD CONSTRAINT `consentimiento_ibfk_5` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `dr_externo`
--
ALTER TABLE `dr_externo`
  ADD CONSTRAINT `dr_externo_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE,
  ADD CONSTRAINT `dr_externo_ibfk_2` FOREIGN KEY (`id_provincia`) REFERENCES `provincia` (`id_provincia`);

--
-- Filtros para la tabla `factura`
--
ALTER TABLE `factura`
  ADD CONSTRAINT `factura_ibfk_1` FOREIGN KEY (`id_paciente`) REFERENCES `paciente` (`id_paciente`) ON DELETE CASCADE,
  ADD CONSTRAINT `factura_ibfk_2` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `imagen`
--
ALTER TABLE `imagen`
  ADD CONSTRAINT `imagen_ibfk_2` FOREIGN KEY (`id_tipo`) REFERENCES `tipo_imagen` (`id_tipo_imagen`),
  ADD CONSTRAINT `imagen_ibfk_3` FOREIGN KEY (`id_paciente`) REFERENCES `paciente` (`id_paciente`) ON DELETE CASCADE,
  ADD CONSTRAINT `imagen_ibfk_4` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `justificante`
--
ALTER TABLE `justificante`
  ADD CONSTRAINT `justificante_ibfk_1` FOREIGN KEY (`id_visita_medica`) REFERENCES `visita` (`id_visita`) ON DELETE CASCADE;

--
-- Filtros para la tabla `libro`
--
ALTER TABLE `libro`
  ADD CONSTRAINT `libro_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE SET NULL;

--
-- Filtros para la tabla `linea_factura`
--
ALTER TABLE `linea_factura`
  ADD CONSTRAINT `linea_factura_ibfk_3` FOREIGN KEY (`id_factura`) REFERENCES `factura` (`id_factura`) ON DELETE CASCADE,
  ADD CONSTRAINT `linea_factura_ibfk_4` FOREIGN KEY (`id_servicio`) REFERENCES `servicio` (`id_servicio`),
  ADD CONSTRAINT `linea_factura_ibfk_5` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `linea_presupuesto`
--
ALTER TABLE `linea_presupuesto`
  ADD CONSTRAINT `linea_presupuesto_ibfk_3` FOREIGN KEY (`id_presupuesto`) REFERENCES `presupuesto` (`id_presupuesto`) ON DELETE CASCADE,
  ADD CONSTRAINT `linea_presupuesto_ibfk_4` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `linea_visita`
--
ALTER TABLE `linea_visita`
  ADD CONSTRAINT `linea_visita_ibfk_5` FOREIGN KEY (`id_visita`) REFERENCES `visita` (`id_visita`) ON DELETE CASCADE,
  ADD CONSTRAINT `linea_visita_ibfk_6` FOREIGN KEY (`id_servicio`) REFERENCES `servicio` (`id_servicio`) ON DELETE SET NULL,
  ADD CONSTRAINT `linea_visita_ibfk_7` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `log`
--
ALTER TABLE `log`
  ADD CONSTRAINT `log_ibfk_14` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE,
  ADD CONSTRAINT `log_ibfk_15` FOREIGN KEY (`id_personal`) REFERENCES `personal` (`id_personal`) ON DELETE SET NULL,
  ADD CONSTRAINT `log_ibfk_16` FOREIGN KEY (`id_tipo_log`) REFERENCES `tipo_log` (`id_tipo_log`) ON DELETE CASCADE;

--
-- Filtros para la tabla `mensaje`
--
ALTER TABLE `mensaje`
  ADD CONSTRAINT `mensaje_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE SET NULL,
  ADD CONSTRAINT `mensaje_ibfk_2` FOREIGN KEY (`id_foro`) REFERENCES `foro` (`id_foro`) ON DELETE CASCADE;

--
-- Filtros para la tabla `opciones`
--
ALTER TABLE `opciones`
  ADD CONSTRAINT `opciones_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE,
  ADD CONSTRAINT `opciones_ibfk_2` FOREIGN KEY (`id_provincia`) REFERENCES `provincia` (`id_provincia`);

--
-- Filtros para la tabla `paciente`
--
ALTER TABLE `paciente`
  ADD CONSTRAINT `paciente_ibfk_1` FOREIGN KEY (`id_provincia`) REFERENCES `provincia` (`id_provincia`),
  ADD CONSTRAINT `paciente_ibfk_2` FOREIGN KEY (`id_paciente_referidor`) REFERENCES `paciente` (`id_paciente`) ON DELETE SET NULL,
  ADD CONSTRAINT `paciente_ibfk_3` FOREIGN KEY (`id_dr_referidor`) REFERENCES `dr_externo` (`id_dr_externo`) ON DELETE SET NULL,
  ADD CONSTRAINT `paciente_ibfk_4` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `pago`
--
ALTER TABLE `pago`
  ADD CONSTRAINT `pago_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE SET NULL;

--
-- Filtros para la tabla `pagopac`
--
ALTER TABLE `pagopac`
  ADD CONSTRAINT `pagopac_ibfk_4` FOREIGN KEY (`id_paciente`) REFERENCES `paciente` (`id_paciente`) ON DELETE CASCADE,
  ADD CONSTRAINT `pagopac_ibfk_5` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `pedido`
--
ALTER TABLE `pedido`
  ADD CONSTRAINT `pedido_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `personal`
--
ALTER TABLE `personal`
  ADD CONSTRAINT `personal_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE,
  ADD CONSTRAINT `personal_ibfk_2` FOREIGN KEY (`id_provincia`) REFERENCES `provincia` (`id_provincia`);

--
-- Filtros para la tabla `presupuesto`
--
ALTER TABLE `presupuesto`
  ADD CONSTRAINT `presupuesto_ibfk_1` FOREIGN KEY (`id_paciente`) REFERENCES `paciente` (`id_paciente`) ON DELETE CASCADE,
  ADD CONSTRAINT `presupuesto_ibfk_2` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `receta`
--
ALTER TABLE `receta`
  ADD CONSTRAINT `receta_ibfk_23` FOREIGN KEY (`id_visita_medica`) REFERENCES `visita` (`id_visita`) ON DELETE CASCADE,
  ADD CONSTRAINT `receta_ibfk_24` FOREIGN KEY (`id_paciente`) REFERENCES `paciente` (`id_paciente`) ON DELETE CASCADE,
  ADD CONSTRAINT `receta_ibfk_25` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE,
  ADD CONSTRAINT `receta_ibfk_26` FOREIGN KEY (`id_tipo_receta`) REFERENCES `tipo_receta` (`id_tipo_receta`) ON DELETE SET NULL;

--
-- Filtros para la tabla `servicio`
--
ALTER TABLE `servicio`
  ADD CONSTRAINT `servicio_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `tesis`
--
ALTER TABLE `tesis`
  ADD CONSTRAINT `tesis_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE SET NULL;

--
-- Filtros para la tabla `tipo_consentimiento`
--
ALTER TABLE `tipo_consentimiento`
  ADD CONSTRAINT `tipo_consentimiento_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `tipo_imagen`
--
ALTER TABLE `tipo_imagen`
  ADD CONSTRAINT `tipo_imagen_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `tipo_receta`
--
ALTER TABLE `tipo_receta`
  ADD CONSTRAINT `tipo_receta_ibfk_1` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;

--
-- Filtros para la tabla `visita`
--
ALTER TABLE `visita`
  ADD CONSTRAINT `visita_ibfk_13` FOREIGN KEY (`id_paciente`) REFERENCES `paciente` (`id_paciente`) ON DELETE CASCADE,
  ADD CONSTRAINT `visita_ibfk_14` FOREIGN KEY (`id_usuario`) REFERENCES `usuario` (`id_usuario`) ON DELETE CASCADE;
