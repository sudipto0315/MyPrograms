'''
Explain rowcount() function with an example
'''
import mysql.connector
myconn=mysql.connector.connect(host='localhost',user='root',password='12345',database='xiics')
c=12
mycursor=myconn.cursor()
mycursor.execute('select rollNo,firstName,lastName FROM Student WHERE class = %s',(c,))
records= list(mycursor.fetchall())
print("No of rows affected: ",mycursor.rowcount)
print ("The collected records are : ", records)
myconn.close()
