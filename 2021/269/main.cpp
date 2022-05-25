#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, set<char>> adj;
        unordered_map<char, int> degree;
        set<char> seen;
        for(int i = 0; i< words.size(); i++){
            for(char s: words[i])
                seen.insert(s);
        }
        // build the directed graph
        for(int i = 0; i < words.size()-1; i++){
            int j = i+1;
            int idx = 0;
            while(idx < words[i].size() && idx < words[j].size()){
                if(words[i][idx] == words[j][idx]){
                    idx++;
                    if(idx != words[i].size() && idx == words[j].size() && adj.empty()) return "";
                }
                else{
                    char key = words[i][idx];
                    char value = words[j][idx];
                    cout << key << ": " << value << endl;
                    if(adj.find(key) == adj.end()){
                        set<char> tmp{value};
                        adj.insert({key, tmp});
                    }else{
                        adj[key].insert(value);
                    }
                    break;
                }
            }
        }

        int minDegree = INT_MAX;
        for(auto a: adj){
            if(degree.find(a.first) == degree.end()) degree[a.first] = 0;
            for(auto nei: a.second){
                degree[nei]++;  // in degre
            }
        }


        queue<char> q;
        string res = "";
        for(auto s: seen){
            if(degree[s] == 0){
                res += s;
                q.push(s);
            }
        }

        while(!q.empty()){
            char cur = q.front();
            q.pop();
            cout << cur << ": " << degree[cur] << endl;

            for(auto nei: adj[cur]){
                degree[nei]--;
                if(degree[nei] == 0){
                    q.push(nei);
                    res += nei;
                }
            }
        }

        return res.size() == seen.size() ? res: "";
    }
};