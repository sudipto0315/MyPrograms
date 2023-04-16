ST=[]
def PUSH(SALES):
    for i in SALES:
        if SALES[i]>500000:
            ST.append(i)
    print(ST)
    POP()
def POP():
    if len(ST)==0:
        print("EMPTY")
    else:
        ST.pop()

#main
SALES={"sunil":700000,"rohit":400000,"rajeev":350000,"mayank":750000,"rahul":1000000}
PUSH(SALES)


