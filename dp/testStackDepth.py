'''
# Runtime:
python 2.7.3 (win)

# Result:
0
1
<...>
998
boom
'''

def f(n):
	print n
	f(n+1)
try:
	f(0)
except:
	print 'boom'