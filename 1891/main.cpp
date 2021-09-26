#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int l = 1;
        int r = 1e5;
        int res = 0;
        // binary search: increase 'len', the number we can get will decrease
        while(l <= r){
            // search len from [l...r];
            int len = (l+r) >> 1;
            if(ok(ribbons, k, len)){
                l = len+1; // the length of the region has to decrease
                res = len;
            }else{
                r = len-1;
            }
        }
        return res;
    }
    bool ok(vector<int>& ribbons, int k, int len){
        int count = 0;
        for(int i = 0; i < ribbons.size(); i++){
            count += ribbons[i]/len;
        }
        if(count >= k) return true;
        else return false;
    }
};