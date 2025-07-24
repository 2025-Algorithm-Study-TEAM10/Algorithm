#include <iostream>
#include <algorithm> 

using namespace std;

// T의 최대값 1000 + 1, W의 최대값 30 + 1, 나무 위치 2
int dp[1001][31][2];
// 각 시간에 자두가 떨어지는 나무 번호를 저장할 배열
int plum_drops[1001];

int main() {
    // 입출력 속도 빨리
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, W; // T는 총 시간, W는 최대 움직일 수 있는 횟수
    cin >> T >> W;

    for (int i = 0; i < T; ++i) {
        cin >> plum_drops[i];
    }

    // 0초에는 1번 나무 아래에 있고 움직인 횟수는 0
    if (plum_drops[0] == 1) {
        dp[0][0][0] = 1; // 0초에 0번 움직여서 1번 나무에 있을 때 1개 획득
    } else {
        // 움직임 횟수가 W를 초과할 수 있어서 W가 0인 경우를 체크
        if (W >= 1) { // 0초에 2번 나무를 가려면 최소 1번은 움직여야 하므로 W가 1 이상일 때만 가능
             dp[0][1][1] = 1;
        }
    }


    // T초 동안 반복
    for (int t = 1; t < T; ++t) {
        // 움직임 횟수 W까지 반복
        for (int w = 0; w <= W; ++w) {
            // 현재 자두가 1번 나무 아래에 있는 경우
            int current_plum_on_tree1 = (plum_drops[t] == 1) ? 1 : 0;
            // 2번 나무에 자두가 떨어졌는지 확인
            int current_plum_on_tree2 = (plum_drops[t] == 2) ? 1 : 0;

            // 이전에도 1번 나무에 서 있었던 경우 
            dp[t][w][0] = dp[t - 1][w][0] + current_plum_on_tree1;

            // 원래 2번 나무에 있었는데 이번에 1번 나무로 움직인 경우
            if (w > 0) {
                dp[t][w][0] = max(dp[t][w][0], dp[t - 1][w - 1][1] + current_plum_on_tree1);
            }


            // 원래도 2번 나무에 서 있었던 경우
            dp[t][w][1] = dp[t - 1][w][1] + current_plum_on_tree2;

            // 원래 1번 나무에 있었는데 이번에 2번 나무로 움직인 경우
            if (w > 0) {
                dp[t][w][1] = max(dp[t][w][1], dp[t - 1][w - 1][0] + current_plum_on_tree2);
            }
        }
    }

    //T초 동안 움직임 횟수 W 이하로 받을 수 있는 최대 자두 개수
    int max_plums = 0;
    for (int w = 0; w <= W; ++w) {
        max_plums = max({max_plums, dp[T - 1][w][0], dp[T - 1][w][1]});
    }

    cout << max_plums << endl;

    return 0;
}
