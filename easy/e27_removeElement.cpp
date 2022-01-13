#include <iostream>
#include <string>
#include <vector>   

using namespace std;

// k = number of elements after removing duplicates

// class Solution { //my ans trial 1, runtime = 3ms
// public:
//     int removeElement(vector<int>& nums, int val) {
//         //begin() return iterator type in vector class, dont need ref*
//         auto ptr = nums.begin();
//         unsigned short k = nums.size();
//         unsigned short j;
//         for (auto it=nums.begin(); it!=nums.end(); it++) {
//             if (*it == val) {               //if target 'val' found
//                 nums.erase(it);
//                 k--;
//                 it--;
//             }
//         }
//         return k;
//     }
// };

// class Solution {     //leetcode JAVA sample, runtime = 4ms
// public:
//     int removeElement(vector<int>& nums, int val) {
//         unsigned short j=0,k=0;
//         for (int i=0; i<nums.size(); i++) {
//             if (val != nums[i]) {
//                 nums[j] = nums[i];
//                 k++;
//                 j++;
//             }
//         }
//         return k;
//     }
// };

class Solution { //my ans trial 2, runtime = 7ms
public:
    int removeElement(vector<int>& nums, int val) {
        unsigned short ans=nums.size();
        auto it = nums.begin();
        while (it != nums.end()) {
            if (*it == val) {
                nums.erase(it);
                it--;
                ans--;
            }
            it++;
        }
        return ans;
    }
};

int main () {
    Solution s1;
    vector<int> testcase= {0,1,2,2,3,0,4,2};
    int val = 2;

    cout << "k = " << s1.removeElement(testcase,val) << endl;

    for (int a:testcase) {
        cout << ' ' << a;
    }
    cout << endl;
    return 0;
}