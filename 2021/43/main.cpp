#include <iostream>

class Solution {
public:
    string multiply(string num1, string num2) {
        string final_res = "0";
        if(num1.size() ==1 && num1[0] =='0'){
            return "0";
        }
        if(num2.size() == 1 && num2[0] == '0'){
            return "0";
        }
        for(int j = num2.size() -1; j >=0 ;j --){
            int mul2 = num2[j] - '0';
            int count = 0; // carry bit
            string res = "";
            for(int i = num1.size() -1; i>=0; i--){
                int mul1 = num1[i] - '0';
                if(mul1 * mul2 + count >= 10){
                    res = to_string((mul1 * mul2 + count)%10) + res;
                    count = (mul1 * mul2 + count)/10;
                }else{
                    res = to_string(mul1 * mul2 + count) + res;
                    count = 0;
                }
            }
            if(count > 0){
                res = to_string(count) + res;
            }
            // add zeros at the end of
            for(int k = 0; k < num2.size()-1-j; k++){
                res += "0";
            }
            final_res = add(final_res, res);
        }
        return final_res;

    }
    string add(string nums1, string nums2){
        int m = nums1.size()-1;
        int n = nums2.size()-1;
        int count = 0; // whether add 1 to front
        string res = "";
        while(m >= 0 || n >= 0 || count > 0){
            int add1 = 0;
            int add2 = 0;
            if(m >= 0){
                add1 = nums1[m] - '0';
            }
            if(n >= 0){
                add2 = nums2[n] - '0';
            }
            if(add1 + add2 + count >= 10){
                res = to_string((add1+add2+count)%10) + res;
                count = 1;

            }else{
                res = to_string(add1+add2+count) + res;
                count = 0;
            }
            m--;
            n--;
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
