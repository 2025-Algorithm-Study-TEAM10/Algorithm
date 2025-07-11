#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main(){
    int towerNum;
    cin >> towerNum;

    ostringstream oss;

    stack<pair<int, int>> tower;   //순서, 값
    int* result = new int[towerNum+1]();
    result[1] = 0;

    for(int i = 1; i <= towerNum; i++){
        int val;
        cin >> val;
        
        if(i == 1){
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
            result[i] = tower.top().first;
            tower.push({i, val});
        }
    }

    for(int i = 1; i <= towerNum; i++){
        oss << result[i] << " ";
    }

    cout << oss.str();



    delete[] result;
    return 0;
}