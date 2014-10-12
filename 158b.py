n=int(raw_input())
s=raw_input()

n1,n2,n3,n4=map(lambda x:s.count(str(x)),range(1,5))

# print n1,n2,n3,n4

if n3>=n1:
	print n4+n3+n2/2+( 1 if n2%2 else 0 )
else:
	extra=(n2%2)*2+(n1-n3)%4
	print n4+n3+n2/2+(n1-n3)/4+extra/4+( 1 if extra%4 else 0)