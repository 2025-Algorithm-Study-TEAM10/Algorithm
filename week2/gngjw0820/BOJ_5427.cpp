#include <iostream>
#include <queue>
#include <string>
using namespace std;

int w, h;
char building[1000][1001];        // 빌딩 지도 (문자열처럼 처리하기 위해 [1001])
int fire_time[1000][1000];        // 불이 도달하는 시간
int person_time[1000][1000];      // 상근이가 도달하는 시간

queue<pair<int, int>> fire;
queue<pair<int, int>> person;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
    // 먼저 불 확산
    while (!fire.empty()) {
        auto [x, y] = fire.front(); fire.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (building[nx][ny] == '#' || fire_time[nx][ny] != -1) continue;

            fire_time[nx][ny] = fire_time[x][y] + 1;
            fire.push({nx, ny});
        }
    }

    // 상근이 이동
    while (!person.empty()) {
        auto [x, y] = person.front(); person.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 탈출 성공 (지도 밖으로 나감)
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
                cout << person_time[x][y] + 1 << "\n";
                return;
            }

            if (building[nx][ny] == '#' || person_time[nx][ny] != -1) continue;
            if (fire_time[nx][ny] != -1 && fire_time[nx][ny] <= person_time[x][y] + 1) continue;

            person_time[nx][ny] = person_time[x][y] + 1;
            person.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> w >> h;

        while (!fire.empty()) fire.pop();
        while (!person.empty()) person.pop();

        for (int i = 0; i < h; i++) {
            cin >> building[i];
            for (int j = 0; j < w; j++) {
                fire_time[i][j] = -1;
                person_time[i][j] = -1;
                if (building[i][j] == '*') {
                    fire.push({i, j});
                    fire_time[i][j] = 0;
                }
                if (building[i][j] == '@') {
                    person.push({i, j});
                    person_time[i][j] = 0;
                }
            }
        }

        bfs();
    }

    return 0;
}
