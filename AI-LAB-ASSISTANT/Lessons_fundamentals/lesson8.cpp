#include<iostream>
#include<string>
#include<vector>

void receiveData(const std::string& chunk,void* userdata){
    std::string* spnt;
    spnt=static_cast<std::string*>(userdata);
    spnt->append(chunk);
}
void simulateServer(void* userdata,void(*callback)(const std::string&,void*)){
    std::vector<std::string> chunks={
        "I love circuits!",
        "Triple E mogs every other course.",
        "QS2 is law.(it's complete BS;we are frauds.)"
    };
    for(int i=0;i<chunks.size();i++){
        callback(chunks[i],userdata);
    }
}
int main(){
    std::string userdata;
    void*pnt=&userdata;
    simulateServer(pnt,receiveData);
    std::cout<<userdata<<std::endl;
}