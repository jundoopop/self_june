#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_set<int> S;
    int iterateNum;
    std::cin >> iterateNum;

    for (int i = 0; i < iterateNum; ++i) {
        std::string command;
        int x = 0;
        std::cin >> command;

        if (command == "add" || command == "remove" || command == "check" || command == "toggle") {
            std::cin >> x;
        }

        if (command == "add") {
            S.insert(x);
        } else if (command == "remove") {
            S.erase(x);
        } else if (command == "check") {
            std::cout << S.count(x) << '\n';
        } else if (command == "toggle") {
            if (S.count(x)) {
                S.erase(x);
            } else {
                S.insert(x);
            }
        } else if (command == "all") {
            S = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        } else if (command == "empty") {
            S.clear();
        }
    }

    return 0;
}
