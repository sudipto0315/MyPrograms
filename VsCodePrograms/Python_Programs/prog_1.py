def puretext():
    f=open(r"C:\Users\SUDIPTO RAY\Desktop\New Text Document (2).txt")
    m=f.read()
    for i in m:
        if (i=='K' or i=='k'):
            print('C',end="")
        else:
            print(i,end="")
    f.close()
puretext()
