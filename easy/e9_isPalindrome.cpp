//#9 Palindrome number

#include <iostream>

using namespace std;

class Solution {
public:

    bool isPalindrome(long int x) {
        int  lastdigit=0, digits=0;
        long int buffer=0,reversed=0;
        buffer = x;
        while (buffer>=1) {
            digits++;
            //cout << "\ndigits found = " << digits << endl;
            buffer /= 10;            
        }
        buffer = x; //buffer resets
        for (int i=0; i<digits; i++) {
            lastdigit = buffer%10;
            reversed = reversed*10+lastdigit;   //push back new last digit
            buffer /= 10;   //eliminate last digit
        }
        //we shall have reversed for now, test the difference by subtractions
        //!0 means not Palindrome
        return {!(reversed-x)};
    }
};

int main() {
    int testcase = 1234567899;
    Solution s1; 

    cout << "Testcase [" << testcase << "] is" ;
    s1.isPalindrome(testcase)?cout<<" Palindrome\n":cout<<" not Palindrome\n";
    return 0;
}