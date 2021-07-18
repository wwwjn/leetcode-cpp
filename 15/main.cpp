#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum2(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        unordered_map<int,vector<vector<int>>> record;  // record 存成res
        vector<vector<int>> res;
        set<vector<int>> test;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(i != j){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    if(record.find(nums[i] + nums[j]) == record.end()){
                        vector<vector<int>> t;
                        t.push_back(temp);
                        record.insert(make_pair(nums[i] + nums[j], t));
                    }
                    else{ // can find nums[i] + nums[j] in record;
                        record[nums[i] + nums[j]].push_back(temp);
                    }
                }
            }
        }
        // 这个循环是O(N^2) * O(n)
        for(int k = 0; k < nums.size(); k++){
            if(record.find(-nums[k]) != record.end()){
                vector<vector<int>> t = record[-nums[k]];
                for(int l = 0; l < t.size(); l++){
                    if(k != t[l][0] && k != t[l][1]){
                        vector<int> res_t = {nums[t[l][0]], nums[t[l][1]], nums[k]};
                        sort(res_t.begin(), res_t.end());
                        test.insert(res_t);
                    }
                }
            }
        }
        for(auto myset : test) {
            vector<int> tmpres;
            for (auto s : myset) {
                tmpres.push_back(s);
            }
            res.push_back((tmpres));
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> nums_count;
        unordered_set<int> keys;
        vector<int> undup;
        for(auto i: nums){
            if(nums_count.find(i) != nums_count.end()) nums_count[i] ++;
            else  {
                nums_count.insert(make_pair(i, 1));
                keys.insert(i);
            }
        }

        set<vector<int>> set_res;
        for(auto i: keys){
            for(auto j: keys){
                if((i == j && nums_count[j] >= 2) || i != j ){
                    int current = - (i + j);
                    int need_cnt = 1 + (current == i) + (current == j);
                    if(nums_count.find(current) != nums_count.end() && nums_count[current] >= need_cnt){
                        vector<int> temp = {current, i, j};
                        sort(temp.begin(), temp.end()); // 去重
                        set_res.insert(temp);
                    }
                }
                else{
                    continue;
                }
            }
        }
        vector<vector<int>> res;
        for(auto myset : set_res) {
            vector<int> tmpres;
            for (auto s : myset) {
                tmpres.push_back(s);
            }
            res.push_back((tmpres));
        }
        return res;
    }
};
int main() {
    int arr[] = {-1,0,1,2,-1,-4};
    vector<int> nums(arr, arr + sizeof(arr)/ sizeof(int) );

    vector<vector<int>> res = Solution().threeSum(nums);
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++){
        cout << i << ": [" ;
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
