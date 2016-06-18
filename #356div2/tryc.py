#coding=utf8
#py3

# rst=[]
# for n in range(2,101):
# 	my=[]
# 	if n%2==0:
# 		my.append(1)
# 	else:
# 		my.append(0)
# 	for fac in range(3,41,2):
# 		if n%fac==0:
# 			my.append(1)
# 		else:
# 			my.append(0)
# 	rst.append(my)

# for mm in rst:
# 	for nn in rst:
# 		if id(mm)!=id(nn) and mm==nn:
# 			print("guiquan zhenluan!")

	

rst=[0,1]
for n in range(2,101):
	my=[0]*101
	for fac in range(2,101):
		if n%fac==0:
			my[fac]=1
	rst.append(my)

for n in range(2,101):
	print('%3d'%n,rst[n])

	# 根本不是让我求出这个数呀... 傻子

# for mm in rst:
# 	for nn in rst:
# 		if id(mm)!=id(nn) and mm==nn:
# 			print("guiquan zhenluan!")
# 		