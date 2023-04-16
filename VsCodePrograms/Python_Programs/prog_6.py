f = open (r'C:\Users\SUDIPTO RAY\Desktop\vs code programs\my2.txt')
lines = f.readlines()
count = 0
for a in lines:
    if a[0]=="A" or a[0]=="a":
        count = count + 1
print("Total Lines is ",count)
f.close()
