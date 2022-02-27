#include "CustomHeader/myCustomHeader.h"

/*
Delete middle node of a linked list
The middle is defined as below
size = n, middle = n/2, for example middle of 5 is 2(index)
indexing is 0-based, meaning 3rd element will be removed in 5 nodes

2 pointer / hare and turtoise method
odd case 7-element:
f       f       f       f
0   1   2   3   4   5   6   _
s   s   s  [d]
            s

even case 6-element:
f       f       f       f
0   1   2   3   4   5   _
s   s   s  [d]
            
*/

//trial #1, 948ms(70.67%) / 294.8mb(69.96%)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) {return nullptr;}

        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            //while loop to exit at n and n-1 element
            fast = fast->next->next;
            if (fast) {
                //move slow ptr only if fast != nullptr
                slow = slow->next;
            }
        }
        ListNode *target = slow->next;
        if (!fast) {
            //if list node is even, you slow->next is the target
            slow->next = slow->next->next;
        }
        else {
            //if listnode is odd, delete target = slow
            slow->val = slow->next->val;
            slow->next = slow->next->next;
        }
        return head;
    }
};

int main () {
    ListNode *testcase = genListNode({2,1});
    Solution s1;

    printList(testcase);
    std::cout << "removing middle...\n";
    printList(s1.deleteMiddle(testcase));

    return 0;
}