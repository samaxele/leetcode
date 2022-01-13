#include <iostream>
#include <string>
#include <vector>   

using namespace std;

// class Solution {  //trial 1, 4ms(42.41%) / 6.3mb(7.1%)
// public:
//     int reverse(int x) {
//         const int i_max = 214748364;
//         const int i_min = -214748364;
//         bool neg_tag=false;
//         int ans=0;
//         vector<int> temp;
//         if (x <= -2147483648 || x > 2147483647) {return 0;}
//         if (x < 0 && x > -214743648) {
//             neg_tag = true;
//             x *=-1;
//         }
//         while (x != 0) {
//             temp.push_back(x%10);
//             x /= 10;
//         }
//         // for (int z:temp) {
//         //     cout << z << endl;
//         // }
//         auto it = temp.begin();
//         while (it != temp.end()) {
//             if (ans > i_max || ans < i_min) {return 1;}
//             ans = ans*10 + *it;
//             it++;
//         }
//         ans *= neg_tag ? -1 : 1;
//         return ans;
//     }
// };

class Solution {  //trial #, ??.??ms(??.??%) / ??.??mb(??.??%)
public:
    int reverse(int x) {
        int ans = 0;
        bool is_neg = false;
        if (x <= -2147483648 || x > 2147483647) {return 0;}
        if (x < 0) {is_neg = true;}

        return ans;
    }
};

int main () {
    Solution s1;
    int testcase = 1463847412;
    cout << s1.reverse(testcase) << endl;
    return 0;
}
