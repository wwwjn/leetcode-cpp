//
// Created by Jiani Wang on 2021/10/10.
//

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<int> q;
        unordered_map<int, vector<int>> record;
        for(int i= 0; i<points.size(); i++){
            vector<int> p = points[i];
            int d = distance(p);
            if(q.size() < k){
                q.push(d);
            }else if(d < q.top()){
                q.pop();
                q.push(d);
            }
            if(record.find(d) == record.end()){
                record.insert({d, vector<int>{i}});
            }else{
                record[d].push_back(i);
            }
        }
        set<vector<int>> res;
        while(!q.empty()){
            for(int i =0; i<record[q.top()].size(); i++){
                res.insert(points[record[q.top()][i]]);
            }
            q.pop();
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
    int distance(vector<int> p1){
        return (p1[0])*(p1[0]) + (p1[1])*(p1[1]);
    }
};