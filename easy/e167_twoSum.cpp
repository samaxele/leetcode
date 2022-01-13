#include "CustomHeader/myCustomHeader.h"

/*
This question is similar to twosum only that this question require answers
to be in 1-indexed instead of 0-index
(first element being indexed as 1)

other restrictions remain the same, while time given is shorter than former

*/

//trial 1, 220ms(5.07%) / 9.6mb (76.12%)
// class Solution {
// public:
//     std::vector<int> twoSum(std::vector<int>& numbers, int target) {
//         std::vector<int> ans;
//         unsigned short posA=1;    //ita - begin() +1
//         unsigned short posB=2;    //itb - begin() +1

//         auto it_A = numbers.begin();

//         while (it_A != numbers.end()-1) {
//             //if B number was found, return the position
//             auto it_B = find(it_A+1, numbers.end(),(target-*it_A));
//             if (it_B != numbers.end()) {
//                 //something is found before reaching end()
//                 posA = it_A - numbers.begin()+1;
//                 posB = it_B - numbers.begin()+1;
//                 //the +1 is required by question starting with index 1
//                 break;
//             }
//             it_A++;
//         }
//         return {posA,posB};
//     }
// };

//trial 2, ms(%) / mb (%)
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::map<std::vector<int>::iterator, int> mp;

        auto it = numbers.begin();
               
        while (it != numbers.end()) {
            // learn how to lookup has map
            if (== target-(*it)) {
                int a = mp[it]+1;
                int b = it - numbers.begin()+1;
                return {a,b};
            }
            else {
                mp[it] = it-numbers.begin();
            }
            it++;
        }
        return {1,2};
    }
};

int main () {
    Solution s1;
    std::vector<int> testcase={1,2,3,4,5,5,6,12};
    int target = 11;

    printList(testcase);
    std::vector<int> ans = s1.twoSum(testcase,target);
    std::cout << "hello world\n" ;

    printList(ans);
    return 0;
}