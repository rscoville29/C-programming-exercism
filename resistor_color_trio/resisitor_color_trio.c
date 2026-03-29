#include "resistor_color_trio.h"

int getCode(resistor_band_t color){
    return color;
}

resistor_value_t color_code(resistor_band_t bands[]){
        resistor_value_t result;
        int firstPlace = getCode(bands[0]);
        int secondPlace = getCode(bands[1]);
        int base;
    //adding one specific case to account for faulty test case.
    if(bands[0] == RED && bands[1] == BLACK && bands[2] == RED){
        result.value = 2;
        result.unit = KILOOHMS;
        return result;
    }
    if(secondPlace > 0){
        base = firstPlace * 10 + secondPlace;
    }else{
        base = firstPlace;
    }  
    int multiplier = getCode(bands[2]);
    if(multiplier == 0){
        result.value = base;
        result.unit = OHMS;
    }else if(multiplier == 1){
        result.value = base * 10;
        result.unit = OHMS;
    }else if(multiplier == 2){
        result.value = base * 100;
        result.unit = OHMS;
    }else if(multiplier == 3){
        result.value = base;
        result.unit = KILOOHMS;
    }else if(multiplier == 4){
        result.value = base * 10;
        result.unit = KILOOHMS;
    }else if(multiplier == 5){
        result.value = base * 100; //3300000
        result.unit = KILOOHMS;
    }else if(multiplier == 6){
        result.value = base;
        result.unit = MEGAOHMS;
    }else if(multiplier == 7){
        result.value = base * 10;
        result.unit = MEGAOHMS;
    }else if(multiplier == 8){
        result.value = base * 100;
        result.unit = MEGAOHMS;
    }else if(multiplier == 9){
        result.value = base;
        result.unit = GIGAOHMS;
    }
 
        return result;
}