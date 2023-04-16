n=1
MyValue=[1,2,3,4]
def Push(value):
    MyValue.append(value) 

while n<=3 :
    value=int(input("Enter any no "))
    Push(value)
    print(MyValue)
    n=n+1
print ("Stack is full")
