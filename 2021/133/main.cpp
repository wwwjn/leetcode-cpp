#include <iostream>
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        // oldNode -> newNode
        unordered_map<Node*, Node*> cloneMap; // whether oldNodes are visited
        queue<Node*> needToVisit; // need to add neighbors to adjacent table
        needToVisit.push(node);

        Node* newRoot = new Node(node->val);
        cloneMap.insert({node, newRoot});

        while(!needToVisit.empty()){
            Node* oldNode = needToVisit.front();
            Node* newNode = cloneMap[oldNode];
            needToVisit.pop();
            vector<Node*> nei = oldNode->neighbors;
            for(int i = 0 ; i< nei.size(); i++){
                if(cloneMap.find(nei[i]) == cloneMap.end()){
                    Node* newNei = new Node(nei[i]->val);
                    newNode->neighbors.push_back(newNei);
                    cloneMap.insert({nei[i], newNei});
                    needToVisit.push(nei[i]);
                }else{  // only need to add an Edge in newNode's adjacent table
                    newNode->neighbors.push_back(cloneMap[nei[i]]);
                }
            }
        }
        return newRoot;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
