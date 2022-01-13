#include <iostream>
#include <string>
#include <vector>   
#include "CustomHeader/myCustomHeader.h"
using namespace std;

//trial 1, 8ms(88.69%) / 11.9mb(7.64%)
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if (!head) {return nullptr;}
//         ListNode *cursor, *ans;
//         cursor = new ListNode(123);
//         ans = cursor;
//         while (head->next) {
//             if (head->val != head->next->val) {
//                 cursor->next = new ListNode(head->val);
//                 cursor = cursor->next;
//             }
//             head = head->next;
//         }
//         cursor->next = new ListNode(head->val);
//         return ans->next;
//     }
// };

// //trial 2, 11ms (53.44%) / 11.7mb (34.58%)
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if (!head) {return nullptr;}
//         ListNode *lead = head;
//         ListNode *trail = head;
//         while (lead) {
//             if (lead->next == nullptr) {break;}
//             else if (lead->val != lead->next->val) {
//                 trail->next = lead->next;
//                 trail = trail->next;
//             }
//             lead = lead->next;
//         }
//         trail->next = nullptr;
//         return head;
//     }
// };

//trial 3, 7ms (88.8%) / 11.7mb (34.58%)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        while(curr && curr->next) {
            if (curr->val == curr->next->val) { curr->next = curr->next->next; }
            else { curr = curr->next; }
        }
        return head;
    }
};


int main () {
    Solution s1;
    vector<int> testcase = {-100, -100, -99,98,100,100}; 
    ListNode *tcase = genListNode(testcase);
    cout << "Test Case = ";
    printList(tcase);
    ListNode *ans = s1.deleteDuplicates(tcase);
    cout << "Deleted duplicates = ";
    printList(ans);
    

    return 0;
}