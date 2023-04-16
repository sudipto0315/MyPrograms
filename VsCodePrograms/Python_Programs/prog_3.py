file1 = open(r'C:\Users\SUDIPTO RAY\Desktop\my1.txt')
b = file1.read()
count =  0
for i in b:
    if( i=='A' or i=='a' or i=='E' or i=='e' or i=='I'or i=='i' or i=='O' or i=='o'or i=='U' or i=='u'):
        count +=1      
print('The Number of Vowels in text file :', count)