class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        int i = nums.size() -1;
        while(i > 0 && nums[i] <= nums[i-1]){
            i--;
        }
        if(i > 0){
            int target = nums[i-1];
            int j = nums.size()-1;
            while(j > i){
                if(nums[j] > target)
                    break;
                j--;
            }
            if(j == i){
                swap(nums[i], nums[i-1]);
            }else{
                swap(nums[j], nums[i-1]);
            }
        }
        sort(nums.begin() + i, nums.end());

//         sort(nums.begin() + i, nums.end());
       
//         if(i > 0){
//             swap(nums[i-1], nums[i]);
//         }
         
        
    }
};