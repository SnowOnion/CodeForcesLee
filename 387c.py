# coding=utf8
# @status Building...

# slice, slice, slice. from right to left.
src=[raw_input()] # Don't remove(ele) directly in a for loop... trap exists
tar=[]
trans=[]

def theSplit(decStr):
	thisSplit=[]
	lc=rc = len(decStr)-1 # left cursor, right cursor
	right=0
	rightDigits=1
	currentDigits=1
	while True:# when each loop ends, 'right' should be decided to be a consistent one (maybe able to split again, but not to be modified this time)
		while decStr[lc]=='0' or currentDigits<rightDigits:
			lc-=1 # a little optimize, avoid some meaningless int(str)
			currentDigits+=1
		# now decStr[lc:rc+1] must be a valid (positive) integer, and have a chance to exceedOrEqual 'right' 

		current=int(decStr[lc:rc+1])
		if current<right:
			lc-=1
			currentDigits+=1
		# now current > right

		# is remaind part in the left HOPEFUL? if not, merge them into 'current'; if yes, start a new traval
		
		
		# thisSplit.append(decStr[lc:rc+1])

		# if lc<=0:
		# 	break
		# else:
		# 	rc=lc-1
		# 	lc=rc


while len(src)>0:
	for ele in src:
