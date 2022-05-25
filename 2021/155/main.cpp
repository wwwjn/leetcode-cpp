#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        s.push(val);
        if(!min_s.empty()){
            if(val <= min_s.top()){
                min_s.push(val);
            }
        }else{
            min_s.push(val);
        }

    }

    void pop() {
        int tmp = s.top();
        if(tmp == min_s.top()){
            min_s.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_s.top();
    }
private:
    stack<int> s;
    stack<int> min_s;
    int min_num = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */