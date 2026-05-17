#include "isogram.h"
#include <string.h>
#include <ctype.h>
bool is_isogram(const char phrase[]){
    if(phrase == NULL){
        return false;
    }
    int len = strlen(phrase);
    if(len <= 1){
        return true;
    }

    for(int i = 0; i < len; i++){
        char temp = tolower(phrase[i]);
        if(temp != ' ' && temp != '-'){
            for(int j = i + 1; j < len; j++){
                if(temp == tolower(phrase[j])){
                    return false;
                }
            }
        }
    }
    return true;
}