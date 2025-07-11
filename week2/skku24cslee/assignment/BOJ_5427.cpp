#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    int ntime;
    int row, col;

    cin >> ntime;

    for(int k = 0; k < ntime; k++){
        cin >> col >> row;

        bool* Board = new bool[row * col]();
        bool* Visited = new bool[row * col]();

        queue<int> SGmove;
        queue<int> Fire;

        for(int i = 0; i < row; i++){   //판 입력
            string line;
            cin >> line;

            for(int j = 0; j < col; j++){
                int coor = i * col + j;

                if(line[j] == '.'){
                    Board[coor] = true;
                }
                else if(line[j] == '#'){
                    Board[coor] = false;
                }
                else if(line[j] == '@'){
                    Board[coor] = true;
                    Visited[coor] = true;
                    SGmove.push(coor);
                }
                else{   //fire
                    Board[coor] = false;
                    Fire.push(coor);
                }
            }
        }

        int turn = 1;
        bool isFinish = false;

        while(1){
            int SGsize = SGmove.size();
            bool isMove = false;
            
            int Firesize = Fire.size();

            for(int i = 0; i < Firesize; i++){
                int b = Fire.front();
                Fire.pop();

                if((b % col != 0) && Board[b - 1]){
                Fire.push(b - 1);
                Board[b - 1] = false;
                }
                if((b % col != col - 1) && Board[b + 1]){
                    Fire.push(b + 1);
                    Board[b + 1] = false;
                }
                if((b >= col) && Board[b - col]){
                    Fire.push(b - col);
                    Board[b - col] = false;
                }
                if((b < (row - 1) * col) && Board[b + col]){
                    Fire.push(b + col);
                    Board[b + col] = false;
                }
            }

            for(int m = 0; m < SGsize; m++){

                int a = SGmove.front();
                SGmove.pop();

                

                if((a < col) || (a >= (row - 1) * col) || (a % col == 0) || (a % col == col - 1)){
                    cout<< turn << endl;
                    isFinish = true;
                    break;
                }

                if((a % col != 0) && Board[a - 1] && !Visited[a - 1]){
                    SGmove.push(a - 1);
                    Visited[a - 1] = true;
                    isMove = true;
                }
                if((a % col != col - 1) && Board[a + 1] && !Visited[a + 1]){
                    SGmove.push(a + 1);
                    Visited[a + 1] = true;
                    isMove = true;
                }
                if((a >= col) && Board[a - col] && !Visited[a - col]){
                    SGmove.push(a - col);
                    Visited[a - col] = true;
                    isMove = true;
                }
                if((a < (row - 1) * col) && Board[a + col] && !Visited[a + col]){
                    SGmove.push(a + col);
                    Visited[a + col] = true;
                    isMove = true;
                }
            }

            if(isFinish) break;

            if(!isMove){
                    cout<< "IMPOSSIBLE" << endl;
                    break;
                }
            turn++;
        }

        delete[] Board;
        delete[] Visited;
    }
    
    
    return 0;
}