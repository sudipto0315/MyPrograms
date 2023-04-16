def VowelCount():
    f = open (r'C:\Users\SUDIPTO RAY\Desktop\vs code programs\my2.txt',"r")
    ch = f.read()
    print(ch)
    a,e,i,o,u = 0,0,0,0,0
    for z in ch:
        if z=="A" or z=="a":
            a += 1
        if z=="E" or z=="e":
            e += 1
        if z=="I" or z=="i":
            i += 1
        if z=="O" or z=="o":
            o += 1
        if z=="U" or z=="u":
            u += 1
    print("Total vowels are: ")
    print("a = ", a)
    print("e = ", e)
    print("i = ", i)
    print("o = ", o)
    print("u = ", u)
    f.close()
VowelCount()