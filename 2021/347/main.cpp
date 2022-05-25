#include <iostream>
#include "queue"
#include "unordered_map"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        for(int i = 0; i< nums.size(); i++){
            record[nums[i]] ++;
        }

        // 频率，元素
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        for(auto r: record){
            if(pq.size() < k){
                pq.push(make_pair(r.second, r.first));
            }
            else if(pq.size() == k){
                if(r.first > pq.top().first){
                    pq.pop(); // 弹出频率最小的
                    pq.push(make_pair(r.second, r.first));
                }
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
