#include <iostream>
#include <string>
#include "mat.cpp"
using namespace std;

int main(){



    int w, h;
    char c1,c2;

    cout<<"Insert width and height sepreated by space: \n";
    cin>>w;
    cin>>h;
    cout<<"Insert two symbols sepreated by space: \n";
    cin>>c1;
    cin>>c2;
    cout<<"char 1: "<<c1<<"char 2: "<<c2<<endl;
    std::string res = ariel::mat(w,h,c1,c2);
    cout<<res;
    return 0;
}