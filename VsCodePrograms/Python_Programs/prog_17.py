def write():
    f=open("myfile.txt",'w')
    while True:
        line = input("enter the lines")
        f.write(line+"\n")
        choice = input("are there any more lines ?")
        if(choice == "yes"):
            continue
        else:
            break
    f.close()
write()
