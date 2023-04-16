from pickle import FALSE
import mysql.connector
mycon = mysql.connector.connect(host = "localhost", user = "root", password = "12345",database="connect")
if mycon.is_connected() == FALSE :
    print("Error Connecting to MySQL database ")


cursor = mycon.cursor()
cursor.execute ("select * form company")