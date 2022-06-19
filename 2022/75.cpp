class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0; //[0, one) = 0
        int twos = nums.size() - 1; // (nums.size() -1, nums.size()-1] = 2
        while(zeros < nums.size() && nums[zeros] == 0){
            zeros++;
        }
        while(twos >=0 && nums[twos] == 2){
            twos --;
        }
        for(int cur = 0; cur <= nums.size()-1; ){
            if(nums[cur] == 0 && cur >= zeros){
                swap(nums[cur], nums[zeros]);
                zeros ++;
            }else if(nums[cur] == 2 && cur <= twos){
                swap(nums[cur], nums[twos]);
                twos--;
            }else{
                cur++;
            }
        }
    }
};