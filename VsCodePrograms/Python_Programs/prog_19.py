def Findoutput():
    L="earn"
    x=" "
    count=1
    for i in L:
        if i in ['a','e','i','o','u']:
            x=x+i.swapcase()
        else:
            if count%2!=0:
                x=x+str(len(L[:count]))
            else:
                count =  count + 1
    print (x)

Findoutput()

    