#include<iostream>
#include<fstream>
#include<vector>

void save_readings(const std::vector<double>* readings,const std::string& filename){
    std::ofstream outfile;
    outfile.open(filename);
    for(int i=0;i<readings->size();i++){
        outfile<<readings->at(i)<<std::endl;
    }
    outfile.close();
}
void average_value(const std::string& filename,double* avg){
    std::ifstream infile;
    infile.open(filename);
    double tnt;
    std::vector<double> v;
    while(infile>>tnt){
        v.push_back(tnt);
    }
    infile.close();
    double sum=0;
    for(int i=0;i<v.size();i++){
        sum=sum+v[i];
    }
    *avg=sum/(v.size());
}
int main(){
    std::vector<double> readings={2.3,3.4,5.1,2.8,9.6};
    std::vector<double>* pntv=&readings;
    std::string s="measurments.txt";
    save_readings(pntv,s);
    double avg;
    double*p=&avg;
    average_value(s,p);
    std::cout<<*p<<std::endl;
}