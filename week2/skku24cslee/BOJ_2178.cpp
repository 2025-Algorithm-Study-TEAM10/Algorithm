#include <iostream>
#include <queue>

using namespace std;

int main(){         //BFS를 이용하면 목적지에 방문 자체가 최소거리 !
    int row, col;   //BFS가 한바퀴 돌 때마다 변숫값이 증가해야함 -> BFS 안에 변수를 넣기

    cin >> row >> col;

    bool* board = new bool[row * col]();
    bool* visited = new bool[row * col]();
    
    for(int i = 0; i < row; i++){
        string line;
        cin >> line;
        for(int k = 0; k < col; k++){
            board[i*col + k] = line[k] - '0'; 
        }
    }

    queue<pair<int, int>> myQueue; // [들어갈 위치, n번 이동]
    myQueue.push({0, 1});

    while(1){

        auto [a, b] = myQueue.front();
        myQueue.pop();
        
        if(a == row * col - 1){
            cout << b << endl;
            break;
        }

        if((a % col != 0) && board[a - 1] && !visited[a - 1]){
            myQueue.push({a - 1, b + 1});
            visited[a - 1] = 1;
        }
        if((a % col != col - 1) && board[a + 1] && !visited[a + 1]){
            myQueue.push({a + 1, b + 1});
            visited[a + 1] = 1;
        }
        if((a >= col) && board[a - col] && !visited[a - col]){
            myQueue.push({a - col, b + 1});
            visited[a - col] = 1;
        }
        if((a < (row - 1) * col) && board[a + col] && !visited[a + col]){
            myQueue.push({a + col, b + 1});
            visited[a + col] = 1;
        }
    }
    
    return 0;
}