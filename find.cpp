#include "find.h"

int search(int *arr, int length, int target){
    int left = 0;
    int right = length - 1;
    
    while(left <= right){
        int m = (left + right) / 2;
        if(arr[m] == target)
            return m;
            
        if(arr[m] > target)
            right = m - 1;
        else
            left = m + 1;
    }
    return -1;
}

int findPeakElement(int* arr, int length){
        int left = 0;
        int right = length - 1;

        while(left < right){
            int mid = (left + right) / 2;

            if(arr[mid] > arr[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }