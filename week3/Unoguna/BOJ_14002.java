package week03.Unoguna;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Collections;

public class BOJ_14002 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int[] dp = new int[N];
        int[] prev = new int[N];  // LIS 경로 복원용

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        // 초기화
        for (int i = 0; i < N; i++) {
            dp[i] = 1;
            prev[i] = -1;
        }

        int maxLen = 1;
        int lastIndex = 0;

        // LIS 계산
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;  // 이전 원소 기록
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // LIS 경로 복원
        ArrayList<Integer> lis = new ArrayList<>();
        while (lastIndex != -1) {
            lis.add(arr[lastIndex]);
            lastIndex = prev[lastIndex];
        }
        Collections.reverse(lis);

        // 출력
        System.out.println(maxLen);
        for (int num : lis) {
            System.out.print(num + " ");
        }
    }
}
