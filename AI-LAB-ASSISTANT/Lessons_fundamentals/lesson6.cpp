#include<iostream>

double addFive(double& x){
return x=x+5;
}
double square(double& x){
    return x=x*x;
}
double halve(double& x){
    return x=x/2;
}
void callback(double& x,double(*operation)(double&)){
    operation(x);
}
int main(){
    double x=4;
    callback(x,addFive);
    callback(x,square);
    callback(x,halve);
    std::cout<<x<<std::endl;
}