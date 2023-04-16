def DISPLAYWORDS():
    f=open (r'C:\Users\SUDIPTO RAY\Desktop\vs code programs\my2.txt')
    st = f.read()
    print(st)
    w = st.split()
    ctr=0
    for i in w:
        if len(i)<4:
            print(i)
            ctr+=1
    print(ctr)
    f.close()
DISPLAYWORDS()
