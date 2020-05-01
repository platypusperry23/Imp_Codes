fname = input("Enter file name: ")
if len(fname) < 1 : fname = "mbox-short.txt"

fh = open(fname)
count = 0

for s in fh:
    if s.startswith('From'):
		sto=s.split()
		print(sto[1])
		count=count+1
    else:
        continue
        
print ('There were',count,'lines int the file with From as the first word')
