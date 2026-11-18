#include<iostream>
#include<nlohmann/json.hpp>
#include<string>
#include<cstddef>

int main(){

    std::string Data=R"({"measurments":[2.4,3.6,4.8,5.2]})";

    nlohmann::json data=nlohmann::json::parse(Data);

    double sum=0;

    double avg;

    for(std::size_t i=0;i<data["measurments"].size();i++){

        double r=data["measurments"][i].get<double>();

        sum=sum+r;
    }

    avg=sum/(data["measurments"].size());

    std::cout<<avg<<std::endl;
}