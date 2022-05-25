#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// 这道题不是问 “1p是否会怎么选都会赢”，而是 “如果1p每次都选特别的两个+，最终他会不会赢”。所以 canWin 这个函数的意思是 “在当前这种状态下，至少有一种选法，能够让他赢”。而 (!canWin) 的意思就变成了 “在当前这种状态下，无论怎么选，都不能赢”。所以 1p 要看的是，是否存在这样一种情况，无论 2p 怎么选，都不会赢。

class Solution {
public:
    bool canWin(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+' && !canWin(s.substr(0, i - 1) + "--" + s.substr(i + 1))) {
                return true;
            }
        }
        return false;
    }
};