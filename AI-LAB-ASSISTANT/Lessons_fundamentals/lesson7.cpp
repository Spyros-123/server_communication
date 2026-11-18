#include<iostream>

void IncreaseInteger(void* data){
    int* pnt;
    pnt=static_cast<int*>(data);
    *pnt=*pnt+10;
}
void DoubleMeasurment(void* data){
    int* pnt;
    pnt=static_cast<int*>(data);
    *pnt=(*pnt)*2;
}

void callback(void* data,void(*implement)(void*)){
    implement(data);
}

int main(){
    int data=3;
    void* pnt=&data;
    callback(pnt,IncreaseInteger);
    std::cout<<data<<std::endl;
    callback(pnt,DoubleMeasurment);
    std::cout<<data<<std::endl;

}