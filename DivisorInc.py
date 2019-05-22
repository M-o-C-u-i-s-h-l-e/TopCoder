from math import sqrt

inf = int(7777777)
n, m = int(input()), int(input())
ls = [inf] * 100001
ls[n] = 0
for i in range(n, m+1):
	if ls[i] != inf:
		for j in range(2, int(sqrt(i))+1):
			if i % j == 0:
				temp = i + j
				if temp <= m:
					ls[temp] = min(ls[temp], ls[i]+1)
				temp = i + i // j
				if temp <= m:
					ls[temp] = min(ls[temp], ls[i]+1)
print(-1) if ls[m] == inf else print(ls[m])
