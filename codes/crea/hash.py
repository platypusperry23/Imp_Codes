m=int(input())
n=int(input())
x={}
for z in range(n):
	str=input()
	s=str.split()
	if(str.startswith('add ')):
		le=len(s[1])
		su=0
		for i in range(le):
			asc=ord(s[1][i])
			su=(su + (asc * (263**i))%1000000007)%1000000007
		su=su%m
		if su in x:
			if s[1] in x[su]:
				continue
			else:
				s[1]=s[1]+' '
				x[su]=s[1]+x[su]

		else:
			x[su]=s[1]+' '
		#print (x[su])
	
	elif str.startswith('check '):
		le=int(s[1])
		if le in x:
			print(x[le])
		else:
			print ()
	elif str.startswith('find '):
		fl=0
		for i in x.values():
			sx=i
			ad=sx.split()
			if s[1] in ad:
				fl=1
				break
		if fl == 1:
			print ('yes')
		else:
			print ('no')

	elif str.startswith('del '):
		s[1]=s[1]+' '
		ind=-1
		for a,b in x.items():
			if s[1] in b:
				s3=b.replace(s[1],'')
				s3.lstrip()
				x[a]=s3
				x[a].strip()
			else:
				continue
