import pickle
stu = {}
with open('Stu.dat','ab') as stufile :
    ans='y'
    while ans=='y':
        rno = int(input("Enter roll number:"))
        name = input("Enter name :")
        marks = float (input("enter marks:"))
        stu['RollNo']=rno
        stu['Name']=name
        stu['Marks']=marks
        pickle.dump(stu,stufile)
        ans = input("Want to append more records?(y/n)...")


