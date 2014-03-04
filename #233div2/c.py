a,b=map(int,raw_input().split(' '))

'''
2a>=b: keep xxxoooooooooooxxxx
2a<b: xxxoxoxoxoxoxoxxxx ,loop inside # @TODO nonono!!!!! be more uniform!
xxooooxx
xxxooooxxx

xxxxooooxxxx
xxxxoxxoooxx
xxoxxoxxooxx

xxxxooooxxxxx
'''


if 2*a>=b:
	print a**2-(b/2)**2-(b/2+b%2)**2
	print '%s%s%s'%('x'*(b/2),'o'*a,'x'*(b/2+b%2))
else:
	if a==0:
		print -b**2
		print 'x'*b
	else:
		# br=b-(a-1) #'b remained'
		# # print br,'br'
		# print 1-(br/2)**2-(br/2+br%2)**2
		# print '%s%so%s'%('x'*(br/2),'ox'*(a-1),'x'*(br/2+br%2))
