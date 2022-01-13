#include "CustomHeader/myCustomHeader.h"

/*
Given a linked list, determine if the list has a loopback cycle
if yes, return true, else return false
We may need to use map
*/

//trial 1, 29ms(5.58%) / 11.3mb(7.14%)
// class Solution {
// public:
//     bool status = false;
//     std::map<ListNode*,short> myMap;
//     short pos = 1;

//     bool hasCycle(ListNode *head) {
//         while (head != nullptr) {
//             /*head->next is found in our record*/
//             if (myMap[head->next] > 0) {
//                 return true;
//             }
//             /*head->next is not found in our record*/
//             else { 
//                 myMap[head] += pos;
//             }
//             pos++;
//             head = head->next;
//         }
//         return false;
//     }

//     Solution (std::vector<int> x) {
//         ListNode *head = genListNode(x);
//         status = hasCycle(testcase);
//     }
// };

//trial 2, 16ms(28.4%) / 8.1mb(57.4%)
class Solution {
public:
    bool status = false;
    
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }

    Solution (std::vector<int> x) {
        ListNode *testcase = genListNode(x);
        status = hasCycle(testcase);
    }
};

int main () {
    Solution s1({1,2,3,4,5,8,8,8});
    std::cout << "hello world\n" ;
    std::cout << "the list node cycle is " << s1.status << std::endl;

    return 0;
}