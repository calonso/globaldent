USE gbd;

-- Vistas para la proxima_cita

create or replace view dias_horas as
select id_cita, DATEDIFF(STR_TO_DATE(fecha, '%d-%m-%Y'), CURDATE()) as dias, subtime(hora, curtime()) as horas FROM cita;

create or replace view proxima_cita as
select id_paciente, fecha, hora, gabinete, tipo, id_usuario from
dias_horas as d join cita on (d.id_cita = cita.id_cita)
where dias >= 0 and id_paciente is not null and horas >= case when dias = 0 then 0 when dias > 0 then -1000 end order by dias asc;

-- Vistas para saldos

create or replace view costes_view as
select id_paciente, sum(precio) as precio from visita group by id_paciente;

create or replace view pagos_view as
select id_paciente, sum(total_tarjeta + total_efectivo) as pagado from pagopac group by id_paciente;

create or replace view saldo_view as
select c.id_paciente as id_paciente, IFNULL(pagado,0) - IFNULL(precio,0) as saldo, nombre, apellido, apellido2 from
costes_view as c
left outer join pagos_view as s on (c.id_paciente = s.id_paciente)
inner join paciente as p on (c.id_paciente = p.id_paciente);
