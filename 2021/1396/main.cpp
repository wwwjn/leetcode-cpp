#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkinData;
    // Id -> pair<startStationName, time>>
    unordered_map<string, pair<double, double>> JourneyData;
    // "startStationName,endStationName" -> <totalTime, count>
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        checkinData.insert({id, make_pair(stationName, t)});
    }

    void checkOut(int id, string stationName, int t) {
        pair<string, int> r = checkinData[id];
        checkinData.erase(id);
        string start = r.first;
        string key = start + "," + stationName;
        int duration = t - r.second;
        if(JourneyData.count(key)){
            double total = JourneyData[key].first + duration;
            double count = JourneyData[key].second+1;
            JourneyData[key] = make_pair(total, count);
        }else{
            JourneyData.insert({key, make_pair(duration, 1)});
        }
    }

    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "," + endStation;
        return JourneyData[key].first / JourneyData[key].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */