a = []
def Push (player):
    for i in D:
        if D[i]>49:
            a.append(i)
    print(a)
    pop() 
def pop():
    if len(a)==0:
        print("The stack is empty")
    else:
        a.pop()
      #  print(a)
D={"kapil":40, "sachin":55, "sourav":80, "rahul":35,"yuvraj":110}
Push(D)


