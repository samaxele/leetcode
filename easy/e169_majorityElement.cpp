#include "CustomHeader/myCustomHeader.h"

//trial 1, 20ms(66.42%) / 19.8mb(8.70%)
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {

        /*
        nums itself is a pass by ref, it doesnt contain size
        create a map to hold: <nums element> and <occurence>
        <nums elemnt> is signed 32bit int;
        <occurence> is unsigned 16bit max (50,000 times)
        */
        /*
        create an array called occurence
        first eleemnt store the index and second to store occurence
        */
        uint16_t maxOccurence;
        int32_t ans;    //indexing can be INT_MIN to INT_MAX

        std::map<int32_t,uint16_t> mp;
        auto it = nums.begin();
        while (it != nums.end()) {
            mp[*it] += 1;
            if (mp[*it] > maxOccurence) {
                /*
                if the map element at index *it is more than current maxOccurence
                then update my maxOccurence with current max and 
                */
                maxOccurence = mp[*it];
                ans = *it;
            }
            it++;
        }
        return ans;
    }
};

int main () {
    Solution s1;
    std::vector<int32_t> testcase = {2,4,7,6,5,6,6,7,1,9,9,8,2};
    std::cout << "my testcase = ";
    printList(testcase);
    int ans = s1.majorityElement(testcase);
    std::cout << "my ans = " << ans << std::endl;
    return 0;
}