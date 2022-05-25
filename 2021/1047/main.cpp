#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (const auto ch : S) {
            if (!res.empty() && res.back() == ch) {
                res.pop_back();
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};