a = []
def Push (book_name):
    if B[book_name]>8:
        a.append(book_name)
def Pop():
    print(a.pop())
#main
B={"AI 2041: Ten Visions for our future":7.9,
"Beginners: The Transformative Joy of Lifelong Learning":8.5,
"Bravery:Chasing Dreams, Befriending Pain, and other Big Ideas":9,
"Chatter:The Voice in our head,why it matters and how to Harness it":8.2,
"The code breaker Jennifer Doudna, Gene Editing and the future of the Human Race":7.5}
for i in B:
    Push(i)
print (a)
for i in range (len(a)):
    Pop()

