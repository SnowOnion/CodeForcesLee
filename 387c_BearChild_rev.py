#coding=utf8

'''
@originalAuthor BearChild
@translator SnowOnion
http://blog.csdn.net/keshuai19940722/article/details/18894143
这样的话就可以让每个数都做为一个元素，然后保证第一个比第二个大即可，像滚雪球一样一直和下一个元素相连接，变大。但是因为题目有一个要求，就是说元素不可以为0，所以所有的0都要归结到前面第一个非0元素，这样就导致在滚雪球的时候碰到一个比自己大的雪球，即当前位置的0非常多，记得重新计数。
@status AC
'''

# num=''

c=[]
v=[]

def init():
	# global num
	num=raw_input()

	x=0
	for cur in range(len(num)-1,-1,-1):
		x+=1
		if num[cur]!='0':
			c.append(x)
			v.append(int(num[cur])-int('0'))
			x=0

def solve():
	ans=1
	cnt=c[len(c)-1]
	val=v[len(v)-1]

	for cur in range(len(c)-2,-1,-1):
		if cnt>c[cur] or (cnt==c[cur] and val>=v[cur]):
			ans+=1
		else:
			ans=1 # nice

		cnt+=c[cur] # nice. 要么本来就在一起, 要么合在一起.

	return ans

init()
print solve()
