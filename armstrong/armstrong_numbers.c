#include "armstrong_numbers.h"
#include <math.h>
#include <stdio.h>
bool is_armstrong_number(int candidate){
    int num_count = candidate;
    int num = candidate;
    int total = 0;
    int digits = 0;
    int rem;
    //count digits:
    while(num_count > 0){
        digits++;
        num_count /= 10;
    }
    printf("digits: %d\nnum: %d\n", digits, num);
    //calculate:
    while(num > 0){
        rem = num % 10;
        num /= 10;
        total += pow(rem, digits);
    }
    printf("total:%d", total);
    if(total == candidate){
        return true;
    }
    return false;
    
}