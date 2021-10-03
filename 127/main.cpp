#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;

        int l = beginWord.size();
        int step = 0;

        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};

        while(!q1.empty() && !q2.empty()){
            ++step;
            // Always expend the smaller queue first
            if (q1.size() > q2.size())
                std::swap(q1, q2);

            unordered_set<string> q;

            for (string w : q1) {
                for (int i = 0; i < l; i++) {
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if (q2.count(w)) return step + 1;
                        if (!dict.count(w)) continue;
                        dict.erase(w);  // avoid duplicate
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }
            std::swap(q, q1);  // q: 所有通过step可以变化到的词

        }
        return 0;
    }
};