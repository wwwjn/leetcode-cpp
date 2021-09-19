#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int calculate(string s) {
        long res = 0;
        long num = 0;
        long n = s.size();
        char op = '+';
        stack<long> record;
        //如果该数字之前的符号是加或减，那么把当前数字压入栈中，注意如果是减号，则加入当前数字的相反数，因为减法相当于加上一个相反数。如果之前的符号是乘或除，那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中
        // 完成一遍遍历后，所有的乘或除都运算完了，再把栈中所有的数字都加起来就是最终结果了
        for(int i = 0; i < n; i++){
            if(s[i] >= '0'){
                // digits
                num = num * 10 + s[i] - '0';
            }
            if((s[i] < '0' && s[i] != ' ') || i == n-1){
                // end of a number, do calculation
                if(op == '+') record.push(num);
                else if(op == '-') record.push(-num);
                else if(op == '*' || op == '/'){
                    long tmp = (op == '*') ? record.top() * num : record.top()/num;
                    record.pop();
                    record.push(tmp);
                }
                op = s[i];
                num = 0;
            }
        }
        while(!record.empty()){
            res += record.top();
            record.pop();
        }
        return res;
    }
};
