#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length){
    int left = 0;
    int right = length - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == value){
            return &arr[mid];
        }else{
            if(arr[mid] > value){
                //go left
                right = mid - 1;
            }else{
                //go right
                left = mid + 1;
            }
            
        }
    }
    return NULL;
}