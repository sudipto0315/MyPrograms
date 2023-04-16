def IMStartCount():
    f=open(r'C:\Users\SUDIPTO RAY\Desktop\vs code programs\my3.txt')
    s=f.readlines()
    print(s)
    c=0
    for l in s:
        if l[0] in "IM":
            c+=1
    print("No of lines starting with I or M :",c)
IMStartCount()
