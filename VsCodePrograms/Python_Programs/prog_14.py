def Hcount():
    f = open (r'C:\Users\SUDIPTO RAY\Desktop\vs code programs\story.txt')
    h = 0
    a = f.readlines()
    for i in a:
        if i[0]=='H':
            h+=1
    print("no of lines starting with H is ",h)
Hcount()