#include<iostream>
int main(){
    int x=10,y=20;
    int*p=&x;
    int& ref=y;
    p=&y;
    *p=30;
    ref=x;
    std::cout<<x<<" "<<y<<std::endl;
}