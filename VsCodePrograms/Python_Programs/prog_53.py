L=[]
def Push (a):
    if len(a)<7:
        L.append(a)
print(L)
def Pop():
    if L:
        print(L.pop())
    else:
        print("The stack is empty")
#main
W=['Elucidate','Haughty','Pacify', 'Quip','Rapport', 'Urba ne','Young','Zenith']
Push(W)
for i in W:
    Push(i)
for i in range (len(L)):
    Pop()