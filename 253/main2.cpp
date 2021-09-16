//
// Created by Jiani Wang on 2021/9/14.
//

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return true;
        }
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> endTime;  // Min heap
        endTime.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++){
            int end = endTime.top();
            if(intervals[i][0] >= end){ // do not need another room
                endTime.pop();
                endTime.push(intervals[i][1]);
            }else{
                endTime.push(intervals[i][1]);
            }
        }
        return endTime.size();
    }
};