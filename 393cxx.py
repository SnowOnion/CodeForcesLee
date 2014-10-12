nn=int(raw_input())
from math import sqrt

if not nn:
	print 1
	
else:

	for n in range(1,nn+1):
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

		print n, edger*4 , int(n/sqrt(2))*8,