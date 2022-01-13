#include <iostream>
#include <string>
#include <vector>   

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//trial 1, 0ms(100%) / 9.2mb(29.23%)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m==0) {nums1 = nums2;}
        //m,n = length, not index
        else {
            auto it1 = nums1.begin();
            auto it2 = nums2.begin();
            //auto it1_end = it1+m;
            while (it1!=nums1.end()-n && it2 != nums2.end()) {
            //cout << "compare it1,it2 = " << *it1 << ", " << *it2 << endl;
                if (*it2<*it1) {
                    it1 = nums1.insert(it1,*it2);
                    it2++;
                }
                it1++;
            }

            if (it2!=nums2.end()) {//i ran out of m
                nums1.insert(it1,it2,nums2.end());
            }
            nums1.erase(nums1.end()-n,nums1.end());
        }
        
    }
};

int main () {
    Solution s1;
    // vector<int> tcase1={-1,0,0,3,4,4,0,0,0};
    // vector<int> tcase2={1,2,2};
    // vector<int> tcase1={1,2,0};
    // vector<int> tcase2={1};
    vector<int> tcase1={1,0};
    vector<int> tcase2={2};
    int n = tcase2.size();
    int m = tcase1.size()-n;

    s1.merge(tcase1,m,tcase2,n);

    auto it = tcase1.begin();
    while (it != tcase1.end()) {
        cout << *it << ", ";
        it++;
    }
    cout << "\b\b  " << endl;
    //cout << "m,n = " << m << ", " << n << endl; 
    return 0;
}