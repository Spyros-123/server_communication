#include<iostream>
#include<nlohmann/json.hpp>
#include<string>
#include<cmath>

int main(){

    nlohmann::json data;

    data["experiment"]="Ohms law";

    data["voltage"]=12;

    data["resistance"]=100;

    std::string DATA=data.dump(4);

    nlohmann::json Jdata=nlohmann::json::parse(DATA);

    double voltage=Jdata["voltage"].get<double>();

    double resistance=Jdata["resistance"].get<double>();

    double power=std::pow(voltage,2)/resistance;

    std::cout<<power<<std::endl;
}