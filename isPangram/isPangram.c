#include "pangram.h"
#include <string.h>
#include <ctype.h>

bool is_pangram(const char *sentence){
    if(sentence == NULL || sentence[0] == '\0'){
        return false;
    }
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int count = 0;
    int input_len = strlen(sentence);
    for(int i = 0; i < 26; i++ ){
        for(int j = 0; j < input_len; j++){
            if(alphabet[i] == tolower(sentence[j])){
                count++;
                    break;
            }
        }
    }
    if(count == 26){
        return true;
    }
    return false;
}