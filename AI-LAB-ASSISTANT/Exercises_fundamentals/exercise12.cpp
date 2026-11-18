#include<iostream>
#include<vector>
void increase_measurment(void* data,double offset){
    std::vector<double>* pntv;
    pntv=static_cast<std::vector<double>*>(data);
    for(int i=0;i<pntv->size();i++){
        pntv->at(i)=pntv->at(i)+offset;
    }
}
int main(){
    std::vector<double> data={2.3,2.7,3.8,1.6,9.4};
    void* p=&data;
    double offset=1.0;
    increase_measurment(p,offset);
    for(int i=0;i<data.size();i++){
        std::cout<<data[i]<<" ";
    }
}