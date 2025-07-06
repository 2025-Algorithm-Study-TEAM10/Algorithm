#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    int myStack[10000] = {};
    int top = 0;

    int count;

    cin >> count;

    cin.ignore();

    while(count){
        string line;
        while(count && getline(cin, line)){
            istringstream iss(line);

            string cmd;
            iss >> cmd;

            if( cmd == "push"){
                int x;
                iss >> x;
                myStack[top++] = x;
                
            }
            else if( cmd == "pop"){
                cout << (top ? to_string(myStack[--top]) : "-1") <<endl;
            }
            else if( cmd == "size"){
                cout << top <<endl;
            }   
            else if(cmd == "empty"){
                cout << (top ? "0" : "1") <<endl;
            }
            else{
                cout << (top ? to_string(myStack[top - 1]) : "-1") <<endl;
            }

            count--;
        }

        
    }

    return 0;
}