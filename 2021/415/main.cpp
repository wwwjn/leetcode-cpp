#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() -1;
        int j = num2.size() -1;
        int carry = 0;
        string res = "";
        while(i >= 0 || j >=0 || carry != 0){
            int add1 = 0;
            int add2 = 0;
            if(i < 0 && j < 0){
                res = to_string(carry) + res;
                carry = 0;
                break;
            }
            else if(i < 0){
                add2 = num2[j] - '0';
                j--;
            }else if(j < 0){
                add1 = num1[i] - '0';
                i--;
            }else{
                add1 = num1[i] - '0';
                add2 = num2[j] - '0';
                i--;
                j--;
            }
            int tmp = (add1 + add2 + carry) % 10;
            if(add1 + add2 + carry >= 10){
                carry = 1;
            }else{
                carry = 0;
            }
            // cout << tmp << endl;
            res = to_string(tmp) + res;
        }
        return res;
    }
};