#include <iostream>

class Solution {
private:
    unordered_map<int, vector<string>> ans;
    // [i... s.size()-1] the possible sentences

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(int i = 0 ; i< wordDict.size(); i++){
            dict.insert(wordDict[i]);
        }
        findWord(s, 0, dict);
        return ans[0];

    }
    void findWord(string s, int index, unordered_set<string>& dict){
        if(ans.find(index) == ans.end()){  // no record in ans
            if(index == s.size()){
                ans[index] = {""}; // use as a vector
                return;
            }
            ans[index] = {};
            // Traceback to find all the anwser
            for(int i = index; i< s.size(); i++){
                string tmp = s.substr(index, i-index+1);
                if(dict.find(tmp) != dict.end()){
                    findWord(s, i+1, dict);
                    for(string c: ans[i+1]){
                        if(c == "")
                            ans[index].push_back(tmp);
                        else
                            ans[index].push_back(tmp + " " + c);
                    }
                }
            }
        }

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
