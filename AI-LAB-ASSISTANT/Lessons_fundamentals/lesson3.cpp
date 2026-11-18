#include<iostream>

void double_value(int* p){
    int n=*p;
    *p=2*n;
}
int main(){
    int current=5;
    double_value(&current);
    std::cout<<current<<std::endl;
}