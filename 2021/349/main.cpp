#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record(nums1.begin(), nums1.end());
        set<int> res_set;
        for(int j = 0; j < nums2.size(); j++){
            if(record.count(nums2[j]))
                res_set.insert(nums2[j]);
        }
        vector<int> res(res_set.begin(), res_set.end());
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
