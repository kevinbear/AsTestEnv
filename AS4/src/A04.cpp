#include <iostream>
#include "CS52Vector.h"

int main() {
    Vector a, b, c;
    std::cout << "Vector a, b, c;\n\n";
    std::cout << "construct_vector(a, 5, 0);";    
    construct_vector(a, 5, 0);
    std::cout << "\na = ";

    for (int i = 0; i < size(a); i++)
        std::cout << at(a, i) << " ";

    std::cout << "\nsize(a) is " << size(a);
    std::cout << "\ncapacity(a) is " << capacity(a);

    std::cout << "\n\n//add elements to a\n";

    at(a, 0) = 10;
    at(a, 3) = 5;
 
    std::cout << "at(a,0) = 10;\n";
    std::cout << "at(a,3) = 5;";
    std::cout << "\na = ";
 
    for(int i=0;i<size(a);i++)
        std::cout << at(a, i) << " ";

    int& vFront = front(a);
    std::cout << "\n\nfront(a) = " << vFront;
    int& vBack = back(a);
    std::cout << "\nback(a) = " << vBack << "\n";

    destroy_vector(a);
    std::cout << "\n//destroy vector a\n";
    std::cout << "destroy_vector(a);";

    std::cout << "\n\nException handling:";
    try{
        std::cout << "\nfront(a) = ";
        std::cout << front(a);
    }catch (std::out_of_range e) { 
        std::cerr << e.what(); 
    }

    try{
        std::cout << "\nat(a,9) = ";
        std::cout << at(a, 9);
    }catch (const std::out_of_range& e){
        std::cerr << e.what() << std::endl;
    }

    std :: cout <<"\n\n---------------------------------------------------------";
 // Create confidence tests for Vector b and Vector c as shown below
    return 0;
 }