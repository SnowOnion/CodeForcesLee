#coding=utf8
#@status RE. python function stack depth<1000.(python 2.7.3)

# n,a,b,c E [1,4000]
N=4000+10
n=0
a=0
DP=[-1 for i in xrange(N)]
DP[0]=0

def init():
	global n,a,dic
	lalala=map(int,raw_input().split(' '))
	n=lalala[0]
	a=lalala[1:]

'''r:=restLength'''
def dp(r):
	# print 'call dp',r
	if DP[r]!=-1:
		return DP[r]

	# print 'Eval dp',r

	DP[r]=-200000 # needed?# yes

	#for each sublength
	for ai in a:
		if r>=ai: # able to transfer that way
			DP[r]=(lambda x:x if DP[r]<x else DP[r])(dp(r-ai)+1)
	return DP[r]

init()
print dp(n)