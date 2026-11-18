#include<iostream>
#include<string>
void add_Sensor_label(std::string* pnt, const std::string& label){
    pnt->append(label);
}
int main(){
    std::string message="Sensor: ",label1="voltage",label2=" and current";
    std::string*pnt=&message;
    add_Sensor_label(pnt,label1);
    std::cout<<message<<std::endl;
    add_Sensor_label(pnt,label2);
    std::cout<<*pnt<<std::endl;
}