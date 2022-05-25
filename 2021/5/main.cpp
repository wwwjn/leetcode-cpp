#include <iostream>
// expend from center
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 1;
        int left = 0;
        int right = 0; // [left... right] is palindromic
        for(int i = 0; i < n; i++){
            vector<int> res = expendCenter(s, i);
            if(res[1] - res[0] + 1 > len){
                len = res[1] - res[0] + 1;
                left = res[0];
                right = res[1];
            }
        }
        return s.substr(left, right-left+1);
    }
    vector<int> expendCenter(string& s, int center){
        vector<int> res;
        // condition 1: from substring with lenghth 1
        int res1 = 0;
        int left = center;
        int right = center;  // [left...right] is palindromic
        while((left-1) >=0 && (right+1) < s.size() && s[left-1] == s[right+1]){
            left--;
            right++;
        }
        res1 = right - left + 1;
        //condition2: from substring with length 2
        int res2 = 0;
        int left2 = center;
        int right2 = center+1;
        // start from [center, center+1]
        if(center+1 < s.size() && s[center+1] == s[center]){
            while((left2-1) >=0 && (right2+1) < s.size() && s[left2-1] == s[right2+1]){
                left2--;
                right2 ++;
            }
            res2 = right2 - left2 + 1;
        }
        if(res1 > res2){
            res.push_back(left);
            res.push_back(right);
        }else{
            res.push_back(left2);
            res.push_back(right2);
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
