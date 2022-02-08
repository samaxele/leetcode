#include "CustomHeader/myCustomHeader.h"

//trial 1, 3ms(53.21%) / 5.9mb(47.15%)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while (n>=1) {
            if (n%2) { 
                ans++;
            }
            n >>= 1;
        }
        return ans;
    }
};

int main () {
    Solution s1;
    uint32_t testcase = 0b11111111111111111111111111111101;
    std::cout << "my testcase = " << testcase << std::endl
    << "there are " << s1.hammingWeight(testcase)
    << " one's found." << std::endl;
    return 0;
}