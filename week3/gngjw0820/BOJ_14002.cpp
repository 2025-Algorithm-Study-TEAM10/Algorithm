#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

// N의 최대값 1000 + 1
int A[1001];
int dp[1001];
int prev_idx[1001];

int main() {
    // 입출력 속도를 빨리
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // 모든 dp[i]는 1로 초기화
    // 모든 prev_idx[i]는 -1로 초기화
    for (int i = 0; i < N; ++i) {
        dp[i] = 1;
        prev_idx[i] = -1;
    }

    int max_len = 0;      // 가장 긴 증가하는 부분 수열의 최대 길이
    int last_idx = -1;    // 가장 긴 증가하는 부분 수열의 마지막 원소의 인덱스

    // DP 계산
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1; // 길이 업데이트
                prev_idx[i] = j;   // A[i] 앞에는 A[j]가 온다는 것을 기록
            }
        }
        // 현재 A[i]를 마지막 원소로 하는 길이가 최대보다 크다면 업데이트
        if (dp[i] > max_len) {
            max_len = dp[i];
            last_idx = i; // 가장 긴 마지막 원소 인덱스 갱신
        }
    }
    
    if (N == 0) { // N이 0일 때의 예외 처리
        cout << 0 << endl;
        return 0;
    }
    
    // N이 1일 때 max_len과 last_idx 초기화 처리
    if (N == 1) {
        max_len = 1;
        last_idx = 0;
    }


    // 가장 긴 증가하는 부분 수열의 길이 출력
    cout << max_len << endl;

    // 가장 긴 증가하는 부분 수열 출력
    stack<int> result_sequence; // last_idx부터 prev_idx를 따라가며 수열을 찾고 스택에 저장
    int current_idx = last_idx;
    while (current_idx != -1) {
        result_sequence.push(A[current_idx]); // 현재 원소를 스택에 넣고
        current_idx = prev_idx[current_idx];  // 이전 원소의 인덱스로 이동
    }

    // 스택에서 원소를 꺼내면서 출력
    while (!result_sequence.empty()) {
        cout << result_sequence.top() << " ";
        result_sequence.pop();
    }
    cout << endl;

    return 0;
}