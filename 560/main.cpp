#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // perfix + hashTable
        map<int, int> record; // the prefix sum, how many times
        record.insert({0,1});

        int sum = 0; // prefix sum
        int res = 0;

        for(int i = 0; i< nums.size(); i++){
            sum += nums[i];
            int target = sum - k;
            if(record.find(target) != record.end()){
                res += record[target];
            }
            //update hashtable;
            if(record.find(sum) == record.end()){
                record.insert({sum, 1});
            }else{
                record[sum] ++;
            }
        }
        return res;
    }
};

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), comp);
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }

};