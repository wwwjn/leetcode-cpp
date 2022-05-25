class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3){
            return res;
        }
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int target = 0 - nums[i];
            // two sum
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                if(nums[j] + nums[k] < target){
                    j++;
                    while(j < nums.size() && nums[j] == nums[j-1]) j++;
                }else if(nums[j] + nums[k] > target){
                    k--;
                    while(k >= 0 && nums[k] == nums[k+1]) k--;
                }else{
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    res.push_back(tmp);
                    j++;
                    while(j < nums.size() && nums[j] == nums[j-1]) j++;
                }
            }
        }
        return res;
    }
};