#include <iostream>

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return 0;
        }
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> endTime;
        endTime.push(intervals[0][1]);
        for(int i=1; i< intervals.size(); i++){
            if(intervals[i][0] < endTime.top()){
                // assign a new room
                endTime.push(intervals[i][1]);
            }else{
                endTime.pop();

                endTime.push(intervals[i][1]);
            }
        }
        return endTime.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
