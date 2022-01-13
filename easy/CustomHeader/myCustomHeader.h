// my custom header
#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

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
    if (!l1) {  //if nullptr is received
        std::cout << "is empty." << std::endl; 
    }
    else {
        while (l1) {
            std::cout << l1->val << " > ";
            l1 = l1->next;
        }
        std::cout << "end(null)" << std::endl;
    }
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