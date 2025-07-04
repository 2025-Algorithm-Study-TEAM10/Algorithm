#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Node {
    public:
        int num = -1;
        Node* next = nullptr;
};

class Queue {
    private:
        Node* front;
        Node* back;
        int count = 0;

    public:
        Queue(){
            Node* start = new Node;
            front = start;
            back = start;
        }

        ~Queue(){
            Node* temp = front;
            while(front != nullptr){
                temp = front->next;
                delete front;
                front = temp;
            }
        }

        void push(int num){
            Node* new_node = new Node;
            new_node->num = num;

            back->next = new_node;
            
            back = new_node;

            count++;

            return;
        }

        int pop(){
            if(empty()){
                return -1;
            }

            int num = front->next->num;
            
            Node* temp = front->next;
            front->next = front->next->next;

            delete temp;

            count--;

            if(front->next == nullptr) back = front;

            return num;
        }

        int size(){
            return count;
        }

        int empty(){
            if(front == back) return 1;
            else return 0;
        }

        int get_front(){
            if(empty()){
                return -1;
            }

            return front->next->num;
        }

        int get_back(){
            if(empty()){
                return -1;
            }

            return back->num;
        }
};

int main(){
    Queue* myQueue = new Queue;

    int count;

    cin >> count;

    cin.ignore();

    while(count){
        string line;
        while(getline(cin, line)){
            istringstream iss(line);

            string cmd;
            iss >> cmd;

            if( cmd == "push"){
                int x;
                iss >> x;

                myQueue->push(x);
            }
            else if( cmd == "pop"){
                cout << myQueue->pop()<<endl;
            }
            else if( cmd == "size"){
                cout << myQueue->size()<<endl;
            }
            else if(cmd == "empty"){
                cout << myQueue->empty()<<endl;
            }
            else if(cmd == "front"){
                cout << myQueue->get_front()<<endl;
            }
            else{
                cout << myQueue->get_back()<<endl;
            }
        }

        count--;
    }

    delete myQueue;

    return 0;
}