#include <iostream>

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

#include <vector>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:

    int getImportance(vector<Employee*> employees, int id) {
        int imp = 0;
        for(int i = 0; i < employees.size(); i++){
            if(employees[i]->id == id){
                imp += employees[i]->importance;
                vector<int> subs = employees[i]->subordinates;
                for (int j = 0; j < subs.size(); j++){
                    imp += getImportance(employees, subs[j]);
                }
                break;
            }
        }
        return imp;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
