#include "dnd_character.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
int compare(const void* x_void, const void* y_void){
    int x = *(int*)x_void;
    int y = *(int*)y_void;
    return x - y;
}
int ability(void){
    int min = 1;
    int max = 6;
    int dice1 = (rand() % (max - min + 1)) + min;
    int dice2 = (rand() % (max - min + 1)) + min;
    int dice3 = (rand() % (max - min + 1)) + min;
    int dice4 = (rand() % (max - min + 1)) + min;
    int arr[4] = {dice1, dice2, dice3, dice4};
    qsort(arr, 4, sizeof(int), compare);
    int max1 = arr[3];
    int max2 = arr[2];
    int max3 = arr[1];
    return max1 + max2 + max3;
    
}
int modifier(int score){
    float fscore = score;
    return floor((fscore - 10) / 2);
}
dnd_character_t make_dnd_character(void){
   int strength = ability();
   int dexterity = ability();
   int constitution= ability();
   int intelligence = ability();
   int wisdom = ability();
   int charisma = ability();
   int hitpoints = modifier(constitution) + 10;
    dnd_character_t newCharacter = {
        strength,
        dexterity,
        constitution,
        intelligence,
        wisdom,
        charisma,
        hitpoints
    };
    printf("strength: %d\ndexterity: %d\nconstitution: %d\nintelligence: %d\nwisdom: %d\ncharisma: %d\nhitpoints: %d\n", strength, dexterity, constitution, intelligence, wisdom, charisma, hitpoints);
    return newCharacter;
}