//
// Created by mumansk on 25-7-23.
//
# include <iostream>
# include <vector>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 在两条链表上交替遍历。
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr; // 如果存在空链表，返回空
        }
        ListNode * pA = headA, *pB = headB;
        while (pA != pB) {
            if (pA == nullptr) {
                pA = headB;
            } else {
                pA = pA->next;
            }

            if (pB == nullptr) {
                pB = headA;
            } else {
                pB = pB->next;
            }

        }

        return pA;
    }
};


int main() {
    return 0;
}