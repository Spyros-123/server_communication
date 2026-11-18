#include<iostream>
#include<curl/curl.h>
#include<string>
#include<cstddef>
#include<cstdlib>

std::size_t receiveData(char* data,std::size_t size,std::size_t nmemb,void* response){

    std::size_t bytes=size*nmemb;
    std::string*pnts;
    pnts=static_cast<std::string*>(response);
    pnts->append(data,bytes);
    return bytes;

}

bool fetchWebsite(CURL* curl, const std::string& url, std::string*response){

    curl_easy_setopt(curl,CURLOPT_URL,url.c_str());

    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,receiveData);

    curl_easy_setopt(curl,CURLOPT_WRITEDATA,response);

    CURLcode result=curl_easy_perform(curl);

    if(result!=CURLE_OK){
        std::cout<<"ERROR"<<std::endl;

        return false;
    }
    else{
        return true;
    }


}
int main(){
    CURL* curl=curl_easy_init();

    if(curl==nullptr){
        std::cout<<"Initialisation failed!"<<std::endl;

        return EXIT_FAILURE;
    }

    std::string url1="https://example.org", url2="https://example.com";

    std::string response1, response2;
    std::string* pr1=&response1;
    std::string* pr2=&response2;

    bool success1=fetchWebsite(curl,url1,pr1);

    bool success2=fetchWebsite(curl,url2,pr2);

    std::cout<<response1<<std::endl;

    std::cout<<"Bytes of 1: "<<response1.size()<<std::endl;

    std::cout<<response2<<std::endl;

    std::cout<<"Bytes of 2: "<<response2.size()<<std::endl;

    curl_easy_cleanup(curl);


}