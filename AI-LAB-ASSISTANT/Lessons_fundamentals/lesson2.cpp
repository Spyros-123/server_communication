#include<iostream>
int main(){
    int voltage=12;
    int* p=&voltage;
    *p=24;
    std::cout<<(24==voltage)<<std::endl;
    int current=5;
    p=&current;
    *p=20;
    std::cout<<(20==current)<<std::endl;
}