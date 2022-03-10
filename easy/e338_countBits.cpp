#include "CustomHeader/myCustomHeader.h"

/*
Given integer input n, create an array with size n+1
for each array element (0 -> n-1) return the number of '1' 
eg, n = 6;
array size = 6+1 = 7 (can be indexed to 7)
0 = 000 -> 0
1 = 010 -> 1
...
6 = 110 -> 2
7 = 111 -> 3

if i = 12, then ans[i] = 1100 = 2
*/

//trial #1, 3ms(95.53%) / 8.5mb(34.56%)
class Solution {
public:
    std::vector<int> countBits(int n) {
        
        auto getOnes = [&] (int n) {
            //this anonymous function returns 1's given integer 
            uint8_t ans = 0;
            while (n>0) {
                if (n%2) {
                    ans++;
                }
                n >>= 1;
            }
            return ans;
        };

        std::vector<int> ans = {};
        uint8_t ones;
        for (int i=0;i<n+1;i++) {
            ans.push_back(getOnes(i));
        }
        return ans;
    }
};

int main () {
    Solution s1;
    int testcase;  //0 <= n <= 100,000
    std::cout << "Enter number (0-100000): ";
    std::cin >> testcase;
    std::vector<int> ans = s1.countBits(testcase);
    printList(ans);
    
    return 0;
}