#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 辅助函数
ListNode* createLinkedList(int arr[], int n){
    if(n == 0){
        return NULL;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for(int i = 1; i < n; i++){
        cur -> next = new ListNode(arr[i]);
        cur = cur -> next;
    }
    return head;
}

void printLinkedList(ListNode* head){
    ListNode* curNode = head;
    while(curNode != NULL){
        cout << curNode -> val << " -> ";
        curNode = curNode -> next;
    }
    cout << "NULL" << endl;
}


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        if(head == NULL || head->next == NULL)
            return head;
        while(current != NULL){
            ListNode* next = current -> next;
            while(next != NULL && next->val == current->val){
                next = next->next;
            }
            current->next = next;
            current = next;
        }
        return head;
    }
};

int main() {
    int arr[] = {1,1,2,3,3};
    ListNode* head = createLinkedList(arr, sizeof(arr)/sizeof(int));
    ListNode* new_head = Solution().deleteDuplicates(head);
    printLinkedList(new_head);
    return 0;
}
