#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;

        vector<vector<int>> r;

        while(i < firstList.size() && j < secondList.size()){
            vector<int> vec1 = firstList[i];
            vector<int> vec2 = secondList[j];
            int m = max(vec1[0], vec2[0]);
            int n = min(vec1[1], vec2[1]);
            if(m <= n){
                r.push_back({m,n});
            }
            if(vec1[1] > vec2[1]){
                j++;
            }else{
                i++;
            }

        }
        return r;
    }

};