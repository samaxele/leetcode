#include "CustomHeader/myCustomHeader.h"

//trial 1, 450ms(11.8%) / 10.3mb(66.51%)
// class Solution {  
//     public:
//     std::vector<int> twoSum(std::vector<int>&num, int target) {
//         unsigned short n=0;
//         for (n=0; n<num.size()-1; n++) {
//             for (int i=n+1; i<num.size(); i++) {
//                 if (num[n] + num[i] == target) {
//                     return {n,i};
//                 }
//             } 
//         }
//         return {0,1};
//     }
// };

//trial 2, 20ms(49.78%) / 10.9mb(45.53%)
class Solution {  
    public:
    std::vector<int> twoSum(std::vector<int>&num, int target) {
        short n = 0;
        std::unordered_map<int,int> mp;

        for (n=0; n<=num.size(); n++) {
            //int B = target-num[n];
            if (mp.find(target-num[n]) != mp.end()) {
                //will return end() if none found
                return {mp[target-num[n]],n};
            }
            else {
                mp[num[n]] = n;   //add index as value & value as map index
            }
        }
        return {0,1};
    }

int main () {
    Solution s1;
    std::vector<int> testcase = {1,2,3,4};
    int target = 6;
    std::vector<int> ans = s1.twoSum(testcase, target);
    
    printList(ans);
    return 0;
}
