#include "CustomHeader/myCustomHeader.h"

/*
Return true if at least 1 element exist twice
Return false if every element is distinct
*/

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int,int> mp;
        auto it = nums.begin();
        while (it != nums.end()) {
            mp[*it]++;
            if (mp[*it] > 1) {return true;}
            it++;
        }   
        return false;
    }
};

int main() {
    std::vector<int> testcase = {1,2,3,4,5,5};
    Solution s1;
    std::cout << "Hello world\n";
    if (s1.containsDuplicate(testcase)) {
        std::cout << "is true\n";
    }
    else {
        std::cout << "is false\n";
    }
    return 0;
}