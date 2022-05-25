#include <iostream>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int start = 0;
        int end = 0;
        vector<vector<int>> res;
        for(int i = 0; i< intervals.size(); i++){
            if(intervals[i][1] < newInterval[0]){
                start++;
                res.push_back(intervals[i]);
            }
            if(intervals[i][0] <= newInterval[1]){
                end++;
            }
        }
        // from [start...end) need to be merged.
        if(start == end){ // no overlap
            res.push_back(newInterval);

        }else{
            int min_start = min(intervals[start][0], newInterval[0]);
            int max_end = max(intervals[end - 1][1], newInterval[1]);
            res.push_back({min_start, max_end});
        }
        for(int j = end; j < intervals.size(); j++){
            res.push_back(intervals[j]);
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
