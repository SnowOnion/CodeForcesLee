# AC # @GET Embrace the "a if p else b" expression!!!

n, m = map(int, raw_input().split(' '))
ndc = (n / 2) + (n % 2)
if m == 1:
    print 1
elif 0 < m and m < ndc:
    print (ndc / m) * m + (m if ndc % m > 0 else 0)
elif ndc <= m and m <= n:
    print m
else:
    print -1