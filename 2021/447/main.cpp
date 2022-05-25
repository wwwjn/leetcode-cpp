#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(int i=0; i< points.size(); i++){
            unordered_map<int, int> tmp_rec;  // distence: nums
            for(int j = 0; j < points.size(); j++){
                if(i != j){
                    int dis = CalDistance(points[i], points[j]);
                    if(tmp_rec.find(dis) != tmp_rec.end()) tmp_rec[dis] ++;
                    else tmp_rec.insert(make_pair(dis, 1));
                }
            }
            // find same distance
            for(auto item: tmp_rec){
                if(item.second >= 2){
                    res += item.second * (item.second - 1);
                }
            }
        }
        return res;
    }
    int CalDistance(vector<int>& point1, vector<int>& point2){
        return (point1[0] - point2[0]) * (point1[0] - point2[0]) +
               (point1[1] - point2[1]) * (point1[1] - point2[1]);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
