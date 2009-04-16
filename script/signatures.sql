USE gbd;

ALTER TABLE presupuesto DROP COLUMN extension;
ALTER TABLE presupuesto ADD COLUMN firma VARCHAR(2048) default null collate utf8_general_ci;

ALTER TABLE factura DROP COLUMN extension;
ALTER TABLE factura ADD COLUMN firma VARCHAR(2048) default null collate utf8_general_ci;

ALTER TABLE consentimiento DROP COLUMN extension;
ALTER TABLE consentimiento ADD COLUMN firma VARCHAR(2048) default null collate utf8_general_ci;

ALTER TABLE consentimiento_revocado DROP COLUMN extension;
ALTER TABLE consentimiento_revocado ADD COLUMN firma VARCHAR(2048) default null collate utf8_general_ci;

ALTER TABLE consentimiento_revocado DROP COLUMN extensionr;
ALTER TABLE consentimiento_revocado ADD COLUMN firmar VARCHAR(2048) default null collate utf8_general_ci;
