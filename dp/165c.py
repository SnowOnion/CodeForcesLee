'''
#9:35
find the num of substrings which contains k '1'
same pattern(literals), different position -> different substrings
0<=k<=10e6 
	# CARE ABOUT k=0,k=1,k>n 
	# k=0 is ridiculous.. # NONONO.. only-0-substrings...
|s|<=10e6
'''

# @status TLE

k=int(raw_input())
s=map(int,list('0'+raw_input()))
n=len(s)-1
dp=[0 for i in range(n+10)]

'''
dp[n]:= sum(i=1,n,s[i])
two ptrs
i like starting with 1...
'''
# if k>0:
for right in range(1,n+1):
	dp[right]=dp[right-1]+s[right]

# print dp

#k for optimization, n for generalizaion, 1 as patch for k=0 case
left,right=1,max(min(k,n),1)

total=0

while True:
	localOne=dp[right]-dp[left-1]
	if localOne==k: #[left,right]~[left,n] ok
		# print '=k',left,right
		total+=1
		if right<n: # patch...
			right+=1
		else:
			left+=1
			right=max(left+k-1,left) # traceback..O(n^2)?
			# patch for k=0... bad design
	elif localOne<k:
		# print '<k',left,right
		right+=1
	else: # localOne>k
		# print '>k',left,right
		left+=1
		right=max(left+k-1,left) # traceback..O(n^2)?

	if right>n:
		break

print total

# else:
# 	print 0

#10:05
#10:21 WA traceback
#10:27 WA k=0
