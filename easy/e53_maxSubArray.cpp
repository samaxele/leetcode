#include "CustomHeader/myCustomHeader.h"

//trial 1, 104 ms(70.03%) / 67.8mb(12.28%)
//Kadane's Algorithm
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         auto it = nums.begin();
//         int curr, maxima;
//         curr = *it;
//         maxima = *it;
//         it++;
//         while (it != nums.end()) {
//             curr = max(*it,curr+*it);
//             maxima = max(curr,maxima);
//             it++;
//         }
//         return maxima;
//     }
// };

//trial 2, 104 ms(70.03%) / 67.8mb(12.28%)
//try brute force
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        auto mySum = [&](std::vector<int>::iterator it) {
            int ans = *it;
            int curr = *it;
            auto l = it;
            auto r = it;
            while (nullptr!=l && nullptr!=r) {
                l--;
                r++;
                curr += (*l+*r);
                ans = std::max(ans,curr);
            }
            return ans;
        };
        auto it = nums.begin();
        int curr, maxima;
        curr = *it;
        maxima = *it;
        it++;
        while (it != nums.end()) {
            curr = std::max(*it,curr+*it);
            maxima = std::max(curr,maxima);
            it++;
        }
        return maxima;
    }
};


int main () {
    Solution s1;
    std::vector<int> testcase = {-2,1,-3,4,-1,2,1,-5,4};  
    std::vector<int> testcase2 = {5,4,-1,7,8}; //23
    std::cout << "largest = " << s1.maxSubArray(testcase) << std::endl;
    return 0;
}