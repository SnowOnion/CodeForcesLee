print (lambda n,m,a:(lambda f1,f2: f1*f2)(*map(lambda l:l/a+int(bool(l%a)),[n,m])))(*map(int,raw_input().split(' ')))
# print (lambda n,m,a:(n/a+int(bool(n%a))) * (m/a+int(bool(m%a))))(*map(int,raw_input().split(' ')))

# Long live Codeforces!
# CF don't <mandarin>Ku</mandarin>, stand up and <mandarin>Lu<mandarin>!
# 20140304, Beijing

# @GET trick: int(bool(x))  ==  1 if x then 0 
	# well [valueWhenFalse,valueWhenTrue][x] is also a good idea
# @GET f(*args) : use list or tuple as argument list. other sequencial data sturcture not tested yet.
	# f(**{arg1:xx,arg2:yy})
