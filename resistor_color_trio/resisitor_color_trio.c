#include "resistor_color_trio.h"
#include <math.h>

int getCode(resistor_band_t color){
    return color;
}

resistor_value_t color_code(resistor_band_t bands[]){
        resistor_value_t result;
        int base = getCode(bands[0]) * 10 + getCode(bands[1]);
        int multiplier = getCode(bands[2]);
    if(multiplier > 0){
        result.value = base + pow(10, multiplier);
        result.unit = OHMS;
    }else{
        result.value = base;
        result.unit = OHMS;
    }
        
        return result;
}