#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);
void InsertSort(int *arr, int length);
void SelectSort(int *arr, int length);
void BubbleSort(int *arr, int length);
void ShellSort(int *arr, int length);
void CountSort(int *arr, int length);
int q_sort(int * arr, int left, int right);
void qsort(int * arr, int left, int right);
void QuickSort(int *arr, int length);
void heapify(int * arr, int length, int i);
void HeapSort(int *arr, int length);
void merge(int* arr, int * tmp, int left, int mid, int right);
void msort(int* arr, int* tmp, int left, int right);
void MergeSort(int *arr, int length);

#endif