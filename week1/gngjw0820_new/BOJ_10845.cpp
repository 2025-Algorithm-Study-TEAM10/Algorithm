#include <iostream>
#include <queue>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::queue<int> q;
    std::string command;

    while (n--) {
        std::cin >> command;

        if (command == "push") {
            int x;
            std::cin >> x;
            q.push(x);
        } else if (command == "pop") {
            if (q.empty()) {
                std::cout << -1 << '\n';
            } else {
                std::cout << q.front() << '\n';
                q.pop();
            }
        } else if (command == "size") {
            std::cout << q.size() << '\n';
        } else if (command == "empty") {
            std::cout << (q.empty() ? 1 : 0) << '\n';
        } else if (command == "front") {
            if (q.empty()) {
                std::cout << -1 << '\n';
            } else {
                std::cout << q.front() << '\n';
            }
        } else if (command == "back") {
            if (q.empty()) {
                std::cout << -1 << '\n';
            } else {
                std::cout << q.back() << '\n';
            }
        }
    }

    return 0;
}