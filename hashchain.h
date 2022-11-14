#include <iostream>
#include "linkedlist.h"
class hash_chaining {
    private:

    linkedlist* chain;

    size_t hash_size;

    public:
    
    //default constructor
    hash_chaining();

    //constructor with specified value
    hash_chaining(size_t input_size);

    //inputting key
    void input_chain(unsigned int key, std::string student_name);

    //searching key
    void search_chain(unsigned int key);

    //deleting key
    void delete_chain(unsigned int key);

    //printing chain of keys
    void print_chain(size_t input);

    //destructor
    ~hash_chaining();

};