'''Write a python database connectivity script to update the first name
of the student having roll no as 101 in the 'Student' table.'''

import mysql.connector
myconn=mysql.connector.connect(host='localhost', user='root',password='12345',database='xiics')
mycursor=myconn.cursor()
mycursor.execute('UPDATE Student SET firstName="sudipto" WHERE rollNo=101')
print("No of rows affected=",mycursor.rowcount) 
myconn.commit()
myconn.close()