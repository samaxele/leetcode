#include "CustomHeader/myCustomHeader.h"

//trial #, ms(%) / mb(%)
// class Solution {
// public:

//     bool isPalindrome(long int x) {
//         int  lastdigit=0, digits=0;
//         long int buffer=0,reversed=0;
//         buffer = x;
//         while (buffer>=1) {
//             digits++;
//             //cout << "\ndigits found = " << digits << endl;
//             buffer /= 10;            
//         }
//         buffer = x; //buffer resets
//         for (int i=0; i<digits; i++) {
//             lastdigit = buffer%10;
//             reversed = reversed*10+lastdigit;   //push back new last digit
//             buffer /= 10;   //eliminate last digit
//         }
//         //we shall have reversed for now, test the difference by subtractions
//         //!0 means not Palindrome
//         return {!(reversed-x)};
//     }
// };

//trial #2, 19ms(54.87%) / 5.9mb(32.71%)
class Solution {
public:
    bool isPalindrome(long int x) {
        int64_t inv_x=0, buffer = x;
        while (buffer > 0) {
            inv_x = (inv_x*10)+(buffer%10);
            buffer /= 10;
        }
        if (inv_x == x) {return true;}
        else {return false;}
    }
};

int main() {
    int testcase;
    Solution s1; 

    std::cout << "Testcase = ";
    std::cin >> testcase;

    s1.isPalindrome(testcase)?std::cout<<"Palindrome\n":std::cout<<"not Palindrome\n";

    return 0;
}