#include "CustomHeader/myCustomHeader.h"

//trial 1, 4ms(47.38%) / 6mb(26.18%)
// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         const int soft_max = 0x40000000; //0b01000...32 bits
//         if(dividend == divisor) {
//             return 1;
//         }
//         else if (divisor == INT_MIN || divisor == INT_MAX) {
//             if (dividend == INT_MIN) {return -1;}
//             else {return 0;}
//         }
//         else if (dividend == INT_MIN && divisor == -1) {return INT_MAX;}

//         bool isNeg = false;
//         if (dividend<0 != divisor<0) { //XOR for dividend and divisor
//             isNeg = true;
//         }
//         unsigned int new_dividend = abs(dividend);
//         int new_divisor = abs(divisor);
//         int a = new_divisor;
//         int n = 1; //count divisor^pow
//         unsigned int ans = 0;

//         while (new_dividend >= new_divisor) {
//             if (new_divisor >= soft_max) {
//                 new_dividend -= new_divisor;
//                 ans += 1;
//             }
//             else {
//                 a <<= 1;
//                 n <<= 1;
//                 if (a > new_dividend || a >= soft_max) {
//                     a >>= 1;
//                     n >>= 1;
//                     new_dividend -= a;
//                     ans += n;
//                     a = new_divisor;
//                     n = 1;
//                 }
//             }
//         }
//         return isNeg?-ans:ans;
//     }
// };

//trial 2, 0ms(100%) / 5.8mb(73.76%)
class Solution {
public:
    int divide(int &m, int &n) {
        //const int soft_max = 0x40000000;    //limit for abs number
        bool isNeg = false;
        if (m == INT_MIN && n == -1) {return INT_MAX;}
        if (!(m<0) != !(n<0)) {   //check ans neg sign
            isNeg = true;
        }   
        unsigned int dividend = abs(m);
        unsigned int divisor = abs(n);
        unsigned int a = divisor;   //assign variable as cursor
        int count = 1;
        int ans=0;  //count of divisor^n
        while (dividend > divisor) {
            if (divisor >= 0x40000000) {
                dividend -= divisor;
                ans += 1;
            }
            else {
                a <<= 1;
                count <<= 1;  
                if (a > dividend || a >= 0x40000000) {
                    a >>= 1;
                    count >>= 1;
                    dividend -= a;
                    ans += count;
                    a = divisor;
                    count = 1;
                }                     
            } 
        }
        return isNeg?-ans:ans; 
    }
};

int main () {
    int dividend, divisor;
    Solution s1;
    cout << "dividend: ";
    cin >> dividend;
    cout << "divisor: ";
    cin >> divisor;
    cout << "Output = " << s1.divide(dividend, divisor) << endl;
    return 0;
}