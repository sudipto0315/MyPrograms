SCORE = {"KAPIL":40,"SACHIN":55,"SAURAV":80, "RAHUL":35,"YUVRAJ":110}
def PUSH(S,R):
    S.append(R)
def POP(S):
    if S!=[]:
        return S.pop()
    else:
        return None 
ST=[]
for k in SCORE:
    if SCORE [k]>49:
        PUSH(ST,k)
    while True:
        if ST!=[]:
            print (POP(ST),end="")
        else:
            break
