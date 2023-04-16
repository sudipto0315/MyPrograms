N=[2,5,10,13,20,23,45,56,60,78]
def push(ST,k):
    ST.append(k)
def pop(ST):
    if ST!=[]:
        return ST.pop()
    else:
        return None
#main
ST=[]
for k in N:
    if k%5==0:
        push(ST,k)
    while True :
        if ST!=[]:
            print(pop(ST),end=" ")
        else:
            break