inp =int(input())
ha={}
for e in range(inp):
	s = input()
	if s.startswith('add '):
		x=s.split()
		ha[x[1]]=x[2]

	elif s.startswith('find '):
		x=s.split()
		try:
			print(ha[x[1]])
		except:
			print('not found')

	elif s.startswith('del '):
		x=s.split()
		try:
			ha.pop(x[1])
		except:
			continue

