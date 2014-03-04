
# CodeForces #233b
# TLE

n=int(raw_input())
ri=raw_input()
s=list(ri)
s.reverse()

# print stk

times=0

def rq():
	return len(s)>0 and s[-1]=='R'
def bq():
	return len(s)>0 and  s[-1]=='B'

while s.count('R')<n:
	# print '1111'
	
	while rq():
		# print '2222'
		s.pop()
	s[-1]='R'
	s.extend(['B' for x in xrange(n-len(s))])
	times+=1
	print s

print times