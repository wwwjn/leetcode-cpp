#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int> need(128, 0);
        int needCnt = t.size();
        for(int i = 0; i< n; i++){
            need[t[i]-'A'] ++;
        }

        int i = 0;
        int j = 0;
        int minLen = INT_MAX;
        vector<int> res(2, 0);
        // [i..j] is considered
        while(j < s.size()){
            // considering j;
            if(needCnt > 0){  // still need some chars
                if(need[s[j]-'A'] > 0)
                    needCnt --;
                need[s[j]-'A']--;
                j++;  // extend the window
            }
            if(needCnt == 0){
                while(true){ // contract the left side of window
                    if(need[s[i]-'A'] == 0){ // find a exact good windows
                        break;
                    }
                    need[s[i] - 'A'] ++;
                    i++;
                }
                // update minLen
                if(j-i < minLen){
                    minLen = j-i;
                    res[0] = i;
                    res[1] = j;
                }
                // move i to find another window that meets requirments
                need[s[i] - 'A'] ++;
                i++;
                needCnt++;
            }
        }
        if(res[1] > res[0])
            return s.substr(res[0], res[1] - res[0]);
        else
            return "";

    }
};

int main() {
    string s = "ADOBECODEBANC";

    string p = "ABC";
    cout << Solution().minWindow(s, p) << endl;
    return 0;
}
