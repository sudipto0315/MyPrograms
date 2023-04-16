import csv
f=open(r"C:\Users\SUDIPTO RAY\Desktop\Book1.csv","r")
obj=csv.reader(f)
print(obj)
count=0
for a in obj:
    print(a)
    count+=1
print("no of record =",count)