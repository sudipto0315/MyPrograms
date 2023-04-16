file1 = open(r'C:\Users\SUDIPTO RAY\Desktop\my1.txt')
b = file1.read()
a = 0
for i in b:
	if i.isdigit() == True:
		a += 1
print("The sum is:", a)