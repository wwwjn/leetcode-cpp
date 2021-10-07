#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0) return 0;
        //sliding window
        map<char, int> m;
        int i = 0;
        int j = 0; // considering [i..j]
        m.insert({s[i], 1});
        int maxLen = 1;
        while(j < s.size()){
            if(m.size() < k){
                maxLen = max(j-i+1, maxLen);
                j++;
                m[s[j]]++;
            }else if(m.size() > k){  // s.size() == k
                if(m[s[i]] == 1) m.erase(s[i]);
                else m[s[i]]--;
                i++;
            }else{
                maxLen = max(j-i+1, maxLen);
                j++;
                m[s[j]]++;
            }
        }
        return maxLen;
    }
};