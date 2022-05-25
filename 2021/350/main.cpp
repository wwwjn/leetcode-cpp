#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++){
            if(record.find(nums1[i]) != record.end())
                record.insert(make_pair(nums1[i],1));
            else record[nums1[i]]++;
        }
        for(int j=0; j<nums2.size(); j++){
            if(record[nums2[j]] > 0){
                res.push_back(nums2[j]);
                record[nums2[j]] -- ;
            }
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
