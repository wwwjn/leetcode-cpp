#include <iostream>

class Solution {
private:
    unordered_map<int,int> record;
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n, true);
    }
    vector<string> find(int n, bool isEnd){
        record.insert({1,1});
        record.insert({0,0});
        record.insert({8,8});
        record.insert({9,6});
        record.insert({6,9});
        vector<string> res;
        if(n == 1){
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
            return res;
        }
        if(n == 2){
            res.push_back("11");
            res.push_back("69");
            res.push_back("88");
            res.push_back("96");
            if(!isEnd)
                res.push_back("00");
            return res;
        }
        vector<string> tmp = find(n-2, false);
        for(int i = 0; i< tmp.size(); i++){
            for(auto r: record){
                if(isEnd && r.first == 0)
                    continue;
                res.push_back(to_string(r.first) + tmp[i] + to_string(r.second));
            }
        }
        return res;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
