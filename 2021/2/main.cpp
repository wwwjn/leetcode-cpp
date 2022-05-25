#include <iostream>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* dummyRes= new ListNode(0, NULL);
        ListNode* res = dummyRes;
        int add = 0; // add = 0 or add = 1
        int val1 = 0, val2 = 0;
        while(ptr1 != NULL || ptr2 != NULL || add == 1){
            if(ptr1 != NULL) val1 = ptr1 -> val;
            else val1 = 0;
            if(ptr2 != NULL) val2 = ptr2 -> val;
            else val2 = 0;
            if(val1 + val2 + add >= 10){
                int val = (val1 + val2 + add) - 10;
                res -> next = new ListNode(val, NULL);
                res = res -> next;
                add = 1;
            }
            else{
                int val = (val1 + val2 + add);
                res -> next = new ListNode(val, NULL);
                res = res -> next;
                add = 0;
            }
            if(ptr1 != NULL) ptr1 = ptr1 -> next;
            if(ptr2 != NULL) ptr2 = ptr2 -> next;
        }
        return dummyRes -> next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
