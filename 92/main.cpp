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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 0;
        ListNode* new_head = new ListNode(-1, head);
        ListNode* cur = new_head;
        ListNode* prev = NULL;
        ListNode* left_side;
        ListNode* left_node;
        ListNode* right_side;
        ListNode* right_node;
        if(left == right){
            return head;
        }
        while(cur != NULL){
            ListNode* next = cur-> next;
            if(count == (left-1)){
                left_side = cur;
                left_node = next;
            }
            else if(count > left && count <= right){
                if(count == right){
                    right_node = cur;
                    right_side = next;
                }
                cur->next = prev;
            }
            prev = cur; // move the pointers
            cur = next;
            count += 1;
        }
        left_side->next = right_node;
        left_node->next = right_side;
        return new_head -> next;
    }
};


int main() {
    int arr[] = {3,5};
    ListNode* head = createLinkedList(arr, sizeof(arr) / sizeof(int));
    ListNode* new_head = Solution().reverseBetween(head,1,2);
    printLinkedList(new_head);
    return 0;
}
