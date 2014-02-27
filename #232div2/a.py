# @status AC

n=int(raw_input())
pairs=[
map(int,raw_input().split(' '))
for x in xrange(n)
]

# print pairs

rightgot=[False for x in xrange(100)]

for i in range(1,n):
	for j in range(pairs[i][0],pairs[i][1]):
		rightgot[j]=True

print rightgot[pairs[0][0]:pairs[0][1]].count(False)
