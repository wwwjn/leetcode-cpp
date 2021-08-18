#include <iostream>

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int res = 0;
        int flag = 1; // positive
        while(i < s.size() && s[i] == ' '){
            i++;  // to the first non-whitespace char
        }
        if(i == s.size()){
            return 0;
        }
        if(s[i] == '-'){
            flag = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }else if(!isNumber(s[i])){
            return 0;
        }

        // read numbers
        while(i < s.size() && isNumber(s[i])){
            if(flag == 1){ // positive number
                if(res <= (INT_MAX - singleAtoI(s[i]))/10){
                    res = res* 10 + singleAtoI(s[i]);
                    cout << res << " ";
                    i++;
                }else{
                    return INT_MAX;
                }
            }else{ // negtive number
                if(res >= (INT_MIN + singleAtoI(s[i]))/10){
                    res = res*10 - singleAtoI(s[i]);
                    i++;
                }else{
                    return INT_MIN;
                }
            }
        }
        return res;
    }
    bool isNumber(char c){
        return c>='0' && c<='9';
    }
    int singleAtoI(char c){
        return (c-'0');
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
