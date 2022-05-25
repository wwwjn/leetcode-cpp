#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> record_p, record_s;
        for(int i = 0; i< p.size(); i++){
            if(!record_p.count(p[i]))
                record_p.insert(make_pair(p[i], 1));
            else
                record_p[p[i]] += 1;
        }
        int l = 0;
        int r = p.size()-1; //[l....r]
        for(int i = l; i <= r; i++){
            if(!record_s.count(s[i]))
                record_s.insert(make_pair(s[i], 1));
            else
                record_s[s[i]] += 1;
        }
        if(record_s == record_p)
            res.push_back(l);
        while(r < s.size()){
            if(r + 1 < s.size()){
                if(record_s[s[l]] == 1)
                    record_s.erase(s[l]);
                else
                    record_s[s[l]] -= 1;
                l++;
                r++;
                if(!record_s.count(s[r]))
                    record_s.insert(make_pair(s[r], 1));
                else
                    record_s[s[r]] += 1;
                if(record_s == record_p)
                    res.push_back(l);
            }else{
                break;
            }
        }
        return res;

    }
};



int main() {
    string s = "aa";
    string p = "bb";
    vector<int> res = Solution().findAnagrams(s, p);
    for(int i = 0; i<res.size(); i++){
        cout << res[i];
    }
    cout << endl;
    return 0;
}
