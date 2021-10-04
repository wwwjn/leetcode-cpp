#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        ListNode* nextN = dummyHead;
        int count = 0;
        while(count < n){
            nextN = nextN -> next;
            count++;
        }
        while(nextN->next != NULL){
            nextN  = nextN->next;
            pre = pre->next;
            cur = cur->next;
        }
        //delete
        pre->next = cur->next;

        return dummyHead->next;
    }
};