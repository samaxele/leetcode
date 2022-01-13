#include <iostream>
#include <string>
#include <vector>   

using namespace std;

// class Solution { //my ans trial 1, runtime = 9ms, top 16.53%
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         auto it = nums.begin();
//         unsigned short int ptr=0;
//         for (it; it != nums.end(); it++) {
//             if (target <= *it) { return ptr;}
//             ptr++;
//         }
//         return ptr;
//     }
// };

class Solution { //my ans trial 2, runtime = 4ms, top 81.01%
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = nums.begin();
        unsigned short ans=0;

        while (it != nums.end()) {
            if (target <= *it) {return ans;}
            it++;
            ans++;
        }

        return ans;
    }
};

int main () {
    Solution s1;
    vector<int> testcase={1,3,5,6};
    int target = 5;

    cout << "index = " << s1.searchInsert(testcase,target) << endl;

    return 0;
}