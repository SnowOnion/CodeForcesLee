n=int(raw_input())
a=[]
b=[]
for i in xrange(n):
	inin=map(int,raw_input().split(' '))
	a.append(inin[0])
	b.append(inin[1])

cap=0
need=0
for i in xrange(n):
	cap+=(-a[i]+b[i])
	if need<cap:
		need=cap
print need