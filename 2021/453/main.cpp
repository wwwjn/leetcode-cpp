#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int x=nums[0],k=0;
        while(k<nums.size() && nums[k]==x){
            k++;
        }
        for(int i=k;i<nums.size();i++){
            nums[i]+=ans;
            ans+=nums[i]-nums[i-1];
        }
        return ans;
    }
};