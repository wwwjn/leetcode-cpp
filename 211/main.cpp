#include <iostream>

class Trie{
private:
    bool isEnd;
    Trie* next[26];
public:
    Trie(){
        isEnd = false;
        memset(next, 0, sizeof(next));
    };
    void add(string s){
        Trie* node = this;
        for(char c: s){
            if(node->next[c-'a'] == NULL){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    bool search(string s){
        Trie* node = this;
        return dfs(s, 0, node);
    }
    bool dfs(string& s, int index, Trie* node){
        if(index == s.size()){
            return node->isEnd;
        }
        if(s[index] == '.'){
            bool flag = false; // can not find
            for(int i = 0; i < 26; i++){
                if(node->next[i] != NULL){
                    flag = flag || dfs(s, index+1, node->next[i]);
                    if(flag)
                        break;
                }
            }
            return flag;
        }else{ // s[index] != '.'
            if(node->next[s[index] - 'a'] != NULL){
                return dfs(s, index+1, node->next[s[index] - 'a']);
            }else{
                return false;
            }
        }
    }

};

class WordDictionary {
private:
    Trie* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }

    void addWord(string word) {
        root->add(word);
    }

    bool search(string word) {
        return root->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
