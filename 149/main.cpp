#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res_max = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<double, int> record;
            for(int j = 0; j < points.size(); j++){
                if(i != j){
                    double k = calK(points[i], points[j]);
                    if(record.find(k)!= record.end()) record[k]++;
                    else record.insert(make_pair(k, 2));
                }
            }
            for(auto item: record){
                if(res_max < item.second) res_max = item.second;
            }
        }
        return res_max;
    }
    double calK(vector<int> point1, vector<int> point2){
        if(point1[0] != point2[0])
            return ((double)(point1[1] - point2[1]))/(point1[0] - point2[0]);
        else
            return 10000.0;  // 注意斜率的范围
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
