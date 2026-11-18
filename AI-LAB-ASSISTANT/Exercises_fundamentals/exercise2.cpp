#include<iostream>

void calibrate(double*p,double offset){
    *p=*p+offset;
}

int main(){
    double voltage=4.7;
    double* p=&voltage;
    double offset=0.3;
    std::cout<<*p<<std::endl;
    calibrate(p,offset);
    std::cout<<*p<<std::endl;
}