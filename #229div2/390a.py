n=int(raw_input())
xlist=[]
ylist=[]

for t in xrange(n):
	x,y=map(int,raw_input().split(' '))
	if xlist.count(x)==0:
		xlist.append(x)
	if ylist.count(y)==0:
		ylist.append(y)

print len(xlist) if len(xlist)<len(ylist) else len(ylist)