#include<iostream>
#include<nlohmann/json.hpp>
#include<string>

int main(){

    nlohmann::json data;
    data["measurments"]="Voltage drops";
    data["voltage"]=3.8;
    data["current"]=0.01;

    std::cout<<data.dump(4);

}