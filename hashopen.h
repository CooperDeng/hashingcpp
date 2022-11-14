#include <iostream>
#include "Node.h"

class hashopen {
    private:

    Node* list;

    size_t hash_size;

    int element_counter;

    public:
    //constructor
    hashopen();
    hashopen(size_t input);

    void open_insert(unsigned int key, std::string student_name);
    void open_delete(unsigned int key);
    void open_search(unsigned int key);

    //printing the entire array
    //for test purposes only
    void open_print();

    //destructor
    ~hashopen();

};