#include "CustomHeader/myCustomHeader.h"

//trial 1, 0ms(100%) / 7.5mb(15.96%)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        ListNode *ans = new ListNode;
        ans->next = head;
        head = ans;

        /*
        This lambda only swap N-nodes starting from l1
        for eg, left=2 and right=4, then swappable nodes are 3
        */
        auto reverse = [] (ListNode* l1, int n_nodes) {
            ListNode *prev = l1;
            ListNode *tail = l1;    //anchor tail at beginning
            l1 = l1->next;  //move l1 forward
            ListNode *ans;
            for (int i=0; i<n_nodes; i++) {
                //point current node to previous node by setting ans = L1
                ans = l1;
                /*
                before changing ans->next, make sure free up l1 by moving l1 forward
                need to check if l1->next is not null to move
                if L1 is null, create new list to hold l1, according to the input restriction
                this node shall be final
                */
                l1 = l1->next;
                ans->next = prev;
                //move prev front to ans without touching tail.
                prev = ans;
            }
            tail->next = l1;
            return ans;
        };

        for (int i=1; i<left; i++) {
            /**
             * we are moving towards n-th node from 'left'
             * this for loop shall exit at 1 node before the affected
             * sublist
             * 
             * If Left = 1, we shall not move
            */
            head = head->next;
        }
        head->next = reverse(head->next,right-left);

        // std::cout<< "my reversed link list = " ;
        // printList(head);

        return ans->next;
    }
};

int main () {
    Solution s1;
    std::vector<int> testcase = {1,2,3,5,7};
    int left = 3, right = 3;
    ListNode *sample = genListNode(testcase);
    std::cout << "hello world\n" ;
    printList(sample);
    ListNode *segmented = s1.reverseBetween(sample,left,right);
    printList(segmented);

    
    return 0;
}