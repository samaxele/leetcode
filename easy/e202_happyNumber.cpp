#include "CustomHeader/myCustomHeader.h"

/*
Test if a number is happy, a happy number consist of following:
start with positive integer. square sum each digits, eg:
Input 9, 9x9 = 81
8x8 + 1x1 = 64
6x6 + 4x4 = 52
5x5 + 2x2... and so on....

Method 1: Calculate the equation as usual, run 2 pointers: fast and slow
fast = 2 steps and slow = 1 step
when (value) fast == slow, we know a close loop occurs
> we can just return false, need not to find the intersection point
*/

//trial 1, 4ms(43.11%) / 6.3mb(25.27%)
// class Solution {
// public:
//     bool isHappy(int n) {
//         std::map<int,int> mp = {};
//         auto nextValue = [&](int x) {
//             //enter 81, return 8x8 + 1x1 = 64
//             int ans = 0;
//             while (x >= 1) {
//                 ans += (x%10)*(x%10);
//                 x /= 10;
//             }
//             return ans;
//         };
        
//         int ans = nextValue(n);
//         while (ans > 1) {
//             if (mp[ans] > 1) {return false;}
//             mp[ans]++; 
//             ans = nextValue(ans);
//         }
//         return true;
//     }
// };

//trial 2, 0ms(100%) / 5.9mb(64.0%)
class Solution {
public:
    bool isHappy(int n) {
        std::map<int,int> mp = {};

        /*
        This lambda will return the next node value
        */
        auto nextValue = [&](int x) {
            //enter 81, return 8x8 + 1x1 = 64
            int ans = 0;
            while (x >= 1) {
                ans += (x%10)*(x%10);
                x /= 10;
            }
            return ans;
        };
        
        int fast = n;
        int slow = n;
        while (slow > 1) {
            fast = nextValue(nextValue(fast));
            slow = nextValue(slow);
            if (fast == slow && fast != 1) {
                return false;
            }
        }
        return true;
    }
};

int main () {
    Solution s1;
    int x;
    std::cout << "enter number: ";
    std::cin >> x;
    if (s1.isHappy(x)) {
        std::cout << "is true\n";
    }
    else
    std::cout << "is false\n";
    
    return 0;
}