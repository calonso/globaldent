USE gbd;

ALTER TABLE presupuesto MODIFY COLUMN numero INTEGER NOT NULL DEFAULT 0;
ALTER TABLE presupuesto DROP COLUMN extension;
ALTER TABLE presupuesto ADD COLUMN firma MEDIUMBLOB;

ALTER TABLE factura MODIFY COLUMN numero INTEGER NOT NULL DEFAULT 0;
ALTER TABLE factura DROP COLUMN extension;

ALTER TABLE consentimiento DROP COLUMN extension;
ALTER TABLE consentimiento ADD COLUMN firma MEDIUMBLOB;

ALTER TABLE consentimiento_revocado DROP COLUMN extension;
ALTER TABLE consentimiento_revocado DROP COLUMN extensionr;
ALTER TABLE consentimiento_revocado DROP COLUMN fecha_r;
ALTER TABLE consentimiento_revocado DROP COLUMN id_paciente;
ALTER TABLE consentimiento_revocado DROP COLUMN id_tipo_consentimiento;
ALTER TABLE consentimiento_revocado ADD COLUMN firma MEDIUMBLOB;
ALTER TABLE consentimiento_revocado CHANGE COLUMN id_consentimiento id_consentimiento_revocado INTEGER UNSIGNED auto_increment;
ALTER TABLE consentimiento_revocado ADD COLUMN id_consentimiento INTEGER UNSIGNED;
ALTER TABLE consentimiento_revocado ADD INDEX id_consentimiento(id_consentimiento),
 ADD CONSTRAINT FK_consentimiento_revocado_1 FOREIGN KEY FK_consentimiento_revocado_1 (id_consentimiento)
    REFERENCES consentimiento (id_consentimiento)
    ON DELETE CASCADE
    ON UPDATE RESTRICT;

ALTER TABLE consentimiento_revocado ADD CONSTRAINT FK_consentimiento_revocado_2 FOREIGN KEY FK_consentimiento_revocado_2(id_usuario)
    REFERENCES usuario (id_usuario)
    ON DELETE CASCADE
    ON UPDATE RESTRICT;
