v=50
def change (n):
    global v
    v,n=n,v
    print (v,n,sep="#",end="@")
change(20)
print (v)