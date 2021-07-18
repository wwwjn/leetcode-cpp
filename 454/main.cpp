#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> record1, record2;
        for(int i = 0; i < nums1.size(); i ++){
            for(int j = 0; j < nums2.size(); j++){
                int temp_sum = nums1[i] + nums2[j];
                if(record1.find(temp_sum) != record1.end()){
                    record1[temp_sum] ++;
                }
                else{
                    record1.insert(make_pair(temp_sum, 1));
                }

            }
        }
        for(int i = 0; i < nums3.size(); i ++){
            for(int j = 0; j < nums4.size(); j++){
                int temp_sum = nums3[i] + nums4[j];
                if(record2.find(temp_sum) != record2.end()){
                    record2[temp_sum]++;
                }
                else{
                    record2.insert(make_pair(temp_sum, 1));
                }
            }
        }
        int res = 0;
        for(auto item: record1){ //item:pair
            if(record2.find(-item.first) != record2.end()){
                res += (record2[-item.first] * record1[item.first]);
            }
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
