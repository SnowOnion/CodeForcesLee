def start():
    w,m,k=map(int,raw_input().split(' '))
    num=w/k
    rst=''
    lenny=0
    while True:
        rst+=str(m)
        if len(rst)>num:
            break
        else:
            m+=1
            lenny+=1
        
    print lenny

start()
