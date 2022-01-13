#include <iostream>
#include <map>

using namespace std;

class Solution {
    public:
    map<char,int> romanMap = { 
        {'I',1},{'V',5},
        {'X',10},{'L',50},
        {'C',100},{'D',500},
        {'M',1000}
    };
    int romanToInt(string s) {
        int n = s.size();
        int ans=romanMap[s[n-1]]; //start from unit
            for (int i=n-2; i>=0; i--) {
            // count from behind
            if (romanMap[s[i]] >= romanMap[s[i+1]]) {
                ans += romanMap[s[i]];
            }
            else {
                ans -= romanMap[s[i]];
            }
        }
        return ans;
    }
};

int main() {
    string testcase1 = "XXXVIII"; 
    Solution s1;

    cout << s1.romanToInt(testcase1);
    return 0;
}