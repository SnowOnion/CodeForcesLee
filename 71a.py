n=int(raw_input())
for i in xrange(n):
  print (lambda word:word if len(word)<=10 else word[0]+str(len(word)-2)+word[-1])(raw_input())