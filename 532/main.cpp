#include <iostream>
#include<iostream>
using namespace std;

int main()
{
    int i = 5, j = 2;
    printf("%d %d", ++i, --i);
}
//class Solution {
//public:
//    int findPairs(vector<int>& nums, int k) {
//        unordered_map<int, int> m;
//        for(int i = 0; i< nums.size(); i++){
//            m[nums[i]]++;
//        }
//        int sum = 0;
//        for(auto i: m){
//            int num = i.first;
//            int count = i.second;
//            if(k == 0){
//                if(m[num] > 1){
//                    sum++;
//                    continue;
//                }
//            }else{
//                if(m.find(num+k) != m.end()){
//                    sum += 1;
//                }
//            }
//
//        }
//        return sum;
//    }
//};