#include <iostream>
#include "hashopen.h"

hashopen::hashopen(){
    list = new Node[0];
    hash_size = 0;
    element_counter = 0;
}

hashopen::hashopen(size_t input){
    list = new Node[input];
    hash_size = input;
    element_counter = 0;
    std::cout << "success\n";
}


void hashopen::open_insert(unsigned int key, std::string student_name){
    unsigned int m = hash_size;
    unsigned int k = key;

    //h1(k) = k mod m
    //h2(k) = floor(k/m) mod m
    unsigned int h1 = (k % m);
    unsigned int counter = 0;
    unsigned int offset = ((k/m) % m);

    //make sure offset is odd
    if (offset % 2 == 0){
        offset = offset +1;
    }

    unsigned int ans = ((h1 + counter*offset) % m);

    //full array
    if (element_counter == m) {
        std::cout <<"failure\n";
        return;
    }
    //non-full array
    else {
        //loop through array
        //keeps looking for spot if element isn't empty
        while ((list[((h1 + counter*offset) % m)].s_name != "") && (list[((h1 + counter*offset) % m)].s_number != key)){
            counter = counter+1;
        }

        //breaks out of loop, either found duplicate or have found a place for insertion
        //if duplicate
        if (list[((h1 + counter*offset) % m)].s_number == key){
            std::cout << "failure\n";
            return;
        }
        list[((h1 + counter*offset) % m)].s_name = student_name;
        list[((h1 + counter*offset) % m)].s_number = key;
        element_counter = element_counter +1;
        std::cout <<"success\n";
        return;
    }

}

void hashopen::open_delete(unsigned int key){
    unsigned int m = hash_size;
    unsigned int k = key;

    //h1(k) = k mod m
    //h2(k) = floor(k/m) mod m
    unsigned int h1 = (k % m);
    unsigned int counter = 0;
    unsigned int offset = ((k/m) % m);

    //make sure offset is odd
    if (offset % 2 == 0){
        offset = offset +1;
    }

    //initial ans
    unsigned int ans = ((h1 + counter*offset) % m);

    //empty array
    if (element_counter == 0) {
        std::cout << "failure\n";
        return;
    }

    //non-empty
    else {

        //looping through array starting with counter = 0, which is straight out h1 mod m, which is h1
        //keeps looping if the counter does not exceed and element does not match
        while ((list[((h1 + counter*offset) % m)].s_number != key) && (counter < m)){
            counter = counter+1;
        }

        //has counter exceeded?
        if (counter >= m) {
            std::cout <<"failure\n";
            return;
        }

        //must havefound the specified key if counter did not exceed
        else{
            list[((h1 + counter*offset) % m)].s_number = 0;
            list[((h1 + counter*offset) % m)].s_name = "";
            std::cout << "success\n";
            element_counter = element_counter-1;
            return;
        }
    }


}

void hashopen::open_search(unsigned int key){
    unsigned int m = hash_size;
    unsigned int k = key;

    //h1(k) = k mod m
    //h2(k) = floor(k/m) mod m
    unsigned int h1 = (k % m);
    unsigned int counter = 0;
    unsigned int offset = ((k/m) % m);

    //make sure offset is odd
    if (offset % 2 == 0){
        offset = offset +1;
    }

    //initial ans
    unsigned int ans = ((h1 + counter*offset) % m);

    //if empty array
    if (element_counter == 0){
        std::cout << "not found\n";
        return;
    }

    //non-empty array
    else{

        //looping through array starting with counter = 0, which is straight out h1 mod m, which is h1
        //keeps looping if the counter does not exceed and element does not match
        while ((list[((h1 + counter*offset) % m)].s_number != key) && (counter < m)){
            counter = counter+1;
        }

        //has counter exceeded?
        if (counter >= m) {
            std::cout <<"not found\n";
            return;
        }

        //must havefound the specified key if counter did not exceed
        else{
            std::cout <<"found "<<list[((h1 + counter*offset) % m)].s_name<<" in "<<((h1 + counter*offset) % m) << "\n";
            return;
        }

    }
}

void hashopen::open_print(){
    if(element_counter == 0){
        std::cout <<"array is empty\n";
        return;
    }

    else{
        for(size_t i = 0; i < hash_size; i++){
            std::cout << list[i].s_number << " ";
        }
        std::cout << "\n";
    }
}

hashopen::~hashopen(){

}
