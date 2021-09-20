#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> record;
        int res = 0;
        for(int i = 0; i< s.size(); i++){
            if(s[i] == '('){
                record.push(s[i]);
            }
            else{
                if(!record.empty())
                    record.pop();
                else{
                    // record is empty: no ( in stack
                    res++;
                }
            }
        }
        res += record.size();
        return res;
    }
};