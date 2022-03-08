#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
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


TEST_CASE("one line pattern"){
    CHECK(mat(11,1, '(','4') == "(((((((((((\n");
    CHECK(mat(5,1, '@','4') == "@@@@@\n");
}

TEST_CASE("Special characters"){

    CHECK(mat(5,5,' ',' ') == "     \n"
                              "     \n"
                              "     \n"
                              "     \n"
                              "     \n"  );
    CHECK(mat(7,7,'\n','\n') == "\n\n\n\n\n\n\n\n"
                                "\n\n\n\n\n\n\n\n"
                                "\n\n\n\n\n\n\n\n"
                                "\n\n\n\n\n\n\n\n"                                
                                "\n\n\n\n\n\n\n\n"
                                "\n\n\n\n\n\n\n\n"
                                "\n\n\n\n\n\n\n\n");                   
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



