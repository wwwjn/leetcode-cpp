#include <iostream>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* dummyHead = new ListNode(0, NULL);
        ListNode* res = dummyHead;
        while(ptr1 != NULL || ptr2 != NULL){
            int val1 = 101, val2 = 101;
            if(ptr1 != NULL) val1 = ptr1->val;
            if(ptr2 != NULL) val2 = ptr2->val;
            if(val1 <= val2){
                res -> next = new ListNode(val1, NULL);
                res = res->next;
                ptr1 = ptr1 -> next;
            }
            else{
                res -> next = new ListNode(val2, NULL);
                res = res -> next;
                ptr2 = ptr2 -> next;
            }
        }
        return dummyHead -> next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
