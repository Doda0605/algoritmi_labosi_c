#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void heap_sort(int *array, int n);
void heapify(int *array, int n, int i);
void bubble_sort(int *array, int n);
void swap(int *xp, int *yp);
void bubbleSort(int *array, int n);
void merge_sort(int *array, int l, int r);
void merge(int *array, int l, int m, int r);

int main(void){

    int n = 20000;
    int *array = (int*)malloc(n * sizeof(int));
    time_t t1, t2, t3, t4, t5, t6;

    for(int i = 1; i <= n; i++){
        array[i] = rand()%100 + 1;
    }

    t1 = clock();
    heap_sort(array, n);
    t2 = clock();
    printf("Vrijeme heap_sort je %dms\n", t2-t1);
    
    t3 = clock();
    bubble_sort(array, n);
    t4 = clock();
    printf("Vrijeme bubble_sort je %dms\n", t4-t3);

    t5 = clock();
    merge_sort(array, 0, n - 1);
    t6 = clock();
    printf("Vrijeme merge_sorta je %dms\n", t6-t5);

    free(array);

    return 0;
}

void heap_sort(int *array, int n){

    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(array, n, i);
    }
 
    for (int i = n - 1; i >= 0; i--){
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;
 
        heapify(array, i, 0);
    }

}

void heapify(int *array, int n, int i)
{
    int largest = i;
 
    int left = 2 * i + 1;
    int right  = 2 * i + 2;
 
    if (left < n && array[left] > array[largest]){
        largest = left;
    }
 
    if (right < n && array[right] > array[largest]){
        largest = right;
    }
 
    if (largest != i){
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
 
        heapify(array, n, largest);
    }
}

void bubble_sort(int array[], int n){
    
    int i, j;
    bool swapped;

    for (i = 0; i < n - 1; i++) {
        
        swapped = false;
        
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = true;
            }
        }
 
        if (swapped == false)
            break;
    }

}

void swap(int* xp, int* yp){
    
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}

void merge_sort(int *array, int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        
        merge_sort(array, l, m);
        merge_sort(array, m + 1, r);
 
        merge(array, l, m, r);
    }
}

void merge(int *array, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            array[k] = L[i];
            i++;
        }else{
            array[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}