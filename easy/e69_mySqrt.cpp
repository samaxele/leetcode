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

//trial 1, 4ms(54.36%) / 5.9mb(25.43%)
// class Solution {
// public:
//     int mySqrt(int x) {
//         if (x<=3) {
//             return x==0?0:1;
//         }
//         if (x >= 2147395600) {return 46340;}
//         int n_up = 2;
//         int k = n_up*n_up;
//         // 2*31 -1 = 2147483647 (max), sqrt of max = 46340.95 (can use short)
//         while (k < x && n_up < 46340) {
//             cout << "n up = " << n_up << endl;
//             if (n_up < 32768) { n_up += n_up; }
//             else if (n_up < 45001) { n_up += 100; }
//             else {n_up += 1;}
//             k = n_up*n_up;
//         }
//         cout << "N-up stops at " << n_up << endl;
//         if (k == x) {return n_up;}
//         unsigned short n_low = n_up;
//         while (k > x) {
//             n_low -= 1;
//             k = n_low * n_low;
//         }
//         return n_low;        
//     }
// };

//trial 2, 4ms(54.36%) / 5.9mb(74.58%)
class Solution {
    //we know that the ans lies between 0 ~ 46340, start from mid
public:
    int mySqrt(int x) {
        long long start=0, end=x,mid;
        while (start <= end) {
            mid = (start+end)/2;
            if (mid*mid == x) {return mid;}
            if (mid*mid < x) {
                //+1 for input x=0
                start = mid+1;
            }
            else {
                //when reach correct ans, end will extra -1, exiting while
                end = mid-1;
            }
        }
        return start-1;
        
    }
};

int main () {
    Solution s1;
    int tcase  = 2147483647;
    int tcase2 = 2147483647;
    cout << "sqrt of " << tcase2 << " = "
    << s1.mySqrt(tcase2) << endl;
    return 0;
}