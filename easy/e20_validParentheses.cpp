#include <iostream>
#include <string>
#include <vector>   

using namespace std;

class Solution {
    public:
    bool isPair(char &str1, char &str2) {
        switch (str2) {
            case ')':{if (str1 == '(') {return true;}break;}
            case ']':{if (str1 == '[') {return true;}break;}
            case '}':{if (str1 == '{') {return true;}break;}
        }
        return false;
    }

    bool isValid(string s) {
        if (0==s.length() || s.length()%2) {return false;}
        unsigned short link = s.length()/2;
        for (short i=1; i<s.length(); i++) {
            if (isPair(s[i-1],s[i])) {
                link--;
                s.erase(i-1,2);
                i<2?i=0:i-=2;
                }
        }
        return !link;
        return 0;
    }
};

/*
Valid parentheses - check if the incoming brackets are valid
1. open and close must be same type
2. open and close must be in correct order
 */ 

int main () {
    Solution s1;

    return 0;
}