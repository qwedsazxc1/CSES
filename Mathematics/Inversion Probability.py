from decimal import *
getcontext().prec = 200

n = int(input())
arr = input().split(" ")

ans = Decimal(0.0)
for i in range(n):
	arr[i] = int(arr[i])
	for j in range(i):
		temp = 0
		if arr[j] > arr[i]:
			temp = (arr[i] * (arr[i] - 1)) / 2
			temp += (arr[j] - arr[i]) * arr[i]
		else:
			temp = (arr[j] * (arr[j] - 1)) / 2
		ans += Decimal(temp) / Decimal(arr[i] * arr[j])

print("%.6f" % ans)
