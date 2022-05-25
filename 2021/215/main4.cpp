//
// Created by Jiani Wang on 2021/10/10.
//

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // MinHeap
        for(int i = 0; i< nums.size(); i++){
            if(pq.size() == k && nums[i]> pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }else if(pq.size() < k){
                pq.push(nums[i]);
            }
        }
        return pq.top();

    }
};