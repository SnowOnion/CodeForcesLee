#@ status AC

t=int(raw_input())

for time in xrange(t):
	n,l,r=map(int,raw_input().split(' '))

	# xk: exist k, s.t. l*k<=n<=r*k,
	# namely exist k s.t. float(n/r)<=k<=float(n/l), namely int(n/l)>int((n-1)/r)
	# @GET math is good

	if n/l>(n-1)/r:
		print 'Yes'
	else:
		print 'No'