SALES={"sunil":700000,"rohit":400000,"rajeev":350000,"mayank":750000,"rahul":1000000}
def PUSH(s,n):
    s.append(n)
def POP(s):
    if s!=[]:
        return s.pop()
    else:
        return None
#__main__
ST=[]
for k in SALES:
    if SALES[k]>500000:
        PUSH(ST,k)
    while True:
        if ST!=[]:
            print (POP(ST),end=" ")
        else:
            break

