#include <iostream>
#include <vector>
using namespace std;
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
    for(int i = 0; i < n; i++){
        head -> next = new ListNode(arr[i]);
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur != NULL){
            ListNode* next = cur -> next;
            cur -> next = prev; // reverse
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
