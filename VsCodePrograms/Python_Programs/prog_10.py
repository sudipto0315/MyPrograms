import pickle 
e = {'Namita':25000,'Manya':30000,'Tanu':20000}
f1=open('emp.dat','wb')
pickle.dump(e,f1)
f1.close()
