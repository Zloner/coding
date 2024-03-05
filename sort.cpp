#include "sort.h"

void swap(int* a, int* b){
    int *temp = a;
    a = b;
    b = temp;
}

void InsertSort(int *arr, int length){
    for(int i = 1; i < length; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void SelectSort(int *arr, int length){
    for(int i = 0; i < length; i++){
        int min = i;
        for(int j = i+1; j < length; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i], &arr[min]);
    }
}

void BubbleSort(int *arr, int length){
    for(int i = length; i > 1; i--){
        int swap_flag = 0;
        for(int j = 0; j < i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swap_flag = 1;
            }
        }
        if(!swap_flag)
            break;
    }
}

void ShellSort(int *arr, int length){
    for(int step = length/2; step > 0; step/=2){
        for(int i = step; i < length; i++){
            int key = arr[i];
            int j;
            for(j = i; j >= 0 && arr[j-step] > arr[j];j += step)
                arr[j] = arr[j-step];
            arr[j] = key;
        }
    }
}

void CountSort(int *arr, int length){
    int max = arr[0];
    for(int i = 0; i < length; i++)
        max = max>arr[i] ? max : arr[i];

    int* count = (int*)malloc(sizeof(int) * (max+1));

    for(int i = 0; i < length; i++){
        count[arr[i]]++;
    }

    for(int i = 1; i < max+1; i++){
        count[i] = count[i] + count[i - 1];
    }

    int* result = (int*)malloc(sizeof(int) * length);

    for(int i = 0; i < length; i++){
        if(count[arr[i]] - 1 != 0){
            result[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }
    }

    for(int i = 0; i < length; i++){
        arr[i] = result[i];
    }

    free(count);
    free(result);
}

int q_sort(int * arr, int left, int right){
    int key = arr[right];
    int i = left;

    for(int j = left; j < right; j++){
        if(arr[j] < key){
            swap(&arr[j], &arr[i]);
            i++;
        }
    }
    arr[right] = arr[i];
    arr[i] = key;
    return i;
}

void qsort(int * arr, int left, int right){
    if(left < right){
        int mid = q_sort(arr, left, right);
        qsort(arr, left, mid - 1);
        qsort(arr, mid, right);
    }
}

void QuickSort(int *arr, int length){
    qsort(arr, 0, length-1);
}

void heapify(int * arr, int length, int i){
    int largest = i; 
    int rson = i*2 + 1;
    int lson = i*2 + 1;

    if(rson < length && arr[largest] < arr[rson]){
        largest = rson;
    }
    if(lson < length && arr[largest] < arr[lson]){
        largest = lson;
    }
    if(largest != i){
        swap(&arr[largest], &arr[i]);
        heapify(arr, length, largest);
    }
}

void HeapSort(int *arr, int length){
    for(int i = (length- 1 - 1)/2; i >= 0; i--){
        heapify(arr, length, i);
    }

    for(int i = length-1; i > 0; i--){
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }

}

void merge(int* arr, int * tmp, int left, int mid, int right){
    int l = left;
    int r = mid + 1;
    int i = left;

    while(l <= mid && r <= right){
        if(arr[l] < arr[r])
            tmp[i++] = arr[l++];
        if(arr[r] < arr[l])
            tmp[i++] = arr[r++];
    }

    while(l <= mid){
        tmp[i++] = arr[l++];
    }
    while(r <= right){
        tmp[i++] = arr[r++];
    }

    for(int i = left; i <= right; i++)
        arr[i] = tmp[i];
}

void msort(int* arr, int* tmp, int left, int right){
    if(left < right){
        int mid = (left + right)/2;

        msort(arr, tmp, left, mid);
        msort(arr, tmp, mid+1, right);

        merge(arr, tmp, left, mid, right);
    }
}

void MergeSort(int *arr, int length){
    int * tmp = (int *)malloc(sizeof(int) * length - 1);
    if(tmp){
        msort(arr, tmp, 0, length - 1);
    }
    free(tmp);
}
