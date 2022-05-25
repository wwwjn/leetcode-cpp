//
// Created by Jiani Wang on 2021/7/26.
//

#ifndef GRAPH_COMPONENTS_H
#define GRAPH_COMPONENTS_H

// 求无权图的联通分量
template <typename Graph>
class Component{

private:
    Graph &G;       // 图的引用
    bool *visited;  // 记录dfs的过程中节点是否被访问
    int ccount;     // 记录联通分量个数
    int *id;        // 每个节点所对应的联通分量标记

    void dfs( int v ){
        visited[v] = true;
        id[v] = ccount;
        typename Graph::Iterator adj(G, v);
        // 注意这个迭代器并不标准。vector/map/set的begin，end，next方法都是定义在这个该类中，并不是迭代器的方法。
        // 另外，iterator是个类名。此处for循环的写法也与一般不同。
        for(int i = adj.begin(); !adj.end(); adj.next){
            if(!visited[i]){
                dfs[i];
            }
        }
    }

public:
    // 构造函数, 求出无权图的联通分量
    Component(Graph &graph): G(graph){

        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for( int i = 0 ; i < G.V() ; i ++ ){
            visited[i] = false;
            id[i] = -1;
        }

        // 求图的联通分量
        for( int i = 0 ; i < G.V() ; i ++ )
            if( !visited[i] ){
                dfs(i);
                ccount ++;
            }
    }

    // 析构函数
    ~Component(){
        delete[] visited;
        delete[] id;
    }

    // 返回图的联通分量个数
    int count(){
        return ccount;
    }

    // 查询点v和点w是否联通
    bool isConnected( int v , int w ){
        assert( v >= 0 && v < G.V() );
        assert( w >= 0 && w < G.V() );
        return id[v] == id[w];
    }
};

#endif //GRAPH_COMPONENTS_H
