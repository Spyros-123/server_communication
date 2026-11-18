#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<string>
#include<cstdlib>

void analyseReadings(std::vector<double>* readings,double* max,double* rms,double* avg){
    *avg=0;
    *rms=0;
    *max=readings->at(0);
    for(int i=0;i<readings->size();i++){
        *avg=*avg+readings->at(i);
        if(readings->at(i)>*max){
            *max=readings->at(i);
        }
        *rms=*rms+std::pow((readings->at(i)),2);
    }
    *avg=(*avg)/(readings->size());
    *rms=(*rms)/(readings->size());
    *rms=std::sqrt(*rms);
}

void addOffset(double* value){
    double offset=0.5;
    *value=*value+0.5;
}
void applyGain(double* value){
    double scalefactor=1.2;
    *value=(*value)*scalefactor;
}
void processReadings(std::vector<double>* readings,void(*callback)(double*)){
    double value;
    double*pntv;
    for(int i=0;i<readings->size();i++){
        value=readings->at(i);
        pntv=&value;
        callback(pntv);
        readings->at(i)=value;
    }
}

void receiveData(const std::string& chunk,void*userdata){
    std::string* pnts;
    pnts=static_cast<std::string*>(userdata);
    pnts->append(chunk);
}
void simulateServer(void*userdata, void(*callback)(const std::string&,void*)){
std::vector<std::string> chunks={
        "Circuit analysis complete. ",
    "Maximum voltage is within range. ",
    "No critical anomalies detected."
    };
    for(int i=0;i<chunks.size();i++){
        callback(chunks[i],userdata);
    }
}

int main(){
    std::vector<double> voltages={
        2.1,3.4,4.0,5.2,3.8
    };
    std::string userdata;
    void*pnts=&userdata;
    std::vector<double>* pntv=&voltages;
    double rms,max,avg;
    double*rmsp=&rms;
    double*maxp=&max;
    double*avgp=&avg;
    processReadings(pntv,addOffset);
    processReadings(pntv,applyGain);
    
    analyseReadings(pntv,maxp,rmsp,avgp);
    simulateServer(pnts,receiveData);

    std::ofstream outfile;
    outfile.open("circuit_report.txt");
    if(!outfile.is_open()){
        std::cout<<"ERROR"<<std::endl;
        return EXIT_FAILURE;
    }
    outfile<<"Calibrated Voltages: ";
    for(int i=0;i<pntv->size();i++){
        outfile<<voltages[i]<<", ";
    }
    outfile<<std::endl;
    outfile<<"Max= "<<*maxp<<std::endl;
    outfile<<"RMS= "<<*rmsp<<std::endl;
    outfile<<"Average= "<<*avgp<<std::endl;
    outfile<<userdata<<std::endl;

}