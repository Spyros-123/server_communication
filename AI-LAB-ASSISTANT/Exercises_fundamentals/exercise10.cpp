#include<iostream>
#include<cmath>
void corner_frequency(const double* R,const double* C,double* f){
    double pi=acos(-1);
    *f=1/(2*pi*(*R)*(*C));
}
int main(){
    double R=1e+4,C=4e-9,f;
    double* pr=&R;
    double* pc=&C;
    double* pf=&f;
    corner_frequency(pr,pc,pf);
    std::cout<<*pf<<std::endl;
}