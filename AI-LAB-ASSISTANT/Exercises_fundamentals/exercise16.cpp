#include<iostream>
#include<nlohmann/json.hpp>
#include<string>
#include<cstddef>
#include<cmath>

int main(){
    std::string DATA=R"({
    "experiment":{
    "name":"Voltage test",
    "resistance":100,
    "measurments":[2.0,3.0,4.0,5.0]
    }
    })";
    nlohmann::json data=nlohmann::json::parse(DATA);

    double avgV, sumV=0;
    

    for(size_t i=0;i<data["experiment"]["measurments"].size();i++){

        double V=data["experiment"]["measurments"][i].get<double>();
        sumV=sumV+V;

    }
    avgV=sumV/(data["experiment"]["measurments"].size());

    double max=avgV;

    for(size_t i2=0;i2<data["experiment"]["measurments"].size();i2++){

        double r=data["experiment"]["measurments"][i2].get<double>();

        if(r>max){
            max=r;
        }
    }
    double resistance=data["experiment"]["resistance"].get<double>();

    double sumPow=0;

    for(std::size_t c=0;c<data["experiment"]["measurments"].size();c++){

        double vol=data["experiment"]["measurments"][c].get<double>();

        double power=std::pow(vol,2)/resistance;

        sumPow=sumPow+power;

    }

    double avgpow=sumPow/(data["experiment"]["measurments"].size());

    std::cout<<"Average voltage: "<<avgV<<std::endl;

    std::cout<<"Max voltage: "<<max<<std::endl;

    std::cout<<"Average power: "<<avgpow<<std::endl;

}