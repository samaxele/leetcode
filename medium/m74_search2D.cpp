/*
    Write an efficient algorithm that able to search for a value
    'target' in an m*n matrix.

    The matrix has following properties:
    1. integer ascending sorted from left to right
    2. first integer is greater than integer of prev row

    return true if target found, else false
*/

#include "../CustomHeader/CustomHeader.h"

//trial #, ms(%) / mb(%)
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        auto it_y = matrix.begin();
        auto it_x = it_y->end();

        

       
    }
        
    //you may remove this constructor / destructor
    Solution() {
        std::cout << "Soluiton created\n";
    }

    ~Solution() {
        std::cout << "Soluiton destroyed\n";
    }

};

int main () {
    Solution s1;
    auto testcase=0;
    std::cout << "hello world\n" ;
    return 0;
}