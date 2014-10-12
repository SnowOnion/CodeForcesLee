#coding=utf8
# I don't know about this author. LEE said.
# @status Thanks God AC
# write-only

def start():
	def has(lst,ele):
		return lst.count(ele)>0

	n,m=map(int,raw_input().split(' '))
	mlist=[
	map(int,raw_input().split(' '))
	for i in xrange(m)
	]

	group=[[] for i in xrange(n+10)]

	# desire-satisfy
	# write-only
	# @GET i should use *set* at very first
	# FML
	for mpair in mlist:
		s=set(group[mpair[0]])
		s.add(mpair[1])
		group[mpair[0]]=list(s)
		if len(group[mpair[0]])==2:
			# group[group[mpair[0]][0]].append(mpair[1])
			s=set(group[group[mpair[0]][0]])
			s.add(mpair[1])
			group[group[mpair[0]][0]]= list(s)
			# group[mpair[1]].append(group[mpair[0]][0])
			s=set(group[mpair[1]])
			s.add(group[mpair[0]][0])
			group[mpair[1]]=list(s)
		s=set(group[mpair[1]])
		s.add(mpair[0])
		group[mpair[1]]=list(s)

		if len(group[mpair[1]])==2:
			# group[group[mpair[1]][0]].append(mpair[0])
			s=set(group[group[mpair[1]][0]])
			s.add(mpair[0])
			group[group[mpair[1]][0]]=list(s)
			# group[mpair[0]].append(group[mpair[1]][0])
			s=set(group[mpair[0]])
			s.add(group[mpair[1]][0])
			group[mpair[0]]=list(s)

	####################################
	# print group

	# desire-correctness
	for i in range(1,n+1):
		#FFFFFFFFFFFFFFFFFFFFFFFuck my life
		if group[i].count(i)>0:
			group[i].remove(i) # 忘单词の重造

		g=group[i]
		if len(g)>2:
			####################################
			# print 'len3 break', g
			print -1
			return

	# 3p-satisfy
	for i in range(1,n+1):
		if len(group[i])==1:
			foundPartner=False
			for j in range(i+1,n+1):
				if len(group[j])==0:
					group[j].append(i)
					group[j].append(group[i][0])
					group[i].append(j)
					group[group[i][0]].append(j)
					foundPartner=True
					break
			if not foundPartner:
				####################################
				# print i,group[i],'has no partner'
				print -1
				return

		# one-person-group-satisfy will be done next step

		elif len(group[i])==0:
			# foundPartner=False
			for j in range(i+1,n+1):
				if len(group[j])==1:
					group[i].append(j)
					group[i].append(group[j][0])
					group[j].append(i)
					group[group[j][0]].append(i)
					# foundPartner=True
					break
			# if not foundPartner:
			# 	####################################
			# 	print i,group[i],'has no partner'
			# 	print -1
			# 	return
	# print group

	def printGroupLine(g):
		for mem in g:
			print mem,
		print ''

	# print '='*30

	visit=[False for x in xrange(n+10)]
	temp3=[]
	for i in range(1,n+1):
		if visit[i]:
			continue

		visit[i]=True
		if len(group[i])==0:
			temp3.append(i)
			if len(temp3)==3:
				printGroupLine(temp3)
				temp3=[]
		else: #len==2
			group[i].append(i)
			printGroupLine(group[i])
			visit[group[i][0]]=True
			visit[group[i][1]]=True


start()