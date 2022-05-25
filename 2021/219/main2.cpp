//
// Created by Jiani Wang on 2021/8/17.
//

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 1)
            return false;
        unordered_set<int> record;
        int l = 0;
        int r = 0;
        while(r < nums.size()){
            // [l...r]
            if(l + k >= r){
                if(record.find(nums[r]) != record.end())
                    return true;
                else{
                    record.insert(nums[r]);
                    r++;
                }
            }else{
                record.erase(nums[l]);
                l++;
            }
        }
        return false;
    }
};