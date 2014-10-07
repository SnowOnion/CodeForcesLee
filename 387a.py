# @status AC

'''hh:mm
hh in the 24-hour format
'''
def hhmm2m(hhmm):
	h,m=map(int,hhmm.split(':'))
	return h*60+m

def m2hhmm(m):
	mm=m%60
	hh=(m/60)%24
	return '%02d:%02d'%(hh,mm)

print m2hhmm( hhmm2m(raw_input()) - hhmm2m(raw_input()) )