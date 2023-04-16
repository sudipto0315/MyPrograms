ST=[]
def push(N):
    for i in N:
        if i%5==0:
            ST.append(i)
    print(i)
    pop()
def pop():
    if ST == 0:
        print("EMPTY")
    else:
        print(ST.pop())
#main
N=[2,5,10,13,20,23,45,56,60,78]
push(N)
