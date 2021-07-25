//
// Created by Jiani Wang on 2021/7/25.
//

#include "iostream"

namespace UF2{
    class UnionFind{
    private:
        int* parent; // 理解为只有父指针的二叉树
        int count;
        int* rank; // 以i为根的树 的 rank

    public:
        UnionFind(int count){
            parent = new int[count];
            this->count = count;
            for(int i = 0; i < count; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }
        ~UnionFind(){
            delete [] parent;
            delete [] rank;
        }
        int find(int p){  //路径压缩：在find的同时，将树的高度压缩
            assert(p>=0 && p<count);
//            while(p!=parent[p]){
//                parent[p] = parent[parent[p]]; // 根节点的父亲是自己，不会有空指针的问题;
//                p = parent[p];
//            }
//            return p;
            //另一种路径压缩: 压缩的层次给你
            if(p != parent[p])
                parent[p] = find(parent[p]);
            return parent[p]; // parent[p]才是最终的根
        }
        bool isConnected(int p, int q){
            return find(p) == find(q);
        }
        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);
            if(pRoot == qRoot) return;
            if(rank[pRoot] > rank[qRoot]){
                parent[qRoot] = pRoot;
            }
            else if(rank[pRoot] < rank[qRoot]){
                parent[pRoot] = qRoot;
            }else{  //rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] ++;
            }
        }
    };
}