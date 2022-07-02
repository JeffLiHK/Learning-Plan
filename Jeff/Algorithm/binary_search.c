#include <stdio.h>
#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))

int binsearch(int element, int array[], int size);

int main() {
    int list[] = {1,3,5,8,12,43};
    int index = binsearch(3, list, ARRAY_SIZE(list));
    printf("%d\n", index);
    return 0;
}

int binsearch(int element, int array[], int size) {
    int low, high, mid;
    high = size-1;
    low = 0;
    while (low <= high) {
        mid = (high+low) / 2;
        printf("low:%d, high:%d, mid:%d\n", low, high, mid);
        if (element > array[mid]) {
            low = mid+1;
        } else if (element < array[mid]) {
            high = mid-1;
        } else {
            return mid;
        }
    }
    return -1;
}