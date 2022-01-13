#include <iostream>
#include <string>
#include <vector>   

using namespace std;

class Solution { //my ans trial 1, runtime = 15ms, top 66.55%
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {return 0;}
        else if (haystack.empty() && !needle.empty()) {return -1;}

        return haystack.find(needle);

    }
};

int main () {
    Solution s1;
    string testcase = "hello world";
    string needle = "uu";

    cout << s1.strStr(testcase,needle) << endl;

    return 0;
}