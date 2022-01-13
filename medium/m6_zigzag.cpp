#include <iostream>
#include <string> 

using namespace std;


//trial 1, 8ms(87.31%) / 8.2mb(89.13%)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) { return s; }

        bool dir = true;    //true = incre
        short row=0;
        string sentence[numRows];
        string ans = "";
        auto its = s.begin();
        while (its != s.end()) {
            //cout << "it now = " << *its << endl;
            sentence[row] += *its;
            dir?row++:row--;
            //cout << "moving to row " << row
            //<< ", direction is " << dir << endl;
            if (row >= numRows-1 || row <= 0) {
                dir = !dir;
            }
            //cout << "at row " << row
            //<< ", direction is " << dir << endl;
            its++;
        }

        for (int i=0; i<numRows; i++) {
            //cout << "row " << i << " sentence = " << sentence[i] << endl;
            ans += sentence[i];
        }
        return ans;
    }
};

int main () {
    Solution s1;
    string tcase="PAYPALISHIRING";
    string tcase2 = "AB";
    int in2 = 3;
    
    cout << s1.convert(tcase,3) << endl;
    cout << s1.convert(tcase2,1) << endl;
    cout << "hello" << endl;
    return 0;
}