#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); ){
            for(int j = i + 1; j < nums.size(); ){
                int tmp_target = target - nums[i] - nums[j];
                int l = j + 1;
                int r = nums.size() - 1;
                while( l < r ){
                    if(nums[l] + nums[r] == tmp_target){
                        vector<int> temp_res = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(temp_res);
                        // move l;
                        while(l < r && nums[l+1] == nums[l]) l++;
                        l++;
                        // move r;
                        while(l < r && nums[r-1] == nums[r]) r--;
                        r--;
                    }else{
                        // move r;
                        while(l < r && nums[r] > tmp_target - nums[l]) r--;
                        // move l
                        while(l < r && nums[l] < tmp_target - nums[r]) l++;
                    }
                }
                // move j
                while(j + 1 <nums.size() && nums[j+1] == nums[j]) j++;
                j++;  //注意while退出的条件，j指向下一个位置
            }
            // move i
            while(i + 1 < nums.size() && nums[i+1] == nums[i]) i++;
            i++;
        }
        int res = IN
        return res;

    }

};

int main() {

    return 0;
}
