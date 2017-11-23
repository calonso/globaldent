-- -----------------------------------------------------
-- Name: Schema-0.2.3.sql
-- Author: Carlos Alonso Pérez
-- Date: 13/10/2009
-- Description: Schema that adds a new column at visitas 
--    table for those visits where the patient is absent
-- ------------------------------------------------------

USE gbd;

ALTER TABLE visita ADD COLUMN fsa BOOLEAN NOT NULL DEFAULT 0 AFTER id_usuario;

COMMIT;
