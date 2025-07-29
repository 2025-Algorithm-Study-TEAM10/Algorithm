package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int Home_id=0;
    static int Chicken_id=0;

    static int min = Integer.MAX_VALUE;

    public static class Home{
        int id;
        int x;
        int y;
        int[] chicken_length;

        Home(int x, int y){
            id = Home_id++;
            this.x = x;
            this.y = y;
        }
    }

    public static class Chicken{
        int id;
        int x;
        int y;
        Chicken(int x, int y){
            id = Chicken_id++;
            this.x = x;
            this.y = y;
        }
    }

    public static int calc(Home home, Chicken chicken){
        return Math.abs(home.x -  chicken.x) + Math.abs(home.y -  chicken.y);
    }

    public static void findMin(Home[] homes, boolean[] visited){
        int sum = 0;
        for(int i=0; i<Home_id; i++){
            int local_min = Integer.MAX_VALUE;
            for(int j=0; j<visited.length; j++){
                if(visited[j]){
                    local_min = Math.min(local_min, homes[i].chicken_length[j]);
                }
            }
            sum += local_min;
        }
        min = Math.min(min, sum);
    }

    //n개중에서 r개 뽑기
    public static void combination(Home[] homes, boolean[] visited, int start, int n, int r) {
        if(r == 0) {
            findMin(homes, visited);
            return ;
        }

        for(int i=start; i<n; i++) {
            visited[i] = true;
            combination(homes, visited, i + 1, n, r - 1);
            visited[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]); // 2<=N<=50
        int M = Integer.parseInt(input[1]); // 1<=M<=13

        int[][] matrix = new int[N][N];

        Chicken[] chickens = new Chicken[13];   //치킨집의 최대 개수는 13
        Home[] homes = new Home[2*N];   //집의 최대 개수는 2*N

        // 13C7 = 1716 (치킨집 13개중 6개 or 7개만 고르는 경우의 수) 6 or 7일 때가 최대값이라서
        // 집마다 치킨집의 거리를 계산후 max : 100 * 13 = 1300
        // 살려야 하는 치킨집의 조합의 경우의 수 만큼 치킨거리를 계산하여 최솟값 구함 max : 1716 * 100(집의 개수) * 13(13개의 치킨집중 가장 작은 거리 구할 때 필요한 계산) = 2230800

        for(int i = 0; i < N; i++){
            String[] info =  br.readLine().split(" ");
            for(int j=0; j<N; j++){
                int num =  Integer.parseInt(info[j]);
                if(num == 2) chickens[Chicken_id] = new Chicken(j,i);
                else if(num == 1) homes[Home_id] = new Home(j,i);
            }
        }

        int chicken_length = Chicken_id;
        int home_length = Home_id;

        for(int i=0; i<home_length; i++){
            homes[i].chicken_length = new int[chicken_length];
            for(int j=0; j<chicken_length; j++){
                homes[i].chicken_length[j] = calc(homes[i], chickens[j]);
            }
        }

        boolean[] visited =  new boolean[chicken_length];
        combination(homes, visited, 0, chicken_length, M);

        System.out.println(min);
    }
}

