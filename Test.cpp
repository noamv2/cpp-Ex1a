/** *
 * AUTHORS: <Noam Vanunu>
 * 
 * Date: 08/03/2022
 */

#include <algorithm>
#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

TEST_CASE("single symbol"){

    CHECK(mat(1,1,'#','*') == "#\n");
    CHECK(mat(1,1,'#','#') == "#\n");
    CHECK(mat(1,1,'*','#') == "*\n");
    CHECK(mat(1,1,'*','*') == "*\n");
}

TEST_CASE("same symbols different sizes"){

    CHECK(mat(3,7,'#','#') == "###\n###\n###\n###\n###\n###\n###\n");
    CHECK(mat(1,3,'@','@') == "@\n@\n@\n");
    CHECK(mat(5,5,'*','*') == "*****\n*****\n*****\n*****\n*****\n");
    CHECK(mat(3,1,'*','*') == "***\n");
}

TEST_CASE("same symbols same sizes"){

    CHECK(mat(7,7,'#','#') == "#######\n#######\n#######\n#######\n#######\n#######\n#######\n");
    CHECK(mat(3,3,'@','@') == "@@@\n@@@\n@@@\n");
    CHECK(mat(5,5,'*','*') == "*****\n*****\n*****\n*****\n*****\n");
    CHECK(mat(3,3,'*','*') == "***\n***\n***\n");
}
TEST_CASE("same symbols same sizes"){

    CHECK(mat(7,7,'#','#') == "#######\n#######\n#######\n#######\n#######\n#######\n#######\n");
    CHECK(mat(3,3,'@','@') == "@@@\n@@@\n@@@\n");
    CHECK(mat(5,5,'*','*') == "*****\n*****\n*****\n*****\n*****\n");
    CHECK(mat(3,3,'*','*') == "***\n***\n***\n");
}

TEST_CASE("Different symbols same sizes"){

    CHECK(mat(7,7,'#','*') == "#######\n"
                               "#*****#\n"
                               "#*###*#\n"
                               "#*#*#*#\n"
                               "#*###*#\n"
                               "#*****#\n"
                               "#######\n");
    CHECK(mat(3,3,'@','-') == "@@@\n"
                              "@-@\n"
                              "@@@\n");
    CHECK(mat(5,5,'*','Q') == "*****\n"
                              "*QQQ*\n"
                              "*Q*Q*\n"
                              "*QQQ*\n"
                              "*****\n");
    CHECK(mat(3,3,'%','!') == "%%%\n"
                              "%!%\n"
                              "%%%\n");
}

TEST_CASE("Different symbols different size"){
       CHECK(mat(5,3,'%','!') == "%%%%%\n"
                                 "%!!!%\n"
                                 "%%%%%\n");
        CHECK(mat(3,7,'$','^') == "$$$\n"
                                  "$^$\n"
                                  "$^$\n"
                                  "$^$\n"
                                  "$^$\n"
                                  "$^$\n"
                                  "$$$\n");
                    
        CHECK(mat(11,1, '7','4') == "77777777777\n");
}


TEST_CASE("horizntal line pattern"){
    CHECK(mat(11,1, '(','4') == "(((((((((((\n");
    CHECK(mat(5,1, '@','4') == "@@@@@\n");
}

TEST_CASE("vertical line pattern"){
    CHECK(mat(1,5, '(','4') == "(\n"
                               "(\n"
                               "(\n"
                               "(\n"
                               "(\n");

    CHECK(mat(1,7, '@','4') == "@\n"
                               "@\n"
                               "@\n"
                               "@\n"
                               "@\n"
                               "@\n"
                               "@\n");
}


TEST_CASE("Illegal - even values"){

    CHECK_THROWS(mat(6,6,'X','O')); // both illegal
    CHECK_THROWS(mat(5,6,'X','O')); // right illegal
    CHECK_THROWS(mat(5,6,'X','O')); // left illegal

    CHECK_THROWS(mat(0,6,'X','O')); // left illegal
    CHECK_THROWS(mat(0,0,'X','O')); // both illegal
    CHECK_THROWS(mat(0,5,'X','O')); // right illegal
}

TEST_CASE("Illegal - negtive values"){

    CHECK_THROWS(mat(-1,-7,'X','O')); // both illegal
    CHECK_THROWS(mat(3,-7,'X','O')); // right illegal
    CHECK_THROWS(mat(-2,-1,'X','O')); // left illegal
}

TEST_CASE("Illegal - negtive and even values"){

    CHECK_THROWS(mat(-2,-8,'X','O')); // both illegal
    CHECK_THROWS(mat(-16,-4,'X','O')); // right illegal
    CHECK_THROWS(mat(-2,-18,'X','O')); // left illegal
}


TEST_CASE("Capital Letters only"){

    CHECK(mat( 3,3,'X','O') == "XXX\n"
                                      "XOX\n"
                                      "XXX\n"); // both illegal
    CHECK(mat(3,1,'X','Z')== "XXX\n"); // right illegal
    CHECK(mat(5,3,'L','P') == "LLLLL\n"
                              "LPPPL\n"
                              "LLLLL\n"
                             ); // left illegal
}

TEST_CASE(" lower case letters only"){

    CHECK(mat( 3,3,'x','o') == "xxx\n"
                                      "xox\n"
                                      "xxx\n"); // both illegal
    CHECK(mat(3,1,'x','z')== "xxx\n"); // right illegal
    CHECK(mat(5,3,'l','p') == "lllll\n"
                              "lpppl\n"
                              "lllll\n"
                             ); // left illegal
}

TEST_CASE("numbers only"){

    CHECK(mat(3,3,'3','7') == "333\n"
                                      "373\n"
                                      "333\n"); // both illegal
    CHECK(mat(3,1,'9','0')== "999\n"); // right illegal
    CHECK(mat(5,3,'1','1') == "11111\n"
                              "11111\n"
                              "11111\n"
                             ); // left illegal
}

TEST_CASE("symbols only"){

    CHECK(mat(3,3,'@','#') ==         "@@@\n"
                                      "@#@\n"
                                      "@@@\n"); // both illegal
    CHECK(mat(3,1,'~','~')== "~~~\n"); // right illegal
    CHECK(mat(5,3,'~','!') == "~~~~~\n"
                              "~!!!~\n"
                              "~~~~~\n"
                             ); // left illegal
}

TEST_CASE("capital and lower cases"){

    CHECK(mat(3,3,'A','a') ==         "AAA\n"
                                      "AaA\n"
                                      "AAA\n"); // both illegal
    CHECK(mat(3,1,'b','N')== "bbb\n"); // right illegal
    CHECK(mat(5,3,'o','X') == "ooooo\n"
                              "oXXXo\n"
                              "ooooo\n"
                             ); // left illegal
}

TEST_CASE("capital letter and number"){

    CHECK(mat(3,3,'A','7') ==         "AAA\n"
                                      "A7A\n"
                                      "AAA\n"); // both illegal
    CHECK(mat(3,1,'1','N')== "111\n"); // right illegal
    CHECK(mat(5,3,'1','X') == "11111\n"
                              "1XXX1\n"
                              "11111\n"
                             ); // left illegal
}

TEST_CASE("lower case letter and number"){

    CHECK(mat(3,3,'a','7') ==         "aaa\n"
                                      "a7a\n"
                                      "aaa\n"); // both illegal
    CHECK(mat(3,1,'1','n')== "111\n"); // right illegal
    CHECK(mat(5,3,'1','x') == "11111\n"
                              "1xxx1\n"
                              "11111\n"
                             ); // left illegal
}

TEST_CASE("lower case letter and symbol"){

    CHECK(mat(3,3,'a','`') ==         "aaa\n"
                                      "a`a\n"
                                      "aaa\n"); // both illegal
    CHECK(mat(3,1,'{','n')== "{{{\n"); // right illegal
    CHECK(mat(5,3,';','x') == ";;;;;\n"
                              ";xxx;\n"
                              ";;;;;\n"
                             ); // left illegal
}

TEST_CASE("Large patterns"){

    CHECK(mat(19,17,'-','@') == "-------------------\n"
"-@@@@@@@@@@@@@@@@@-\n"
"-@---------------@-\n"
"-@-@@@@@@@@@@@@@-@-\n"
"-@-@-----------@-@-\n"
"-@-@-@@@@@@@@@-@-@-\n"
"-@-@-@-------@-@-@-\n"
"-@-@-@-@@@@@-@-@-@-\n"
"-@-@-@-@---@-@-@-@-\n"
"-@-@-@-@@@@@-@-@-@-\n"
"-@-@-@-------@-@-@-\n"
"-@-@-@@@@@@@@@-@-@-\n"
"-@-@-----------@-@-\n"
"-@-@@@@@@@@@@@@@-@-\n"
"-@---------------@-\n"
"-@@@@@@@@@@@@@@@@@-\n"
"-------------------\n");
}




