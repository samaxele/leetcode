#include <iostream>  
#include <vector>

using namespace std;

void showVec (vector<int> x) {
    auto it = x.begin();
    while (it != x.end()) {
        cout << *it << ", ";
        it++;
    }
    cout << "\b\b \n";
}

//trial 1, 0ms(100%) / 8.7mb(85.53%)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto it = digits.end()-1;
        *it += 1;
        while (*it >= 10 && it != digits.begin()) {
            *it = *it % 10;
            it--;
            *it += 1;
        }
        //it is now at begin
        //it = digits.begin();
        if (*it >= 10) {
            *it = *it%10;
            digits.insert(it,1);
        }
        return digits;
    }
};


int main () {
    Solution s1;
    vector<int> testcase = {1,0,9,9};
    vector<int> ans = s1.plusOne(testcase);
    showVec(ans);
    return 0;
}