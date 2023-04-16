value = 100
def display (N):
    global value
    value = 150
    if N%7 == 0:
        value = value + N
    else:
        value = value - N
print (value, end = '#')
display (50)
print (value)