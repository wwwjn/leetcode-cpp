#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maximumSwap(int num) {
        if(num < 10){
            return num; // can not swap
        }
        string s = to_string(num);
        vector<int> maxSucc(s.size()); // max number in [k..s.size()]
        vector<int> maxIdx(s.size()); // the index of max number
        maxSucc[s.size()-1] = s[s.size()-1] - '0';
        maxIdx[s.size()-1] = s.size()-1;
        for(int j = s.size()-2; j >= 0; j--){
            if(s[j] - '0' > maxSucc[j+1]){
                maxSucc[j] = s[j] -'0';
                maxIdx[j] = j;
            }else{
                maxSucc[j] = maxSucc[j+1];
                maxIdx[j] = maxIdx[j+1];
            }
        }

        for(int i = 0; i< s.size(); i++){
            if(maxSucc[i] > s[i] -'0'){
                swap(s[i], s[maxIdx[i]]);
                break;
            }
        }

        int res = 0;
        for(int i = 0; i< s.size(); i++){
            res = res*10 + (s[i] - '0');
        }
        return res;
    }
};