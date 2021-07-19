#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() == 0){
            return false;
        }
        set<long> record;
        int l = 0; // [l ...r)
        int r = l + 1;  // r is the considering index
        record.insert(nums[l]);
        while(r < nums.size() && r <= l+k){
            // find if nums[r] - t < .... < nums[r] + t
//            for(long j = (long)nums[r] - (long)t; j <= (long)nums[r] + (long)t; j++){
//                if(record.find(j) != record.end())
//                    return true;
                auto iter = record.lower_bound(max(nums[r], INT_MIN + t) - t);
                if(iter != record.end() && *iter <= min(nums[r], INT_MAX - t) + t)
                    return true;
            }
            record.insert(nums[r]);
            r++;
//        }
        while(r < nums.size()){
            // move l;
            record.erase(nums[l]);
            l++;
            // move r;
//            for(int j = nums[r] - t; j <= nums[r] + t; j++){
//                if(record.find(j) != record.end())
//                    return true;
//            }
            auto iter = record.lower_bound(max(nums[r], INT_MIN + t) - t);
            if(iter != record.end() && *iter <= min(nums[r], INT_MAX - t) + t)
                return true;
            record.insert(nums[r]);
            r++;
        }
        return false;
    }
}

int main() {
    vector<int> nums = {2147483647,-1,2147483647};
    int k = 1;
    int t = 2147483647;
    cout << Solution().containsNearbyAlmostDuplicate(nums, k ,t) << endl;
    return 0;
}
