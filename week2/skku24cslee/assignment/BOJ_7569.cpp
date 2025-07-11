#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int main(){
    int row, col, height;

    cin >> row >> col >> height;

    vector<vector<vector<bool>>> Fresh(row, vector<vector<bool>>(col, vector<bool>(height, false))); //안익은 토마토의 위치
    queue<tuple<int, int, int>> Ripe; //익은 토마토

    int freshNum = 0;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < col; j++){
            for(int k = 0; k < row; k++){
                int  val;
                cin >> val;
                if(val == 0) {
                    Fresh[k][j][i] = true;
                    freshNum++;
                }
                else if(val == 1) Ripe.push({k, j, i});
                else continue;
            }
        }
    }

    bool isDone = false;
    int turn = 0;

    int dx[6] = {-1, 1, 0, 0, 0, 0};
    int dy[6] = {0, 0, -1, 1, 0, 0};
    int dz[6] = {0, 0, 0, 0, -1, 1};

    while(!Ripe.empty() && freshNum){
        int ripeNum = Ripe.size();

        for(int i = 0; i < ripeNum; i++){
            auto [x, y, z] = Ripe.front();
            Ripe.pop();

            for(int j = 0; j < 6; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                int nz = z + dz[j];

                if(nx < 0 || nx >= row || ny < 0 || ny >= col || nz < 0 || nz >= height) continue;
                if(Fresh[nx][ny][nz]){
                    Fresh[nx][ny][nz] = false;
                    Ripe.push({nx, ny, nz});
                    freshNum--;
                }                
            }

        }
        turn++;
    }

    if(!freshNum){
        cout << turn << endl;
    }
    else{
        cout << "-1" << endl;
    }

    return 0;
}