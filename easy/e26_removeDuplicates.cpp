#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {return 0;}

        unsigned short j=0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }

};

void printVect (vector<int> val) {
    cout << "[";
    for (int x:val) {
        cout << x << ", ";
    } 
    cout << "\b\b]" <<endl;
}

int main() {
    Solution s1;
    vector<int> nums = {-100,-77,-77,-20,-3,-3,0,2,3,3,23,80};
    cout << "k=" << s1.removeDuplicates(nums) << endl;
    printVect(nums);

    return 0;
}