#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include "CS52Vector.h"

void unittest(std::ifstream& fin, Vector& a);

int main(int argc, char* argv[]){
    if(argc <= 1){
        std::cerr << "Insufficient Arguments" << std::endl;
        exit(1);
    } 

    std::ifstream fin;
    Vector a;
    for(int i=1; i<argc; i++){
        fin.open(argv[i]);
    
        unittest(fin, a);

        if(!fin.is_open()){
            std::cerr << strerror(errno) << std::endl;
            fin.close();
            exit(1);
        }

        fin.close();
    }

   return 0;
}

void unittest(std::ifstream& fin, Vector& a){
    std::string funcall;
    std::string instruction;
    std::string name;

    while(fin >> funcall){
        if (funcall == "specifier"){
            fin >> name;
        }else if(funcall == "Constructor"){
            if(fin >> instruction){
                if(instruction == "unspec"){
                    std::cout << "construct_vector(" << name << ")"<< std::endl; 
                    construct_vector(a); // invoke the cnonstructor 
                }else{
                    int pos = instruction.find(',');
                    // construct_vector();
                    std::string size = instruction.substr(0,pos); // get size 
                    instruction.erase(0,1); 
                    std::string rest = instruction.substr(pos);
                    pos = rest.find(',');
                    std::string initV = rest.substr(0,pos); // get initV
                    int vinit = std::stoi(initV);
                    int vsize = std::stoi(size);
                    // std::cout << "size: " << vsize << " intiV: " << vinit << std::endl;
                    std::cout << "construct_vector(" << name << ", " << size << ", " << vinit << ")"<< std::endl; 
                    construct_vector(a, vsize, vinit); // invoke the cnonstructor 
                }
            }
            // construct_vector();
        }else if(funcall == "printArray"){
            std::cout << name << " = ";
            for (int i = 0; i < size(a); i++)
                std::cout << at(a, i) << " ";
            std::cout << std::endl;
        }else if(funcall == "size"){
            std::cout << "size(" << name << ") is " << size(a) << std::endl;
        }else if(funcall == "capacity"){
            std::cout << "capacity(" << name << ") is " << capacity(a) << std::endl;
        }else if(funcall == "at"){
            if(fin >> instruction){
                int pos = instruction.find(',');
                std::string accPos = instruction.substr(0,pos);
                int ind = std::stoi(accPos);
                instruction.erase(0,pos+1);
                int value = std::stoi(instruction);
                try{
                    at(a, ind) = value;
                    std::cout << "at(" << name << ", " << ind << ") = ";
                    std::cout << at(a, ind) << std::endl;
                }catch (const std::out_of_range& e){
                    std::cout << "at(" << name << ", " << ind << ") = ";
                    std::cerr << e.what() << std::endl;
                }
            }
            
        }else if(funcall == "Destructor"){
            std::cout << "Destory vector" << std::endl;
            destroy_vector(a);
            std::cout << "destroy_vector(" << name <<")" << std::endl;
        }else if(funcall == "front"){
            try{
                std::cout << "\nfront(" << name << ") = ";
                std::cout << front(a);
            }catch (std::out_of_range e) { 
                std::cerr << e.what(); 
            }
        }else if(funcall == "back"){
            try{
                std::cout << "\nback(" << name << ") = ";
                std::cout << back(a) << std::endl;
            }catch (std::out_of_range e) { 
                std::cerr << e.what() << std::endl; 
            }
        }else if(funcall == "pushback"){
            int value;
            fin >> value;
            std::cout << "pushback("<< name <<", " << value << ")" << std::endl;
            push_back(a, value);
        }else if(funcall == "clear"){
            clear(a);
            std::cout << "empty(" << name << ")" << std::endl; 
        }else if(funcall == "empty"){
            std::cout << "empty(" << name << ") is " << std::boolalpha << empty(a) << std::endl;
        }else if(funcall == "find"){
            int value;
            fin >> value;
            int i = find(a, value);
            std::cout << "int i = find("<< name <<", " << value << "), i = " << i << std::endl;
        }else if(funcall == "traverse"){
            int *ptr = a.data;
            std::cout << "int* ptr = data(" << name << ")" << std::endl;
            std::cout << name << " = ";
            
            for(int i=0; i< size(a); i++)
                std::cout << *(ptr+i)<< " ";
            std::cout << std::endl;
        }else{
            std::cout << funcall << std::endl;
            std::cout << "Invalid Command" << std::endl;
        }
    }
    
}