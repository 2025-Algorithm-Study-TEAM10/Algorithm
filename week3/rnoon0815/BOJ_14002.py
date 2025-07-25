
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

max_cnt = 0
dp = [1] * N
q = [-1] * N # 최장 길이를 구성하는 요소들의 직전 위치

for i in range(1, N):
    for j in range(0, i):
        if A[i] > A[j]:
            if dp[i] < dp[j] + 1:
                dp[i] = dp[j] + 1
                q[i] = j
                
max_length = max(dp)
max_index = dp.index(max_length)

lis = []
while max_index != -1:
    lis.append(A[max_index])
    max_index = q[max_index]
    
lis.reverse()

print(max(dp))
print(*lis)
