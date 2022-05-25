#include <iostream>


class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        ListNode *oddHead = new ListNode(0, head);
        ListNode *evenHead = new ListNode(0, head);
        ListNode *odd = oddHead;
        ListNode *even = evenHead;
        ListNode *current = head;
        int count = 1;
        while (current != NULL) {
            ListNode *next = current->next;
            if (count % 2 != 0) {
                odd->next = current;
                odd = odd->next;
            } else {
                even->next = current;
                even = even->next;
            }
            current = next;
            count += 1;
        }
        even->next = NULL;
        odd->next = evenHead->next;
        return oddHead->next;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
