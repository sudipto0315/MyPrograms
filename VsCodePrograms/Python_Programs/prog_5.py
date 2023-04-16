def AMCount():
    f = open (r'C:\Users\SUDIPTO RAY\Desktop\vs code programs\my2.txt')
    A,M = 0,0
    r = f.read()
    for a in r:
        if a[0] == "A" or a[0] == "a":
            A=A+1
        elif a[0] == "M" or a[0]=="m":
            M=M+1
    f.close()
    print("A or A:",A)
    print("M or m:",M)
AMCount()