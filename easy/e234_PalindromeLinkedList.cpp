#include "CustomHeader/myCustomHeader.h"

/*
Method 1 [not considered]
As the linked list cycle through, we reverse all passed nodes
until we got a duplicate (which happens at the middle point of LL)
Then we can check both list (first half reversed and 2nd half)
if equals, then its Palindrome

Method 2 [suggested in leetcode discussion]
Using floyd's turtoise and hare method to have 2 iterating pointers, fast and slow
The fast will iterate 2 steps while slow iterate 1
By fast reachs the end, slow will stop at middle
                  r    s              f
(odd)   1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> end
for odd case: slow head = slow->next
                  r    s              f
(even)  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> end
for even case, slow = head of 2nd half

situation to consider
1*) what is duplicate was found before reaching middle node (eg. 133242331)
*not relevant for methof 2
2) how to handle even / odd number of nodes? (135531 and 13531 are Palindromic)
3) single node situation

To solve [1] and [2]:

*/


//trial 1, 384ms(28.77%) / 110.2mb(97.88%)
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         if (head->next == nullptr) {
//             return true;
//         }
//         /*
//         fast = leading pointer to the end of list
//         slow = head of 2nd half list
//         revHead = head of reversed 1st half list
//         */
//         ListNode* prev = nullptr;
//         ListNode* slow=head, *fast=head, *revHead;
//         while (fast && fast->next) { 
//             fast = fast->next->next;
//             /*
//             reverse algorithm begin
//             */
//             revHead = slow;
//             slow = slow->next;
//             revHead->next = prev;
//             prev = revHead;
//             /*
//             reverse algorithm ends
//             */
//         }
//         if (fast == nullptr) {
//             //link list is even
//             return compare2LL(slow,revHead);
//         }
//         else {
//             return compare2LL(revHead,slow->next);
//         }
//         return false;
//     }
    
//     bool compare2LL(ListNode* l1, ListNode* l2) {
//         while (l1 && l2) {
//             if (l1->val != l2->val) {
//                 //if one pair of val is inequal, break
//                 break;
//             }
//             l1 = l1->next;
//             l2 = l2->next;
//         }
//         if (l1 == nullptr && l2 == nullptr) {
//             return true;
//         }
//         else {
//             return false;
//         }
        
//     }
// };

//trial 2
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (nullptr == head->next) { return true;}
        ListNode *fast, *slow, *revHead;
        fast = head;
        slow = head;
        ListNode *prev = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            //reversion begin
            revHead = slow;
            slow = slow->next;
            revHead->next = prev;
            prev = revHead;
            //reversopm end
        }
        if (nullptr == fast) {
            while ()
        }
    }
};

int main () {
    Solution s1;
    ListNode *testcase = genListNode({1});
    ListNode *testcase2 = genListNode({});
    printList (testcase);
    if (s1.isPalindrome(testcase)) {
        std::cout << "Is Palindrome\n";
    }
    else 
        std::cout << "Is not Palindrome\n";
    return 0;
}