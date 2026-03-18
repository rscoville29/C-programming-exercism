#include "grains.h"
uint64_t square(uint8_t index){
    if(index == 0){
        return 0;
    }
    uint64_t total = 1;
    for(uint64_t i = 1; i < index; i++){
        total *= 2;
    }
    return total;
}
uint64_t total(void){
    uint64_t total = 1;
    uint64_t square = 1;
    for(int i = 1; i < 64; i++){
        square *= 2;
        total += square;
    }
    return total;
}