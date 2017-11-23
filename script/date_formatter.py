
import MySQLdb
import re

db = MySQLdb.connect(host='localhost', user='root', passwd='root', db='gbd')
cursor = db.cursor()
sql = "select id_paciente, fecha_nacimiento from paciente"
update = "update paciente set fecha_nacimiento = '%s' where id_paciente = %s"
cursor.execute(sql)
resultado = cursor.fetchall()

for row in resultado:
  newDate = row[1];
  if re.search("/", row[1]) != None :
    newDate = re.sub("/", "-", newDate)
  
  newDate = re.sub("-(\d{1,2})$", "-19\g<1>", newDate)
  newDate = re.sub("-(\d{1})-", "-0\g<1>-", newDate)
  newDate = re.sub("^(\d{1})-", "0\g<1>-", newDate)
  cursor.execute (update % (newDate, row[0]))
  print "%s" % update % (newDate, row[0])
      
cursor.close ()
db.commit ()
db.close ()
