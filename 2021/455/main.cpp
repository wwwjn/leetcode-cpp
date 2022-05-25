#include <iostream>

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end(), greater<int>());
        sort(g.begin(), g.end(), greater<int>());
        int si = 0;
        int gi = 0;
        int res = 0;
        while(gi < g.size() && si < s.size()){
            if(g[gi] <= s[si]){
                gi++;
                si++;
                res++;
            }
            else{
                gi++; // 这个小朋友不能被满足
            }
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
