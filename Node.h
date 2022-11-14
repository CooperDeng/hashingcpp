#include <iostream>

class Node {
    public:

    unsigned int s_number;
    std::string s_name;

    Node *next;
    Node *prev;

    Node();

    Node(unsigned int in_number, std::string in_name);

    ~Node();

};