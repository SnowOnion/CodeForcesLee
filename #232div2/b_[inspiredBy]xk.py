#@ status AC

t=int(raw_input())

for time in xrange(t):
	n,l,r=map(int,raw_input().split(' '))

	# xk: exist k, s.t. n in [l*k,r*k],
	# namely [n/l]=[n/r]!=0 ? nop...

	k=max(n/r,1) # TLE. then assign a reasonable init value
	while True:
		if n>=l*k and n<=r*k:
			print 'Yes'
			break
		elif n>r*k:
			k+=1
		else:# n<l*k: give up caring
			print 'No'
			break