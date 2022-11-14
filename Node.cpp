#include <iostream>
#include "Node.h"

Node::Node() {
    next = NULL;
    prev = NULL;
    s_number = 0;
    s_name = "";
}

Node::Node(unsigned int in_number, std::string in_name) {
    next = NULL;
    prev = NULL;
    s_number = in_number;
    s_name = in_name;
}

Node::~Node(){
    this->s_name = "";
    this->s_number= 0;
}