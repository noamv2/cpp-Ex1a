#pragma once
#include <string>
#include <algorithm>
using std::string;

/** *
 * AUTHORS: <Noam Vanunu>
 * 
 * Date: 08/03/2022
 */

namespace ariel{

     string mat(int, int, char, char);
     struct badInput : std::exception {
        const char* what() const noexcept {return "Mat size is always odd";}
    };

}
