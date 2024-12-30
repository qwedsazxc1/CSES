
n = int(input())
arr = input().split(" ")

num = 0
den = 1
for i in range(n):
	arr[i] = int(arr[i])
	for j in range(i):
		temp = 0
		if arr[j] > arr[i]:
			temp = (arr[i] * (arr[i] - 1)) // 2
			temp += (arr[j] - arr[i]) * arr[i]
		else:
			temp = (arr[j] * (arr[j] - 1)) // 2
		den2 = arr[i] * arr[j]
		num *= den2
		num += den * temp
		den *= den2

num *= 1000000
res = num // den
rem = num % den
l = res // 1000000
r = res % 1000000
rem *= 2
if rem > den:
	r += 1
elif rem == den and r % 2 == 1:
	r += 1

if r == 1000000:
	l += 1
	r = 0

r = str(r)
print(f"{l}.{r.zfill(6)}")
