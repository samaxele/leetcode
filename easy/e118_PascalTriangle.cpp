#include "CustomHeader/myCustomHeader.h"

//trial 1, 5ms(5.56%) / 6.5mb(32.33%)
// class Solution {
// public:
//     std::vector<std::vector<int>> generate(int numRows) {
//         std::vector<std::vector<int>> ans(numRows);
//         ans[0] = {1};
//         unsigned short i=1,j=0;
//         for (i=1; i<numRows; i++) {
//             ans[i].push_back(1);
//             for (j=1; j<(ans[i-1].size()); j++) {
//                 ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
//             }
//             ans[i].push_back(1);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> r;
        std::vector<int> c;
        r[0]= {1};
        for (int i=1; i<numRows; i++) {
            auto it = r[i-1].begin();
            c.push_back(1);
            while (it != r[i-1].end()-1) {
                it++;
                c.push_back(*it+(*it-1));
            }
            c.push_back(1);
            r[i] = c;
        }
        return r;
    }
};


int main () {
    Solution s1;
    unsigned short testcase; //1 <= n <= 30
    std::cout << "Enter rows (1~30), 99 to exit = " ;
    std::cin >> testcase;
    if (testcase == 99) {
        std::cout << "exit program\n";
        return 0;
    }
    std::vector<std::vector<int>> ans = s1.generate(testcase);
    for (int a=0; a<testcase; a++) {
        std:: cout << "Row " << a+1 << "\t";
        printList(ans[a]);
    }
    
    return 0;
}