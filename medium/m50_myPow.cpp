#include "CustomHeader/myCustomHeader.h"

/*
Constrains:
-100.0 < x < 100.0
-2^31 < n < 2^31-1
-1e4 <= x^n <= 1e4
*/
//trial 1, 2ms(??.??%) / ?.?mb(??.??%)
class Solution {
public:
    double ans = 0;
    double myPow(double x, int n) {
        /*
        We break int n into base of 2
        if n = 13, then pow(x,8)*pow(x,4)*pow(x,1) = x^13
        create a var 'ans' with 1, to be able to change its base
        */
        double ans = 1;
        while (n) {
            /*
            if n is divisible by 2, meaning that we can move one degree higher of n
            */
            if (n%2) {
                // push back ans
                ans = (n<0)? ans/x: ans*x;
            }
            /*
            for every successful x^2, n/2
            */
            x *= x;
            n >>= 1;
        }
        return ans;
    }

    Solution(double& A, int& B) {
        //constructor pass all the input args to function
        ans = myPow(A,B);
    };
};

int main () {
    double testcase_A = 1.000000004288898901;  //-100.0 < x < 100.0
    int testcase_B = INT_MAX; //-2^31 < n < 2^31-1
    // double testcase_A = 3;//1594323
    // int testcase_B = 13;
    Solution s1(testcase_A, testcase_B);

    std::cout << "pow(" << testcase_A << "," << testcase_B << ") = "
    << s1.ans << std::endl;

    return 0;
}