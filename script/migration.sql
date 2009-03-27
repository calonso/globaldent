USE gbd;

-- Modificaciones tabla servicio
ALTER TABLE servicio MODIFY precio_unitario int(5) default 0;
ALTER TABLE servicio DROP COLUMN descripcion;

-- Modificaciones tabla tipo_imagen
ALTER TABLE tipo_imagen MODIFY descripcion varchar(255) default null collate utf8_general_ci;

-- Modificaciones tabla tipo_consentimiento
ALTER TABLE tipo_consentimiento MODIFY texto_incluido text collate utf8_general_ci not null;
ALTER TABLE tipo_consentimiento MODIFY descripcion text collate utf8_general_ci default null;

-- Modificaciones tabla tipo_receta
ALTER TABLE tipo_receta MODIFY nombre varchar(255) collate utf8_general_ci not null;
ALTER TABLE tipo_receta MODIFY texto text collate utf8_general_ci not null;
ALTER TABLE tipo_receta MODIFY resumen text collate utf8_general_ci default null;

-- Modificaciones tabla log
ALTER TABLE log MODIFY nombre varchar(255) collate utf8_general_ci not null;
ALTER TABLE log MODIFY detalles text collate utf8_general_ci not null;

-- Modificaciones tabla pagopac
ALTER TABLE pagopac MODIFY total_tarjeta int(6) default 0;
ALTER TABLE pagopac MODIFY total_efectivo int(6) default 0;

-- Modificaciones tabla cita
ALTER TABLE cita MODIFY duracion int(2) default 0;
ALTER TABLE cita MODIFY tipo varchar(32) default null collate utf8_general_ci;
ALTER TABLE cita MODIFY observaciones varchar(255) default null collate utf8_general_ci;
ALTER TABLE cita MODIFY hora varchar(5) not null collate utf8_general_ci;
ALTER TABLE cita MODIFY gabinete int(1) default 0;
ALTER TABLE cita DROP COLUMN paciente;

-- Modificaciones tabla visita
ALTER TABLE visita MODIFY asiento varchar(10) default null collate utf8_general_ci;
ALTER TABLE visita MODIFY motivo text default null collate utf8_general_ci;
ALTER TABLE visita MODIFY diagnostico text default null collate utf8_general_ci;
ALTER TABLE visita MODIFY observaciones text default null collate utf8_general_ci;
ALTER TABLE visita MODIFY precio int(6) default 0;

-- Modificaciones tabla factura
ALTER TABLE factura MODIFY numero varchar(55) not null collate utf8_general_ci;
ALTER TABLE factura MODIFY total int(6) default 0;

-- Modificaciones tabla presupuesto
ALTER TABLE presupuesto MODIFY numero varchar(55) not null collate utf8_general_ci;
ALTER TABLE presupuesto MODIFY total int(6) default 0;
ALTER TABLE presupuesto MODIFY validez int(6) default 0;
ALTER TABLE presupuesto MODIFY duracion int(6) default 0;
ALTER TABLE presupuesto MODIFY objetivo text default null collate utf8_general_ci;

-- Modificaciones tabla receta
ALTER TABLE receta MODIFY observaciones text default null collate utf8_general_ci;
ALTER TABLE receta MODIFY texto text default null collate utf8_general_ci;
ALTER TABLE receta MODIFY resumen text default null collate utf8_general_ci;

-- Modificaciones tabla linea factura
ALTER TABLE linea_factura MODIFY cantidad int(3) default 0;
ALTER TABLE linea_factura MODIFY total int(6) default 0;

-- Modificaciones tabla linea visita
ALTER TABLE linea_visita MODIFY cantidad int(3) default 0;
ALTER TABLE linea_visita MODIFY total int(6) default 0;

-- Modificaciones tabla linea presupuesto
ALTER TABLE linea_presupuesto MODIFY cantidad int(3) default 0;
ALTER TABLE linea_presupuesto MODIFY total int(6) default 0;

-- Modificaciones tabla paciente
ALTER TABLE paciente DROP COLUMN alto_riesgo;
ALTER TABLE paciente MODIFY extension varchar(3) default null;
ALTER TABLE paciente MODIFY observaciones text default null collate utf8_general_ci;
ALTER TABLE paciente MODIFY alertas_medicas text default null collate utf8_general_ci;
ALTER TABLE paciente MODIFY profesion varchar(255) default null collate utf8_general_ci;
ALTER TABLE paciente MODIFY ciudad varchar(255) default null collate utf8_general_ci;

-- Modificaciones tabla opciones
ALTER TABLE opciones MODIFY nif varchar(9) default null collate utf8_general_ci;
ALTER TABLE opciones MODIFY telefono varchar(13) default null collate utf8_general_ci;
ALTER TABLE opciones MODIFY cp varchar(5) default null collate utf8_general_ci;
ALTER TABLE opciones MODIFY gabinetes int(2) default 0;
ALTER TABLE opciones MODIFY ciudad varchar(255) default null collate utf8_general_ci;

