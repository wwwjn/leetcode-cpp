//
// Created by Jiani Wang on 2021/9/20.
//

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preProd(nums.size(), 0);
        vector<int> sufProd(nums.size(), 0);
        int n = nums.size();
        preProd[0] = 1;
        sufProd[n-1] = 1;
        for(int i = 1; i < n; i++){
            preProd[i] = preProd[i-1] * nums[i-1];
            sufProd[n-1-i] = sufProd[n-i] * nums[n-i];
        }

        vector<int> res;
        for(int i = 0; i< nums.size(); i++){
            res.push_back(preProd[i] * sufProd[i]);
        }
        return res;
    }
};