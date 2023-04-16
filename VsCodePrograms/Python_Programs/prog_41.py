def PUSH(Arr):
    temp=[]
    for x in range(0,len(Arr)):
        if Arr[x]%5==0:
            temp.append(Arr[x])
    if len(temp)==0:
        print("Empty Stack")
    else:
        print(temp)
Arr=[]
maximum = int(input("Enter the no of elements: "))
print("Enter each element and press enter: ")
for i in range(0,maximum):
    n = int(input())
    Arr.append(n)
PUSH(Arr)
