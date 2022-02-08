#include "CustomHeader/myCustomHeader.h"

/*
Given an array, find the shortest sum of element to target
example:
target = 7, sample = [2,3,1,2,4,3]
Ans: 2 -> 4+3 is the shortest possible subset to reach target value
Note: 1+2+4 = 7 also but it has 3 elements
Target can be greater than or equal to.
*/

//trial 1, 384ms(5.56%) / 10.6mb(15.06%)
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int ans=0, curr=0;
        int sum;
        auto it = nums.begin();
        auto it_sum = it;
        while (it != nums.end()) {
            sum = target;
            it_sum = it;
            while (sum > 0 && it_sum != nums.end()) {
                sum -= *it_sum;
                curr++;
                it_sum++;
                if (sum <= 0) {
                    ans = ans==0?curr:std::min(ans,curr);
                    curr = 0;
                }
            }
            it++;
        }
        return ans;
    }
};

int main () {
    Solution s1;
    std::vector<int> testcase = {1,2,3,4,5};
    int target = 11;
    std::cout << "hello world\n" ;
    std::cout << s1.minSubArrayLen(target, testcase);
    return 0;
}