#include<iostream>
#include<curl/curl.h>
int main(){
    CURL* curl=curl_easy_init();
    if(curl!=nullptr){
        std::cout<<"Initialisation succesful."<<std::endl;
    }
    curl_easy_setopt(curl,CURLOPT_URL,"https://example.com");
    CURLcode result=curl_easy_perform(curl);
    if(result==CURLE_OK){
        std::cout<<"Transfer was succesful."<<std::endl;
    }
    curl_easy_cleanup(curl);
}