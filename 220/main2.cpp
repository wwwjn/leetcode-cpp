//
// Created by Jiani Wang on 2021/8/17.
//


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int l = 0;
        int r = 0;
        set<int> record;
        while(r < nums.size()){
            // [l ... r]
            if(l + k >= r){
                // check if returns true;
                auto iter = record.lower_bound(max(nums[r], INT_MIN + t) - t);
                if(iter != record.end() && *iter <= min(nums[r], INT_MAX - t) + t)
                    return true;
                record.insert(nums[r]);
                r++;
            }else{  // l+k <= r
                record.erase(nums[l]);
                l++;
            }
        }
        return false;
    }
};