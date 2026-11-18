#include<iostream>
#include<string>
#include<vector>
#include<curl/curl.h>
#include<nlohmann/json.hpp>
#include<cstddef>
#include<fstream>
#include<cmath>
#include<cstdlib>

std::size_t receiveData(char* data,std::size_t size,std::size_t nmemb,void* response){

    std::size_t bytes=size*nmemb;

    std::string* pnts;

    pnts=static_cast<std::string*>(response);

    pnts->append(data,bytes);

    return bytes;
}


bool fetchData(CURL* curl,const std::string& url, std::string* response){

    curl_easy_setopt(curl,CURLOPT_URL,url.c_str());

    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION, receiveData);

    curl_easy_setopt(curl,CURLOPT_WRITEDATA,response);

    CURLcode result=curl_easy_perform(curl);

    if(result!=CURLE_OK){
        
        std::cout<<"Failure performing"<<std::endl;

        return false;

    }
    else{

        return true;

    }

}


int main() {

    CURL* curl=curl_easy_init();

    if(curl==nullptr){

        std::cout<<"Initialisation failed."<<std::endl;

        return EXIT_FAILURE;

    }

    std::string url="https://example.org";

    std::string response = R"({
        "experiment": {
            "name": "Resistor Analysis",
            "resistance": 200,
            "voltage_limit": 6.0,
            "measurements": [2.0, 4.0, 5.0, 7.0, 3.0]
        }
    })";

    nlohmann::json Response=nlohmann::json::parse(response);

    double resistance=Response["experiments"]["resistance"].get<double>();

    double voltage_limit=Response["experiments"]["voltage_limit"].get<double>();

    std::vector<double> v;

    std::vector<double>* pntv;

    for(std::size_t i=0;i<Response["experiments"]["measurments"].size();i++){

        double V=Response["experiments"]["measurments"][i].get<double>();

        pntv->at(i)=V;

    }

    double avgV, avgP, maxV;

    

    // 3. Calculate statistics.
    // 4. Detect anomalies.
    // 5. Generate the JSON report.
    // 6. Save it to a file.

}
