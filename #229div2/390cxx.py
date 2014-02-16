
# be careful of the priority of unusual operator...
# @status TLE on test1 =.= forget it. Find a good solution and learn.(390c_BearChild.cpp)

n,k,w=map(int,raw_input().split(' '))
c=map(int,list(raw_input()))

OP=[[-1 for j in xrange(1000000+10)] for i in xrange(10+10)]

'''
calc the op of [r-k+1,r]
'''

one2zero=lambda x:x-1
zero2one=lambda x:x+1

def calc(r):
	# print 'c[r-k:r-1].count(1)',c[r-k:r-1].count(1),' 1^c[one2zero(r)]', 1^c[one2zero(r)]
	# print 'calc',r,(c[r-k:r-1].count(1))+(1^c[one2zero(r)])
	
	return c[r-k:r-1].count(1) + (1^c[one2zero(r)])

def op(z,x):
	if x<=0:
		return 0
	elif OP[z][x]!=-1:
		return OP[z][x]
	else:
		OP[z][x] = op(z,x-1)+calc(x*k+z)
		return OP[z][x]

for t in xrange(w):
	# op=0
	l,r=map(int,raw_input().split(' '))
	z=r%k
	ln=l/k
	rn=r/k
	# print(z,ln,rn),(op(z,rn),op(z,ln))

	print op(z,rn)-op(z,ln)

	