def start():
    n=input()
    l=[]
    for i in xrange(n):
        l.append(input())

#print n,l
    l.sort(reverse=True)
#print l

    visible=0
    canhold=True
    while canhold and len(l)>0:
        canhold=False
        ideal=l[0]/2
        for ele in l:
            if ele<=ideal:
                print 'l0',l[0],'ele',ele
                l.remove(l[0])
 #               print l
                l.remove(ele)
  #              print l
                canhold=True
                visible+=1
                break

    print len(l)+visible

start()
