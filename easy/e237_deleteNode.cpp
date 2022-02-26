#include "CustomHeader/myCustomHeader.h"

//trial #1, 16ms(55.75%) / 7.7mb(40.05%)
class Solution {
public:
    void deleteNode(ListNode* node) {
        //since its guarantee the node != last node, we can assign target at next node
        ListNode *target = node->next;
        node->val = target->val;
        node->next = target->next;
        //target = new ListNode(node->next->val);
        //node = target;
    }
};

ListNode* gotoNode(ListNode *head, uint8_t x) {
    ListNode *target = head;
    for (int i=1; i<x; i++) {
        target = target->next;
    }   
    return target;
}

int main () {
    Solution s1;
    ListNode *testcase = genListNode({1,2,4,3,5,2,5});
    ListNode *target = gotoNode(testcase,3);
    printList(testcase);
    std::cout << "3rd node value = ";
    printList(target);
    std::cout << "hello world\n";

    s1.deleteNode(target);

    printList(testcase);


    return 0;
}