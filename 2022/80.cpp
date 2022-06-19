class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2){
            return nums.size();
        }
        // map<int, int> record;  // map number to count
        int cur = 0; //[0, cur] does not have duplicate number
        bool twice = false; // prev number
        for(int i = 1; i< nums.size(); i++){
            if(twice == true && nums[i] <= nums[cur]){
                continue;
            }
            nums[cur+1] = nums[i];
            cur++;
            if(nums[cur] == nums[cur-1]){
                twice = true;
            }else{
                twice = false;
            }
        }
        return cur+1;
        
    }
};