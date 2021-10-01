#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int i = 0;
        int j = 0;
        vector<vector<int>> res;
        int res1 = encoded1[i][1];
        int res2 = encoded2[j][1];  // how many times left;
        int mul1 = encoded1[i][0];
        int mul2 = encoded2[j][0];
        while(i < encoded1.size() && j < encoded2.size()){
            int count = min(res1, res2);
            res.push_back({mul1 * mul2, count});
            res1 -= count;
            res2 -= count;
            if(res1 == 0){
                i++;
                if(i == encoded1.size()) break;
                res1 += encoded1[i][1];
                mul1 = encoded1[i][0];
            }
            if(res2 == 0){
                j++;
                if(j == encoded2.size()) break;
                res2 += encoded2[j][1];
                mul2 = encoded2[j][0];
            }
        }
        vector<vector<int>> ret;
        int val = res[0][0];
        int freq = res[0][1];
        for(int i = 1; i< res.size(); i++){
            if(res[i][0] == val){
                freq += res[i][1];
            }else{
                ret.push_back({val, freq});
                val = res[i][0];
                freq = res[i][1];
            }
        }
        ret.push_back({val, freq});

        return ret;
    }
};