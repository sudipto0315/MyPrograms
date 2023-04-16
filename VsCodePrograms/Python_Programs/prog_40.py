Stack=[]
def push(Books):
    Stack.append(Books)
print ("Element:', Book, 'inserted successfully")
def pop():
    if Stack == []:
        print("Stack is empty!")
    else:
        print("Deleted element is",Stack.pop())
for i in range (2):
    b = input("Enter book title to insert:")
    push(b)
    print(Stack)

for i in range(2):
    pop()
    print(Stack)