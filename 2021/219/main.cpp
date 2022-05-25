#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 1)
            return false;
        unordered_set<int> record;
        int l = 0;
        int r = l+1; // [l... r)
        while(r <= l + k && r < nums.size()){
            if(record.find(nums[r]) == record.end()){
                record.insert(nums[r]);
                r++;
            }else{
                return true;
            }
        }
        while(r < nums.size()){
            record.erase(nums[l]);
            l ++;
            if(record.find(nums[r]) == record.end()){
                record.insert(nums[r]);
                r++;
            }else return true;
        }
        return false;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
