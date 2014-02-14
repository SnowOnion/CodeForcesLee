def gain(ai,bi):
	if bi>=2 and bi<=2*ai:
		if bi%2==0:
			return bi**2/4
		else:
			return (bi/2)*(bi/2+1)
	else:
		return -1

n=int(raw_input())
a=map(int,raw_input().split(' '))
b=map(int,raw_input().split(' '))

total=0
for i in xrange(n):
	# print gain(a[i],b[i])
	total+=gain(a[i],b[i])

print total