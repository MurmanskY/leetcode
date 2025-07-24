//
// Created by mumansk on 25-7-24.
//
# include <iostream>


using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void ListNode_push_back(int x) {
        ListNode *cur = this;
        while (cur->next != nullptr) {
            // 下一个位置非空
            cur = cur->next;
        }
        ListNode *node = new ListNode(x);
        cur->next = node;
        return;
    }
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

        ListNode *tail = head; // 指向排序完了的链表的最后一个

        while (tail->next != nullptr) {


            ListNode * tail_next = tail->next; // 指向tail的下一个位置

            tail->next = tail->next->next;

            tail_next->next = head;


            head = tail_next;

        }

        return head;
    }
};



// class Solution2 {
// public:
//     // solution2，原地翻转
//     ListNode* reverseList(ListNode* head) {
//         ListNode * prev = nullptr;
//         ListNode * cur = head;
//         while (cur != nullptr) {
//
//         }
//     }
// };



int main() {
    ListNode *head = new ListNode(1);
    head->ListNode_push_back(2);
    head->ListNode_push_back(3);
    head->ListNode_push_back(4);
    head->ListNode_push_back(5);
    printList(head);

    cout << endl;
    cout << "------" << endl;

    Solution s;
    ListNode * ans = s.reverseList(head);
    printList(ans);


    return 0;
}