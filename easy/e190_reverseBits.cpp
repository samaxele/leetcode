#include "CustomHeader/myCustomHeader.h"

//trial #, 0ms(100%) / 5.7mb(96.64%)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans;
        uint8_t i;
        for (i=0; i<32; i++) {
            if (n%2) {
                ans += 1;
            }
            /*
            at the LSB, we actually dont need ans to <<1 anymore
            So we set a condition that ans <<= 1 only when n is not == 32nd bit
            */
           if (i<31) { 
               ans <<= 1;
           }
            n >>= 1;
        }
        return ans;
    }
};

int main () {
    Solution s1;
    uint32_t testcase=102;
    uint32_t ans = s1.reverseBits(testcase);
    std::cout << "hello world\n" << ans ;
    return 0;
}