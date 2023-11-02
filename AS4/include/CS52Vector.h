#pragma once
#ifndef __CS52VECTOR_H__
#define __CS52VECTOR_H__

#include <string>
#include <stdexcept>
// struct vector data type
struct Vector{
    int size = 0; 
    int capacity = 0; 
    int *data = nullptr;
};

// Vector prototypes;

// Construct a Vector v with a default size 0
void construct_vector ( Vector& v, int size = 0, int initVal = 0 );
// Destroy Vector v and return memory to the freestore (heap).
void destroy_vector ( Vector& v );
// (optional) Helper function to copy v.
// void copy_data ( Vector& v );
// Returns pointer to the first element in Vector v.
int* data ( const Vector& v );
// Returns the number of elements in Vector v.
int size ( const Vector& v);
// Returns a reference to the element at location i or throws an exception
int& at ( Vector& v, int i);
// Returns a reference to the last element or throws an exception
int& back ( const Vector& v );
// Returns the allocated storage for Vector v.
int capacity ( const Vector& v );
// Erases the elements of Vector v but does not change capacity.
void clear ( Vector& v );
// If Vector v is empty return true, else false.
bool empty ( const Vector& v );
// Returns a reference to the first element or throws an exception
int& front ( const Vector& v );
// Add element to the end of the Vector v.
void push_back ( Vector& v, int element);
// Search for a key in Vector v, return index of key or -1 if not found
int find(Vector &v, int key);

#endif