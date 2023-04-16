from time import sleep
f = open (r'C:\Users\SUDIPTO RAY\Desktop\vs code programs\my2.txt')
lines = f.read()
count = 0
for a in lines:
    if lines.isupper():
        count = count + 1
print("Total no of upper case letter is ",count)
f.close()
sleep(1.5*60)