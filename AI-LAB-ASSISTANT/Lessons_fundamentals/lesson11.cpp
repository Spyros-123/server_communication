#include<iostream>
#include<cstddef>
int main(){
    char message[]={'H','e','l','l','o'};
    //the [] help us create un array of characters;
    //C++ infers its size;
    //its size cannot be altered unlike a vector's;
    //message is the name of the array;
    //char each element of the array is a character.
    std::cout<<message[1]<<std::endl;
    //we can access elements of at array;
    char*p=message;
    //makes a pointer p to the array: message; same way we do it for functions.
    std::cout<<p[1]<<" "<<p<<std::endl;
    //this way we access elements of the array.
    //p indicates the address;*p indicates the first element of the array;*p=H;
    //another way to access elements of an array is via pointer arithmetic;
    //*(p+n-1) accesses the nth element of the array
    std::size_t x=5;
    //std::size_t declares unsigned integers from 0 to infinity inclusive;
    //contrary to int it can't take negative values;
    //used to store size of memory; number of bytes;
    //measure the size of arrays;etc;
}