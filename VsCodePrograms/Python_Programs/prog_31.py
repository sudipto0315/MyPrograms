def funstr(S):
    T=""
    for i in S:
        if i.isdigit():
            T=T+i
    return T
X ="PYTHON 3.9"
Y = funstr(X)
print (X,Y,sep="*")