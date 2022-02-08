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

//trial 2, 9ms(20.03%) / 9.7mb (44.61%)
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        /*
        Map<index,content>
        assume there is always one solution, then there should be no repeat
        value.
        If value occurence > 1, either both are answer or both are not.
        This also applies to n=3, 4, 5 and so on...
        */
        std::map<int, int> mp;
        for (int i=0; i<numbers.size(); i++) {
            auto it = mp.find(target-numbers[i]);
            /*
            if another pair is found
            */
           if (it != mp.end()) {
               return {it->second,i+1};
           }
           else {
               //add in index and save position as value
               mp[numbers[i]] = i+1;
           }
        }
        return {1,2};
    }
};

int main () {
    Solution s1;
    std::vector<int> testcase={1,2,5,6,12};
    int target = 11;

    printList(testcase);
    std::vector<int> ans = s1.twoSum(testcase,target);
    std::cout << "target = " << target << "\n";
    std::cout << "ans = {" << ans[0] << "," << ans[1] << "}\n";
    return 0;
}