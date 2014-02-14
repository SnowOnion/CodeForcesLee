#385 div2 b

istr=raw_input()

#print istr.find("bear")

pairs=0
while True:
    ind=istr.find('bear')
    if ind<0:
###        print "not found"
        break
    else:
   #     print 'found'
        pass
    
    pairs += (ind+1)*(len(istr)-ind-3)
    istr=istr[ind+1:]

print pairs
