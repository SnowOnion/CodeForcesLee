# @status

# @HISTORY Prime=[-1 for x in xrange(1000000010)] # @GET Your computer will 'Boom'

# @GET simple prime judging algorithm, without Memoization, is fast enough here. Be knowledgeable, be brave.

def isPrime(n):
	for i in xrange(2,n):
		if i*i>n:
			break
		if n%i==0:
			return False
	return True

