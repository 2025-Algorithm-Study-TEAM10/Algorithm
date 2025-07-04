#include <iostream>
#include <stack> 

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL); 

    int n;
    std::cin >> n; 

    std::stack<int> s;
    int current_num = 1;
    std::string output;

    for (int i = 0; i < n; ++i) {
        int target;
        std::cin >> target; 

        while (current_num <= target) { 
            s.push(current_num);
            output += "+\n";
            current_num++;
        }

        if (!s.empty() && s.top() == target) { 
            s.pop();
            output += "-\n";
        } else {
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << output;
    return 0;
}
