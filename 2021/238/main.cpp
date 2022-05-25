#include <iostream>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> recordL(nums.size(), 0);
        vector<int> recordR(nums.size(), 0);
        int product = 1;
        recordL[0] = 1;
        for(int i=1; i< nums.size(); i++){
            product *= nums[i-1];
            recordL[i] = product;
        }
        product = 1;
        recordR[nums.size() -1] = 1;
        for(int i = nums.size()-2; i >= 0; i--){
            product *= nums[i+1];
            recordR[i] = product;
        }
        //
        vector<int> res;
        for(int i = 0; i< nums.size(); i++){
            res.push_back(recordL[i] * recordR[i]);
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
