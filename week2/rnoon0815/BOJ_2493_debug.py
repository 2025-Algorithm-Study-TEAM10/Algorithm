
# 2493 - chat gpt ver. (시간초과 해결)
n = int(input())
towers = list(map(int, input().split()))
stack = []  # (index, height) 같이 저장해야 나중에 ,index()로 다시 찾지 않아도 됨. (시간 초과 예방)

for i in range(n):
    while stack and stack[-1][1] < towers[i]: 
        stack.pop()
    if stack:
        print(stack[-1][0] + 1)  # stack[-1][0]이 인덱스, 1-based 출력
    else:
        print(0) # stack에 아무 것도 없는 경우. 즉, 맨 왼쪽 tower
    stack.append((i, towers[i]))

