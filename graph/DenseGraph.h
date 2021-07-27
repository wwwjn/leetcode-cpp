//
// Created by Jiani Wang on 2021/7/26.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include "iostream"
#include "vector"
#include "cassert"

using namespace std;

// 稠密图：邻接矩阵
class DenseGraph{
private:
    int n, m;
    bool directed;   // 是否为有向图
    vector<vector<bool>> g;
public:
    DenseGraph(int n, bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for(int i = 0; i < n; i++){
            g.push_back(vector<bool>(n, false));
        }
    }
    ~DenseGraph(){}
    int V(){return n;}
    int E(){return m;}
    void addEdge(int v, int w){
        assert(v >= 0 & v < n);
        assert(w >= 0 & w < n);

        if(hasEdge(v, w)) return;

        g[v][w] = true;
        if(!directed)
            g[w][v] = true;
        m++;
    }
    bool hasEdge(int v, int w){
        assert(v >= 0 & v < n);
        assert(w >= 0 & w < n);
        return g[v][w];
    }
    void show(){
        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < n ; j ++ )
                cout<<g[i][j]<<"\t";
            cout<<endl;
        }
    }
    class adjIterator{
    private:
        DenseGraph &G;  // 图G的引用
        int v;
        int index;

    public:
        // 构造函数
        adjIterator(DenseGraph &graph, int v): G(graph){
            assert( v >= 0 && v < G.n );
            this->v = v;
            this->index = -1;   // 索引从-1开始, 因为每次遍历都需要调用一次next()
        }
        ~adjIterator(){}
        int begin(){
            index = -1;
            return next();
        }
        int next(){
            for( index += 1 ; index < G.V() ; index ++ )
                if( G.g[v][index] )
                    return index;
            return -1;
        }
        bool end(){
            return index >= G.V();
        }
    };
};


#endif //GRAPH_DENSEGRAPH_H
