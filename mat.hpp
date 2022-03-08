#pragma once
#include <string>
#include <algorithm>
using std::string;
namespace ariel{

     string mat(int, int, char, char);
     struct badInput : std::exception {
        const char* what() const noexcept {return "Mat size is always odd";}
    };

}