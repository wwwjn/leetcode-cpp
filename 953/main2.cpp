//
// Created by Jiani Wang on 2021/10/10.
//

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int, int> o;
        for(int i = 0 ; i < order.size(); i++){
            o.insert({order[i], i});
        }
        for(int i = 0; i<words.size()-1; i++){
            if(compareTwo(words[i], words[i+1], o))
                continue;
            else
                return false;
        }
        return true;

    }
    bool compareTwo(string s1, string s2, unordered_map<int, int>& o){
        // return if s1 comes first
        int i = 0; // index
        while(i < s1.size() && i < s2.size()){
            if(s1[i] == s2[i]) i++;
            else{
                if(o[s1[i]] > o[s2[i]]) return false;
                else return true;
            }
        }
        if(s1.size() > s2.size()) return false;
        else return true;
    }
};