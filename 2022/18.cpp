// # 18

// - Use 2 for loop then 2-sum:
//     - need to return unique indexes, not unique items.
//     - need 4 unique indexes
    
// - 3 Sum: 3 unique indexes, not unique items in list
//     - The first position of i, j, m, n does not skip
//         - i = 0
//         - j = i+1
//         - m = j+1
//         - n = nums.size()-1
//     - But when moving i, j, m, n, Need to skip repeated values.
    
// - Optimize: Move m and n at same time when find a target

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4){
            return res;
        }
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-3; i++){
            while(i < nums.size() && i > 0 && nums[i] == nums[i-1]) i++;
            for(int j = i+1; j< nums.size()-2; j++){
                // cout << j << endl;
                while(j < nums.size() && j > i+1 && nums[j] == nums[j-1]) j++;
                // cout << j << endl;
                int m = j+1;
                int n = nums.size()-1;
                int new_target = target - nums[i] - nums[j];
                while(m < n){
                    if (nums[m] + nums[n] < new_target){
                        m++;
                        while(m < nums.size() && nums[m] == nums[m-1]) m++;
                    }else if(nums[m] + nums[n] > new_target){
                        n--;
                        while(n > 0 && nums[n] == nums[n+1]) n--;
                    }else{
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[m]);
                        tmp.push_back(nums[n]);
                        res.push_back(tmp);
                        m++;
                        while(m < nums.size() && nums[m] == nums[m-1]) m++;
                        n--;
                        while(n > 0 && nums[n] == nums[n+1]) n--;
                    }
                }
            }
        }
        return res;
    }
};