#include "CustomHeader/myCustomHeader.h"

/*
The twin node is defined as:
i node is the twin of n-i-1 node, input is always even:
example, given list node of n=6, at 0-index, the pair will be:
0 <> 5  (6-0-1) i=0
1 <> 4  (6-1-1) i=1
2 <> 3  (6-2-1) i=2

Your mission is to find the largest sum between the pairs

Method 1: fast slow method
Create the pair as palindrome -> slow will be the one to reverse the list
step 1: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
step 2: 1 <- 2 <- 3 <- 4    5 -> 6 -> 7 -> 8
we can clearly see the pair will be 
4 -> 3 -> 2 -> 1 -> null  
5 -> 6 -> 7 -> 8 -> null  

Then we can just use brute force to run the entire halved link list
*/

//trial #1, 317ms (68.54%) / 116.6mb (96.29%)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *fast = head, *slow = head;
        ListNode *pairHead, *prev = nullptr;

        while (fast) {
            //since the list n = even, we can guarantee f will stops at null
            //we can only move pairHead forward at the beginning to keep pairHead
            //as the head of the reversed pair
            pairHead = slow;
            fast = fast->next->next;
            slow = slow->next;
            pairHead->next = prev;
            prev = pairHead;
        }

        // now we have 2 list pair, slow and pairHead
        int max_global = 0;
        while (pairHead && slow) {
            max_global = std::max(max_global,(pairHead->val+slow->val));
            pairHead = pairHead->next;
            slow = slow->next;
        }
        return max_global;
    }
};

int main () {
    ListNode *testcase = genListNode({1,2,3,4,5,6});
    Solution s1;
    
    printList(testcase);
    std::cout << "largest pair = " << s1.pairSum(testcase);

    return 0;
}