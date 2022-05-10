// my custom header
#pragma once

/*
Basic IO
*/
#include <iostream>

/*
Containers library
*/
#include <vector>
#include <map>
#include <unordered_map>

/*
General utilities library
random() can call with time.h (init = srand(time(NULL))
*/
#include <string>
#include <time.h>
#include <ctime>
#include <chrono>

/*
Numerics library
*/
#include <algorithm>
#include <math.h>

/*
Threads support library
*/
#include <thread>
#include <mutex>


// using namespace std;     //not a good habit for using
/**
 * "using namespace" will import & simplify the calling of library fn
 * such as 'cout' instead of 'std::cout'
 * but if this extends to user library, this may impose problems when upgradiing
 * example:
 * foo.h has a function add() which call foo::add()
 * bar.h has a function sum() whcih call bar::sum()
 * 
 * "using namespace 'foo'" -> consist a function named sum()
 * "using namespace 'bar'" -> consist a function named add()
 * you may call sum() or add() without problem until an occasion where foo updated to foo 2.0 and 
 * new function add() added that happens to share the same name from bar.h 
 * now you have add() exist in foo.h and bar.h, this will take some time to fix especially if the
 * program is complex.
 * 
 * one good fix is to call the entire namespace so everyone knows where the fn coming from
 * 
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode (int x) : val(x), next(nullptr) {};
};

ListNode *genListNode(std::vector<int> x) {
    ListNode *head, *tail;
    tail = new ListNode(0);
    head = tail; 
    int size = x.size();
    if (0 == size) {return nullptr;}
    for (int i=0; i<size; i++) {
        tail->next = new ListNode(x[i]);
        tail = tail->next;
    }
    return head->next;
}

void printList (ListNode *l1) {
    while(l1) {
        std::cout << l1->val << " > ";
        l1 = l1->next;
    }
    std::cout << "\b\b  \n";
}

void printList (int &l1) {
    std::cout << l1 << std::endl;
}

void printList (std::vector<int> &vec) {
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end()) {   //only listnode can use nullptr
        std::cout << *it << " > ";
        it++;
    }
    std::cout << "null" << std::endl;
} 

void show_matrix(std::vector<std::vector<int>>& sample) {
    auto it_x = sample.begin();

    while (it_x != sample.end()) {
        auto it_y = it_x->begin();
        while (it_y != it_x->end()) {
            std::cout << *it_y << " ";
            ++it_y;
        }
        std::cout << "\n";
        ++it_x;
    }
}

std::vector<std::vector<int>> generate_matrix(uint8_t m, uint8_t n, int range) {
    //generate new random seed
    srand(time(NULL));
    std::vector<std::vector<int>> row;
    std::vector<int> col;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            col.push_back(rand()%range);
        }
        row.push_back(col);
    }
    return row;
}