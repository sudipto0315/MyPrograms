def popStack(stack):
    if len(stack)==0:
        print("Error")
    else:
        L = len(stack)
        val=stack[L-1]
        print(val)
        print ("The value deleted is: " , stack.pop(L-1))
stack=[]
maximum = int(input("Enter the no of elements: "))
print("Enter each element and press enter: ")
for i in range(0,maximum):
    n = int(input())
    stack.append(n)
popStack(stack)
