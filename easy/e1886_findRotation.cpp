#include "../CustomHeader/CustomHeader.h"

//trial #, ms(%) / mb(%)
class Solution {
private:
    void show_matrix(std::vector<std::vector<int>> sample) {
        auto it_y = sample.begin();
        while (it_y != sample.end()) {
            auto it_x = it_y->begin();
            while (it_x != it_y->end()) {
                std::cout << *it_x << " "; 
                ++it_x;
            }
            std::cout << "\n";
            ++it_y;
        }
    }
    

public:
    bool findRotation(std::vector<std::vector<int>>& mat, std::vector<std::vector<int>>& target) {
        
    }

    void rotate (std::vector<std::vector<int>>& mat) {
        uint32_t i,j, N = mat.size();
        //step 1: swap diagonally
        for (i=0; i<N; ++i) {
            for (j=i+1; j<N; ++j) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        //step 2: swap horizontally
        for (i=0; i<N; ++i) {
            for (j=N-1; j>=N/2; --j) {
                int temp = mat[i][j];
                mat[i][j] = mat[i][N-1-j];
                mat[i][N-1-j] = temp;
            }
        }
    }

    void function_test (std::vector<std::vector<int>> &sample) {
        show_matrix(sample);
    }

    
    bool matrix_compare (std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {
        //assume both matrix are the same m x n
        uint32_t i,j,N = A.size();

        for (i=0; i<N; ++i) {
            for (j=0; j<N; ++j) {
                if (A[i][j] != B[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    //you may remove this constructor
    Solution() {
        std::cout << "Solution created\n";
    }

    ~Solution() {
        std::cout << "Solution destroyed\n";
    }

};

int main () {
    Solution s1;
    std::vector<std::vector<int>> testcase1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    std::vector<std::vector<int>> testcase2 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    std::vector<std::vector<int>> testcase3 = {
        {1,2,3},
        {4,2,6},
        {7,8,9}
    };

    std::cout << "hello world\n" ;

    s1.function_test(testcase1);
    std::cout << "=================\n";
    s1.function_test(testcase2);

    if (s1.matrix_compare(testcase1,testcase3)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
    
    return 0;
}