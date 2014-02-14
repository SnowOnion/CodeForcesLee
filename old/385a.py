n,c=map(int,raw_input().split(' '))
xlst=map(int,raw_input().split(' '))

rst=0
for i in xrange(len(xlst)-1):
   if xlst[i]-xlst[i+1]>rst:
       rst=xlst[i]-xlst[i+1]

if rst>=c:
    print rst-c
else:
    print 0
   
    
