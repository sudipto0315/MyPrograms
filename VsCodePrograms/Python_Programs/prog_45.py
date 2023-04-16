import mysql.connector
con = mysql.connector.connect(
    host = "localhost",
    user = "root",
    password = "12345",
    database="connect"
)
cur = con.cursor()
sql= "insert into Company(Name,Dept,Salary) values(%s,%s,%s)"
val = ("ABC","DBA",35000)
cur.execute(sql,val)
con.commit()