s=raw_input()

s=s.lower()
isVowel= lambda lc:'aeiouy'.count(lc)>0
for ch in s:
	if isVowel(ch):
		pass
	else:
		import sys
		sys.stdout.write('.%s'%(ch))
