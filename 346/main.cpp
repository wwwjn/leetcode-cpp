#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class MovingAverage {
private:
    vector<int> record;
    int head = 0;
    int sum = 0;
    int count = 0;
    int size;
public:
    MovingAverage(int size) {
        record = vector<int>(size, 0);
        this->size = size;
    }

    double next(int val) {
        count++;
        int tail = (head+1)%size;
        sum = sum - record[tail] + val;
        double avg = (double)(sum)/min(size, count);
        record[tail] = val;
        head = tail;
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */