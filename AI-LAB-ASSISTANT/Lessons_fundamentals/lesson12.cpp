#include<iostream>
#include<cstddef>
#include<string>

std::size_t receiveData(char* data,std::size_t size,std::size_t nmemb,void* userdata){
    std::size_t totalBytes=size*nmemb;
    std::string* p;
    p=static_cast<std::string*>(userdata);
    p->append(data,totalBytes);
    return totalBytes;
}
void simulateServer(void* userdata,std::size_t(*callback)(char*,std::size_t,std::size_t,void*)){
    char chunk1[]={'A','I',' '};
    char chunk2[]={'a','n','a','l','y','s','i','s',' '};
    char chunk3[]={'c','o','m','p','l','e','t','e','.'};
    char* p1=chunk1;
    char* p2=chunk2;
    char* p3=chunk3;
    callback(p1,1,sizeof(chunk1),userdata);
    callback(p2,1,sizeof(chunk2),userdata);
    callback(p3,1,sizeof(chunk3),userdata);
}
int main(){
    std::string response;
    void* pnts=&response;
    simulateServer(pnts,receiveData);
    std::cout<<response<<std::endl;
}
