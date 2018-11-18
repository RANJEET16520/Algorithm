'''NON-RECURSIVE'''

# def binpower(a,n):
# 	res = 1
# 	cur = a
# 	while n>0:
# 		if n&1:
# 			res *= cur
# 		cur *= cur
# 		n>>=1
# 	return res

'''RECURSIVE'''
def recubinpower(a,n):
	if n is 1:
		return a
	res = recubinpower(a,n//2)
	return res*res*(a if n%2 is not 0 else 1)
a, n = input().split()
a, n = int(a), int(n)
# print(binpower(a,n))
print(recubinpower(a,n))