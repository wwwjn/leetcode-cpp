#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        int l = 0;
        int r = 0; // [l...r]
        unordered_set<char> record;
        record.insert(s[l]);
        int max_length = 1;
        while(l < s.size()){  //可能有滑动窗口
            if(r < s.size() - 1 && !record.count(s[r+1])){
                r++;
                record.insert(s[r]);
                if(r-l+1 > max_length){
                    max_length = r-l+1;
                }
            }
            else{
                record.erase(s[l]);
                l++;
            }
        }
        return max_length;
    }

};


int main() {
    string s = "aaaaaaa";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}
