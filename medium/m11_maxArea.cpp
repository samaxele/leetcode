#include <iostream>
#include <string>
#include <vector>   

using namespace std;

// //trial 1, timeout(??.??%) / ?.?mb(??.??%)
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int area=0,temp=0;
//         auto getMaxArea = [&](int l, int r) {
//             //input arg cannot be 0
//             int L_area = (r-l)*min(height[l],height[r]);
//             while (l > 0 && r<height.size()-1) {
//                 l--;r++;
//                 L_area = max(L_area,(r-l)*min(height[l],height[r]));
//             }
//             return L_area;
//         };
        
//         for (int i=1; i<height.size(); i++) {
//             temp = max(getMaxArea(i,i),getMaxArea(i-1,i));
//             area = temp>area?temp:area;
//         }
//         return area;
//     }
// };

//trial 2, 88ms (60.55%) / 58.9mb (80.76%)
// class Solution {
//     public:
//     int maxArea (vector<int>& height) {
//         int ans=0;
//         auto it_s = height.begin();
//         auto it_e = height.end()-1;
//         auto getLocalArea = [&](vector<int>::iterator L, vector<int>::iterator R) {
//             int x = R-L;
//             int y = min(*R,*L);
//             return x*y;
//         };

//         while (it_s < it_e) {
//             // just get max area
//             ans = max(ans,getLocalArea(it_s,it_e));
//             if (*it_s < *it_e) {it_s++;}
//             else {it_e--;}
//         }
//         return ans;
//     }
// };

//trial 3, 88ms (60.55%) / 58.9mb (80.76%)
class Solution {
    public:
    int maxArea (vector<int>& height) {
        int ans=0,curr=0;
        auto it_s = height.begin();
        auto it_e = height.end()-1;
        while (it_s < it_e) {
            // just get max area
            curr = min(*it_s,*it_e)*(it_e-it_s);
            ans = max(ans,curr);
            if (*it_s < *it_e) {it_s++;}
            else {it_e--;}
        }
        return ans;
    }
};

int main () {
    //input sample
    /*
    [1,8,6,2,5,4,8,3,7]
    [1,1]
    [4,3,2,1,4]
    [1,2,1]
    [1,2,4,3]
    */
    Solution s1;
    vector<int> testcase;
    //ans = 402471897 <correct>
    cout << "largest Area = " << s1.maxArea(testcase) << endl; 

    return 0;
}