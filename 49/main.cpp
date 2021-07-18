#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> record;
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            vector<int> tmp_vec(26,0);
            // make the vector
            for(int j = 0; j < tmp.size(); j++){
                tmp_vec[tmp[j] - 'a'] ++;
            }
            if(record.find(tmp_vec) == record.end()){
                vector<string> tmp_str;
                tmp_str.push_back(tmp);
                record.insert(make_pair(tmp_vec, tmp_str));
            }
            else{
                record[tmp_vec].push_back(tmp);
            }
        }
        vector<vector<string>> res;
        for(auto item: record){
            res.push_back(item.second);
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
