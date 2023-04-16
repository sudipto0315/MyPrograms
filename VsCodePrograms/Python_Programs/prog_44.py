def push(RollNo):
	Stack.append(RollNo)
	print ('Element:', RollNo , 'inserted successfully')
def pop():
	if Stack == []:
		print('Stack is empty!')
	else:
		print('Deleted element is',Stack.pop())

Stack=[1,2,3]
n=int(input("enter the roll nos : ")) 
push(n)
print(Stack)
pop()
print(Stack)

