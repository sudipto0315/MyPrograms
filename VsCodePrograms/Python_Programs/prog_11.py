def filter(oldfile, newfile):
     f1=open(oldfile,"r")
     f2=open(newfile,"w")
     while True:       
           txt=f1.readline()
           if len(txt)==0:
                 break
           elif txt[0]=="@":
                 continue
           f2.write(txt)
     print("file copied successfully")
     f1.close()
     f2.close()

oldfile = r"C:\Users\SUDIPTO RAY\Desktop\vs code programs\oldfile.txt"
newfile = r"C:\Users\SUDIPTO RAY\Desktop\vs code programs\newfile.txt"
filter(oldfile, newfile)