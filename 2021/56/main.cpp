#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            vector<int> nums1 = merged[merged.size()-1];
            vector<int> nums2 = intervals[i];
            if(min(nums1[1], nums2[1]) >= max(nums1[0], nums2[0])){
                // need to merge
                vector<int> tmp = { nums1[0], max(nums1[1], nums2[1])};
                merged[merged.size() -1] = tmp;
            }else{
                // do not need to merge
                merged.push_back(nums2);
            }
        }
        return merged;
    }
private:
    vector<vector<int>> mergeTwo(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>> res;
        if(min(nums1[1], nums2[1]) >= max(nums1[0], nums2[0]) )
            res.push_back({min(nums1[0], nums2[0]), max(nums1[1], nums2[1])});
        else{
            res.push_back(nums1);
            res.push_back(nums2);
        }
        return res;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
