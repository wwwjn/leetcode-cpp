//
// Created by Jiani Wang on 2021/10/13.
//

class Solution {
private:
    vector<int> num;
public:
    Solution(vector<int>& nums) {
        this->num = nums;
    }

    int pick(int target) {
        int count = 0;
        int resIdx = 0;
        for(int i = 0; i< num.size(); i++){
            if(num[i] == target){
                count ++;
                if(rand() % count == 0)
                    resIdx = i;
            }
        }
        return resIdx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */