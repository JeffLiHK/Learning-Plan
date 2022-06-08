#include <stdio.h>
#define list_size 20

void print_list(int list[], int size);
void quick_sort(int list[], int size);
void swap(int* a, int* b);

int main(){
    int list[list_size];
    for (int i=0; i<list_size; i++) {
        list[i] = ((((i+47)*79-31)/19)*747) % 17;
    }
    printf("Unsort:\t");
    print_list(list, list_size);
    quick_sort(list, list_size);
    printf("Sort:\t");
    print_list(list, list_size);
}

void print_list(int list[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void quick_sort_loop(int list[], int low, int high);

void quick_sort(int list[], int size){
    quick_sort_loop(list, 0, size);
}

void quick_sort_loop(int list[], int low, int high) {
    int pivot = low;    // middle element
    int i = high;   // checking element
    int j = high;   // the first element of all bigger elements
    if (low >= high) {
        return;
    }
    while (i > pivot) {
        if (list[i] > list[pivot]) {
            swap(&list[i], &list[j]);
            j--;
        }
        i--;
    }
    swap(&list[pivot], &list[j]);
    quick_sort_loop(list, low, j-1);
    quick_sort_loop(list, j+1, high);
}

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}
