#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow1(string s, string t) {
        int min_length = s.length() + 1;
        string res = "";
        map<char, int> record_s, record_t;
        for(int i=0; i<t.size(); i++){
            if(!record_t.count(t[i])) record_t[t[i]] = 1;
            else record_t[t[i]] += 1;
        }
        int l = 0;
        int r = t.size() - 1; // [l...r]
        for(int i = l; i <= r; i++){  // put [l...r] into record_s
            if(record_t.count(s[i])){
                if(!record_s.count(s[i])) record_s[s[i]] = 1;
                else record_s[s[i]] += 1;
            }
        }
        while(l < s.size()){
            if(compare(record_s, record_t)){
                if(r-l+1 < min_length) {
                    min_length = r - l + 1;
                    res = s.substr(l, min_length);
                }
                // move left pointer;
                if(record_t.count(s[l])){
                    if(record_s[s[l]] == 1) record_s.erase(s[l]);
                    else record_s[s[l]] --;
                }
                l++;
            }
            else{
                if(r+1 < s.size()){
                    r++;
                    if(record_t.count(s[r])){
                        if(record_s.count(s[r])) record_s[s[r]] ++;
                        else record_s[s[r]] = 1;
                    }
                }
                else break;
            }
        }
        if(min_length == s.size() + 1) return "";
        return res;
    }
    bool compare(map<char, int> A, map<char, int> B){
        // return whether A is greater than B
        bool res = true;
        map<char,int>::iterator b;
        for(b = B.begin(); b != B.end(); b++){
            if(A.count(b->first)) {
                if (b->second > A[b->first])
                    return false;
            }else{
                return false;  // key in A but no in B
            }
        }
        return res;
    }
    string minWindow(string s, string t) {
        int min_length = s.length() + 1;
        string res = "";
        unordered_map<char, int> record_s, record_t;
        int needCnt = 0; // 需要有多少个不同的字母的综合。替代compare。
        for(int i=0; i<t.size(); i++){
            if(!record_t.count(t[i])){
                record_t[t[i]] = 1;
                needCnt += 1;
            }
            else record_t[t[i]] += 1;
        }
        int l = 0;
        int r = t.size() - 1; // [l...r]
        for(int i = l; i <= r; i++){  // put [l...r] int
            if(record_t.count(s[i])){
                if(!record_s.count(s[i])) record_s[s[i]] = 1;
                else record_s[s[i]] += 1;
                if(record_t[s[i]] == record_s[s[i]]) needCnt -= 1;  // need the char
            }
        }
        while(l < s.size()){
            if(needCnt == 0){
                if(r-l+1 < min_length) {
                    min_length = r - l + 1;
                    res = s.substr(l, min_length);
                }
                // move left pointer;
                if(record_t.count(s[l])){ // in the target
                    if(record_s[s[l]] == 1) record_s.erase(s[l]);
                    else record_s[s[l]] --;
                    if(record_t[s[l]] > record_s[s[l]]) needCnt += 1;
                }
                l++;
            }
            else{
                if(r+1 < s.size()){
                    r++;
                    if(record_t.count(s[r])){
                        if(record_s.count(s[r])) record_s[s[r]] ++;
                        else record_s[s[r]] = 1;
                        if(record_t[s[r]] == record_s[s[r]]) needCnt -= 1;
                    }
                }
                else break;
            }
        }
        if(min_length == s.size() + 1) return "";
        return res;
    }
};
int main() {
    string s = "a";

    string p = "a";
    cout << Solution().minWindow(s, p) << endl;
    return 0;
}
