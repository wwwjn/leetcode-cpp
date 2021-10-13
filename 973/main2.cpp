//
// Created by Jiani Wang on 2021/10/10.
//

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,pair<int,int>>> maxh; // using maxheap here because we need to find closest or smallest number here and the top of maxheap always gives the kth smallest integer
        for(int i=0;i<points.size();i++){

            maxh.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}}); // Simply caclculating the distance here for our key
            if(maxh.size()>k) maxh.pop(); // if the size is greater than required then pop the heap
        }
        vector<vector<int> > ans; // create an extra vector to store the values
        while(!maxh.empty()){

            ans.push_back({maxh.top().second.first, maxh.top().second.second}); // pushing the second part of the heap
            maxh.pop();
        }
        return ans;
    }
};

