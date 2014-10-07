def start():
	n,k=map(int,raw_input().split(' '))
	a=map(int,raw_input().split(' '))

	if a[k-1]==0:
		for i in range(k-2,-1,-1):
			if a[i]!=0:
				print i+1
				return
		print 0
	else:
		# benchmark=a[k-1]
		for i in range(k,len(a)):
			if a[i]<a[k-1]:
				print i
				return
		print n

start()