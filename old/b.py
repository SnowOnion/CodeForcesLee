#div2 373b

import math

def start():

    w,m,k=map(int,raw_input().split(' '))
    dm=int(math.log10(m)+1)
    num=w/k

#    print 'dm',dm,'num',num
 #   print '(10**(dm)-m)*dm',(10**(dm)-m)*dm
    
    if (10**(dm)-m)*dm>=num:
        print int(num/dm)
    else:
        num-=(10**(dm)-m)
        delta=1
        lenny=10**(dm)-m
        while True:
     #       print '='*10
      #      print 'dm+delta',dm+delta
       #     print (9*10**(dm+delta))*(dm+delta)###WRONG ARITHMETIC ###NOT WRONG...
        #    print num
         #   print '----------'
            if 9*10**(dm+delta)*(dm+delta)>=num:
                print int(lenny+num/(dm+delta))
                break
            else:
                lenny+=9*10**(dm+delta)
                num-=(9*10**(dm+delta))*(dm+delta)
                delta+=1
    
start()
