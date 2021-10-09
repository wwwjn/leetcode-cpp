#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.empty()) return ans;
        multiset<int> window(nums.begin(), nums.begin()+k);
        ans.push_back(*window.rbegin());
        for(int i = k; i < nums.size(); i++){
            // [i-k+1, i]
            window.insert(nums[i]);
            window.erase(window.equal_range(nums[i-k]).first);
            ans.push_back(*window.rbegin());
        }
        return ans;
    }
};