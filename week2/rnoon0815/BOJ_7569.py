
# 7569 토마토 

# BFS => Queue 사용해 방문 노드 기록. -> deque 활용

from collections import deque

input = sys.stdin.readline

box = deque()
visited = deque()
ripe = deque() # 익은 토마토들



m, n, h = map(int, input().strip().split()) # 가로 칸의 수, 세로 칸의 수, 쌓은 상자의 수
box = [[[0] * m for _ in range(n)] for _ in range(h)] # 박스 초기화


for z in range(h):  # 높이만큼 반복 - 가장 바깥 차원을 밖에
    for y in range(n):  # 각 층에서 n줄 입력받음
        row = list(map(int, input().split())) # input으로 들어온 5개 숫자
        for x in range(m): # 숫자 하나씩 앞에서부터
            box[z][y][x] = row[x] # 3차원에 맞게 토마토 추가
            if box[z][y][x] == 1: 
              ripe.append([z,y,x]) # 익은 토마토의 좌표를 ripe queue에 넣음.

# 움직일 방향 설정
dx = [0,0,0,0,1,-1] 
dy = [0,0,1,-1,0,0]
dz = [1,-1,0,0,0,0]

answer = 0

def bfs():
  while ripe: # 익은 토마토 queue
    z,y,x = ripe.popleft() # pop 연산. 익은 토마토 중 탐색 시작 부분

    for i in range(6): # 3차원 x2 -> 6가지 연산
      nx, ny, nz = x + dx[i], y+dy[i], z+dz[i] # 뽑힌 토마토의 6가지 방향으로 +1 새로운 좌표 형성
      
      if 0 <= nx < m and 0 <= ny < n and 0 <= nz < h: # 박스 크기 초과하지 않도록 점검
        if box[nz][ny][nx] == 0: # 안 익은 토마토들이었으면
                    box[nz][ny][nx] = box[z][y][x] + 1 # +1 함. 
                    ripe.append((nz,ny,nx))


bfs()
Flag = False

for i in range(h):
    for j in range(n):
        for k in range(m):

            if box[i][j][k] == 0:
                Flag = True # 아직 익지 않은 토마토 발견 -> 전체가 익는 경우 없음
                break
            answer = max(answer, box[i][j][k])

if Flag: # 아직 익지 않은 토마토 발견
    answer = -1
elif answer == -1: # 이미 다 익어있었을 경우
    answer = 0
else: # 가장 오래 걸린 일수에서 -1을 해야 소요 시간 정확히 측정
    answer -= 1

print(answer)
