#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


class Solution {
public:
    int calculate(string s) {
        int i = 0;
        stack<int> ops; // contains sign
        int sign = 1;
        ops.push(sign);

        int res = 0;

        while(i < s.size()){
            if(s[i] == ' '){
                i++;
            }
            else if(s[i] == '+'){
                sign = 1 * ops.top();
                i++;
            }else if(s[i] == '-'){
                sign = -1 * ops.top();
                i++;
            }else if(s[i] == '('){
                ops.push(sign);
                i++;
            }else if(s[i] == ')'){
                ops.pop();
                i++;
            }else{
                long num = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                res += sign * num;
            }
        }

        return res;
    }
};
