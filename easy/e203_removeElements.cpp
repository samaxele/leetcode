#include "CustomHeader/myCustomHeader.h"
//trial 1, 20ms(80.50%) / 14.9mb(78.65%)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (val==0) {return head;}
        ListNode *ans = new ListNode;
        ans->next = head;
        ListNode *target = ans;
        while (head) {
            if (head->val == val) {
                //skip next node
                target->next = head->next;
            }
            else {
                target = target->next;
            }        
            head = head->next;    
        }
        return ans->next;
    }
};

int main () {
    Solution s1;
    auto tcase={1,2,3,4,2};
    unsigned int val=0;
    ListNode *testcase = genListNode(tcase);
    printList(testcase);

    ListNode *ans;
    cout << "enter val to remove: ";
    cin >> val;
    ans = s1.removeElements(testcase,val);
    cout << "removed " << val << ", new List: " << endl;
    printList(ans);
    return 0;
}