# @status AC

n,m=map(int,raw_input().split(' '))
a=map(int,raw_input().split(' '))
b=map(int,raw_input().split(' '))

# a.reverse()
# b.reverse()

aptr,bptr=len(a)-1,len(b)-1
comeup=0

while True:
	if aptr<0: # end
		break
	elif bptr<0: # not enough
		aptr-=1
		comeup+=1
	elif a[aptr]>b[bptr]: # can't satisfy
		aptr-=1
		comeup+=1
	else: # normal
		aptr-=1
		bptr-=1

print comeup
		