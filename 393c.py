n=int(raw_input())

if not n:
	print 1
elif n>=400000:
	from math import sqrt
	print int(n/sqrt(2))*8
else:

	x=n
	y=0
	edger=0

	def d(x,y):
		import math
		return math.sqrt(x*x+y*y)

	while not(x==0 and y==n):
		# print x,y
		if d(x,y+1)-n<0.000001:
			y+=1
		elif d(x-1,y+1)-n<0.000001:
			x-=1
			y+=1
		else:
			x-=1
		edger+=1
		# if edger%4000000==1:
		# 	print edger

	print edger*4