#include <iostream>
#include <string>
#include <vector>   

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//trial 1, 4ms(55.53%) / 6.4mb(89.32%)
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         auto it = s.end()-1;
//         unsigned short start,end;
//         while (*it==' ' && it >= s.begin()) {
//             //search for trailing spaces
//             cout << "char checked = '" << *it << "'" << endl;  
//             it--;
//         }
//         cout << "char is found and exited while\n";
//         end = s.end()-it;
//         cout << "end = " << end << endl;
//         while (*it!=' ' && it >= s.begin()) {
//             cout << "char checked = '" << *it << "'" << endl;  
//             it--;
//         }
//         cout << "char is found and exited while\n";
//         start = s.end()-it;
//         cout << "start = " << start << endl;

//         return start-end;
//     }
// };

//trial 2, 4ms(55.53%) / 6.4mb(89.32%)
// class Solution {
// public:
//     int lengthOfLastWord (string s) {
//         bool charFound = false;
//         auto it = s.end();
//         unsigned short start=0,end=0;
//         while (it >= s.begin()) {
//             it--;
//             if (*it != ' ' && !charFound) { 
//                 charFound = !charFound;
//                 end = s.end()-(it+1);
//             }
//             else if(*it == ' ' && charFound) {
//                 start = s.end()-(it+1);
//                 return start-end;
//             }    
//         }
// //if we manage to exit while loop, that means last word connected to begin()
//         start = s.end()-(it+1);
//         return start-end;
//     }
// };

//trial 3, 0ms(100%) / 6.3mb(99.31%)
class Solution {
    public:
    int lengthOfLastWord(string str) {
        auto it = str.end();
        unsigned short ans=0;
        while (it > str.begin()) {
            it--;
            if (*it!=' ') {
                ans++;
                if (*(it-1)==' ') {
                    break;
                }
            }
        }
        return ans;
    }
};

int main () {
    Solution s1;
    auto testcase="a ";
    cout << "length of last word: " << testcase << endl
    << s1.lengthOfLastWord(testcase);

    return 0;
}