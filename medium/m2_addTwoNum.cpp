#include <iostream>
#include <string>
#include <vector>   

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
Special case
l1 longer than l2 
l2 longer than l1
extra remainder after l1;
*/

class Solution { //my ans trial 2, runtime = 59ms, top 23.32%
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tail = new ListNode(0);
        ListNode *ans = tail;
        int sum=0;
        while (l1 || l2 || sum) {
            sum += (l1?l1->val:0) + (l2?l2->val:0);
            tail->next = new ListNode(sum%10);  //create new node with remainder
            tail = tail->next;
            sum /= 10;  //if sum < 10, this will = 0;
            if (l1) {l1=l1->next;}
            if (l2) {l2=l2->next;}
        }
        return ans->next;
    }
};

int main () {
    Solution s1;
    ListNode l1=2;
    ListNode l2 = 2;

    return 0;
}