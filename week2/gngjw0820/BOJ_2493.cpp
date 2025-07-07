#include <iostream> 
#include <stack> 
using namespace std;

const int MAX = 500000; // 최대 탑 수

int N;                  // 탑 개수
int height[MAX];        // 탑 높이 배열
int answer[MAX];        // 각 탑의 수신 결과 저장

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> height[i]; 
    }

    stack<pair<int, int>> st; 

    for (int i = 0; i < N; i++) {
        // 현재 탑보다 낮은 애들은 스택에서 제거
        while (!st.empty() && st.top().second < height[i]) {
            st.pop();
        }

        if (st.empty()) {
            // 왼쪽에 막아줄 탑이 없음
            answer[i] = 0;
        } else {
            answer[i] = st.top().first + 1;
        }

        // 현재 탑을 스택에 넣어줌 (다음 탑들이 참고하게)
        st.push({i, height[i]});
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}
