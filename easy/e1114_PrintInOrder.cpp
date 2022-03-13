#include "CustomHeader/myCustomHeader.h"
#include <functional>
#include <condition_variable>

/*
    Given threads to be called in sequence A->B->C
    Assuming the 3 functions first(), second() and third() are called separately by ABC in random
    eg A(first()) -> B(third()) -> C(second())
    We will need to ensure function sequence are called correctly first->second->third

    eg [3,1,2], thread A runs third(), B runs first, C runs second()
    Output: firstsecondthird

    Method:
    We will need to implement a method to handle so that first() will called first
    no matter which threads runs it.
*/

/*
    Question specific functions
*/
void printFirst() {
    std::cout << "First "; 
}

void printSecond() {
    std::cout << "Second ";
}

void printThird() {
    std::cout << "Third\n";
}

//trial #1, 71ms(55.98%) / 7.3mb(21.3%)
class Foo {
public:
    uint8_t runThread = 0;
    std::mutex mu;
    std::condition_variable cv;
    Foo() {}

    void first(std::function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        runThread = 1;
        cv.notify_all();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> ulock(mu);
        //while first() is not called
        if (runThread != 1) {
            cv.wait(ulock);
        }
        mu.lock();
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        //std::cout << "2nd ";
        runThread = 2;
        mu.unlock();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> ulock(mu);
        if (runThread != 2) {
            cv.wait(ulock);
        }
        mu.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        
        //std::cout << "3rd\n";
        runThread = 0;
        mu.unlock();
    }
};



int main () {
    Foo sample;

    Foo *classPtr = new Foo();
    std::thread thA(sample.first);
    std::thread thB(sample.third);
    std::thread thC(sample.second);

    thA.join();
    std::cout << "Thread A joined!\n";
    thB.join();
    std::cout << "Thread B joined!\n";
    thC.join();
    std::cout << "Thread C joined!\n";
    return 0;
}