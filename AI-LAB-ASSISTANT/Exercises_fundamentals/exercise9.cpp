#include<iostream>
#include<vector>

void find_peak_voltage(const std::vector<double>* data,double* peak){
    double max=data->at(0);
    for(int i=0;i<data->size();i++){
        if(data->at(i)>max){
            max=data->at(i);
        }
    }
    *peak=max;
}
int main(){
    std::vector<double> data={1.4,3.2,2.6,9.4,5.1};
    std::vector<double>* pntv=&data;
    double peak;
    double*p=&peak;
    find_peak_voltage(pntv,p);
    std::cout<<*p<<std::endl;
}