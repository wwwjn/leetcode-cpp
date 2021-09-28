#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
private:
    vector<int> time;
    map<int, int> record;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        time.push_back(1);
        time.push_back(7);
        time.push_back(30);
        return costTickets(days, 0, costs);
    }

    int costTickets(vector<int>& days, int start, vector<int>& costs){
        if(record.find(start) != record.end()){
            return record[start];
        }
        if(start >= days.size()){
            return 0;
        }
        int minCost = INT_MAX;
        for(int i = 0; i < 3; i++){
            int startDay = days[start];
            int endDay = days[start] + time[i] - 1;
            int j = start;
            while(j < days.size() && days[j] <= endDay){
                j++;
            }
            int other = costTickets(days, j, costs);
            int cost = other + costs[i];
            if(cost < minCost) minCost = cost;

        }
        record.insert({start, minCost});
        return minCost;

    }
};