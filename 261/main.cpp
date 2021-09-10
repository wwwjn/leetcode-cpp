#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<set<int>> adj;
        adj.resize(n);
        for(int i = 0;i < edges.size(); i++){
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }

        set<int> visited;
        visited.insert(0);
        int prev = -1;
        bool res = dfs(0, adj, prev, visited);
        return res && visited.size() == n;
    }
    bool dfs(int node, vector<set<int>>& adj, int prev, set<int>& visited){
        set<int> e = adj[node];
        for(auto a: e){
            // cout << node << " : " <<  a  << ", prev: " << prev << endl;
            if(a == prev)
                continue;
            else{
                if(visited.find(a) != visited.end())
                    return false;
                else{
                    visited.insert(a);
                    if(dfs(a, adj, node, visited) == false)
                        return false; // contains a loop;
                }
            }
        }
        return true;
    }
};