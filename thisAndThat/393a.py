s=raw_input()

n,e,i,t=s.count('n'),s.count('e'),s.count('i'),s.count('t')
print min((n-1)/2,e/3,i,t)