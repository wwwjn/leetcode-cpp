#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int pos = -1;
        int neg = nums.size();
        vector<int> res;
        if(nums[0] >= 0){
            pos = 0;
            while(pos < nums.size()){
                res.push_back(nums[pos] * nums[pos]);
                pos++;
            }
            return res;
        }
        else if(nums[nums.size() -1] <= 0){
            neg = nums.size()-1;
            while(neg >= 0){
                res.push_back(nums[neg] * nums[neg]);
                neg--;
            }
            return res;
        }
        else{
            int i  = 0;
            for(i = 0; i < nums.size(); i++){
                if(nums[i] <= 0 && nums[i+1] > 0) break;
            }
            neg = i;
            pos = i+1;
            while(neg >= 0 || pos < nums.size()){
                if(pos >= nums.size()){
                    res.push_back(nums[neg]* nums[neg]);
                    neg--;
                    continue;
                }
                if(neg < 0){
                    res.push_back(nums[pos] * nums[pos]);
                    pos ++;
                    continue;
                }
                if(abs(nums[neg]) < nums[pos]){
                    res.push_back(nums[neg] * nums[neg]);
                    neg--;
                }else{
                    res.push_back(nums[pos] * nums[pos]);
                    pos++;
                }
            }

            return res;
        }
    }
};