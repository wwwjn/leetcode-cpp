//
// Created by Jiani Wang on 2021/8/25.
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() <= 2){
            return res;
        }
        // O(nlogn)
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size() -2; i++){ // i is the smallest in (i, j, k)
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int j = i+1;
            int k = nums.size() - 1;

            while(j < k){
                // find nums[j] + nums[k] == target;
                if(nums[j] + nums[k] == target){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    res.push_back(tmp);
                    j = moveToRight(nums, j); // move left
                }else if(nums[j] + nums[k] > target){
                    k = moveToLeft(nums, k);
                }else{
                    j = moveToRight(nums, j);
                    cout << j;
                }
            }
        }
        return res;
    }
    int moveToRight(vector<int>& nums, int i){
        while(i+1 < nums.size() && nums[i+1] == nums[i]){
            i++;
        }
        return i+1;
    }
    int moveToLeft(vector<int>& nums, int i){
        while(i-1>=0 && nums[i-1] == nums[i]){
            i--;
        }
        return i-1;
    }
};