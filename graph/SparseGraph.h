//
// Created by Jiani Wang on 2021/7/26.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H
using namespace std;

class SparseGraph{
private:
    int n, m;
    bool directed;
    vector<vector<int>> g;

public:
    SparseGraph(int n, bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for(int i = 0; i < n; i++){
            g.push_back(vector<int>());
        }
    }
    ~SparseGraph(){}
    int V(){return n;}
    int E(){return m;}
    void addEdge(int v, int w){
        assert(v >= 0 & v < n);
        assert(w >= 0 & w < n);

        // if(hasEdge(v, w)) return; // 先不管平行边的位置

        g[v].push_back(w);
        if(v != w && !directed)
            g[w].push_back(v);
        m++;
    }
    bool hasEdge(int v, int w){
        assert(v >= 0 & v < n);
        assert(w >= 0 & w < n);
        for(int i = 0; i < g[v].size(); i ++){
            if(g[v][i] == w)
                return true;
        }
        return false;
    }
    void show(){
        for( int i = 0 ; i < n ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; j < g[i].size() ; j ++ )
                cout<<g[i][j]<<"\t";
            cout<<endl;
        }
    }
    class adjIterator{
    private:
        SparseGraph &G; // 图G的引用
        int v;
        int index;

    public:
        // 构造函数
        adjIterator(SparseGraph &graph, int v): G(graph){  // 注意参数列表的初始化方法
            this->v = v;
            this->index = 0;
        }

        ~adjIterator(){}

        // 返回图G中与顶点v相连接的第一个顶点
        int begin(){
            index = 0;
            if( G.g[v].size() )
                return G.g[v][index];
            // 若没有顶点和v相连接, 则返回-1
            return -1;
        }
        int next(){
            index ++;
            if( index < G.g[v].size() )
                return G.g[v][index];
            // 若没有顶点和v相连接, 则返回-1
            return -1;
        }
        bool end(){
            return index >= G.g[v].size();
        }
    };
};


#endif //GRAPH_SPARSEGRAPH_H
