fh=open("marks.txt","r")
fh.seek(15,0)
str1=fh.read(15)
print("Last 15 bytes of the file content:",str1)
