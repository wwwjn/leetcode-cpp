#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> record;
        map<string, char> record2;

        vector<string> sub;
        int l=0, r=0;
        s += ' ';
        while(r + 1 < s.size() && l <= r ){
            if(s[r] != ' ' && s[r+1] == ' '){
                sub.push_back(s.substr(l, r-l+1));
                l = r+2;
                r = l;
            }
            else{
                r++;
            }
        }
        for(int i=0; i<sub.size(); i++)
            cout << sub[i] << endl;
        if(sub.size() != pattern.size())
            return false;
        for(int i = 0; i<pattern.size() ; i ++){
            if(record.find(pattern[i]) == record.end() && record2.find(sub[i]) == record2.end()){
                record.insert(make_pair(pattern[i], sub[i]));
                record2.insert(make_pair(sub[i], pattern[i]));

            }else{
                if(record[pattern[i]] != sub[i] || record2[sub[i]] != pattern[i])
                    return false;
                else
                    continue;
            }
        }
        return true;
    }
};


int main() {
    cout << Solution().wordPattern("abba", "dog cat cat dog");
    return 0;
}
