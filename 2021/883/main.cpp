#include <iostream>

class Solution {
public:
    struct node{
        int p;  // index of this node
        int d;  // distence from node0
        node(int _p=0, int _d = 0):p(_p), d(_d){}
        // using the distance to compair
        bool operator<(const node& o) const{
            return d>o.d;
        }
        // 此题不用记录from的数组，否则Node中还需加入predecessor节点index的信息。（加一个int）
    };
    struct edge{
        int u, v, w;
        edge(int _u=0, int _v=0, int _w=0):u(_u), v(_v), w(_w){}
        int another(int x) const{
            return x==u? v:u;
        }
    };
    void addEdge(vector<vector<int>>& grid, vector<edge>& _edges, vector<int>& v){
        edge e(v[0], v[1], v[2]+1);
        _edges.push_back(e);
        int index = _edges.size() -1;
        // adjacent table
        grid[e.u].push_back(index);
        grid[e.v].push_back(index);
    }
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        int M = maxMoves;
        int N = n;
        // graph. N nodes -- index of edge
        vector<vector<int>> grid(N, vector<int>());
        vector<edge> _edges;

        // Build a graph
        for(int i = 0; i< edges.size(); i++){
            addEdge(grid, _edges, edges[i]);
        }

        vector<int> dis(N, INT_MAX);  // distance from node 0
        dis[0] = 0;
        priority_queue<node> Q;  //
        Q.push(node(0,0));
        while(!Q.empty()){
            node nd = Q.top();
            Q.pop();
            int p = nd.p;
            int d = nd.d;
            for(int i = 0; i< grid[p].size(); i++){
                edge e= _edges[grid[p][i]];
                int v = e.another(p); // index of another node
                if(dis[p] + e.w < dis[v]){ // from node p to node v has short path
                    dis[v] = dis[p] + e.w;
                    Q.push(node(v, dis[v]));
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<_edges.size(); i++){
            edge& e = _edges[i];
            // important: the most number of nodes that each edge can contribute to the answer
            ans += min(max(M-dis[e.u], 0) + max(M-dis[e.v],0), e.w-1);
        }
        for(int i = 0; i < N; i++){
            if(dis[i] <= M) ans++;
        }
        return ans;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
