#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber > 0){
            res += (columnNumber-1) % 26 + 'A';
            columnNumber = (columnNumber-1) / 26;
        }
        reverse(res.begin(), res.end());

        return res;
    }
};