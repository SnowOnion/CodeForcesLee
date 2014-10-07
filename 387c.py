# coding=utf8
# @status Go To Hell. 还需要学习一个. 目前是 test 9 RE. "lc=rc+((-rightDigits+1) if -rightDigits+1>=0 else 0) #optimize" 突破了 test 8 TLE.
# http://codeforces.com/problemset/problem/387/C

# slice, slice, slice. from right to left.
src=[raw_input()] # Don't remove(ele) directly in a for loop... trap exists
tar=[]
trans=[]
tarnum=0

def theSplit(decStr):
	global tarnum # 学习一个... @GET
	thisSplit=[]
	lc=rc = len(decStr)-1 # left cursor, right cursor
	right=0
	rightDigits=1
	currentDigits=1
	while True:# when each loop ends, 'right' should be decided to be a certain one (maybe able to split again,
	# but not to be modified this time)

		while decStr[lc]=='0' or currentDigits<rightDigits:
			lc-=1 # a little optimization, avoid some meaningless int(str)
			currentDigits+=1

		# now decStr[lc:rc+1] must be a valid (positive) integer, and have a chance to >= 'right' 

		current=int(decStr[lc:rc+1])
		# print 'CURRENT',current
		if current<right:
			lc-=1 # why would lc>0 after -=1? because int(decStr[0:rc+1]) is HOPEFUL.
			currentDigits+=1
			current=int(decStr[lc:rc+1])
		# now current > right

		# is remaind part in the left HOPEFUL? if not, merge them into 'current'; if yes, start a new traval
		# @OPTIMIZED
		if lc>currentDigits or (lc==currentDigits and int(decStr[0:lc])>=current) : # HOPEFUL. split here.
			
			#@optimize: 1-digit, 2-digit-and-left<right, 1-digit-non-zero-then-zeros -> 'tar'
			if (rc==lc)	or (rc-lc==1 and decStr[lc]<decStr[rc]):
				''' or decStr[lc+1]=='0' '''
				# tar.append(decStr[lc:rc+1])
				tarnum+=1
			else:
				thisSplit.append(decStr[lc:rc+1])

			right=current
			rightDigits=currentDigits
			currentDigits=1
			rc=lc-1
			lc=rc+((-rightDigits+1) if -rightDigits+1>=0 else 0) #optimize
			#continue
		else: 
			thisSplit.append(decStr[0:rc+1])
			break

		if lc<0:
			break

	# print '===before extend, thisSplit:', thisSplit

	if len(thisSplit)==1:
		# tar.extend(thisSplit)
		tarnum+=1
	else:
		trans.extend(thisSplit)


while len(src)>0:
	for ele in src:
		# print 'ele',ele
		theSplit(ele) # middle product in 'trans', final product in 'tar'
	src=trans
	trans=[]
	# print '---big loop ends'
	# print 'src if next big loop',src

# print trans
# print len(tar)
print tarnum
