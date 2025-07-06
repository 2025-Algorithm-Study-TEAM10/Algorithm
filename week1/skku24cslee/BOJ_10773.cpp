#include <iostream>

using namespace std;

int main(){
    int myStack[100000] = {};
    int top = 0;

    int count = 0;
    cin >> count;
    for(int i = 0; i < count; i++){
        int num;
        cin >> num;
        num ? myStack[top++] = num : top--;
    }

    int sum = 0;
    for(int i = 0; i < top; i++){
        sum += myStack[i];
    }

    cout << sum << endl;




    return 0;
}