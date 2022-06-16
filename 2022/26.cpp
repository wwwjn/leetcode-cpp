class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int ptr = 0;
        int cur = 0;
        while(cur < nums.size()){
            while(cur < nums.size() && nums[cur] == nums[ptr]){
                cur++;
            }
            if(cur < nums.size()){
                nums[ptr+1] = nums[cur];
                cur++;
                ptr++;
            }
            
        }
        // for(int cur = 0; cur < nums.size();){
        //     while(nums[cur] == nums[ptr]){
        //         cur++;
        //     }
        //     if(cur < nums.size()) {
        //         nums[ptr+1] = nums[cur];
        //         cur++;
        //         ptr++;
        //     }
        // }
        return ptr+1;
    }
};