#include <iostream>
#include <string>
#include <vector>   

using namespace std;

class Solution {  //trial 1, 60ms(16.89%) / 6.9mb(96.27%)
    public:
    int lengthOfLongestSubstring(string s) {
        if (1 == s.size()) {return 1;}

        string temp = "";
        unsigned short k=0;
        auto it = s.begin();

        while (it != s.end()) {   //do while within string array
        //cout << "\ncheck '" << *it << "'... ";
            if ((int)temp.find(*it) >= 0) {  //duplicate found / remember to convert to int
            //cout << *it << " duplicate found, ";
                if (temp.size() > k) {
                    k = temp.size();
                    it -= k-(int)temp.find(*it);
                    //cout << "new k = " << k << endl;
                }
                else {
                    it -= temp.size();
                    //cout << "k = " << k << " unchange" << endl;
                }
                temp = "";
            }
            else { 
                temp += *it;
            }
            it++;
        }
        //cout << "\nString ends, k=";
        return k>temp.size()?k:temp.size();
    }
};

// class Solution {  //ans trial 2, time = 72 ms, better than 14.88% subs
//     public:
//     int lengthOfLongestSubstring(string s) {
//         auto it = s.begin();
//         int index=0, k=0;
//         string temp = "";
//         while (it != s.end()) {
//             cout << "\ncheck '" << *it << "'... ";
//             temp += *it;
//             index = temp.find(*it);
//             if (index >= 0 && index != temp.size()-1) { 
//                 //if duplicate found && not last element
//                 cout << *it << " duplicate found, ";
//                 //due to duplicated char is added, need to extra -1
//                 if (temp.size()-1 > k) {k = temp.size()-1;}
//                 it -= temp.size()-index-1;   
//                 temp = "";
//                 cout << "k = " << k << endl;
//                 }
//             it++;
//         }
//         if (k < temp.size()) {k = temp.size();}
//         return k;

//         //return k>temp.size()?k:temp.size();    
//     }
// };

// class Solution {  //trial 3, 60ms(16.89%) / 7mb(90.09%)
//     public:
//     int lengthOfLongestSubstring(string s) {
//         int k=0;
//         string temp = "";
//         string ans = "";
//         for (int i=0; i<s.size(); i++) {
//             //cout << "received " << s[i] <<endl;
//             if ((int)temp.find(s[i])<0) {   //found unique
//                 temp += s[i];
//                 //cout << s[i] << " is unique" <<endl;
//             }
//             else {  // found same
//                 //cout << s[i] << " is duplicated!" <<endl;
//                 if (temp.size() > ans.size()) {ans = temp;} //swap ans if temp > ans
//                 //cout << "temp(size) =  " << temp.size() << endl;
//                 //cout << "dup index =  " << temp.find(s[i]) << endl;
//                 //cout << "i old =  " << i << endl;
//                 i -= (temp.size() - (int)temp.find(s[i]));
//                 //cout << "i new =  " << i << endl;
//                 temp = "";
//             }
//         }
//         if (temp.size() > ans.size()) {
//             ans = temp;
//         }
//         return ans.size();
//     }
// };

int main () {
    Solution s1;
    string testcase="aaaab";
    cout  << "longest substring = " << s1.lengthOfLongestSubstring(testcase) << endl;

    int index = testcase.find('c');
    //cout << "index of 'c' = " << index << ' ' << endl;
    return 0;
}