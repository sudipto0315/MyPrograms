def SHOW_TODO():
    f = open (r'C:\Users\SUDIPTO RAY\Desktop\vs code programs\ABC.txt',"r")
    ch = f.readlines()
    z = ch.upper().split()
    for z in ch:
        if "TO" in z or "DO" in z:
            print(z)         
    f.close()
SHOW_TODO()