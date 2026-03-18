#include "collatz_conjecture.h"
int steps(int start){
    if(start <= 0){
        return -1;
    }
    if(start == 1){
        return 0;
    }else{
        int totalSteps = 0;
        int temp = start;
        while(temp != 1){
            totalSteps++;
            if(temp % 2 ==0){
                //is even
                temp/= 2;
            }else{
                //is odd
                temp = temp * 3 + 1;
            }
        }
        return totalSteps;
    }
}