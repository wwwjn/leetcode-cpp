#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> record1, record2;
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            if(record1.find(s[i]) == record1.end() && record2.find(t[i]) == record2.end()){
                record1.insert(make_pair(s[i], t[i]));
                record2.insert(make_pair(t[i], s[i]));
            }
            else{
                if(record1[s[i]] != t[i] || record2[t[i]] != s[i]) return false;
                else continue;
            }
        }
        return true;
    }
};

int main() {
    cout << Solution().isIsomorphic("foo", "bar");
    return 0;
}
