#include<iostream>
#include<curl/curl.h>
#include<nlohmann/json.hpp>

//rather than writing the long name repeatedly, we create a shorter type alias.
//eg. using Number=double;
//Number x=3.14;
//thus, it is an alias for a type.
//same for using namespase std;
//rather than std::cout
//just use cout
//JSON stands for JavaScript Object Notation. It's a standard text format for storing and exchanging structured information.

//For example, a JSON object might look like:
//{
// "resistance": 10000,
// "capacitance": 4e-9,
// "frequency": 1000
//}
int main(){
    using json=nlohmann::json;
    json student={
        {"name","Engineering student"},
        {"university","Imperial College London"},
        {"course","Triple E"}
    };
std::cout<<student["name"]<<std::endl;
//outpout:Engineering student.
std::cout<<student["university"]<<std::endl;
std::cout<<student["course"]<<std::endl;
//in a JSON object, we can access values using string keys.
std::cout<<"JSON Library Test:"<<std::endl;
//just prints the text inside the brackets.
std::cout<<student.dump(4)<<std::endl;
//dump() method converts the JSON object into a string containing JSON text.
//4 tells the library to indent nested lements using four spaces:
//{one space
//course -- space
//2nd in the list --space
//3rd object -- space (four spaces overall)
//}
std::cout<<"nlibcurl Test"<<std::endl;
std::cout<<"Version: "<<curl_version()<<std::endl;
//curl_version() is a function provided by libcurl
//it returns a pointer to a null-terminated character string containing version and feature info
std::cout<<"Both libraries are working!"<<std::endl;
}