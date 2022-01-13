#include "CustomHeader\myCustomHeader.h"


//trial 1, 4ms(78.85%) / 10.8mb(31.45%)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //3 elements and above
        ListNode *target=head, *lead=head;
        for (int i=0; i<n; i++) {lead = lead->next;}
        if (!lead) {return head->next;}
        while (lead->next) {
            lead = lead->next;
            target = target->next;
        }
        target->next = target->next->next;
        return head;    
    }
};

int main () {
    Solution s1;
    vector<int> raw = {1}; 
    ListNode *testcase, *temp;
    
    testcase = genListNode(raw);
    printList(testcase);
    temp = s1.removeNthFromEnd(testcase,1);   //temp is nullptr
    cout << "ans = ";
    printList(temp);

    return 0;
}