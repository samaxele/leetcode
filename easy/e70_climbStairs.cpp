#include <iostream>
#include <string>
#include <vector>   

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//trial 1, 0ms(100%) / 5.9mb(52.41%)
class Solution {
public:
    int climbStairs(int n) {
        if (n<4) {  return n;  }      
        else {
            unsigned int num_ways[2] = {1,2};
            for (short i=2; i<n; i++) {
                //cout << num_ways[0] << "+" << num_ways[1] << "=";
                num_ways[1] = num_ways[1] + num_ways[0]; 
                //cout << num_ways[1] << endl;
                num_ways[0]=num_ways[1]-num_ways[0];
            }
            return num_ways[1];
        }
    }
};

int main () {
    Solution s1;
    int testcase=10;

    cout << s1.climbStairs(testcase) << endl;

    return 0;
}