#include<iostream>

void swap(double*a,double*b){
    double tnt;
    tnt=*a;
    *a=*b;
    *b=tnt;
}

int main(){
    double a=2.5,b=3.5;
    double* pa=&a;
    double* pb=&b;
    swap(pa,pb);
    std::cout<<a<<" "<<b<<std::endl;
}