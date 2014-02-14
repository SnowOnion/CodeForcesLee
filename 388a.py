# coding=utf8
# http://codeforces.com/problemset/problem/388/A

# @status AC
# @BGM young for you! young for you! YFY! YFY!

n=int(raw_input())
x=map(int,raw_input().split(' '))

# don't know why greedy.. just try

x.sort() # ascending
pilelist=[[]] 
''' Actually it's not necessary to store the specific value of pile element, 
the size of each pile is enough. Well, this is more general.
'''

for xi in x:	
	# targetFound=False
	for pile in pilelist:
		if len(pile)<=xi:
			# targetFound=True
			pile.append(xi)
			break
	else: # means 'if not targetFound'. loop-else is a brilliant...
		pilelist.append([])
		pilelist[-1].append(xi)

print len(pilelist)