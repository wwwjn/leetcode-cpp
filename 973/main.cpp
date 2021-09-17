#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<int> dis; // MaxHeap
        map<int, vector<vector<int>>> m; // dis --> (x,y)
        vector<vector<int>> res;
        int count = 0;
        for(int i = 0; i < points.size(); i++){
            int d = distance(points[i][0], points[i][1]);
            // cout << d << endl;
            if(count < k){
                if(m.find(d) == m.end()){
                    vector<vector<int>> tmp;
                    tmp.push_back(points[i]);
                    m.insert({d, tmp});
                }else{
                    m[d].push_back(points[i]);
                }
                count ++;
                dis.push(d);
            }else{ // evict the largest one
                int max_d = dis.top();
                if(d >= max_d) continue; // do nothing
                if(m[max_d].size() > 1){
                    m[max_d].pop_back(); // delete
                }
                else{
                    m.erase(max_d);
                    dis.pop();
                }
                if(m.find(d) == m.end()){
                    vector<vector<int>> tmp;
                    tmp.push_back(points[i]);
                    m.insert({d, tmp});
                }else{
                    m[d].push_back(points[i]);
                }
                dis.push(d);
            }
        }
        for(auto a = m.begin(); a != m.end(); a++){
            vector<vector<int>> tmp = a->second;
            for(int i = 0; i < tmp.size(); i++){
                res.push_back(tmp[i]);
            }
        }
        return res;

    }
    int distance(int x, int y){
        return x*x + y*y;
    }
};