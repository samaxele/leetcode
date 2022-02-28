#include "CustomHeader/myCustomHeader.h"

/*
Given non zero linked list, return the middle node
if there are 2, return second middle (high side)

2 pointer method, on odd and even situation:

odd:
h
1   2   3   4   5   n
F       f       f
S   s  [s]

even:
h
1   2   3   4   5   6   n
F       f       f       f
S   s   s  [s] 
*/

//trial #1, 0ms(100%) / 7.1mb(73.21%)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast=head, *slow=head;
        while (fast && fast->next) { 
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
};

int main () {
    Solution s1;
    auto testcase=0;
    std::cout << "hello world\n" ;
    return 0;
}