#include <iostream>

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* prev = dummyHead;
        ListNode* current = head;
        while(current != NULL){
            ListNode* next = current-> next;
            if(current -> val == val){
                prev -> next = next;
                current = next;
            }
            else{
                prev = current;
                current = next;
            }

        }
        return dummyHead-> next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
