#include<iostream>
int main(){
    int n=50;
    void*pnt=&n;
    int* pnt1=static_cast<int*>(pnt);
    std::cout<<*pnt1<<std::endl;
    std::string message="C++";
    void*pnt2=&message;
    std::string*pnt3=static_cast<std::string*>(pnt2);
    std::cout<<pnt3->append(" AI agent")<<std::endl;
}