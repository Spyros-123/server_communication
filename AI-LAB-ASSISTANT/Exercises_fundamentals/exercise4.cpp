#include<iostream>

void calculate_power(const double*pvoltage,const double*pcurrent,double* ppower){
    *ppower=(*pvoltage)*(*pcurrent);
}
int main(){
    double voltage=12,current=2.5,power;
    double* pvoltage=&voltage;
    double* pcurrent=&current;
    double* ppower=&power;
    calculate_power(pvoltage,pcurrent,ppower);
    std::cout<<voltage<<" "<<current<<" "<<power<<std::endl;
}