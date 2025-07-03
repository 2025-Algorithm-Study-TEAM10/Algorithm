#include <iostream>
#include <stack>  

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int K; 
    std::cin >> K;

    std::stack<int> numbers_stack;

    for (int i = 0; i < K; ++i) {
        int num; 
        std::cin >> num;

        if (num == 0) {
            numbers_stack.pop();
        } else {
            numbers_stack.push(num);
        }
    }

    long long sum = 0;

    while (!numbers_stack.empty()) {
        sum += numbers_stack.top();
        numbers_stack.pop();  
    }

    std::cout << sum << std::endl;

    return 0;
}