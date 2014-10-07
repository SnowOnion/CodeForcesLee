n=int(raw_input())
a=map(int,raw_input().split(' '))

a1,a2,a3=[],[],[]

for ai in a:
	if ai<0:
		a1.append(ai)
	elif ai>0:
		a2.append(ai)
	else:
		a3.append(ai)

# if empty set not allowed then:

if len(a2)==0:
	a2.append(a1.pop())
	a2.append(a1.pop())

# correctness guarantee
if len(a1)%2==0:
	a3.append(a1.pop())

def printResult(lst):
	print len(lst),
	for x in lst:
		print x,
	print ''	

map(printResult,[a1,a2,a3])