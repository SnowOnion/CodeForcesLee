n,k,w=map(int,raw_input().split(' '))
craw=raw_input()
c=map(int,list(craw))

# op of [l,l+k-1] for each l
oplst=[-1 for xx in xrange(n+10)]
opxmat=[[-1 for xx in xrange(n/k+10)] for xx in xrange(n+10)]

def opl(l):
	# print 'l='+str(l)
	if oplst[l]!=-1:
		# print 'oplst['+str(l)+' is '+str(oplst[l])
		return oplst[l]
	else:
		oplst[l]=craw[l-1:l-1+w-1].count('1')+ 1 if craw[l-1+k]=='0' else 0
		return oplst[l]

def oplx(l,num):
	if num==1:
		return opl(l)
	else:
		for iter in range(2,num+1)

for t in xrange(w):
	op=0
	l,r=map(int,raw_input().split(' '))
	# for x in map(lambda x:x+1, range(l,r+1,w)):
	for x in xrange(l,r+1,k):
		op+=opl(x)
	print op