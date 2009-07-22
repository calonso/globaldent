ALTER TABLE imagen ADD COLUMN id_grupo_imagen INTEGER UNSIGNED DEFAULT NULL;
ALTER TABLE imagen ADD INDEX id_grupo_imagenes(id_grupo_imagen),
 ADD CONSTRAINT imagen_ibfk_5 FOREIGN KEY imagen_ibfk_5 (id_grupo_imagen)
    REFERENCES grupo_imagenes (id_grupo_imagenes)
    ON DELETE SET NULL
    ON UPDATE NO ACTION;
