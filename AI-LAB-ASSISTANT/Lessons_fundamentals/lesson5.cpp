#include<iostream>
#include<string>
int main(){
    std::string message="Hello";
    void*pnt=&message;
    //std::cout<<*pnt<<std::endl;
    //thisnline will print error as the type of pointer is not specified;
    //C++ doesn't know the type;we have to specify it.
    std::string*d = static_cast<std::string*>(pnt);
    //we define a new pointer d;
    //static_cast converts the type of the pointer from void to string and stores it in a new pointer d;
    //<> contains the type we want to change to;
    //() the pointer we want to change;
    //pnt remains unchanged;
    std::cout<<*d<<std::endl;
}