#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include "CS52Vector.h"

int main(int argc, char* argv[]){
    if(argc <= 1){
        std::cerr << "Insufficient Arguments" << std::endl;
        exit(1);
    } 

    std::ifstream fin;
    
    fin.open(argv[1]);
    if(!fin.is_open()){
        std::cerr << strerror(errno) << std::endl;
        fin.close();
		exit(1);
    }

    std::string funcall;
    std::string instruction;
    int i = 0;
    // int size, initV;
    Vector a,b,c;
    while(fin >> funcall){
        if(funcall == "Constructor"){
            if(fin >> instruction){
                std::cout << "inst: ";
                std::cout << instruction << std::endl;
                // int pos = instruction.find(',');
                // // construct_vector();
                // std::string size = instruction.substr(0,pos);
                // std::string rest = instruction.substr(pos);
                // pos = rest.find(',');
                // std::string initV = rest.substr(0,pos);
                // std::cout << "inst: ";
                // std::cout << instruction << std::endl;
            }
            // construct_vector();
        }else if(funcall == "printArray"){
            if(fin >> instruction){
                std::cout << "inst: ";
                std::cout << instruction << std::endl;
            }
            // for (int i = 0; i < size(a); i++)
            //     std::cout << at(a, i) << " ";
        }else if(funcall == "size"){
            if(fin >> instruction){
                std::cout << "inst: ";
                std::cout << instruction << std::endl;
            }
        }else if(funcall == "capacity"){
            if(fin >> instruction){
                std::cout << "inst: ";
                std::cout << instruction << std::endl;
            }
        }else if(funcall == "at"){
            if(fin >> instruction){
                std::cout << instruction << std::endl;
            }
        }else if(funcall == "Destructor"){
            if(fin >> instruction){
                std::cout << "inst: ";
                std::cout << instruction << std::endl;
            }
        }else if(funcall == "front"){
            if(fin >> instruction){
                std::cout << "inst: ";
                std::cout << instruction << std::endl;
            }
        }else if(funcall == "back"){
            if(fin >> instruction){
                std::cout << "inst: ";
                std::cout << instruction << std::endl;
            }
        }else if(funcall == "Exception"){
            if(fin >> instruction){
                std::cout << "inst: ";
                std::cout << instruction << std::endl;
            }
        }
    }
    return 0;
}