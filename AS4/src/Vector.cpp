#include "CS52Vector.h"
#include <iostream>

void construct_vector ( Vector& v, int size, int initVal){
    v.size = size; // set the size
    v.capacity = size; // set the capacity
    v.data = new int[size]; // dynamic allocate the integer array to the "data"
    for(int i=0; i<size; i++){ // Init the value of each value in vector
        v.data[i] = initVal;
    }
    // std::cout << "constructor" << std::endl;
}

// Destroy Vector v and return memory to the freestore (heap).
void destroy_vector ( Vector& v ){
    // std::cout << "destructor" << std::endl;
    v.size = 0;
    v.capacity = 0;
    delete v.data;
}

// (optional) Helper function to copy v.
// void copy_data ( Vector& v ){

// }

// Returns pointer to the first element in Vector v.
int* data ( const Vector& v ){
    // std::cout << "data" << std::endl;
    return v.data;
}

// Returns the number of elements in Vector v.
int size ( const Vector& v){
    // std::cout << "size" << std::endl;
    return v.size;
}

// Returns a reference to the element at location i or throws an exception
int& at ( Vector& v, int i){
    if(empty(v))
        throw std::out_of_range("at exception");
    // std::cout << "at" << std::endl;
    return v.data[i];
}

// Returns a reference to the last element or throws an exception
int& back ( const Vector& v ) {
    // std::cout << "back" << std::endl;
    if(empty(v))
       throw std::out_of_range("back exception");;
    return v.data[v.size-1];
}

// Returns the allocated storage for Vector v.
int capacity ( const Vector& v ){
    // std::cout << "capacity" << std::endl;
    return v.capacity;
}

// Erases the elements of Vector v but does not change capacity.
void clear ( Vector& v ){
    // std::cout << "clear" << std::endl;
    for(int i=0; i< v.size; i++){
        v.data[i] = 0;
    }
    v.size = 0;
}

// If Vector v is empty return true, else false.
bool empty ( const Vector& v ){
    // if(v.size <= 0) return true;
    // else return false;
    return (v.size <= 0) ? true : false;
}

// Returns a reference to the first element or throws an exception
int& front (const Vector& v ){
    // std::cout << "front" << std::endl;
    if(empty(v))
        throw std::out_of_range("front exception");
    return v.data[0];
}

// Add element to the end of the Vector v.
void push_back (Vector& v, int element){
    // std::cout << "push_back" << std::endl;
    if(v.size < 0) v.size = 0;
    v.size++; // increment the size of vector
    
    if(v.size > v.capacity && v.size > 1){ // the capacity is growinng up
        // std::cout << "push_back size > cap [increase the size] copy the old data to new one" << std::endl;
        int* nv = new int[v.size]; // create an new dynamic array
        for(int i=0; i<v.size; i++){ // copy the data from vector to new array
        // std::cout << "before crash " << i << std::endl;
            nv[i] = v.data[i];
        }
        nv[v.size - 1] = element;
        v.data = nv; // point to the new vector
        v.capacity++; // update the capacity
    }else if (v.size > v.capacity && v.size <= 1){ // init condition
        // std::cout << "push_back size > cap [increase the size of data] create a new data" << std::endl;
        int* nv = new int[v.size]; // create an new dynamic array
        nv[v.size - 1] = element;
        v.data = nv; // point to the new vector
        v.capacity++; // update the capacity
    }else if (v.size <= v.capacity){
        // std::cout << "push_back size <= cap push the value after the current data" << std::endl;
        v.data[v.size-1] = element;
    }
}

// Search for a key in Vector v, return index of key or -1 if not found
int find(Vector &v, int key){
    // std::cout << "find" << std::endl;
    int pos = -1;
    for(int i=0; i<v.size; i++){
        if (v.data[i] == key){
            pos = i;
            break;
        } 
    }    
    return pos;
}