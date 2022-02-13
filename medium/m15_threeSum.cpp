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
        if (nums.size() < 3) {return {};}
        std::vector<std::vector<int>> ans = {};
        std::sort(nums.begin(),nums.end());
        
        auto it = nums.begin();

        while (it < nums.end()-2) {
            if (*it > 0) {break;}
            while (it > nums.begin() && *it == *(it+1)) {it++;}
            auto it_low = it+1;
            auto it_high = nums.end()-1;
            while (it_low < it_high) {
                int sum = *it + *it_low + *it_high;
                if (sum < 0) {it_low++;}
                else if (sum > 0) {it_high--;}
                else {
                    /*
                    The duplicate may ovvurs in situation like these
                    {-7,-4,-2,-1,0,0,1,3,3,4,5,8}}
                    if 3(n=7) was part of solution, then 3(n=8) should not be considered
                    */
                    int prev_low = *it_low, prev_high = *it_high;
                    ans.push_back({*it,*it_low,*it_high});
                    /*
                    once push back, continue moving both pointers until 
                    either they met each other or no longer duplicates found
                    */
                    while (it_low < it_high) {
                        if (*it_low == prev_low) {it_low++;}
                        else if (*it_high == prev_high) {it_high--;}
                        else {break;}
                    }
                }
            }
            it++;
        }
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
    std::vector<int> testcase={0,1,0,-1};
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