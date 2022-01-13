#include <iostream>
#include <string>
#include <vector>   

using namespace std;

class Solution {
    public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        short n = strs.size()-1;    //assign last index to n
        for (int i=n-1; i>0; i--) { 
            if(strs[i].length() <= strs[n].length()) {
                n=i;    //shortest string occurs at n
            }
        }
        //cout << "shortest n=" << n <<endl;
        for (int j=0; j<strs[n].length(); j++) {
            for (int k=0; k<strs.size()-1; k++) {
                //cout << "compare " << strs[k][j] << " and " << strs[k+1][j] << endl;
                if ((strs[k][j] != strs[k+1][j])) {
                    return ans;}
            }
            ans += strs[n][j];
        }
        return ans;
    }
};

int main () {
    Solution s1;

    return 0;
}