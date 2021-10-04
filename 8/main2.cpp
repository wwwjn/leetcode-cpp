//
// Created by Jiani Wang on 2021/10/3.
//

class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        long long num = 0;
        while(s[idx] == ' ') idx++;
        int flag = 1;
        if(s[idx] == '+'){
            flag = 1;
            idx++;
        }
        else if(s[idx] == '-'){
            flag = -1;
            idx++;
        }

        while(idx < s.size()){
            if(s[idx] >='0' && s[idx]<='9'){
                if(flag == 1){
                    if(num <= (INT_MAX - (s[idx]-'0'))/10)
                        num = num * 10 + (s[idx] - '0');
                    else
                        return INT_MAX;
                }else{
                    if(num >= (INT_MIN + (s[idx]-'0'))/10)
                        num = num * 10 - (s[idx]-'0');
                    else
                        return INT_MIN;
                }
                idx++;
            }
            else{
                break;
            }
        }
        return num;

    }
};