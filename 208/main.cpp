#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
class Trie {  // TrieNode
private:
    bool isEnd;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next)); // set memory
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(node->next[ch-'a'] == 0){
                node->next[ch-'a'] = new Trie();
            }
            node = node->next[ch-'a'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for(char c: word){
            node = node->next[c-'a'];
            if(node == NULL){
                return false;
            }
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c: prefix){
            node = node->next[c-'a'];
            if(node == NULL){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */