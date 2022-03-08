/** *
 * AUTHORS: <Noam Vanunu>
 * 
 * Date: 08/03/2022
 */
#include "mat.hpp"
#define flip(a,b,c) (a) == (b) ? (c) : (b)

string ariel::mat(int w, int h, char c1, char c2){

    char currChar = c1; // the pattern we weave this round
    if(w % 2 == 0 || h % 2 == 0 ||  w < 0  || h < 0){
        throw ariel::badInput();
    }

    char rug[h][w + 1];
    
    // we will weave the rug layer by layer, starting from the out layer
    int lcol = 0;
    int urow = 0;
    int rcol = w -1;
    int lrow = h - 1; // edges of the current layers

    while(lcol <= rcol && urow <= lrow){

        // weave the left and right columns of the current layer
        for(int i = urow; i <= lrow; i++ ){
            rug[i][lcol] = currChar; //left colmun
            rug[i][rcol] = currChar; // right column
        }
        // weave the upper and lower rows of the current layer
        for(int i = lcol; i <= rcol; i++ ){
            rug[urow][i] = currChar; //uuper row
            rug[lrow][i] = currChar; // lower row
        }

        //update layer edges
        lcol++;
        rcol--;
        urow++;
        lrow--;
        //change the character
        currChar = flip(currChar,c1,c2);
    }
    // add new lines to get a rectangle shape string
    for(int i = 0 ;  i <  h;i++){
        rug[i][w] = '\n';
        }

    return string(&rug[0][0], &rug[h-1][w] +1);
}


