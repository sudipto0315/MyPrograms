d={1:"One",2:"Two",3:"Three"}
l = []
for k,v in d.items():
    if v[0] == "T":
        l.append(k)
print(l)
