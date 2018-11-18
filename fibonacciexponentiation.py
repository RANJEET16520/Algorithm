def multipy(a,b):
	c = [[0,0],[0,0]]
	#	print(c)
	for i in range(2):
		for j in range(2):
			for k in range(2):
				c[i][j]+=(a[i][k]*b[k][j])
				# print(c[i][j])
	# print(c)
	return c

def binary(b,n):
	a = [[1,0],[0,1]]
	# print(b,a)
	while n>0:
		if n&1:
			a = multipy(a,b)
		b = multipy(b,b)
		n>>=1
	return(a)
mod = int(1e9+7)
b = [[1,1],[1,0]]
t = int(input())
while t>0:
	t-=1
	x,y = input().split()
	x,y = int(x), int(y)
	result1 = binary(b,x+1)
	result2 = binary(b,y+2)
	ans1 = (result1[1][0])%mod
	ans2 = (result2[1][0])%mod

	print((ans2-ans1)%mod)
