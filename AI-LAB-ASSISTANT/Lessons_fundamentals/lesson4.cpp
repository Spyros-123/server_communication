#include<iostream>
#include<string>
int main(){
    std::string message="Analyse";
    std::string*pnt=&message;
    std::cout<<pnt->append(" my circuit.")<<std::endl;
    pnt->clear();
    pnt->push_back('l');
    std::cout<<message<<std::endl;
}