#include <iostream>
#include <queue>

using namespace std;

int main(){
    int row, col;
    int rowcol = row * col;
    cin >> row >> col;

    bool* board = new bool[rowcol]();
    bool* visited = new bool[rowcol]();

    for(int i = 0; i < rowcol; i++){
        cin >> board[i];
    }

    int num = 0;
    int max = 0;

    for(int i = 0; i < rowcol; i++){
        if(visited[i]) continue;
        if(!board[i]) continue;

        queue<int> drawing;

        drawing.push(i);

        num++;
        int size = 1;
        visited[i] = 1;

        while(!drawing.empty()){
            int k = drawing.front();
            drawing.pop();

            if((k % col != 0) && !visited[k - 1] && board[k - 1]) {size++; drawing.push(k - 1); visited[k - 1] = 1;}
            if((k % col != col - 1) && !visited[k + 1] && board[k + 1]) {size++; drawing.push(k + 1); visited[k + 1] = 1;}
            if((k > col - 1) && !visited[k - col] && board[k - col]) {size++; drawing.push(k - col); visited[k - col] = 1;}
            if((k < (row - 1) * col) && !visited[k + col] && board[k + col]) {size++; drawing.push(k + col); visited[k + col] = 1;}
        }
       
        max = (max > size) ? max : size;
    }
    cout << num << endl << max << endl;

    return 0;
}