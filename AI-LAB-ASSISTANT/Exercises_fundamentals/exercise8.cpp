#include<iostream>
#include<vector>
void offset_f(std::vector<double>* data,double offset){
    for(int i=0;i<data->size();i++){
        data->at(i)=data->at(i)+offset;
    }
}
int main(){
    std::vector<double> data={2.1,2.3,3.0,3.4};
    std::vector<double>*pntv=&data;
    double offset=0.3;
    offset_f(pntv,0.3);
    for(int i=0;i<pntv->size();i++){
        std::cout<<pntv->at(i)<<" ";
    }
}