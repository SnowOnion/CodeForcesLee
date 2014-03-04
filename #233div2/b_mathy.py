'''
aBRR...R->
aRBB...B

let 1->n denotes top->bottom, when the n-th is blue:
s(n)=
1+s(n-1)+s(n-2)+...+s(1)=
2+2s(n-2)+2s(n-3)+..+2s(1)=
4+4s(n-3)+4s(n-4)+..+4s(1)=
2^(n-1)

@status AC

'''

n=int(raw_input())
ri=raw_input()

op=0
for i in range(n):
	if ri[i]=='B':
		op+=2**i
print op