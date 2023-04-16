f=open("Letter.txt","r")
s=f.read()
f.close()
f1=open("Vowel.txt","w")
f2=open("Other.txt","w")
for w in s.split():
    if w[0] in "AEIOUaeiou":
        f1.write(w+" ")
    else:
        f2.write(w+" ")
f1.close()
f2.close()
