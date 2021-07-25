#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
using namespace std;

template <typename Key, typename Value>
class BST{
private:
    struct Node{
        Key key;
        Value value;
        Node* left;
        Node* right;
        Node(Key key, Value value){  // this的用法
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
        Node(Node* node){
            this->left = node->left;
            this->right = node->right;
            this->key = node->key;
            this->value = node->value;
        }
    };
    Node* root;
    int count;
public:
    BST(){
        count = 0;
        root = NULL;
    }
    bool isempty(){
        return count == 0;
    }
    bool size(){
        return count;
    }
    void insert(Key k, Value v){
        root = insert(root, k, v);
    }
    void insert2(Key k, Value v){
        Node* node = new Node(k, v);
        Node* ptr = root;
        if(root == NULL){
            root = node;
            return;
        }
        while(true){
            if(ptr->key == k){
                ptr->value = v;
                break;
            }else if(ptr->key > k){
                if(ptr->left!= NULL) ptr = ptr->left;
                else{
                    ptr->left = node; break;
                }
            }else{
                if(ptr->right != NULL)ptr = ptr->right;
                else{
                    ptr->right = node; break;
                }
            }
        }
        count ++;
    }
    bool contain(Key key){
        return contain(root, key);
    }
    Value* search(Key key){
        return search(root, key);
    }
    void destroy(Node* node){
        if(node != NULL){
            destroy(node->left);
            destroy(node->right);
            delete node;
            count --;
        }
    }
    void inorder(){
        inorder(root);
    }
    Key maximum(){ // 返回最大值
        assert(count > 0);
        Node* maxNode = maximum(root);
        return maxNode->key;
    }
    Key minimum(){
        assert(count> 0);
        Node* minNode = minimum(root);
        return minNode->key;
    }
    void removeMax(){
        if(root)
            root = removeMax(root);

    }
    void removeMin(){
        if(root) root = removeMin(root);
    }
    void remove(Key key){
        // 迭代的方法
        root = remove(root, key);
    }
private:
    Node* insert(Node* node, Key k, Value v){
        //返回插入后二叉搜索树的根
        if(node == NULL){
            count ++;  // 注意递归算法时count++的位置
            return new Node(k, v);
        }
        //如果有相等的值，要更新
        if(node->key == k){
            node->value = v;
        }else if(k < node->key){
            node->left = insert(node->left, k, v);
        }else{
            node->right = insert(node->right, k, v);
        }
        return node;
    }
    bool contain(Node* node, Key k){
        // 在node为根的二叉树中寻找key
        if(node == NULL) return false;
        Node* ptr = node;
        if(ptr->key == k) return true;
        else if(ptr->key > k){
            return contain(ptr->left, k);
        }else{
            return contain(ptr->right, k);
        }
    }
    Value* search(Node* node, Key k){
        if(node == NULL) return NULL;
        Node* ptr = node;
        if(ptr->key == k)
            return &(ptr->value);
        else if(ptr->key > k)
            return search(ptr->left, k);
        else
            return search(ptr->right, k);
    }
    void inorder(Node* node){
        if(node != NULL){
            inorder(node->left);
            cout << node->key << endl;
            inorder(node->right);
        }
    }
    Node* maximum(Node* node){
        if(node->right == NULL) return node;
        return maximum(node->right);
    }
    Node* minimum(Node* node){
        if(node->left == NULL) return node;
        return maximum(node->left);
    }
    Node* removeMax(Node* node){
        if(node == NULL) return NULL;
        // 删除以node为根的树中的最大值，返回删除后的根
        if(node->right == NULL){
            Node* ret = node->left;
            delete node;
            count --;
            return ret;
        }
        node->right = removeMax(node->right); //TODO: 注意这里的写法
        return node;
    }
    Node* removeMin(Node* node){
        if(node == NULL) return NULL;
        // 删除node为根的子树中的最小值，返回删除后的根
        if(node->left == NULL){
            Node* ret = node->right;
            delete node;
            count --;
            return ret;
        }
        node->left = removeMin(node->left);
        return node;
    }
    Node* remove(Node* node, Key k){
        // 删除以Node为根节点的子树中，key 为k的结点
        // 返回删除后子树的根节点
        if(node == NULL) return NULL;
        if(node->key > k){
            node->left = remove(node->left, k);
            return node;
        }else if(node->key < k){
            node->right = remove(node->right, k);
            return node;
        }else{ // node就是待删除节点
            if(node->left == NULL){
                Node* ret = node->right;
                delete node;
                count --;
                return ret;
            }
            if(node->right == NULL){
                Node* ret = node->left;
                delete node;
                count --;
                return ret;
            }

            //node 的左右孩子均不为空
            Node* minNode = minimum(node->right);
            // 此处新生成一个successor是为了防止后序removeMin时，successor指向的node消失
            Node* successor = new Node(minNode);
            count ++;
            // 右子树删除最小值，返回新的右子树的根
            Node* right_root = removeMin(node->right); // removeMin不会影响node节点哦
            successor->right = right_root;
            successor->left = node->left;
            delete node;
            count --;
            return successor;
        }
    }
};



int main() {
    BST<int, int> tree = BST<int, int>();
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        int k = rand()%100;
        int v = rand()%100;
        cout << k << ": " << v << "  ";
        tree.insert(k,v);
    }
    tree.insert(50,0);
    cout << endl;
    tree.inorder();
    cout << endl;
    tree.remove(50);
    tree.inorder();
    return 0;
}
