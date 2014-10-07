
# CodeForces #233a

n,p,k=map(int,raw_input().split(' '))

if p-k>1:
	print '<<',
for x in range(max(p-k,1),min(p+k,n)+1):
	if x==p:
		print '(%d)'%(p),
	else:
		print x,
if p+k<n:
	print '>>'
