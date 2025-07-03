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
};

int main(){
    int num;
    cin >> num;
    
    Queue* myQueue = new Queue;

    for(int i = 1; i <= num; i++){
            myQueue->push(i);
    }

    num -= 1;
    for(int i = 0; i < num; i++){
        myQueue->pop();
        myQueue->push(myQueue->pop());
    }

    cout << myQueue->get_front();

    delete myQueue;

    return 0;
}