#include<iostream>
int main(){
    int voltage=12;
    std::cout<<voltage<<std::endl;
    std::cout<<&voltage<<std::endl;
    int* pnt=&voltage;
    std::cout<<pnt<<std::endl;
}