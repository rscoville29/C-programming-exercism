#include "high_scores.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareFunc(const void *a, const void *b) {
    int32_t x = *(int32_t*)a;
    int32_t y = *(int32_t*)b;
    return (x > y) - (x < y);  
}

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len){
    return scores[scores_len - 1];
    
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t scores_copy[scores_len];
    memcpy(scores_copy, scores, scores_len * sizeof(int32_t));
    qsort(scores_copy, scores_len, sizeof(int32_t), compareFunc);
    return scores_copy[scores_len - 1];
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output){
    int32_t scores_copy[scores_len];
    memcpy(scores_copy, scores, scores_len * sizeof(int32_t));

    qsort(scores_copy, scores_len, sizeof(int32_t), compareFunc);

    size_t count = scores_len < 3 ? scores_len : 3;

    for(size_t i = 0; i < count; i++){
        output[i] = scores_copy[scores_len - 1 - i];
    }

    return count;
}