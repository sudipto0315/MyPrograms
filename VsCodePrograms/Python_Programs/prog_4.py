num = 0
f = open (r'C:\Users\SUDIPTO RAY\Desktop\vs code programs\my1.txt')
#n = f.read()
#m = n.split()
m = f.read().split()
for x in m:
    if x=="Me" or x=="My" or x=="me" or x=="my":
        num = num+1
        f.close()
print ("Count of Me/My in file: ",num)
