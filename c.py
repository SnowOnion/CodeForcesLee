n,k,w=map(int,raw_input().split(' '))
c=map(int,list(raw_input()))

# op of [l,l+k-1] for each l
oplst=[-1 for xx in xrange(n+10)]
opxmat=[[-1 for xx in xrange(n/k+10)] for xx in xrange(n+10)]

def opl(l):
	# print 'l='+str(l)
	if oplst[l]!=-1:
		# print 'oplst['+str(l)+' is '+str(oplst[l])
		return oplst[l]
	else:
		theop=0
		for xx in range(l,l+k-1):
			if c[xx-1]==1:
				# print 'c['+str(x-1)+' is 1'
				theop+=1
		if c[l+k-1-1]==0:
			# print 'c['+str(l+k-1-1)+' is 0'
			theop+=1
		oplst[l]=theop
		return theop

def oplx(l,num):
	if num==1:
		return opl(l)
	else:
		opop=opl(l)
		for iter in range(2,num+1):
			if opxmat[l][iter]!=-1:
				return opxmat[l][iter]
			else:
				newnew=opl(l+(iter-1)*k)
				opop+=newnew
				opxmat[l][iter]=opop
		return opop

for t in xrange(w):
	# op=0
	l,r=map(int,raw_input().split(' '))
	
	print oplx(l,(r-l+1)/k)
	# for x in xrange(l,r+1,k):
	# 	op+=opl(x)
	# print op