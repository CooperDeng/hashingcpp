#include <iostream>
#include "Node.h"

class linkedlist {
   
    private:
    Node* head;

    //this is especially used for expressing found functionality
    Node* found;

    public:
    //default constructor
    linkedlist();

    void sorted_insert(unsigned int key, std::string student_name);
    void sorted_delte(unsigned int key);

    bool empty();
    void print();
    bool find(unsigned int input); 
    void print_found();
    //default destructor
    ~linkedlist();
};
