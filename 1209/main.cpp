#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution2 {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        st.push({'*', 0});
        for(int i = 0; i < s.size(); i++){
            char c = st.top().first;
            if(s[i] != c){
                st.push(make_pair(s[i],  1));
            }else{
                int count = st.top().second;
                st.pop();
                if(count + 1 == k){
                    continue;
                }else
                    st.push({s[i], count +1});
            }
        }
        string res = "";
        while(!st.empty()){
            pair<char, int> p = st.top();
            st.pop();
            int count = p.second;
            char c = p.first;
            while(count > 0){
                res = c + res;
                count --;
            }
        }
        return res;
    }
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st{{'*', 0}};
        for (char c : s)
            if (c != st.back().first)
                st.emplace_back(c, 1);
            else if (++st.back().second == k)
                st.pop_back();
        string ans;
        for (const auto& p : st)
            ans.append(p.second, p.first);
        return ans;
    }
};