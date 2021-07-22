#include <iostream>
#include <vector>
using namespace  std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedInteger{
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    vector<int> res;
    vector<int>::iterator res_iter;

    void recursive(const vector<NestedInteger>& nestedList, vector<int>& res){
        for(auto& n: nestedList){
            if(n.isInteger()) res.push_back(n.getInteger());
            else{
                recursive(n.getList(), res);
            }
        }
    }


public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        recursive(nestedList, res);
        res_iter = res.begin();
    }
    int next() {
        return *res_iter++;
    }

    bool hasNext() {
        return res_iter != res.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
