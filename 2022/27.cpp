class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        int ptr = nums.size()-1;   // (ptr, nums.size()-1] equal val
        while(ptr >= 0 && nums[ptr] == val){
            ptr--;
        }
        
        int cur = 0;  //[0, cur) does not equal val
        while (cur < ptr){
            if(nums[cur] == val){
                swap(nums[cur], nums[ptr]);
                while(ptr >=0 && nums[ptr] == val){
                    ptr--;
                }
            }
            cur++;
        }
        return ptr+1;
    }
};