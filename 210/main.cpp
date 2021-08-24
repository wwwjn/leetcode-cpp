#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indegs;
    vector<int> res;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> record;
        edges.resize(numCourses);
        indegs.resize(numCourses);
        // build the graph
        for(int i = 0; i< prerequisites.size(); i++){
            indegs[prerequisites[i][0]]++;
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i< numCourses; i++){
            if(indegs[i] == 0){
                record.push(i);
                indegs[i] --; // mark already used courses;
            }

        }

        while(!record.empty()){
            int k = record.front();
            record.pop();
            res.push_back(k);
            for(int j = 0; j < edges[k].size(); j++){
                indegs[edges[k][j]]--;
                if(indegs[edges[k][j]] == 0){
                    record.push(edges[k][j]);
                }
            }
        }
        if(res.size() == numCourses)
            return res;
        else
            return {};

    }
};