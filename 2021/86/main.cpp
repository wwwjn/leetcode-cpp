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

void deleteLinkedList(ListNode* head){
    ListNode* current = head;
    while(current != NULL){
        ListNode* delNode = current;
        current = current -> next;
        delete delNode;
    }
    return;
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small_head = new ListNode(0, head);
        ListNode* big_head = new ListNode(0, head);
        ListNode* small = small_head;
        ListNode* big = big_head;
        ListNode* current = head;
        while(current != nullptr){
            ListNode* next = current-> next;
            if(current->val >= x){
                big->next = current;
                big = big -> next;
            }
            else{
                small -> next = current;
                small = small -> next;
            }
            current = next;
        }
        big -> next = nullptr;
        small -> next = big_head->next;
        return small_head->next;  // dummynode return next
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
