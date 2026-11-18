#include<iostream>
void five(){
    std::cout<<"5"<<std::endl;
}
int main(){
    void(*p)()=five;
    //we define a pointer to a function *p;
    //p(); calls back the function.
    p();
}