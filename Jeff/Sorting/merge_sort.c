#include <stdio.h>
#define list_size 24

void print_list(int list[], int size);
void merge_sort(int list[], int low, int high);
void merge(int list[], int low, int mid, int high);
void swap(int* a, int* b);

int main(){
    int list[list_size];
    for (int i=0; i<list_size; i++) {
        list[i] = ((((i+47)*79-31)/19)*747) % 17;
    }
    printf("Unsort:\t");
    // printf("4+3/2 = %d\n", (4+3)/2);
    print_list(list, list_size);
    // int list2[list_size];
    merge_sort(list, 0, list_size-1);
    printf("Sort:\t");
    print_list(list, list_size);
}

void merge_sort(int list[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low+high)/2;
    merge_sort(list, low, mid);
    merge_sort(list, mid+1, high);
    merge(list, low, mid, high);
}

void merge(int list[], int low, int mid, int high) {
    int new_list[high-low+1];
    int left_size = mid-low+1;
    int right_size = high-mid;
    // printf("low=%d, high=%d, mid=%d ", low, high, mid);
    // printf("left_size=%d, right_size=%d\n", left_size, right_size);
    int i = low;
    int j = mid+1;
    int k = 0;
    while (i <= mid && j <= high) {
        if (list[i] < list[j]) {
            new_list[k++] = list[i++];
        } else {
            new_list[k++] = list[j++];
        }
    }

    while (i <= mid) {
        new_list[k++] = list[i++];
    }

    while (j <= high) {
        new_list[k++] = list[j++];
    }

    for (int i=0; i<left_size + right_size; i++) {
        list[i+low] = new_list[i];
    }
}

void print_list(int list[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}