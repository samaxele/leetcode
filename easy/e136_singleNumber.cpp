#include "CustomHeader/myCustomHeader.h"

/*
After checking in leetcode, the XOR method able to achieve 8ms run time
This is common leetcode problem where the time decision is inconsistent
*/

//trial 1, 62ms(5.24%) / 20.7mb(6.52%)
// class Solution {
// public:
//     int singleNumber(std::vector<int>& nums) {
//         std::map<int,int> myMap;
//         auto it = nums.begin();
//         while (it != nums.end()) {
//             if (myMap[*it] > 0) {
//                 myMap.erase(*it);
//             }
//             else {
//                 // map not found, create and assign
//                 myMap[*it]++;
//             }
//             it++;
//         }
//         auto map_it = myMap.begin();
//         return map_it->first;
//     }
// };

//trial 2, 48ms(5.24%) / 20.9mb(6.52%)
// class Solution {
// public:
//     int singleNumber(std::vector<int>& nums) {
//         std::map<int,int> myMap;
//         for (int i=0; i<nums.size(); i++) {
//             myMap[nums[i]] = 1-myMap[nums[i]];
//         }

//         auto it = myMap.begin();

//         while (it != myMap.end()) {
//             if (it->second > 0) {
//                 return it->first;
//             }
//             it++;
//         }
//         return 0;
//     }
// };

/*
Example of XOR sign "^"
XOR is commutative, means data flow is correct (flow control is irrelevant)
just as AND and OR, A && B and B&&A are both valid
XOR is also makes no change when B^B, leaving:
a^b^c^b^c = a^b^b^c^c = a, since b^b = 0 (if a = 1)
*/
//trial 3, 33ms(16.15%) / 17mb(47.8%)
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ans=0;
        for (int i=0; i<nums.size(); i++) {
           ans ^= nums[i]; 
        }
        return ans;
    }
};

int main () {
    Solution s1;
    std::vector<int> testcase = {1,1,2,3,3,4,5,2,5};
    std::cout << "Solution begin" << std::endl;
    std::cout << "testcase = ";
    printList(testcase);
    std::cout << "ans = " << s1.singleNumber(testcase) << std::endl;

    return 0;
}