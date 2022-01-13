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

// //trial 1, 0ms(100%) / 7mb(87.60%)
// class Solution {
//     public:
//     const long min = -2147483648, max =2147483647 ;
//     int myAtoi(string s) {
//         auto toNum = [&](char s1) { 
//             //<0 when non digit was read
//             switch (s1) {
//                 case '1': return 1; break;
//                 case '2': return 2; break;
//                 case '3': return 3; break;
//                 case '4': return 4; break;
//                 case '5': return 5; break;
//                 case '6': return 6; break;
//                 case '7': return 7; break;
//                 case '8': return 8; break;
//                 case '9': return 9; break;
//                 case '0': 
//                 case ' ': return 0; break;
//                 default: return -1;
//             }
//             //default
//             return -1;
//         };

//         if ((s.length()==1 && s[0]=='-') || s.length()==0) {return 0;}
//         long long ans = 0;
//         bool isNeg = false, num_Begin = false;
 
//         auto it = s.begin();
//         //cout << "checking string \"" << s << "\"" << endl;
//         while (it != s.end()) {   
//             //cout << "Current it = " << *it << endl;      
//             if ((toNum(*it)>=0 || *it=='-' || *it=='+') && !num_Begin) {   
//                 //enter condition space 
//                 //cout << "line 50" << endl;
//                 if (*it != ' ') {
//                     num_Begin = true;
//                     //cout << "number begin at \"" << *it << "\"" << endl;
//                 }
//                 isNeg = *it=='-'?true:false;    //check before if *it is neg
               
//             }
//             else if (!num_Begin && toNum(*it)<0) {
//                 //cout << "line 56" << endl;
//                 break;
//             } 
//             else if (num_Begin && ( *it == ' ' || toNum(*it)<0)) {   //exit condition
//                 //cout << "line 60" << endl;
//                 break;
//             } 

//             if(*it != '-' && *it!='+' && num_Begin) {
//                 //cout << "line 65" << endl;
//             if (ans > max || (ans > max+1 && isNeg)) {
//                 if (isNeg) {ans *= -1;}
//                 return ans>max?max:min;
//             }
//                 ans = ans*10 + toNum(*it);
//                 //cout << "my ans = " << ans << endl;
//             }
            
//             it++;
//         }     
//         if (isNeg) {ans *= -1;}
//         if (ans > max || ans < min) {
//             return ans>max?max:min;
//         }
//         return ans;                   
//     }
// };

//trial 2, 0ms(100%) / 7mb(51.13%)
class Solution {
    public:
    int myAtoi(string s) {
        int min = -214748364, max = 214748364;
        auto toNum = [&](char s1) { 
            //<0 when non digit was read
            switch (s1) {
                case '1': return 1; break;
                case '2': return 2; break;
                case '3': return 3; break;
                case '4': return 4; break;
                case '5': return 5; break;
                case '6': return 6; break;
                case '7': return 7; break;
                case '8': return 8; break;
                case '9': return 9; break;
                case '0': return 0; break;
            }
            //default
            return -1;
        };

        auto isSign = [&](char s2) {
            //return pos if '+', return neg if '-'
            switch (s2) {
                case '+': return 1; break;
                case '-': return -1; break;
            }
            return 0; //for default
        };
        if (s.length()==0) {return 0;}

        bool isNeg = false, numBegin = false;
        auto it = s.begin();
        int ans =0;
        while (it != s.end()) {
//cout << "value now is = '" << *it << "'" << endl;
            if ((isSign(*it)!=0 || toNum(*it) >= 0) && !numBegin){  //enter
//cout << "enter num mode"<< endl;
                isNeg = isSign(*it)==-1?true:false;
                numBegin = true;
            }
            else if (numBegin && toNum(*it)<0) {    //exit
//cout << "exit num mode" << endl;            
                break;
            }
            else if (!numBegin && toNum(*it)<0 && *it!=' ') { 
                break;
            }
            
                     
            if (!isNeg && toNum(*it)>=0 && numBegin) {
                if (ans>max || (ans==max && toNum(*it)>7))  {return 2147483647;}
//cout << "acc +ans = " << ans << endl;
                ans = ans*10 + toNum(*it);
            }
            else if (isNeg && toNum(*it)>=0 && numBegin) { 
                if (ans<min || (ans==min && toNum(*it)>8))  {return -2147483648;}
//cout << "acc -ans = " << ans << endl;
                ans = ans*10 - toNum(*it);
            }
            
            it++;
        }
        return ans;                  
    }
};

int main () {
    Solution s1;
    string testcase[6]={
        "--42", 
        "- 42", 
        "   -42-  ", 
        "4193 with words",  
        "words and 987", 
        "2147483648"
    };

    // for (int i=0; i<6; i++) {
    //     cout << s1.myAtoi(testcase[i]) << endl;
    // }
    cout << s1.myAtoi("1") << endl;
    return 0;
}