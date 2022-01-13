#include "CustomHeader\myCustomHeader.h"
//trial 1, 72ms(20.16%) / 21.1mb(5.11%)
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         //ListNode *lead=headA;
//         map<ListNode*,bool> m;
//         while (headA) {
//             m[headA] = true;
//             headA = headA->next;
//         }
//         while (headB) {
//             if (m[headB]) {return headB;}
//             headB = headB->next;
//         }
//         return nullptr;
//     }
// };

// //trial 2, 44ms(66.24%) / 14.6mb(30.89%)
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *ptr1 = headA, *ptr2=headB;
//         while (ptr1 != ptr2) {
//             if (!ptr1) {ptr1 = headB;}
//             else {ptr1 = ptr1->next;}
//             if (!ptr2) {ptr2 = headA;}
//             else {ptr2 = ptr2->next;}
//         }
//         return ptr1;
//     }
// };

//trial 3, 44ms(66.24%) / 14.4mb(88.60%)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB = headB;
        unsigned short len_A=0, len_B=0;
        while (ptrA) {
            len_A++;
            ptrA = ptrA->next;
        }
        while (ptrB) {
            len_B++;
            ptrB = ptrB->next;
        }
        if (len_A > len_B) {
            while (len_A > len_B) {
                headA = headA->next;
                len_A--;
            }
        }
        else if (len_A < len_B) {
            while (len_A < len_B) {
                headB = headB->next;
                len_B--;
            }
        }
        while (headA && headB) {
            if (headA == headB) {return headA;}
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};

int main () {
    Solution s1;
    auto testcase=0;

    return 0;
}