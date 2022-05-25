#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(-1, NULL);
        vector<ListNode*> ptrs = vector<ListNode*>(lists.size(), NULL);
        // (val, 第i个队列)
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> record;
        for(int i = 0; i < lists.size(); i++){
            ptrs[i] = lists[i];  // 初始化
            if(lists[i] != NULL)
                record.push(make_pair(lists[i]->val, i));
        }
        while(!record.empty()){
            int list_id = record.top().second;
            record.pop();
            ListNode* least = ptrs[list_id];
            dummyHead->next = least;
            // move pointer
            ptrs[list_id] = least->next;
            if(least->next != NULL)
                record.push(make_pair(least->next->val, list_id));
            else continue;
        }
        return dummyHead->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
