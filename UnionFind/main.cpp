#include <iostream>
#include "cassert"
using namespace std;
class UnionFind{
private:
    int* id;
    int count;
public:
    UnionFind(int n){
        count = n;
        id = new int[n];
        for(int i = 0; i < n; i++){
            id[i] = i; // 初始，每个结点都不连通
        }
    }
    ~UnionFind(){
        delete [] id;
    }
    int find(int p){
        assert(p>=0 && p < count);
        return id[p];
    }
    bool isConnected(int p, int q){ // quick find实现
        return find(p) == find(q);
    }
    void unionElement(int p, int q){
        int pID = find(p);
        int qID = find(q);
        if(pID == qID) return;
        for(int i = 0; i < count; i++){
            if(id[i] == pID){
                id[i] = qID;
            }
        }
    }

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
