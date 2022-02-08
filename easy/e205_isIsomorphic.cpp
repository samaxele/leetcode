#include "CustomHeader/myCustomHeader.h"

/*
Isomorphic = convert one string to another string char by char
mapping happens only 1 way (1 to 1 relationship)
if map a->z, and b->y, we cannot map c->z as z has been occupied
if map a->z, and b->y, our z->!z and y->!y as both z2 and y2
are linked to a1 and b1

Tips:
Although isomorph is a one-way 1-to-1 relationship, this also 
tells us that the isomorph also applicable in the reverse method
if abccba and pqrrqp are isomorph, the  pqrrqp is also mappable to abccba
just use && for logic checking
*/

//trial 1, 30ms(5.33%) / 7.2mb(11.68%)
// class Solution {
// public:
//     bool checkIsoMorph(std::string Str1, std::string Str2) {
//         std::map<char,char> mp;
//         auto it_s = Str1.begin();  //primary iterator
//         auto it_t = Str2.begin();  //secondary iterator
//         while (it_s != Str1.end()) {
//             //set states for it_s
//             if (mp[*it_s] == '\0' || mp[*it_s] == *it_t) {
//                 //this will ensure null are being replaced
//                 //and will not affect existing value
//                 mp[*it_s] = *it_t;
//             }
//             else {
//                 return false;
//             }
//             it_s++;it_t++;
//         }
//         return true;
//     }

//     bool isIsomorphic(std::string s, std::string t) {
//         /*
//         function checkIsoMorph is check the relationship of str1 ans str2
//         if s & t are isomorph, then (s,t) and (t,s) suppose to return true
//         for both, this case, use && logic shall return desired answer.
//         */
//         return {checkIsoMorph(s,t) && checkIsoMorph(t,s)};
//     }
// };

//trial 2, 8ms(67.05%) / 7.4mb(9.51%)
class Solution {
public:
    bool checkIsoMorph(std::string Str1, std::string Str2) {
        std::map<char,char> mp;
        auto it_s = Str1.begin();  //primary iterator
        auto it_t = Str2.begin();  //secondary iterator
        while (it_s != Str1.end()) {
            if (mp.find(*it_s) == mp.end()) {
                /*
                key first occurence
                */
                mp[*it_s] = *it_t;
            }
            else if (mp.find(*it_s)->second != *it_t) {
                // found something but val different
                return false;
            }
            //if found key and val equals, do nothing
            it_s++;it_t++;
        }
        return true;
    }

    bool isIsomorphic(std::string s, std::string t) {
        /*
        function checkIsoMorph is check the relationship of str1 ans str2
        if s & t are isomorph, then (s,t) and (t,s) suppose to return true
        for both, this case, use && logic shall return desired answer.
        */
        return {checkIsoMorph(s,t) && checkIsoMorph(t,s)};
    }
};

int main () {
    Solution s1;
    std::string s = "abccba";
    std::string t = "123327";
    if (s1.isIsomorphic(s, t)) {
        std::cout << s << " and " << t << " are isomorphic\n";
    }
    else
        std::cout << s << " and " << t << " not isomorphic\n";
    return 0;
}