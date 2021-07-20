#include <iostream>
#include <vector>
#include <stack>
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
    ListNode* addTwoNumbers_wrong(ListNode* l1, ListNode* l2) {
        int count1 = 0;
        int count2 = 0;
        ListNode *ptr1 = l1, *ptr2 = l2;
        while(ptr1 != NULL){
            count1++;
            ptr1 = ptr1 -> next;
        }
        while(ptr2 != NULL){
            count2 ++;
            ptr2 = ptr2 -> next;
        }
        int val1 =0 ,val2=0;
        ListNode* long_ptr;
        ListNode* short_ptr;
        long_ptr = l1;
        short_ptr = l2;
        vector<int> add((max(count2, count1) + 1), 0);
        if(count2 > count1){
            long_ptr = l2;
            short_ptr = l1;
        }
        int count_long = max(count1, count2);
        int count_short = min(count1, count2);
        ListNode *dummyRes = new ListNode(0, NULL);
        ListNode *res_ptr= dummyRes;
        while(long_ptr != NULL){
            if(count_long > count_short){
                val1 = long_ptr -> val;
                val2 = 0;
            }else{
                val1 = long_ptr -> val;
                val1 = short_ptr -> val;
            }
            if(val1 + val2 >= 10){
                res_ptr -> next = new ListNode((val1+val2-10), NULL);
                res_ptr = res_ptr -> next;
                add[count_short] = 1;
            }
            else{
                res_ptr -> next = new ListNode((val1+val2-10), NULL);
                res_ptr = res_ptr -> next;
            }
            count_long --;
            long_ptr = long_ptr -> next;
            if(count_long == count_short){
                count_short --;
                short_ptr = short_ptr -> next;
            }
        }
        ListNode *add_head = new ListNode(0, NULL);
        ListNode *add_ptr = add_head;
        int add_count = add.size();
        while(add_count >= 0){
            if(add[add_count] == 0 && add_ptr == add_head) add_count--;
            else{
                add_ptr -> next = new ListNode(add[add_count] , NULL);
                add_ptr = add_ptr->next;
                add_count --;
            }
        }
        return addTwoNumbers_wrong(dummyRes->next, add_head->next);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1 != NULL){
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while(l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int add = 0;
        ListNode* res = NULL;
        while(!s1.empty() || !s2.empty() || add != 0){
            int val1=0, val2=0;
            if(!s1.empty()){
                val1 = s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                val2 = s2.top();
                s2.pop();
            }
            // add node at the front of the res
            if(val2 + val1 + add >= 10){
                ListNode* new_head = new ListNode((val1 + val2 + add - 10), NULL);
                new_head -> next = res;
                res = new_head;
                add = 1;
            }
            else{
                ListNode* new_head = new ListNode((val1 + val2 + add), NULL);
                new_head -> next = res;
                res = new_head;
                add = 0;
            }
        }
        return res;
    }
};



int main() {
    int arr[] = {7,2,4,3};
    int arr2[] = {5,6,4};
    ListNode* l1= createLinkedList(arr, 4);
    ListNode* l2 = createLinkedList(arr2, 3);
    ListNode* res = Solution().addTwoNumbers(l1, l2);
    printLinkedList(res);
    return 0;
}
