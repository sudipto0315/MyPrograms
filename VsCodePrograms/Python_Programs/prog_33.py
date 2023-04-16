l1 = [10,20,30,20,10]
l2 = []
for i in l1:
    if i not in l2:
        l2.append(i)
print(l1,l2,sep="&")
