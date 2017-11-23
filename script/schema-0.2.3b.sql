-- -----------------------------------------------------
-- Name: Schema-0.2.3b.sql
-- Author: Carlos Alonso Pérez
-- Date: 28/10/2009
-- Description: Schema that adds a new column at facturas
--  table to store detailed text instead of a service id
--  Also make the foreign key id_servicio nullable for this purpose
-- ------------------------------------------------------

USE gbd;

ALTER TABLE linea_factura ADD COLUMN texto VARCHAR(255);

COMMIT;