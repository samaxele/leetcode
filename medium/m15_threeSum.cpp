#include "CustomHeader/myCustomHeader.h"
/*
Given an array of numbers, look for:
1. 3 element so that sum is 0, and
2. 3 element cannot be repeated
Note: Same value is ignored, eg, {-1,-1,2,0,3,6} = ans{-1,-1,2}
Explanation: 
*/
//trial #, ms(%) / mb(%)
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans = {};
        //sort the vector
        std::sort(nums.begin(),nums.end());
        int vec_end = nums.size();
        if (vec_end < 3) {
            return {};
        }
        int anchor = 1;
        int n_left = anchor-1;
        int n_right = anchor+1;

        while (anchor <= vec_end-2) {
            while (n_left >= 0  && n_right < vec_end) {
                if (-1*nums[anchor]==nums[n_left]+nums[n_right]) {
                    ans.push_back({nums[n_left],nums[anchor],nums[n_right]});
                    break;
                }
                else if (-1*nums[anchor]>nums[n_left]+nums[n_right] && n_right<vec_end) {
                    n_right++;
                }
                else if (-1*nums[anchor]<nums[n_left]+nums[n_right] && n_left>0) {
                    n_left--;
                }
                // if both iterations has no solution
                else {break;}
            }
            anchor++;
            n_left = anchor-1;
            n_right = anchor+1;
        }
        // for every possible combination / true answer, we push_back to partial_ans
        return ans;
    }
};

int main () {
    auto timeNow = std::chrono::system_clock::now();
    time_t timeTick = std::chrono::system_clock::to_time_t(timeNow); 
    std::string timeMsg = ctime(&timeTick);
    std::cout << "Exec time = " << timeMsg;

    std::vector<std::vector<int>> ans;
    Solution s1;
    std::vector<int> testcase={0,0,0,0};
    ans = s1.threeSum(testcase);
    std::cout << "hello world\n";
    for (auto x : ans) {
        std::cout << "{";
        for (auto y : x) {
            std::cout << y << ", ";
        }
        std::cout << "\b\b} \n";
    }
    
    return 0;
}