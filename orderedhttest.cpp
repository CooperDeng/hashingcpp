#include <iostream>
#include "hashchain.h"

int main () {

    std::string first_input;
    std::string first_letter;
    std::string size;
    unsigned int size_int = 0;

    std::getline(std::cin, first_input);
    first_letter = first_input.substr(0,1);

    //declaring a hashtable
    if (first_letter == "m"){
        size = first_input.substr(2);
        size_int = stoi(size);
    }

    hash_chaining hc(size_int);

    while(true) {
        
        // looking for commands
        std::string user_input;
        std::getline(std::cin, user_input);
        int found = user_input.find(" ");
        std::string input_c = user_input.substr(0, found);
        std::string rest = user_input.substr(found+1);

        if (input_c == "i") {
            found = rest.find(" ");
            std::string SN = rest.substr(0, found);
            std::string S = rest.substr(found+1);
            unsigned int S_N_int = stoi(SN);
            hc.input_chain(S_N_int, S);
        }

        if (input_c == "s") {
            unsigned int S_N_int = stoi(rest);
            hc.search_chain(S_N_int);
            
        }

        if (input_c == "d") {
            unsigned int S_N_int = stoi(rest);
            hc.delete_chain(S_N_int);
        }

        if (input_c == "p") {
            unsigned int input = stoi(rest);
            hc.print_chain(input);
        }

        if (user_input == ""){
            break;
        }
        
    }
    
    return 0;
};

