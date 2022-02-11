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
        std::vector<std::vector<int>> ans;
        //sort the vector
        std::sort(nums.begin(),nums.end());
        int vec_end = nums.size();

        int anchor = 1;
        int n_left = anchor-1;
        int n_right = anchor+1;

        while (anchor != vec_end-2) {
            while (n_left >= 0  || n_right < vec_end) {
                if (-1*anchor == n_left + n_right) {
                    ans.push_back({anchor, n_left, n_right});
                    n_left--;n_right++;
                }
                else if (-1*anchor > n_left + n_right && n_right < vec_end) {
                    n_right++;
                }
                else if (-1*anchor < n_left + n_right && n_left >= 0) {
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
    Solution s1;
    std::vector<int> testcase={-1,0,1,2,-1,-4};
    std::cout << "hello world\n" ;
    
    return 0;
}