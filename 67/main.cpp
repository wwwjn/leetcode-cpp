#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size() -1;
        int j = b.size() -1;
        string res = "";
        while(i >=0 || j >= 0 || carry != 0){
            int num1 = 0, num2 = 0;
            if(i >= 0){
                num1 = a[i] - '0';
            }
            if(j >= 0){
                num2 = b[j] - '0';
            }
            if(num1 + num2 + carry >= 2){
                res = to_string((num1+num2+carry)%2) + res;
                carry = 1;
                i--;
                j--;
            }else{
                res = to_string((num1+num2+carry)) + res;
                carry = 0;
                i--;
                j--;
            }
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
