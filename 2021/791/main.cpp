#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> order(128, INT_MAX);
        int i = 0;
        for (char c: S)
            if (order[c] == INT_MAX) order[c] = ++i;
        std::sort(T.begin(), T.end(), [&order](const char c1, const char c2){
            return order[c1] < order[c2];
        });
        return T;
    }
};