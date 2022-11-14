#include <iostream>
#include "hashchain.h"

hash_chaining::hash_chaining(){
    //an array of doubly linkedlist
    chain = new linkedlist[0];
    hash_size = 0;
}

hash_chaining::hash_chaining(size_t input_size){
    //an array of doubly linkedlist
    chain = new linkedlist[input_size];
    hash_size = input_size;
    std::cout<<"success\n";
}

void hash_chaining::input_chain(unsigned int key, std::string student_name){
    unsigned int m = hash_size;
    unsigned int k = key;
    unsigned int ans = (k % m);

    chain[ans].sorted_insert(key, student_name);
    return;
}

void hash_chaining::search_chain(unsigned int key){
    unsigned int m = hash_size;
    unsigned int k = key;
    unsigned int ans = (k % m);

    if (chain[ans].find(key)){
        chain[ans].print_found();
        std::cout << ans <<"\n";
    }

    else {
        std::cout<<"not found\n";
    }

}

void hash_chaining::delete_chain(unsigned int key){
    unsigned int m = hash_size;
    unsigned int k = key;
    unsigned int ans = (k % m);

    chain[ans].sorted_delte(key);

 
}

void hash_chaining::print_chain(size_t input){

    chain[input].print();
 
}

hash_chaining::~hash_chaining(){

}