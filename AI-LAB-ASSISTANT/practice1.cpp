#include<iostream>
#include<curl/curl.h>
#include<nlohmann/json.hpp>
#include<vector>
//nlohmann::json
int main(){
    nlohmann::json values={
        {"resistance",1000}
    };
std::cout<<values["resistance"]<<std::endl;
}