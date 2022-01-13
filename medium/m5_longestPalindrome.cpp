#include <iostream>
#include <string>
#include <vector>   

using namespace std;

class Solution {  //trial 1, 16ms(89.79%) / 7.1mb(82.14%)
public:
    string longestPalindrome(string s) {  
        int n = s.length();

        //use of auto to assign anonymous function
        //getLen exist as a 'variable' in my class function 'longestPalindrome'
        //with function rather than data storage.
        auto getLen = [&](int l, int r) {
            while ( l >= 0 && r < n && s[l] == s[r]) {
                l--; 
                r++;
            }
            // a half number of length will return
            return r-l-1;
        };

        int length_max = 0;
        int pos=0;
        for (int i=0; i<n; i++) {
            int cur_length = max(getLen(i,i) , getLen(i,i+1));
            if (cur_length > length_max) {
                length_max = cur_length;
                pos = i - (length_max-1)/2;
            }
        }
        return s.substr(pos,length_max);
    }
};

int main () {
    Solution s1;
    string testcase[5] = {
        "xabax",
        "fbabadc",
        "rfcbbdeh",
        "a",
        "ac"
    };

    cout << s1.longestPalindrome(testcase[2]) << endl;


    return 0;
}