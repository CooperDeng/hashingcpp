#include <iostream>
#include "linkedlist.h"

linkedlist::linkedlist() {
    head = NULL;
    found = NULL;
}

void linkedlist::sorted_insert(unsigned int key, std::string student_name){

    //if empty chain
    if (head == NULL){
        Node* newNode = new Node(key, student_name);
        head = newNode;
        newNode=NULL;
        std::cout<<"success\n";
        return;
    }

    //head equal
    else if (head->s_number == key){
       std::cout <<"failure\n";
       return;
    }

    //head smaller than key
    else if (head->s_number < key){
        Node* newNode = new Node(key, student_name);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        newNode = NULL;
        std::cout << "success\n";
        return;
    }

    //head larger than key
    else {
        Node* currentNode = head;

        // we loop through the entire chain to find where to put it
        // while currentNode is not the last element
        // and it matches that we couldn't insert it after current node
        while (currentNode ->next != NULL && (currentNode->next->s_number > key)) {
            currentNode = currentNode->next;
        }

        //out of while loop, it matches that we could insert it after currentNode
        //if current Node is the end
        if (currentNode->next == NULL){

            if (currentNode->s_number == key){
                std::cout<< "failure\n";
                currentNode=NULL;
                return;
            }

            Node* newNode = new Node(key, student_name);
            currentNode->next = newNode;
            newNode->prev = currentNode;
            std::cout<<"success\n";
            currentNode=NULL;
            newNode=NULL;
            return;

        }

        //if current node not the end
        else {
                //if current Node is equal
            if (currentNode->next->s_number == key){
                std::cout<<"failure\n";
                currentNode = NULL;
                return;
            }

            Node* newNode = new Node(key, student_name);
            newNode->next = currentNode->next;
            newNode->prev = currentNode;
            currentNode->next->prev = newNode;
            currentNode->next = newNode;
            std::cout <<"success\n";
            currentNode = NULL;
            newNode = NULL;
            return;
        }

    }
}


void linkedlist::sorted_delte(unsigned int key){
    // if empty chain
    if(head == NULL){
        std::cout<< "failure\n";
        return;
    }

    //non-empty chain
    else {
        Node* currentNode = head;
        //find the Node first
        while(currentNode != NULL){
            if (currentNode->s_number == key){
                break;
            }
            else{
                currentNode = currentNode->next;
            }
        }

        //if we've reached the end
        if(currentNode == NULL){
            std::cout<< "failure\n";
            currentNode = NULL;
            return;
        }
        else {
            //edge cases: currentNode is head or last element
            
            //EDGE CASE 1
            //if currentNode is head
            if(currentNode == head){
                //if there is only one element
                if(currentNode->next == NULL){
                    delete head;
                    head = NULL;
                    currentNode = NULL;
                    std::cout << "success\n";
                    return;
                }
                //if more than one element
                else {
                    head = currentNode->next;
                    head->prev = NULL;
                    delete currentNode;
                    currentNode = NULL;
                    std::cout << "success\n";
                    return;
                }

            }

            //EDGE CASE 2
            //currentNode is last
            else if(currentNode->next == NULL){
                currentNode->prev->next = NULL;
                delete currentNode;
                currentNode=NULL;
                std::cout<< "success\n";
            }
            
            //NORMAL CASE
            //currentNode is not last nor head
            else{
                currentNode->prev->next = currentNode->next;
                currentNode->next->prev = currentNode->prev;
                delete currentNode;
                currentNode=NULL;
                std::cout<<"success\n";
                return;
            }
        }
        
    }
}

bool linkedlist::empty(){
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

bool linkedlist::find(unsigned int input){

    if(head == NULL) {
        //empty chain, return false
        return false;
    }

    unsigned int key = input;

    //move through Nodes to find the key
    Node* currentNode = head;
    while (currentNode != NULL) {
       if (currentNode->s_number == key){
            //found, return true
            found = currentNode;            
            currentNode = NULL;
            return true;
       }

       else{
        currentNode = currentNode->next;
       }
    }

    //not found after while loop
    return false;
}

void linkedlist::print_found(){
    if (found == NULL){
        std::cout<<"found is NULL, error!\n";
        return;
    }

    else{
        std::cout << "found " << found->s_name <<" in ";
        found = NULL;
        return;
    }
}

void linkedlist::print(){

    Node* currentNode = head;

    if(head == NULL) {
        std::cout << "chain is empty" << "\n";
    }
    else {
        while(currentNode != NULL) {
            std::cout << currentNode->s_number << " ";
            currentNode = currentNode->next;
        }   
        std::cout << "\n";
    }

}


linkedlist::~linkedlist() {

    while (head != NULL){
        Node*tempptr = head;
        head = head->next;
        delete tempptr;
        tempptr = NULL;
    }

    found = NULL;
    
}
