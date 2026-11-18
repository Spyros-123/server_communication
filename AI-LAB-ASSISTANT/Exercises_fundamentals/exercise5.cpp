#include<iostream>
#include<string>
int main(){
    std::string command="Measure";
    std::string* pnt=&command;
    pnt->append(" voltage");
    std::cout<<*pnt<<std::endl;
    pnt->append(" and current.");
    std::cout<<*pnt<<std::endl;
}