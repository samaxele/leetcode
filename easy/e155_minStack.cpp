#include "CustomHeader/myCustomHeader.h"

//trial 1, 136 ms(6.3%) / 16.3mb (67.47%)
// class MinStack {
// public:
//     std::vector<int> x;
//     MinStack() {}
    
//     void push(int val) {
//         auto it = x.begin();
//         MinStack::x.insert(it,val);
//     }
    
//     void pop() {
//         x.erase(x.begin());
//     }
    
//     int top() {
//         return x.front();
//     }
    
//     int getMin() {
//         std::vector<int>::iterator result = std::min_element(x.begin(), x.end());
//         return *result;
//     }
// };

//trial 2, 160ms(5.71%) / 16.3mb 91.64%)
class MinStack {
public:
    std::vector<int> x;
    MinStack() {}
    
    void push(int val) {
        std::reverse(x.begin(),x.end());
        x.push_back(val);
        std::reverse(x.begin(),x.end());
    }
    
    void pop() {
        x.erase(x.begin());
    }
    
    int top() {
        return x.front();
    }
    
    int getMin() {
        std::vector<int>::iterator result = std::min_element(x.begin(), x.end());
        return *result;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main () {
    MinStack s1;
    s1.push(2);
    std::cout << "hello world\n" ;
    return 0;
}