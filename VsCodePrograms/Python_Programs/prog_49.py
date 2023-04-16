'''
Write a python database connectivity script that delete records from 'Student' table 
having second character of Surname as 'u'
'''
import mysql.connector
myconn=mysql.connector.connect(host='localhost',user='root',password='12345',database='xiics')
mycursor=myconn.cursor()
mycursor.execute('DELETE FROM Student WHERE lastName LIKE %s',('_u%',))
myconn.commit()
myconn.close()