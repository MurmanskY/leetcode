//
// Created by mumansk on 25-7-23.
//
# include <iostream>


using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};




void printList(ListNode *head) {
    ListNode *p = head;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    return;
}




class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {return nullptr;}

        ListNode * tail = head->next;
        while(tail != nullptr) {
            ListNode * temp = tail->next;
            head->next = temp;
            ListNode * new_head = new ListNode(tail->val, head);
            head = new_head;
            tail = temp; // tail往后移一个
        }
        return head;
    }
};


int main() {
    ListNode *head = new ListNode(1);
    printList(head);
    return 0;
}