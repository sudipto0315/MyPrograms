def bubble_Sort(list1):
    n = len(list1)
    for i in range(n):
        for j in range(0, n-i-1):
            if list1[j] > list1[j+1] :
                list1[j], list1[j+1] = list1[j+1], list1[j]
numList = [] 
maximum = int(input("How many elements in your list? "))
print("Enter each element and press enter: ")
for i in range(0,maximum):
    n = int(input())
    numList.append(n)
bubble_Sort(numList)
print ("The sorted list is :")
for i in range(len(numList)):
    print (numList[i], end="")