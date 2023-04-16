import mysql.connector
myconn = mysql.connector.connect(
    host = "localhost",
    user = "root",
    password = "12345",
    database="connect")
mycursor = myconn.cursor()
mycursor.execute('CREATE DATABASE IF NOT EXISTS XIICS') 
mycursor.execute('USE XIICS')
mycursor.execute("""
    CREATE TABLE IF NOT EXISTS Student ( 
        rollNo INT PRIMARY KEY,
        firstName VARCHAR(15) NOT NULL,
        lastName VARCHAR(15) NOT NULL,
        class INT NOT NULL,
        city VARCHAR(20)
    );
""")
myconn.commit()
myconn.close()
print("Database and Table created successfully")