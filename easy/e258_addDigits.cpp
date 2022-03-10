#include "CustomHeader/myCustomHeader.h"

//trial #1, 0ms(100%) / 6mb(26.46%)
// class Solution {
// public:
//     int addDigits(int num) {
//         int curr = 0;
//         if (num < 10) {return num;}
//         for ( ; num>0; num/=10) {
//             curr += num%10;
//         }
//         return addDigits(curr);
//     }
// };

class Solution {
public:
    int addDigits(int num) {
        uint8_t temp = 0;
        while (num > 0) {
            temp += num%10;
            num /= 10;
            if (temp >= 10 && 0 == num) {
                num = temp;
                temp = 0;
            }
        }
        return temp;
    }
};

int main () {
    Solution s1;
    int testcase = INT_MAX;
    /*
    3+4+3+4+3+4+2 = 23
    2+3 = 5
    */
    std::cout << "Ans = " << s1.addDigits(testcase) << "\n";
    return 0;
}