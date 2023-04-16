import pickle
stu = {}
with open ('stu.dat','rb') as fin:
    try:
        print("File emp.dat stores these records")
        while True:
            stu = pickle.load(fin)
            print (stu)
    except EOFError:
        fin.close()
    
