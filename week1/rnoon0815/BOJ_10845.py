 # 10845 - Queue



# pop 초기 코드. del을 실행하면 모든 요소를 한칸씩 왼쪽으로 밀어 시간복잡도가 O(n)으로 너무 큼.

#def pop(): # 출력 명령
  #if len(Q) == 0: # queue에 아무 것도 들어있지 않을 때
    #print("-1")
  #else:
    #print(Q[0]) # 기존 첫번째 원소 출력
    #del Q[0] # 기존 첫번째 원소 삭제
  #return Q
  

# list보다 deque 자료구조를 추천함. deque: 양방향 큐 구조, 맨 앞/뒤 삽입과 삭제 모두 O(1)
from collections import deque
import sys

Q = deque()

def push(x):
  Q.append(x) # 왼 -> 오 방향으로 쌓임. idx 상 오름차순
  return Q

def pop():
  if len(Q) == 0: # queue에 아무 것도 들어있지 않을 때
    print("-1")
  else:
    print(Q[0])
    Q.popleft()
    return Q

def size(): # 출력 명령
  length = len(Q)
  print(length)

def empty(): # 출력 명령
  if len(Q) == 0:
    print("1")
  else:
    print("0")

def front(): # 출력 명령
  if len(Q) == 0:
    print("-1")
  else:
    print(Q[0])

def back(): # 출력 명령
  if len(Q) == 0:
    print("-1")
  else:
    print(Q[-1])

cmd_map = { # msg와 def 맵핑
    'push':push,
    'pop':pop,
    'size':size,
    'empty':empty,
    'front':front,
    'back':back
}



n = int(input())
#for i in range(n):
  #msg = list(input().split()) input은 한 줄씩 받음. 이것보단 readlines로 한 번에 받는 게 시간복잡도
msgs = sys.stdin.readlines()

for line in msgs:
  msg = line.strip().split()
  if len(msg) == 2:
    #print(msg)
    cmd_map[msg[0]](msg[1])
  else:
    cmd_map[msg[0]]()
    