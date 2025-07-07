#include <tuple> 
#include <iostream> 
#include <queue>
using namespace std;

const int MAX = 100;

int M, N, H;
int box[MAX][MAX][MAX];
int day[MAX][MAX][MAX];

// 3차원 이동 방향
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> q; // 익은 토마토들의 위치를 저장할 큐

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> M >> N >> H;

    // 3중 반복문으로 상자 내용 입력받기
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> box[h][n][m];
                if (box[h][n][m] == 1) {
                    // 익은 토마토면 큐에 미리 넣음
                    q.push({h, n, m});
                    day[h][n][m] = 0;
                } else if (box[h][n][m] == 0) {
                    // 익지 않은 토마토는 아직 방문 안 했으니까 -1로 표시
                    day[h][n][m] = -1;
                }
            }
        }
    }

    // BFS 시작
    while (!q.empty()) {
        int z, y, x;
        tie(z, y, x) = q.front(); q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nz = z + dz[dir];
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M) continue;

            if (box[nz][ny][nx] == 0 && day[nz][ny][nx] == -1) {
                day[nz][ny][nx] = day[z][y][x] + 1;
                q.push({nz, ny, nx});       
            }
        }
    }

    int result = 0;
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (day[h][n][m] == -1 && box[h][n][m] == 0) {
                    // 안 익은 토마토가 그대로면 실패
                    cout << -1 << '\n';
                    return 0;
                }
                if (day[h][n][m] > result) result = day[h][n][m];
            }
        }
    }

    cout << result << '\n';
    return 0;
}
