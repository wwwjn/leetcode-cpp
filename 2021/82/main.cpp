#include <iostream>

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* prev = dummyHead;
        ListNode* current = head;
        while(current != NULL){
            ListNode* next = current -> next;
            while(next != NULL && next-> val== current-> val){
                next = next -> next;
            }
            // delete
            if(next != current -> next){
                prev -> next = next;
                current = next;
            }
            else{
                prev = current;
                current = next;
            }
        }
        return dummyHead->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
