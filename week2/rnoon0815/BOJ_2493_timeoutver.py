


#2493 - 시간 초과.

# 큐나 덱은 deque로, stack은 리스트로 접근하는 게 나음.

n = int(input())
towers = list(map(int, input().split()))
# towers[-1] == 4


S = [] # 더 큰 tower들 넣을 stack


for i in range(n):
  if towers[i] == max(towers): # 가장 높은 타워일 때
    print("0")
  elif i == 0: # top 일 때
    print("0")
  else:
    for tower in towers[:i]: # 여기 이중 반복문이 문제.
      if tower >= towers[i]:
        S.append(tower)
    temp = S[-1]
    print(towers.index(temp)+1)







