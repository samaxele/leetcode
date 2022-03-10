#include "CustomHeader/myCustomHeader.h"

//trial #1, 13ms(48.14%) / 7.5mb(76.1%)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool intersection = false;
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast && fast->next) {
            if (head->next->next == head) {
                //special case for 2 nodes only
                return head;
            }
            fast = intersection ? fast->next : fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                if (intersection) {return fast;}
                // resets the fast pointer
                fast = head;
                intersection = true;
            }
        }
        return nullptr;
    }
};

ListNode *cycleNode(std::vector<int> x, int y) {
    //y = index of link list at 1-index
    if (y >= x.size() && -1 != y) {
        return {};
    }
    ListNode *head, *tail, *target=nullptr;
    tail = new ListNode(0);
    head = tail;
    for (int i=0; i<x.size(); i++) {
        tail->next = new ListNode (x[i]);
        tail = tail->next;
        if (i == y-1) {target = tail;}
    }
    tail->next = target;
    return head->next;
}

int main () {
    /*
    Create a list node that cycles at node = 3
    */
    ListNode *testcase = cycleNode({3,4,5,8,9},3);
    
    /*
    Create a class with constructor, pass in our testcase
    */
    Solution s1;

    std::cout << "The intersection node = " << s1.detectCycle(testcase)->val << "\n";

    //printList(testcase);


    return 0;
}