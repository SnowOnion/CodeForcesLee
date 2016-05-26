from fractions import Fraction as F

inin=input().split(' ')
n=int(inin[0])
t=int(inin[1])

mat=[]
for i in range(n):
	line=[]
	for j in range(i+1):
		line.append(F(0))
	mat.append(line)

# for line in mat:
# 	print(line)

def add(i,j,amt):
	if i>=n or j<0 or j>=n:
		return
	mat[i][j]+=amt
	if mat[i][j]>1:
		over=mat[i][j]-1
		mat[i][j]-=over
		add(i+1,j,over/2)
		add(i+1,j+1,over/2)

for time in range(t):
	add(0,0,1)

result=0
for line in mat:
	for b in line:
		if b>=1:
			result+=1
print(result)

for line in mat:
	# print(line)
	for b in line:
		print(str(b),end='\t')
	print()