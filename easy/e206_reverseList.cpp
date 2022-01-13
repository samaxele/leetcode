#include "CustomHeader/myCustomHeader.h"


// class Solution {  //trial 1, 8 ms(63.79%) / 8.4 mb(41.62%)
//     public:
//     ListNode *reverseList (ListNode *l1) {
//         ListNode head;
//         ListNode *dummy,*tail=nullptr;
//         //head = new ListNode();
//         while (l1) {  //do while not null node
//             dummy = new ListNode(l1->val,tail);
//             tail = dummy;
//             head.next = dummy;
//             l1 = l1->next;
//         }
//         //head = new ListNode(l1->val,dummy);
//         return head.next;
//     }
// };

class Solution {  //trial 2,  4ms(95.84%) / 8.3mb(41.18%)
    public:
    ListNode *reverseList (ListNode *l1) {
        ListNode *ans=nullptr, *prev = nullptr;
        while (l1 != nullptr) {
            ans = l1;
            l1 = l1->next;
            ans->next = prev;
            prev = ans;
        }
        return ans;
    }
};

//test code
// class Solution {  //trial 2,  4ms(95.84%) / 8.3mb(41.18%)
//     public:
//     ListNode *reverseList (ListNode *l1) {
//         ListNode *ans, *temp = nullptr;
//         while (l1 != nullptr) {
//             ans = l1;
//             l1 = l1->next;
//             ans->next = temp;
//             temp = ans;
//         }
//         return ans;
//     }
// };


int main() {
    ListNode *l1;
    ListNode *l1_reversed;
    Solution s1;

    int size = 12;
    std::vector<int> testcase = {1,4,5,12,32,48,73,5,6,9,10,22};

    l1 = genListNode(testcase);
    printList(l1);

    l1_reversed = s1.reverseList(l1);
    printList(l1_reversed);

    //l1_reversed = reversedLink_experiment(l1);
    //printLink(l1_reversed);

    std::cout << "code complete" << std::endl;


    return 0;
    
}