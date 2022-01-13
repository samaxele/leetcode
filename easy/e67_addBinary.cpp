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

//trial #1, 4ms(60.94%) / 6.3mb(84.97%)
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() || b.empty() || a=="0" || b=="0") { 
            if (a=="0" || a.empty()) {return b;}
            else return a;
        }
        string ans;
        bool carry = false;
        auto ita = a.end();
        auto itb = b.end();
        while (ita != a.begin() && itb != b.begin()) {
            ita--; itb--;
            if (*ita == *itb) {
                carry ? ans.insert(0,"1"):ans.insert(0,"0");
                carry = *ita=='1'?true:false;
            }
            else if (*ita != *itb) {
                carry ? ans.insert(0,"0"):ans.insert(0,"1");
            }
        }
        
        if (ita == a.begin() && itb != b.begin()) {
            while (itb != b.begin()) {
                itb--;
                if (carry == true) { 
                    *itb=='1'?ans.insert(0,"0"):ans.insert(0,"1");
                    carry = *itb=='1'?true:false;
                }
                else if (!carry) {
                    ans.insert(0,1,*itb);
                }
            }
        }
        else if (itb == b.begin() && ita != a.begin()) {
            while (ita != a.begin()) {
                ita--;
                if (carry == true) { 
                    *ita=='1'?ans.insert(0,"0"):ans.insert(0,"1");
                    carry = *ita=='1'?true:false;
                }
                else if (!carry) {
                     ans.insert(0,1,*ita);
                }
            }
        }
        if (carry) {
            ans.insert(0,"1");
            carry = false;
        }
        return ans;
    }
};

int main () {
    Solution s1;
    string a="100";
    string b="110010";
    string ans = s1.addBinary(a,b);
    cout << ans;
    return 0;
}