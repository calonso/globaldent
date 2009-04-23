USE gbd;

ALTER TABLE presupuesto DROP COLUMN extension;
ALTER TABLE presupuesto ADD COLUMN firma MEDIUMBLOB;

ALTER TABLE factura DROP COLUMN extension;

ALTER TABLE consentimiento DROP COLUMN extension;
ALTER TABLE consentimiento ADD COLUMN firma MEDIUMBLOB;

ALTER TABLE consentimiento_revocado DROP COLUMN extension;
ALTER TABLE consentimiento_revocado ADD COLUMN firma MEDIUMBLOB;

ALTER TABLE consentimiento_revocado DROP COLUMN extensionr;
ALTER TABLE consentimiento_revocado ADD COLUMN firmar MEDIUMBLOB;
