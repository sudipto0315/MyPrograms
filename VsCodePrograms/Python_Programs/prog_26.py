def count():
    f = open (r'C:\Users\SUDIPTO RAY\Desktop\vs code programs\my4.txt')
    lines = 0
    l = f.readlines()
    for i in l:
        if i[0]=='H':
            lines+=1
    print("no of lines starting with H is ",lines)
count()
