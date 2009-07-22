
import MySQLdb
import os

BASEDIR = '/dev/apache/htsdocs/globaldent/imagenes/1/id%s'

db = MySQLdb.connect(host='localhost', user='root', passwd='root', db='gbd')
cursor = db.cursor()
sql = "select id_paciente from paciente"
cursor.execute(sql)
resultado = cursor.fetchall()

for id in resultado:
	if not os.path.exists(BASEDIR % id):
		print "No existe %s" % id
		os.mkdir(BASEDIR % id)


