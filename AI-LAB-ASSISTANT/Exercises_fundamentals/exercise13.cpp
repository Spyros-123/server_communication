#include<iostream>
#include<curl/curl.h>
#include<cstdlib>
#include<string>
#include<cstddef>
std::size_t receiveData(char* data,std::size_t size,std::size_t nmemb,void* userData){
    std::size_t bytes=size*nmemb;
    std::string* pnt;
    pnt=static_cast<std::string*>(userData);
    pnt->append(data,bytes);
    return bytes;
}
int main(){
    CURL* curl=curl_easy_init();

    std::string response;

    if(curl!=nullptr){
        std::cout<<"Initialisation succesful."<<std::endl;
    }
    else{
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl,CURLOPT_URL,"https://example.com");

    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,receiveData);

    curl_easy_setopt(curl,CURLOPT_WRITEDATA,&response);

    CURLcode result=curl_easy_perform(curl);

    if(result==CURLE_OK){
        std::cout<<"Transfer succesful!"<<std::endl;
    }
    else{
        std::cout<<curl_easy_strerror(result)<<std::endl;
        return EXIT_FAILURE;
    }

    std::cout<<response.size()<<std::endl;
if(response.size()>100){
    for(int i=0;i<100;i++){
        std::cout<<response[i];
    }
}
else{
    std::cout<<response<<std::endl;
}
    curl_easy_cleanup(curl);
}