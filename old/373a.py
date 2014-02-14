
def start():
    k=int(raw_input())
    l=[]
    for i  in range(4):
        l+=list(raw_input())

#    print l
        
    able=True
    for i in range(1,10):
        if l.count(str(i))>2*k:
            able=False
            break

    if able:
        print 'YES'
    else:
        print 'NO'
    

start()
