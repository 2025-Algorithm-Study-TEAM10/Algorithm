#include <iostream>
#include <stack>

using namespace std;

int main(){
    int towerNum;
    cin >> towerNum;


    stack<pair<int, int>> tower;   //순서, 값
    int* result = new int[towerNum];
    result[0] = 0;

    for(int i = 0; i < towerNum; i++){
        int val;
        cin >> val;
        
        if(i == 0){
            tower.push({i, val});
            continue;
        }

        while(tower.size() && val > tower.top().second){
            tower.pop();
        }

        if(!tower.size()){
            tower.push({i, val});
            result[i] = 0;
        }
        else{
            tower.push({i, val});
            result[i] = tower.top().first;
        }
    }
    

    delete[] result;
    return 0;
}