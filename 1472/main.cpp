#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class BrowserHistory {
private:
    stack<string> history;
    stack<string> f;
public:
    BrowserHistory(string homepage) {
        history.push(homepage);
    }

    void visit(string url) {
        while(!f.empty()){
            f.pop();
        }
        history.push(url);
    }

    string back(int steps) {
        int minStep = min(steps, (int)history.size()-1);
        int count = 0;
        string url;
        while(count < minStep){
            url = history.top();
            history.pop();
            f.push(url);
            count ++;
        }
        return history.top();
    }

    string forward(int steps) {
        int minStep = min(steps, (int)f.size());
        int count = 0;
        string url;
        while(count < minStep){
            url = f.top();
            f.pop();
            history.push(url);
            count++;
        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */