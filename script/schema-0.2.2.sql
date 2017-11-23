-- ---------------------------------------------------------------------
-- Name: schema-0.2.2.sql 
-- Author: Carlos Alonso Pérez
-- Description: Removes the foreign keys referencing usuario and
--  personal to be able to register forbidden logs and adds an ip
--  field to get track os possible attacks.
-- ---------------------------------------------------------------------


USE gbd;

ALTER TABLE log ADD COLUMN ip VARCHAR(15) AFTER id_tipo_log, 
DROP INDEX id_usuario, 
DROP INDEX id_personal,
DROP FOREIGN KEY log_ibfk_14,
DROP FOREIGN KEY log_ibfk_15;

ALTER TABLE tipo_consentimiento DROP COLUMN descripcion;
